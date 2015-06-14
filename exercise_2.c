#include <omp.h>
#include <stdio.h>

static long num_steps = 10000000;
#define NUM_THREADS 2
int main()
{
  int i, num_threads;
  double pi, step;
  double sum[NUM_THREADS];
  step = 1.0/(double) num_steps;
  omp_set_num_threads(NUM_THREADS);
  #pragma omp parallel
  {
    int i, id, nthrds ;
    double x = 0.0;
    id = omp_get_thread_num();
    nthrds = omp_get_num_threads();
    if (id==0) num_threads = nthrds;
    for (i=id, sum[id]=0.0; i<num_steps; i=i+nthrds)
    {
      x = (i+0.5)*step;
      sum[id] += 4.0/(1.0+x*x);
    }
  }
  for(i=0, pi=0.0; i<num_threads;i++)
  {
    pi += sum[i] * step;
  }
  printf("pi = %e\n",pi);
  return 0;
}
