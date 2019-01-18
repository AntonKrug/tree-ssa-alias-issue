#!/bin/bash
set -euo pipefail

echo "Expecting path to a GCC binary set in the GCC_TOOLCHAIN_PATH env. variable"

$GCC_TOOLCHAIN_PATH --version


echo
echo "Using LOOP_ITERATIONS 5 should compile without issues:"
$GCC_TOOLCHAIN_PATH -O2 -ftree-loop-vectorize -fpredictive-commoning -D LOOP_ITERATIONS=5 tree-ssa-alias-issue.c


echo
echo "Using LOOP_ITERATIONS 7 might fail:"
$GCC_TOOLCHAIN_PATH -O2 -ftree-loop-vectorize -fpredictive-commoning -D LOOP_ITERATIONS=7 tree-ssa-alias-issue.c

