rm build
rm -r build
mkdir -p $(PWD)/build
cd build
cmake ..
make
cd ..
