# Race version

This folder contains only the race implementation. Its synchronization code is directly written in `camera.h`; no `VERSION_*` define is needed.

macOS (Apple Clang + Homebrew libomp):

```bash
clang++ -std=c++17 -O3 -Xpreprocessor -fopenmp \
  -I"$(brew --prefix libomp)/include" \
  -L"$(brew --prefix libomp)/lib" \
  -Wl,-rpath,"$(brew --prefix libomp)/lib" -lomp \
  main.cc -o raytracer
OMP_NUM_THREADS=4 ./raytracer > image.ppm
```

Windows/Linux with g++ and OpenMP:

```bash
g++ -std=c++17 -O3 -fopenmp main.cc -o raytracer
OMP_NUM_THREADS=4 ./raytracer > image.ppm
```
