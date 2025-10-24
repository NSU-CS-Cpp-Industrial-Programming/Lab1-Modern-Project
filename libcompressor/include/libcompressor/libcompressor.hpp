#pragma once
#include <cstddef>

enum libcompressor_CompressionAlgorithm { libcompressor_Zlib, libcompressor_Bzip };

struct libcompressor_Buffer {
  char* data; 
  int size;   
};

/** 
 * Сжать входной буфер выбранным алгоритмом.
 */
libcompressor_Buffer libcompressor_compress(libcompressor_CompressionAlgorithm algo, libcompressor_Buffer input);
