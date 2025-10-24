#pragma once
#include <cstddef>

/** Доступные алгоритмы */
enum libcompressor_CompressionAlgorithm { libcompressor_Zlib, libcompressor_Bzip };

/** Простой буфер байт */
struct libcompressor_Buffer {
  char* data;  // malloc'ed указатель или nullptr при ошибке
  int size;    // размер буфера в байтах (0 при ошибке)
};

/** Сжать входной буфер выбранным алгоритмом.
 *  Выделяет выход через std::malloc(). В случае ошибки: {nullptr, 0}.
 *  Освобождать через std::free().
 */
libcompressor_Buffer libcompressor_compress(libcompressor_CompressionAlgorithm algo, libcompressor_Buffer input);
