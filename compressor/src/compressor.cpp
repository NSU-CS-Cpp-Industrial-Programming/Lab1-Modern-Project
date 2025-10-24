#include <spdlog/spdlog.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include "libcompressor/libcompressor.hpp"

/**
 * CLI-обёртка над libcompressor.
 * Печатает сжатые данные в hex на STDOUT, ошибки логируются через spdlog в STDERR.
 */
int main(int argc, char** argv) {
  spdlog::set_level(spdlog::level::err);

  if (argc < 3) {
    spdlog::error("Usage: compressor <zlib|bzip> <string>");
    return EXIT_FAILURE;
  }

  libcompressor_CompressionAlgorithm algo;
  std::string a = argv[1];
  if (a == "zlib")
    algo = libcompressor_Zlib;
  else if (a == "bzip")
    algo = libcompressor_Bzip;
  else {
    spdlog::error("Unknown algorithm: {}", a);
    return EXIT_FAILURE;
  }

  libcompressor_Buffer in{argv[2], (int)std::strlen(argv[2])};
  auto out = libcompressor_compress(algo, in);
  if (!out.data || out.size <= 0) {
    spdlog::error("Compression failed");
    return EXIT_FAILURE;
  }

  for (int i = 0; i < out.size; ++i) std::printf("%.2hhx", static_cast<unsigned char>(out.data[i]));

  std::printf("\n");
  std::free(out.data);
  return EXIT_SUCCESS;
}
