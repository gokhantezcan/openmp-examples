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
    int ip1, ip2;

    #pragma omp parallel num_threads(6)
    {
        #pragma omp single
        {
            printf("BU kısım tekbir iplik tarafından yürütülüyor.. %d.\n", omp_get_team_num());
        }

        #pragma omp sections
        {
            #pragma omp section
            {
                ip1 = omp_get_thread_num();
                funcA(ip1);
            }

            #pragma omp section
            {
                ip2 = omp_get_thread_num();
                funcB(ip2);
            }
        }
    }

    return 0;
}
