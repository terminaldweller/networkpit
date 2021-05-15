#!/usr/bin/env sh

make && sudo ./main --in-memory --trace=.* "$@"
