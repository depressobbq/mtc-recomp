#!/usr/bin/env bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BIN="$SCRIPT_DIR/MTCRecomp/build/MTCRecompiled"

if [ ! -f "$BIN" ]; then
    echo "Error: Binary not found at $BIN. Build it first."
    exit 1
fi

cd "$SCRIPT_DIR/MTCRecomp/build"
exec "$BIN" "$@"
