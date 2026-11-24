#!/usr/bin/env bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

echo "==> Ensuring dependencies are set up..."
"$SCRIPT_DIR/setup_dependencies.sh"

echo "==> Configuring and building MTCRecompiled..."
cmake -B "$SCRIPT_DIR/MTCRecomp/build" -S "$SCRIPT_DIR/MTCRecomp" -G Ninja -DCMAKE_BUILD_TYPE=Release
ninja -C "$SCRIPT_DIR/MTCRecomp/build"

echo "==> Build complete! Run with: ./run.sh"
