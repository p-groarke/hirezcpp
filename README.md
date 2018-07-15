# scene-graph-prototype

- Install [conan](https://www.conan.io/).
- Install [cmake 3.10+](https://cmake.org/) (required for VS2017 fix).
- Update your compiler to latest.

```
cd scene_graph_prototype
mkdir build && cd build
conan remote add bincrafters "https://api.bintray.com/conan/bincrafters/public-conan"
..\conan.bat
```

On Windows:
```
cmake .. -A x64 && cmake --build .
```

On other platforms:
```
cmake .. && cmake --build .
```

Test and benchmark executables are in bin/.


Example:
```
bin\scene_graph_tests.exe
bin\scene_graph_benchmarks.exe > NUL
```
