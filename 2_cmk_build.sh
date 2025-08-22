#!/bin/bash

set -e  # Exit on error

# Default values
BUILD_DIR="build"

mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"

# Run Conan to download dependencies and generate files
echo "Running Conan to install dependencies..."
conan install .. --output-folder . --build=missing -s build_type=Release

# Configure CMake to use the Conan-generated toolchain and build type
echo "Configuring CMake..."
cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release

# cmake ..

# cmake --build .

# Build the project
echo "Building the project..."
cmake --build . --config Release

echo "Build complete! 🎉"