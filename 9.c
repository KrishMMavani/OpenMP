#include <stdio.h>
#include <omp.h>
int main()
{
    unsigned char a = 5, b = 9, c=4, d=7, e=14, f=15;
    omp_set_num_threads(5);
    #pragma omp parallel sections
        {
          #pragma omp section 
	  {
              printf("Thread= %d, a^b = %d, \n",omp_get_thread_num(), a^b);
          }
          #pragma omp section 
	  {
              printf("Thread= %d, c^d = %d, \n",omp_get_thread_num(), c^d);
          }
          #pragma omp section 
	  {
              printf("Thread= %d, e^f = %d, \n",omp_get_thread_num(), e^f);
          }
        }
    return 0;
}
