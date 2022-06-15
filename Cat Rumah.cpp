#include <stdio.h>
#include <string.h>

char subsoal[100];
double F;
double m, k, b;

int main() {
    m = 300;
    k = 300;
    b = 300;

    scanf("%s", subsoal);

    printf("TAMBAH MERAH %.4lf\n", m);
    fflush(stdout);

    /* baca keluran dari grader, meskipun tidak digunakan */
    scanf("%lf", &F);

    printf("TAMBAH KUNING %.4lf\n", k);
    fflush(stdout);

    /* baca keluran dari grader, meskipun tidak digunakan */
    scanf("%lf", &F);

    printf("TAMBAH BIRU %.4lf\n", b);
    fflush(stdout);

    /* baca keluran dari grader, meskipun tidak digunakan */
    scanf("%lf", &F);

    printf("SELESAI\n");
    fflush(stdout);

    return 0;
}