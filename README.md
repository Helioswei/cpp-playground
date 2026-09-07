# cpp-playground

个人 C++ 学习积累库（monorepo）。原五个独立开源仓库合并而来，统一用 [xmake](https://xmake.io) 构建。

![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)
![Language: C++](https://img.shields.io/badge/language-C%2B%2B-blueviolet.svg)
![Build: xmake](https://img.shields.io/badge/build-xmake-2f93e0)
![Monorepo: 5 repos merged](https://img.shields.io/badge/monorepo-5_repos_merged-lightgrey)

## 目录结构与源仓库对照

| 模块 | 源仓库 | 内容 |
|---|---|---|
| `notes/` | Helioswei/**booknotes** | Effective C++ 等读书笔记 + 条款实验代码 |
| `patterns/` | Helioswei/**designPatterns** | GoF 设计模式 C++ 实现（创建型/结构型/行为型） |
| `net/` | Helioswei/**testmongoose** | mongoose 7.1 上传/服务示例（内置源，自含） |
| `av/` | Helioswei/**testffmpeg** | ffmpeg 转码 / 滤镜 / 编码实验 |
| `lib-sandbox/` | Helioswei/**testcode** | 第三方开源库试用（opencv / poco / mupdf …） |
| `books/` | — | 参考 PDF 电子书集中存放（版权归原作者，仅供学习） |

```
cpp-playground/
├── xmake.lua
├── README.md
├── LICENSE            # MIT（仅覆盖本仓库原创代码）
├── books/             # 参考 PDF 电子书（集中管理，Git LFS）
├── notes/            ← booknotes（默认编译）
│   └── effective/    # 条款头文件 + 演示 main（改 include 行切条款）
├── patterns/         ← designPatterns（默认编译）
│   └── creational/ structural/ behavioral/
├── net/              ← testmongoose（默认编译）
│   └── thirdparty/mongoose
├── av/               ← testffmpeg（--av=y 启用）
│   ├── engine/
│   └── ref/          # Windows 参考工程 / ffmpeg 版本报告
└── lib-sandbox/      ← testcode（--sandbox=y 启用）
    └── <各库试用>/
```

## 构建

默认只编译**无外部依赖**的部分（notes / patterns / net），日常零负担：

```bash
xmake                 # 编译默认组
xmake run effective   # 运行读书示例（或 notes 各 target）
xmake run pat_visitor # 运行某个设计模式
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

- **一个含 `main()` 的源码文件/目录 = 一个可执行 target**；命名 `pat_*` / `av_*` / `sb_*` 区分来源。
- 合并时已**剔除**各源仓库里的编译产物与可执行文件（`test`/`pist`/`opencvtest`、`.dll/.exe`、`out.jpg` 等）。
- 参考 PDF 等大文件用 **Git LFS** 管理（见 `.gitattributes`），需先 `git lfs install`。

## 迁移说明

本次为一次性的仓库归并，五个源仓库各自的 git 历史未并入（新仓为全新提交）；旧仓库可在核对无误后归档/删除。
