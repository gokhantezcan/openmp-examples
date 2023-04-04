#include <stdio.h>
#include <unistd.h>
#include <omp.h>

void delay(){
    int c, d;
    for(c = 1; c <= 32767; c++){
        for(d = 1; d <= 32767; d++){
        }
    }
}

int main(void)
{
    int i, j, n = 9;

    #pragma omp parallel for default(none) schedule(runtime) private(i,j) shared(n) num_threads(4)
        for(i = 0; i < n; i++){
            printf("%d. İterasyon iplik (%d) tarafından yürütülür.\n", i, omp_get_thread_num());
            for(j = 0; j < i; j++){
                delay();
            }
        }

    return 0;
}
