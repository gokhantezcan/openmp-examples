#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


int main()
{
    int a[5], b[5], i, n=5;

    #pragma omp parallel shared(n,a,b) private(i) num_threads(2)
    {
        #pragma omp for
            for(i = 0; i<n; i++)
                a[i] = i;
        #pragma omp for
            for(i = 0; i < n; i++)
            {
                b[i] = 2 * a[i];
                printf("b[%d] = %d .. burada iplik (%d)\n", i, b[i], omp_get_thread_num());
            }
    }

    return 0;
}
