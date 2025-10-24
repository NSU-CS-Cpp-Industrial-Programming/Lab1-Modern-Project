# Lab1-Modern-Project

# Команды для сборки
## 0. Инструменты
```bash
sudo apt update
sudo apt install -y build-essential cmake git pkg-config doxygen graphviz ninja-build clang clang-tidy clang-format
sudo apt install -y pipx && pipx ensurepath && pipx install conan
```

## 1. Debug: зависимости + конфигурация + сборка
```bash
conan profile detect --force
conan install . --build=missing -s build_type=Debug
cmake -B build/Debug \
  -DCMAKE_BUILD_TYPE=Debug \
  -DCMAKE_TOOLCHAIN_FILE=build/Debug/generators/conan_toolchain.cmake \
  -DCMAKE_POLICY_DEFAULT_CMP0091=NEW
cmake --build build/Debug -j
```

## 2. Тесты + отчёт
```bash
ctest --test-dir build/Debug --output-on-failure
ls build/Debug/test_results.xml
```

## 3. Документация (Doxygen)
```bash
cmake --build build/Debug --target docs
ls build/Debug/docs/html
```

## 4. Форматирование и статический анализ
```bash
cmake --build build/Debug --target format
cmake --build build/Debug --target tidy
```

## 5. Установка артефактов
```bash
sudo cmake --install build/Debug
which compressor
/usr/local/bin/compressor zlib "test_string"
/usr/local/bin/compressor bzip "test_string"
ls -l /usr/local/lib/liblibcompressor.a
ls -l /usr/local/include/libcompressor/libcompressor.hpp
```
