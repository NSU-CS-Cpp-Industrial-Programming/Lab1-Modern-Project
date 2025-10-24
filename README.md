# Lab1-Modern-Project

# Build Commands

## 1. Debug: dependencies + configure + build
```bash
conan profile detect --force
conan install . --build=missing -s build_type=Debug
cmake -B build/Debug \
  -DCMAKE_BUILD_TYPE=Debug \
  -DCMAKE_TOOLCHAIN_FILE=build/Debug/generators/conan_toolchain.cmake \
  -DCMAKE_POLICY_DEFAULT_CMP0091=NEW
cmake --build build/Debug -j
```

## 2. Tests + report
```bash
ctest --test-dir build/Debug --output-on-failure
ls build/Debug/test_results.xml
```

## 3. Documentation (Doxygen)
```bash
cmake --build build/Debug --target docs
ls build/Debug/docs/html
```

## 4. Formatting and static analysis
```bash
cmake --build build/Debug --target format
cmake --build build/Debug --target tidy
```

## 5. Install artifacts
```bash
sudo cmake --install build/Debug
which compressor
/usr/local/bin/compressor zlib "test_string"
/usr/local/bin/compressor bzip "test_string"
ls -l /usr/local/lib/liblibcompressor.a
ls -l /usr/local/include/libcompressor/libcompressor.hpp
```
