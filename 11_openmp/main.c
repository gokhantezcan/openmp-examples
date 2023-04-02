#include <stdio.h>
#include <unistd.h>
#include <omp.h>

int main(void)
{
    int i, n = 6;

    #pragma omp parallel num_threads(3) shared(n) private(i)
        {

            #pragma omp for nowait
                for(i = 0; i < n ; i++){
                    printf("%d. iterasyon iplik (%d) tarafından yürütülür.\n", i, omp_get_thread_num());
                }

                printf("nowaitten sonra. burada iplik (%d) geçiyor.\n", omp_get_thread_num());
        }

    return 0;
}
