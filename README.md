Exercises from the OpenMP tutorial:
- http://tinyurl.com/OpenMP-Tutorial
- http://openmp.org/mp-documents/Intro_To_OpenMP_Mattson.pdf

Run the following commands to time an exercise:
```
make pi
gcc -fopenmp -Wall exercise_[NUM].c
time ./pi; time ./a.out
```
