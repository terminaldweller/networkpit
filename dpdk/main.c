
#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include <rte_eal.h>
#include <rte_debug.h>

int main(int argc, char **argv) {
  int ret = rte_eal_init(argc,argv);
  if (ret < 0) {
    rte_panic("Cannot init EAL\n");
  }
  rte_eal_cleanup();
  return 0;
}
