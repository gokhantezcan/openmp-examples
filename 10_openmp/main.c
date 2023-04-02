#include <stdio.h>
#include <unistd.h>
#include <omp.h>

int main(void)
{
    int a[10], TID, indeks, vlen = 10, i , n=2;

    for(i = 0; i< vlen; i++) a[i] = -i + 1;

    indeks = 4;

    #pragma omp parallel default(none) firstprivate(indeks) private(i, TID) shared(n,a) num_threads(3)
    {
        TID = omp_get_thread_num();
        indeks +=  n*TID;
        for(i = indeks; i < indeks + n; i++)
            a[i] = TID + 1;
    }

    printf("Paralel bölgeden sonra: \n");
    for(i = 0; i < vlen; i++)
        printf("a[%d] = %d\n", i, a[i]);
    return 0;
}
