#include <omp.h>
#include <stdio.h>

static long num_steps = 100000;
#define NUM_THREADS 2
int main()
{
  int i;
  double pi, step;
  double sum[2];
  step = 1.0/(double) num_steps;
  omp_set_num_threads(NUM_THREADS);
  #pragma omp parallel
  {
    int i, id, nthrds ;
    double x = 0.0;
    id = omp_get_thread_num();
    nthrds = omp_get_num_threads();
    for (i=id, sum[id]=0.0; i<num_steps; i=i+nthrds)
    {
      x = (i+0.5)*step;
      sum[id] += 4.0/(1.0+x*x);
    }
  }
  for(i=0, pi=0.0; i<NUM_THREADS;i++)
  {
    pi += sum[i] * step;
  }
  printf("pi = %e\n",pi);
}