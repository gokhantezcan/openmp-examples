#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


int main()
{
    #pragma omp parallel num_threads(4)
    {
        printf("parallel bölge iplik (%d) tarafından yürütülür.\n", omp_get_thread_num());
        if(omp_get_thread_num() == 2) {
            printf("iplik %d farklı iş yapmaktadır. \n", omp_get_thread_num());
        }
    }
    return 0;
}
