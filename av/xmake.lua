-- =====================================================================
-- av/  ffmpeg 转码 / 滤镜 / 编码实验
--   源仓库: Helioswei/testffmpeg
--   启用:   xmake f --av=y    （首次会经 xmake-repo 拉取并编译 ffmpeg）
--   结构:   engine/  核心实验源码（每文件一个独立 main 用例）
--           ref/     Windows 参考工程(netexample) + ffmpeg 版本报告(ffmpegversion)
--   说明:   用例面向个人对 ffmpeg 的学习调试，个别需按现场补输入文件/参数。
-- =====================================================================
if not has_config("av") then
    return
end

add_requires("ffmpeg")

-- engine/encoder|filter|hw|transcode 下每个 .cpp 是一个独立 main 用例 → 一个 target
for _, dir in ipairs({ "encoder", "filter", "hw", "transcode" }) do
    for _, main in ipairs(os.files(path.join("engine", dir, "*.cpp"))) do
        local name = path.basename(main):gsub("%.cpp$", "")
        target("av_" .. name)
            set_kind("binary")
            set_group("av")
            set_default(false)
            add_files(main)
            add_packages("ffmpeg")
            add_includedirs("engine")
            set_languages("c++11")
    end
end
-- engine/avbase 为无 main 的辅助源码，未纳入构建（留作参考）
