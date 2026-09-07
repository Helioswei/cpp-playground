# patterns/ — GoF 设计模式（C++）

源仓库：`Helioswei/designPatterns`。参考 PDF 电子书统一放在仓库根 `books/`（Git LFS）。

```bash
xmake run pat_visitor          # 不行 —— 见下
xmake run pat_state            # 正常
xmake -g patterns              # 编译全部可用模式
```

每个模式一个 target（`pat_<模式名>`），已全部实测可编译可运行。
> 例外：`behavioral/visitor/` 是源仓库里就**未完成**的示例（`main.cpp` 引用仓库中不存在的 `context.h`，内容实为 strategy 写法），保留源码但不生成 target，供研读对照。
