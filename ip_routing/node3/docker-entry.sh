#!/bin/sh
set -e
set -x

echo "running entryp script for node3..."
# ip addr set 171.16.100.1 dev eth0

ip link add name serial0 type veth
ip link set dev serial0 up
ip addr add 171.16.252.2/24 dev serial0

ip link add name serial1 type veth
ip link set dev serial1 up
ip addr add 171.16.251.2/24 dev serial1

#keep the container alive
tail -f /dev/null
