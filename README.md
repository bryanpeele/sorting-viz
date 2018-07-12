# sorting-viz

## build

mkdir build
cd build
cmake ..
make

## run

./sample

generates random.ppm

## convert to png

convert random.ppm -scale 500x random.png

## view from terminal

eog random.png
