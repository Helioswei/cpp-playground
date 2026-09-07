-- =====================================================================
-- patterns/  GoF 设计模式实现（C++）
--   源仓库: Helioswei/designPatterns
--   结构:   {creational,structural,behavioral}/<模式名>/main.cpp ...
--           ref/  PDF 参考书（不进构建）
--   规则:   每个模式目录 = 一个可执行 target（编译该目录全部 .cpp）
--           单个运行: xmake run pat_<模式名>
-- =====================================================================

for _, category in ipairs({ "creational", "structural", "behavioral" }) do
    for _, dir in ipairs(os.dirs(path.join(category, "*"))) do
        local name = path.basename(dir)
        -- visitor 目录为源仓库中的未完成示例（main.cpp 引用缺失的 context.h，实为 strategy 写法），
        -- 保留源码但不生成 target，见 patterns/README.md
        local cpps = os.files(path.join(dir, "*.cpp"))
        if #cpps > 0 and name ~= "visitor" then
            target("pat_" .. name)
                set_kind("binary")
                set_group("patterns")
                add_files(cpps)
                set_languages("c++11")
        end
    end
end
