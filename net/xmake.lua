-- =====================================================================
-- net/  基于内置 mongoose 7.1 的 HTTP 上传 / 静态服务示例
--       源仓库: Helioswei/testmongoose
--   结构: network/   示例代码 (server/client)
--         thirdparty/mongoose/  内置 mongoose 7.1 源码（自含，无外部依赖）
-- =====================================================================

-- 内置 mongoose 静态库
target("mongoose")
    set_kind("static")
    add_files("thirdparty/mongoose/mongoose.c")
    set_languages("c11")
    -- 老版本源码编译告警多且杂，静音该库自身的告警
    add_cflags("-w")
    if is_plat("linux") then
        add_syslinks("pthread", "dl")
    end

-- HTTP 上传/服务 demo（main: 无参数=起服务; 传文件路径=作为客户端上传）
target("net-http-demo")
    set_kind("binary")
    set_group("net")
    add_files("network/main.cpp")
    add_deps("mongoose")
