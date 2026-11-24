#!/usr/bin/env bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
LIB_DIR="$SCRIPT_DIR/lib"
PATCH_DIR="$SCRIPT_DIR/patches"

mkdir -p "$LIB_DIR"

# 1. N64ModernRuntime
RUNTIME_DIR="$LIB_DIR/N64ModernRuntime"
if [ ! -f "$RUNTIME_DIR/CMakeLists.txt" ]; then
    echo "==> Cloning N64ModernRuntime..."
    git clone https://github.com/N64Recomp/N64ModernRuntime.git "$RUNTIME_DIR"
    git -C "$RUNTIME_DIR" checkout cdf5abbd5026fef5c364c676e4667c45e42b6863
    git -C "$RUNTIME_DIR" submodule update --init --recursive
    if [ -f "$PATCH_DIR/runtime-threadqueue.patch" ]; then
        echo "==> Applying runtime-threadqueue.patch..."
        git -C "$RUNTIME_DIR" apply --ignore-whitespace --whitespace=nowarn "$PATCH_DIR/runtime-threadqueue.patch"
    fi
else
    echo "==> N64ModernRuntime already present at $RUNTIME_DIR"
fi

# 2. RT64
RT64_DIR="$LIB_DIR/rt64"
if [ ! -f "$RT64_DIR/CMakeLists.txt" ]; then
    echo "==> Cloning RT64..."
    git clone https://github.com/rt64/rt64.git "$RT64_DIR"
    git -C "$RT64_DIR" checkout a80eb4174955014dd7855f6ae95b6554e74a93bb
    git -C "$RT64_DIR" submodule update --init --recursive
    if [ -f "$PATCH_DIR/rt64-s2dex.patch" ]; then
        echo "==> Applying rt64-s2dex.patch..."
        git -C "$RT64_DIR" apply --ignore-whitespace --whitespace=nowarn "$PATCH_DIR/rt64-s2dex.patch"
    fi
else
    echo "==> RT64 already present at $RT64_DIR"
fi

echo "==> All dependencies are ready!"
