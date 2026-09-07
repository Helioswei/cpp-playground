-- =====================================================================
-- lib-sandbox/  第三方开源库试用 demo
--   源仓库: Helioswei/testcode
--   启用:   xmake f --sandbox=y
--   构建:   xmake -g sandbox          # 编所有依赖已就位的
--           xmake build sb_opencv_x   # 只编某个
--   依赖:   各 demo 原本链接自定义路径下的第三方库（原 testcode/<lib>/com.sh）。
--           库根路径解析: 环境变量 SB_ROOT_<ROOT> → DEPS → /usr/local
--           例: SB_ROOT_VIDEO=/dev/deps/video xmake -g sandbox
--           include 目录不存在的库会被自动跳过。
-- =====================================================================
if not has_config("sandbox") then
    return
end

local function getenv(k)
    local v = os.getenv(k)
    return v and v ~= "" and v or nil
end

-- 根路径: SB_ROOT_<ROOT> / DEPS / /usr/local
local function root(which)
    return getenv("SB_ROOT_" .. which:upper())
        or getenv("DEPS")
        or "/usr/local"
end

-- 各库依赖事实（来自原 com.sh）。字段:
--   links / syslinks      动态库名
--   root + inc_rel/lib_rel  库安装根与 include/lib 相对路径（默认 lib 在 <root>/lib）
--   lib_dir               显式给动态库目录（覆盖 <root>/lib）
--   static_files+static_rel 静态库文件路径（相对 <root>）
local specs = {
    -- 无外部依赖
    regex   = { cxx = "c++11" },

    xml     = { cxx = "c++11", root = "poco",  inc_rel = "include", lib_rel = "lib",
                links = { "PocoFoundation", "PocoXML" } },
    htmlcxx = { cxx = "c++11", root = "htmlcxx", inc_rel = "include", lib_rel = "lib", links = { "htmlcxx" } },
    myhtml  = { cxx = "c++11", root = "myhtml",  inc_rel = "include", lib_rel = "lib", links = { "myhtml" } },
    mysqlpp = { cxx = "c++11", root = "mysqlpp", inc_rel = "include/mysql++", lib_rel = "lib", links = { "mysqlpp" } },
    amqpcpp = { cxx = "c++11", root = "amqpcpp", inc_rel = "include", lib_rel = "lib", links = { "amqpcpp" },
                syslinks = { "pthread", "dl", "ev" } },
    -- poco/rsa*.cpp 用 PocoCrypto；main.cpp 曾注释 PocoData/MySQL
    poco    = { cxx = "c++11", root = "poco", inc_rel = "include", lib_rel = "lib",
                links = { "PocoFoundation", "PocoCrypto" } },
    pistache = { cxx = "c++14", root = "pistache", inc_rel = "include", lib_rel = "lib", links = { "pistache" } },
    webdrive = { cxx = "c++11", root = "include/webdriverxx", inc_rel = ".", lib_rel = "lib",
                 links = { "curl" }, syslinks = { "pthread" } },   -- 原 com.sh 用 -L/usr/local/libcurl/lib，可通过 SB_ROOT_WEBDRIVE 覆盖
    ffmpeg  = { cxx = "c++11", root = "video", inc_rel = "include", lib_rel = "lib",
                links = { "avcodec", "avdevice", "avfilter", "avformat", "avutil", "swscale" } },
    opencv  = { cxx = "c++11", root = "opencv", inc_rel = "include/opencv4", lib_rel = "lib64",
                links = { "opencv_core", "opencv_imgcodecs", "opencv_highgui", "opencv_imgproc", "opencv_videoio" } },
    -- mupdf 为静态链接
    mupdf   = { cxx = "c++11", root = "helios", inc_rel = "include", lib_rel = "lib",
                static_files = { "libmupdf.a", "libmupdf-third.a" }, syslinks = { "m" } },
}

for dir, cfg in pairs(specs) do
    -- 计算依赖是否就位
    local ok = true
    local incdirs, linkdirs, links, syslinks, statics = {}, {}, {}, {}, {}
    if cfg.links then links = cfg.links end
    if cfg.syslinks then syslinks = cfg.syslinks end

    if cfg.root then
        local r = root(cfg.root)
        local inc = path.join(r, cfg.inc_rel)
        incdirs[1] = inc
        if not os.isdir(inc) then ok = false end
        if cfg.static_files then
            for _, f in ipairs(cfg.static_files) do
                local p = path.join(r, cfg.lib_rel, f)
                table.insert(statics, p)
                if not os.isfile(p) then ok = false end
            end
        else
            local ld = path.join(r, cfg.lib_rel)
            linkdirs[1] = ld
            if not os.isdir(ld) then ok = false end
        end
    end

    if not ok then
        local rootname = cfg.root and cfg.root:upper() or "?"
        print(string.format("lib-sandbox: skip [%s] (依赖未就位，可设 SB_ROOT_%s 或 DEPS 指向安装路径)", dir, rootname))
    else
        for _, main in ipairs(os.files(path.join(dir, "*.cpp"))) do
            local name = path.basename(main):gsub("%.cpp$", "")
            target("sb_" .. dir .. "_" .. name)
                set_kind("binary")
                set_group("sandbox")
                set_default(false)
                add_files(main)
                set_languages(cfg.cxx or "c++11")
                if #incdirs > 0 then add_includedirs(incdirs) end
                if #linkdirs > 0 then add_linkdirs(linkdirs) end
                if #links > 0 then add_links(links) end
                if #statics > 0 then add_files(statics) end
                if #syslinks > 0 then add_syslinks(syslinks) end
        end
    end
end
