#!/bin/sh
set -e
set -x

echo "running entryp script for node2..."
# ip addr set 171.16.50.1 dev eth0

ip link add name serial0 type veth
ip link set dev serial0 up
ip addr add 171.16.250.2/24 dev serial0

ip link add name serial1 type veth
ip link set dev serial1 up
ip addr add 171.16.252.1/24 dev serial1

#keep the container alive
tail -f /dev/null
