#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
    int a = 0; int i; int n = 9;

    #pragma omp parallel for num_threads(3) private(i,a)
    for(i = 0; i < n; i++)
    {
            a = i + 1;
            printf("iplik %d için a = %d ve i = %d.\n", omp_get_thread_num(), a, i);
    }
    printf("****\n%d", a);

    return 0;
}
