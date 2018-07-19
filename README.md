# hirezcpp

- Install [conan](https://www.conan.io/).
- Install [cmake 3.10+](https://cmake.org/) (required for VS2017 fix).
- Update MSVC to latest. Tested on 15.7.x.


```
cd hirezcpp
mkdir build && cd build
conan remote add bincrafters "https://api.bintray.com/conan/bincrafters/public-conan"
conan remote add bincrafters "https://api.bintray.com/conan/p-groarke/public-conan"
..\conan.bat
cmake .. -A x64 && cmake --build .
```

Test and lib are in bin/.
```
bin\hirezcpp_tests.exe
```
