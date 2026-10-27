# asynclog-cloud

## 日常使用

```bash
cmake --preset debug
cmake --build build -j
./build/asynclog-cloud
gdb ./build/asynclog_cloud
```

## 在 VS Code 里打开

**直接打开本项目文件夹**：`/home/xuhao/code/asynclog-cloud`

CMake Tools 会自动 configure，clangd 自动读取 `build/compile_commands.json`。

⚠️ 不要打开父目录再点进来——clangd 会找不到编译数据库，满屏红线。

## 加新文件

在 `CMakeLists.txt` 的 `set(SOURCES ...)` 里加上新 .cpp，然后重新构建。
