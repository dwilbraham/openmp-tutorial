#include <omp.h>
#include <stdio.h>

static long num_steps = 1000000;
#define NUM_THREADS 2
int main()
{
  double pi, step;
  step = 1.0/(double) num_steps;
  omp_set_num_threads(NUM_THREADS);
  #pragma omp parallel
  {
    int i, id, nthrds ;
    double sum, x;
    id = omp_get_thread_num();
    nthrds = omp_get_num_threads();
    for (i=id, sum=0.0; i<num_steps; i=i+nthrds)
    {
      x = (i+0.5)*step;
      sum += 4.0/(1.0+x*x);
    }
    #pragma omp critical
    pi += sum * step;
  }
  printf("pi = %e\n",pi);
  return 0;
}
