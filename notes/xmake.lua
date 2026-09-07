-- =====================================================================
-- notes/  读书笔记（Effective C++ 条款实验代码）
--   源仓库: Helioswei/booknotes
--   结构:   effective/  条款头文件 + 演示 main（编辑 main.cpp 的 #include 行即切换条款）
--           ref/        PDF 参考书（不进构建）
--   说明:   头文件即读书笔记载体，多为带注释的演示片段，不保证每条款可独立编译。
-- =====================================================================

-- 默认演示：编辑 effective/main.cpp 顶部的 #include 切换要验证的条款
target("effective")
    set_kind("binary")
    set_group("notes")
    add_files("effective/main.cpp")
    set_languages("c++11")
    add_includedirs("effective")
