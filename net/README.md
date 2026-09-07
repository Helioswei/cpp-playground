# net/ — 网络示例（mongoose）

源仓库：`testmongoose（原仓库已删除）`

- `network/`  上传客户端 / HTTP 服务示例源码
- `thirdparty/mongoose/`  内置 mongoose 7.1（自含，无外部依赖）

构建：
```bash
xmake build net-http-demo
xmake run net-http-demo            # 起服务
xmake run net-http-demo <文件路径>  # 作为客户端上传到 http://127.0.0.1:8000/api/upload
```
