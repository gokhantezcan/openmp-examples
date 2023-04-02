#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
    int a; int i; int n = 6;

    #pragma omp parallel for num_threads(3) private(i) lastprivate(a)
    for(i = 0; i < n; i++)
    {
            a = i + 1;
            printf("iplik %d için a = %d ve i = %d.\n", omp_get_thread_num(), a, i);
    }
    printf("prallel dongu sonrası (a) degeri: %d \n", a);

    return 0;
}
