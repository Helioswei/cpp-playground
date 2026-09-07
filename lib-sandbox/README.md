# lib-sandbox/ — 第三方开源库试用

源仓库：`Helioswei/testcode`

每个子目录试用一个开源库（含独立 `main` 的 `.cpp` 即一个 demo）。目录与依赖：

| 目录 | 试用库 | 备注 |
|---|---|---|
| regex | std::regex | 无外部依赖 |
| xml | Poco::XML | |
| htmlcxx | htmlcxx | |
| myhtml | myhtml | |
| mysqlpp | mysqlpp (+mysql) | |
| amqpcpp | AMQP-CPP (+libev) | |
| poco | Poco | rsa*.cpp 用 PocoCrypto |
| pistache | pistache (+jsoncpp) | |
| webdrive | webdriverxx (+libcurl) | |
| mupdf | mupdf | 静态链接 |
| ffmpeg | ffmpeg | |
| opencv | opencv | |

这些 demo 原本链接**自定义路径**下的库（见原 `com.sh`），跨机器一般需要先装好对应库。
库根路径解析：`SB_ROOT_<ROOT>` → `DEPS` → `/usr/local`。include 目录不存在时对应库会被自动跳过。

构建：
```bash
xmake f --sandbox=y
xmake -g sandbox                       # 编译所有依赖已就位的
xmake run sb_opencv_video              # 运行某个（target 名 = sb_<库>_<源文件基名>）
```
