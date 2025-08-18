#!/bin/bash

set -e  # Exit on error

# Default values
BUILD_DIR="build"

mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"
cmake ..

cmake --build .