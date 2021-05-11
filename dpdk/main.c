
#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include <rte_debug.h>
#include <rte_eal.h>
#include <rte_vect.h>

int main(int argc, char **argv) {
  uint16_t max_simd_bitwidth = rte_vect_get_max_simd_bitwidth();
  printf("max_simd_bitwidth: %d\n", max_simd_bitwidth);
  switch (max_simd_bitwidth) {
  case RTE_VECT_SIMD_DISABLED:
    printf("simd is disabled\n");
    break;
  case RTE_VECT_SIMD_128:
    printf("simd is 128\n");
    break;
  case RTE_VECT_SIMD_256:
    printf("simd is 256\n");
    break;
  case RTE_VECT_SIMD_512:
    printf("simd is 512\n");
    break;
  default:
    printf("dunno what's going on\n");
  }
  int ret = rte_eal_init(argc, argv);
  if (ret < 0) {
    rte_panic("Cannot init EAL\n");
  }
  rte_eal_cleanup();
  return 0;
}
