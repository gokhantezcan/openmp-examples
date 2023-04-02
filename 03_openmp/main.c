#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


int main()
{
    int i; int n = 9;

    #pragma omp parallel num_threads(4) shared(n) private(i)
    {
          #pragma omp for
          for(int i = 0; i < n; i++)
            printf("%d. İterasyon iplik (%d) tarafından yürütülmüştür.\n", omp_get_thread_num(), i);
    }
    return 0;
}
