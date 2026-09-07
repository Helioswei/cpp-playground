# av/ — ffmpeg 转码 / 滤镜 / 编码实验


- `engine/`  核心实验：`encoder/` `filter/` `hw/` `transcode/`，每个 `.cpp` 是一个独立 main 用例
- `ref/`     参考资料
  - `netexample/`  面向 Windows 的 VS 参考工程（.sln/.vcxproj，需自行配 ffmpeg）
  - `ffmpegversion/` ffmpeg 各版本特性/命令记录

构建（需联网拉取 ffmpeg，较慢）：
```bash
xmake f --av=y
xmake -g av                 # 编译全部 engine 用例
xmake run av_transcode      # 单独运行某个
```
> 用例面向个人学习调试，个别需要按现场准备输入文件/参数；`engine/avbase` 为无 main 辅助源码，未纳入构建。
