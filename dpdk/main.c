
#include <errno.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include <rte_debug.h>
#include <rte_eal.h>
#include <rte_rcu_qsbr.h>
#include <rte_ring.h>
#include <rte_trace.h>
#include <rte_trace_point_register.h>
#include <rte_trace_point.h>
#include <rte_vect.h>

RTE_TRACE_POINT(app_trace_string, RTE_TRACE_POINT_ARGS(const char *str),
                rte_trace_point_emit_string(str);)

RTE_TRACE_POINT_REGISTER(app_trace_string, app.trace.string)

void get_simd_bitwidth(void) {
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
}

/* void use_rcu(void) { size_t qs_size = rte_rcu_qsbr_get_memsize(2); } */

void create_ring_buffers(const char* ring_buffer_name, unsigned int ring_buffer_size) {
  struct rte_ring *ring = rte_ring_create(ring_buffer_name, ring_buffer_size, SOCKET_ID_ANY,
                                          RING_F_SP_ENQ | RING_F_SC_DEQ);
  if (NULL == ring) {
    rte_panic("could not create ring.\n");
  } else {
    printf("ring created successfully.\n");
  }

}

static int dummy_produce() {return 0;}
static int dummy_consume() {return 0;}

int main(int argc, char **argv) {
  int ret = rte_eal_init(argc, argv);
  if (ret < 0) {
    rte_panic("Cannot init EAL\n");
  }

  rte_trace_mode_set(RTE_TRACE_MODE_OVERWRITE);

  create_ring_buffers("ring_one",1024);

  get_simd_bitwidth();

  rte_eal_cleanup();
  return 0;
}
