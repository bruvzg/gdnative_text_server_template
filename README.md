# GDNative based TextServer plugin for Godot

This is a template for GDNative based plugin that adds TextServer implementation to Godot.

Provided code is a stub and do not contain actual implementation.

### Compiling Library

Symlink/copy upstream GDNative headers (`godot/modlues/gdnative/include`) as the `godot_headers` subfolder.

For macOS (Intel):

```bash
clang++ -g -fPIC -std=c++14 -arch x86_64 -isysroot `xcrun --sdk macosx --show-sdk-path` -c src/gdnative_text_server.cpp -I./godot_headers -o ./gdnative_text_server.macos.o
clang++ -arch x86_64 -isysroot `xcrun --sdk macosx --show-sdk-path` -g -shared -Wl,-undefined,dynamic_lookup ./gdnative_text_server.macos.o -o ./bin/gdnative_text_server.dylib
```

For macOS (Universal):

```bash
clang++ -g -fPIC -std=c++14 -arch x86_64 -arch arm64 -isysroot `xcrun --sdk macosx --show-sdk-path` -c src/gdnative_text_server.cpp -I./godot_headers -o ./gdnative_text_server.macos.o
clang++ -arch x86_64 -arch arm64 -isysroot `xcrun --sdk macosx --show-sdk-path` -g -shared -Wl,-undefined,dynamic_lookup ./gdnative_text_server.macos.o -o ./bin/gdnative_text_server.dylib
```

For Windows (MinGW cross-build, x86-64):

```bash
x86_64-w64-mingw32-c++ -g -fPIC -std=c++14 -c src/gdnative_text_server.cpp -I./godot_headers -o ./gdnative_text_server.win.o
x86_64-w64-mingw32-c++ -g -shared -static -static-libgcc -static-libstdc++ ./gdnative_text_server.win.o -o ./bin/gdnative_text_server.dll
```

For Linux:

```bash
clang++ -g -fPIC -std=c++14 -c src/gdnative_text_server.cpp -I./godot_headers -o ./gdnative_text_server.linux.o
clang++ -g -shared ./gdnative_text_server.linux.o -o ./bin/gdnative_text_server.so
```
