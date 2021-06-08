#!/bin/sh
set -e
set -x

echo "running entryp script for node1..."
# ip addr add 171.16.1.1/24 dev eth0

ip link add name ethernet1 type veth
ip link set dev ethernet1 up
ip addr add 192.168.1.1/24 dev ethernet1

ip link add name serial0 type veth
ip link set dev serial0 up
ip addr add 171.16.250.1/24 dev serial0

ip link add name serial1 type veth
ip link set dev serial1 up
ip addr add 171.16.251.1/24 dev serial1

#keep the container alive
tail -f /dev/null
