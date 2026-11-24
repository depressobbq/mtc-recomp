cmake_minimum_required(VERSION 3.20)
project(MTCRecompiled LANGUAGES C CXX)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set(MTC_RECOMP_DIR  "${CMAKE_CURRENT_SOURCE_DIR}/../recomp" CACHE PATH "Folder with RecompiledFuncs")
set(MTC_RUNTIME_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../lib/N64ModernRuntime" CACHE PATH "N64ModernRuntime path")
set(MTC_RT64_DIR    "${CMAKE_CURRENT_SOURCE_DIR}/../lib/rt64" CACHE PATH "RT64 path" FORCE)

if (NOT EXISTS "${MTC_RECOMP_DIR}/RecompiledFuncs/funcs.h")
    message(FATAL_ERROR "No recompiled code in ${MTC_RECOMP_DIR}/RecompiledFuncs. Run N64Recomp first.")
endif()

if (CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64|amd64|AMD64")
    set(MTC_SIMD_FLAGS -msse4.1)
endif()

# ---- Runtime -----------------------------------------------------------------
add_subdirectory(${MTC_RUNTIME_DIR} ${CMAKE_BINARY_DIR}/N64ModernRuntime)

# ---- RT64 Renderer -----------------------------------------------------------
set(RT64_STATIC TRUE CACHE BOOL "" FORCE)
set(RT64_SDL_WINDOW_VULKAN TRUE CACHE BOOL "" FORCE)
add_compile_definitions(HLSL_CPU RT64_SDL_WINDOW_VULKAN)
add_subdirectory(${MTC_RT64_DIR} ${CMAKE_BINARY_DIR}/rt64)
target_include_directories(rt64 PRIVATE ${CMAKE_BINARY_DIR}/rt64/src)

# ---- Recompiled game code ----------------------------------------------------
file(GLOB MTC_FUNC_SOURCES "${MTC_RECOMP_DIR}/RecompiledFuncs/*.c" "${MTC_RECOMP_DIR}/RecompiledFuncs/*.cpp")
add_library(MTCRecompiledFuncs STATIC
    ${MTC_FUNC_SOURCES}
)
target_include_directories(MTCRecompiledFuncs PRIVATE
    "${MTC_RECOMP_DIR}/RecompiledFuncs"
    "${MTC_RUNTIME_DIR}/N64Recomp/include"
    "${MTC_RUNTIME_DIR}/librecomp/include"
    "${MTC_RUNTIME_DIR}/ultramodern/include"
)
target_compile_options(MTCRecompiledFuncs PRIVATE -fno-strict-aliasing -Wno-everything)

# ---- SDL2 & Threads ----------------------------------------------------------
find_package(Threads REQUIRED)
find_package(SDL2 REQUIRED)

# ---- Executable --------------------------------------------------------------
add_executable(MTCRecompiled
    src/main.cpp
    src/register_overlays.cpp
    src/sdl_backend.cpp
    src/sdl_audio.cpp
    src/rt64_render_context.cpp
    ../recomp/rsp/aspMain.cpp
    src/hle_audio.cpp
    src/hle_audio/alist.c
    src/hle_audio/alist_audio.c
    src/hle_audio/audio.c
    src/hle_audio/memory.c
    src/mtc_hle_stubs.cpp
)

target_include_directories(MTCRecompiled PRIVATE
    src
    src/hle_audio
    "${MTC_RECOMP_DIR}"
    "${MTC_RUNTIME_DIR}/librecomp/include/librecomp"
    "${MTC_RUNTIME_DIR}/N64Recomp/include"
    "${MTC_RUNTIME_DIR}/ultramodern/include"
    "${MTC_RT64_DIR}/src"
    "${MTC_RT64_DIR}/src/contrib"
    "${MTC_RT64_DIR}/src/contrib/hlslpp/include"
    "${MTC_RT64_DIR}/src/contrib/dxc/inc"
    "${MTC_RT64_DIR}/src/rhi"
    "${MTC_RT64_DIR}/src/render"
    ${CMAKE_BINARY_DIR}/rt64/src
    ${SDL2_INCLUDE_DIRS}
)

target_compile_options(MTCRecompiled PRIVATE ${MTC_SIMD_FLAGS} -fno-strict-aliasing)
target_link_libraries(MTCRecompiled PRIVATE
    MTCRecompiledFuncs
    librecomp
    ultramodern
    rt64
    SDL2::SDL2
    Threads::Threads
    atomic
    ${CMAKE_DL_LIBS}
)
