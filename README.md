# cpp-playground

个人 C++ 学习积累库（monorepo）：读书记录、设计模式、网络与多媒体实验、三方库试用，统一用 [xmake](https://xmake.io) 构建。

![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)
![Language: C++](https://img.shields.io/badge/language-C%2B%2B-blueviolet.svg)
![Build: xmake](https://img.shields.io/badge/build-xmake-2f93e0)

## 目录结构

```
cpp-playground/
├── xmake.lua
├── LICENSE            # MIT（仅覆盖本仓库原创代码）
├── books/             # 参考 PDF 电子书（集中管理，Git LFS）
├── notes/             # Effective C++ 条款笔记 + 演示代码（默认编译）
│   └── effective/
├── patterns/          # GoF 设计模式实现：创建型/结构型/行为型（默认编译）
│   └── creational/ structural/ behavioral/
├── net/               # mongoose 7.1 网络示例（内置源，自含，默认编译）
│   └── network/ thirdparty/mongoose/
├── av/                # ffmpeg 转码/滤镜/编码实验（--av=y 启用）
│   ├── engine/
│   └── ref/           # Windows 参考工程 / ffmpeg 版本报告
└── lib-sandbox/       # 第三方开源库试用（--sandbox=y 启用）
    └── opencv/ poco/ mupdf/ amqpcpp/ …
```

## 构建

默认只编译**无外部依赖**的部分（notes / patterns / net），日常零负担：

```bash
xmake                 # 编译默认组
xmake run effective   # 运行读书示例（编辑 effective/main.cpp 的 include 切条款）
xmake run pat_state   # 运行某个设计模式
xmake run net-http-demo
```

重依赖模块按需启用：

```bash
# ffmpeg 实验（联网经 xmake-repo 拉取 ffmpeg，较慢）
xmake f --av=y
xmake -g av            # 编译 engine 全部用例；xmake run av_transcode 单跑

# 三方库试用（先在本机装好对应库；库根路径: SB_ROOT_<LIB> / DEPS / /usr/local）
xmake f --sandbox=y
xmake -g sandbox
```

切换 debug/release：`xmake f -m debug` / `xmake f -m release`。

## 约定

- **一个含 `main()` 的源码文件/目录 = 一个可执行 target**；命名 `pat_*` / `av_*` / `sb_*` 区分模块。
- 头文件/笔记类内容偏重于学习备注，个别条款/用例不保证能独立编译（详见各模块 README）。
- 参考 PDF 等大文件用 **Git LFS** 管理（见 `.gitattributes`），需先 `git lfs install`。
- `books/` 电子书为第三方版权作品，仅供个人学习，不属于 MIT 许可范围（见 `books/README.md`）。
