#include <stdio.h>

long frac(int);
long C(int, int);

int main()
{
    FILE *inp = fopen("tohop.inp", "r");
    FILE *out = fopen("tohop.out", "w");

    int n, k;
    while (fscanf(inp,"%d %d", &n, &k) != EOF)
        fprintf(out, "%ld\n", C(n, k));
    fclose(inp);
    fclose(out);

    return 0;
}

long C(int n, int k){
    if (k == 0)
        return 1;
    else {
        double res = 1;
        for (int i = n - k + 1, j = 1; i <= n, j <= k; i++, j++) {
            res = res * i / j;
        }
        return (double) res;
    }
}

