# Sequential version

Original single-threaded renderer. Compile without OpenMP:

```bash
clang++ -std=c++17 -O3 main.cc -o raytracer
./raytracer > image.ppm
```
