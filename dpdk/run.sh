#!/usr/bin/env sh
set -e
set -x

NR_HUGEPAGES=$(sudo -u root cat /sys/kernel/mm/hugepages/hugepages-2048kB/nr_hugepages)
if [ $NR_HUGEPAGES -eq 0 ]; then
  sudo -i echo 1024 > /sys/kernel/mm/hugepages/hugepages-2048kB/nr_hugepages
fi
# we have not mounted the hugepages so we need to pass --in-memory
make && sudo -u root ./main --in-memory --trace=.* "$@"
