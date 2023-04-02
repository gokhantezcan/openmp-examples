#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


int main()
{
    #pragma omp parallel for
    for(int i = 0; i< 10; i++){
        printf("%i from thread number %i \n", i, omp_get_thread_num());
    }
    return 0;
}
