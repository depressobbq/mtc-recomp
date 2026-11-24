#!/usr/bin/env bash
set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"
BIN="$ROOT_DIR/MTCRecomp/build/MTCRecompiled"

if [ ! -f "$BIN" ]; then
    echo "Error: Binary not found at $BIN. Build the project first via ./build.sh."
    exit 1
fi

export APPIMAGE_EXTRACT_AND_RUN=1

BUILD_DIR="$ROOT_DIR/build"
mkdir -p "$BUILD_DIR"

if ! command -v linuxdeploy >/dev/null 2>&1; then
    LINUXDEPLOY="$BUILD_DIR/linuxdeploy-x86_64.AppImage"
    if [ ! -f "$LINUXDEPLOY" ]; then
        echo "==> Downloading linuxdeploy..."
        wget -q -O "$LINUXDEPLOY" https://github.com/linuxdeploy/linuxdeploy/releases/download/continuous/linuxdeploy-x86_64.AppImage
        chmod +x "$LINUXDEPLOY"
    fi
else
    LINUXDEPLOY="linuxdeploy"
fi

echo "==> Packaging AppImage with linuxdeploy..."
"$LINUXDEPLOY" --appdir "$BUILD_DIR/AppDir" \
    -e "$BIN" \
    -d "$SCRIPT_DIR/mtc.desktop" \
    -i "$SCRIPT_DIR/mtc.png" \
    --output appimage

OUTPUT_NAME="MagicalTetrisChallenge-Linux-x86_64.AppImage"
find . -maxdepth 1 -name "Magical_Tetris_Challenge*.AppImage" -exec mv {} "$OUTPUT_NAME" \;
echo "==> AppImage ready: $OUTPUT_NAME"
