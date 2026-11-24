# Magical Tetris Challenge: Recompiled

A native PC port of **Magical Tetris Challenge** (Nintendo 64) created via static binary recompilation using the [N64Recomp](https://github.com/N64Recomp/N64Recomp) toolchain.

## Downloads

Grab the latest build for Windows or Linux from the [Releases](https://github.com/depressobbq/mtc-decomp/releases) page.

- **Windows (x64):** Download the zip archive, extract it anywhere, place your ROM in the folder, and run `MTCRecompiled.exe`.
- **Linux:** Download the `.AppImage`, make it executable (`chmod +x`), and run it with your ROM in the directory.

## Features

- **Native Execution:** High-performance native PC binary without traditional CPU emulation overhead.
- **Enhanced Graphics (RT64):** Direct3D 12 and Vulkan rendering backends with custom fixes for Nintendo's S2DEX 2D sprite microcode (pixel-perfect background slicing and color-indexed rendering).
- **Accurate Audio (RSPRecomp):** Custom RSP audio microcode (`aspMain`) statically translated into native C++, reproducing the original soundtrack and sound effects with zero HLE inaccuracies.
- **SDL2 Audio & Controller Support:** Dynamic audio rate matching, full gamepad support with standard controller mappings, and customizable keyboard controls.

---

## Building from Source

### Prerequisites

**Ubuntu / Debian:**
```bash
sudo apt update
sudo apt install build-essential cmake ninja-build libsdl2-dev libvulkan-dev vulkan-tools libgtk-3-dev
```

**Arch Linux:**
```bash
sudo pacman -S base-devel cmake ninja sdl2 vulkan-headers vulkan-icd-loader gtk3
```

**Windows:**
- Visual Studio 2022 (with the "Desktop development with C++" workload)
- CMake 3.20+ and Git

### Build Instructions

**Linux:**
```bash
git clone https://github.com/depressobbq/mtc-decomp.git
cd mtc-decomp
./build.sh
```

**Windows:**
```bash
git clone https://github.com/depressobbq/mtc-decomp.git
cd mtc-decomp
./setup_dependencies.sh
cmake -B MTCRecomp/build -S MTCRecomp
cmake --build MTCRecomp/build --config Release
```

---

## Running

Place your legally acquired **Magical Tetris Challenge (USA)** ROM (`.z64`) in the same directory as the executable, or inside a `roms/` folder:
- Accepted names: `baserom.us.z64`, `Magical Tetris Challenge (USA).z64`, `baserom.z64`, or passed directly as a command-line argument.

---

## Controls

### Keyboard (Player 1)

| Action | Key |
| :--- | :--- |
| **D-Pad Up / Down / Left / Right** | Arrow Keys |
| **Analog Stick** | W / S / A / D |
| **A Button (Rotate Right)** | X / Space |
| **B Button (Rotate Left)** | C |
| **Z Trigger (Hard Drop)** | Z |
| **Start Button** | Enter |
| **L Trigger / R Trigger** | Q / E |
| **C-Buttons** | I / K / J / L |
| **Fullscreen Toggle** | Alt + Enter |

### Gamepad

Plug and play support for standard controllers (Xbox, PlayStation, Switch Pro Controller) automatically mapped to the original N64 controller layout.

---

## Technical Details

- **S2DEX 2D Graphics Engine:** Fixed RT64 TMEM byte-stride calculations for `bgCopy` and TMEM height calculations for Color-Indexed (CI) textures. Added support for RDP `G_RDPNOOP` (opcode `0xC0`).
- **Audio Interface (AI) Rate Matching:** Emulates hardware DMA buffer pacing with a 2-VI headroom buffer, eliminating buffer underrun crackles and resampler pitch hunting.
- **RSP Audio Translation:** Audio commands are executed directly through C++ functions decompiled from the game's RSP binary using `RSPRecomp`.

---

## Credits

- **N64Recomp & RT64 Teams:** For the recompilation tools and modern graphics runtime.
- **Capcom & Disney:** Original game developers and publishers.
