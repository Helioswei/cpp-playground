-- =====================================================================
-- cpp-playground —— C++ 个人学习积累库（单仓）
--   由 5 个源仓库合并而来，见 README「源仓库对照表」。
--   构建系统: xmake  https://xmake.io
-- =====================================================================
set_xmakever("3.0.0")

set_project("cpp-playground")
set_version("0.1.0")
set_languages("c++17")

add_rules("mode.debug", "mode.release")

-- 两个"重依赖"模块默认关闭、按需启用：
--   xmake f --av=y       启用 ffmpeg 实验 (av/)
--   xmake f --sandbox=y  启用三方库试用 (lib-sandbox/)
option("av")
    set_default(false)
    set_showmenu(true)
    set_description("Enable ffmpeg demos under av/ (requires ffmpeg via xmake-repo)")

option("sandbox")
    set_default(false)
    set_showmenu(true)
    set_description("Enable third-party library demos under lib-sandbox/")

-- 各模块
includes("notes/xmake.lua")       -- 读书笔记（默认编译）
includes("patterns/xmake.lua")    -- 设计模式（默认编译）
includes("net/xmake.lua")         -- mongoose 网络示例（默认编译）
includes("av/xmake.lua")          -- ffmpeg 实验（--av=y 启用）
includes("lib-sandbox/xmake.lua") -- 三方库试用（--sandbox=y 启用）
