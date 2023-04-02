#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void funcA(int iplik_numarasi){
    printf("FuncA'da: bu bölüm iplik (%d) tarafından yürütülüyor.\n", iplik_numarasi);
}

void funcB(int iplik_numarasi){
    printf("FuncB'da: bu bölüm iplik (%d) tarafından yürütülüyor.\n", iplik_numarasi);
}

int main()
{
    int a[9] = {0}; int i; int n = 9;
    #pragma omp parallel shared(a) private(i) num_threads(3)
    {
        #pragma omp for
            for(i = 0; i < n; i++)
            {
                    a[i] = i;
                    printf("Iplik (%d) tarafından yürütülür ve a[%d] = %d \n", omp_get_thread_num(), i, a[i]);
            }

            printf("For songusu dısındadır: Iplik (%d) tarafındaın yürütülür ve a[8] = %d\n", omp_get_thread_num(), a[8]);
    }
    printf("For songusu dısındadır: Iplik (%d) tarafındaın yürütülür ve a[8] = %d\n", omp_get_thread_num(), a[8]);

    return 0;
}
