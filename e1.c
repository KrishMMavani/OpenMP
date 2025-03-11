#include <stdio.h>
#include <omp.h>

int main(int argc, char* argv[])
{
int avg = 0;
int tid, sum=5 ;
int arr[100];
#pragma omp parallel firstprivate(sum) 
{
  tid = omp_get_thread_num();
//  sum = sum + tid;
  for(int i = 0; i < 99; i++){
arr[i] = sum + tid;
printf("Value at thread %d = %d \n", tid, arr[i]) ;
}



for(int i = 0; i < 99; i++)
{
avg = avg + arr[i];
}
avg = avg/100;
}
printf("Avg = %d\n", avg);

printf("Value After parallel region, thread %d = %d \n", omp_get_thread_num(), avg) ;
}
