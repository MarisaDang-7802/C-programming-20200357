#include <stdio.h>
#include <limits.h>
#include <float.h>

int n;
double a[10000];
double *maximum(double*, int);
void inp(void);
void prt(void);

int main(){
    inp();
    prt();
    return 0;
}

void inp(void){
    printf("Enter the number of members and contents: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%lf", &a[i]);
    }
}

double *maximum(double *a, int n){
    if ((a == NULL) || (n == 0))
        return NULL;
    else {
        double *res, max = DBL_MIN;
        for (int i = 0; i < n; i++)
        {
            if (max < *a)
            {
                max = *a;
                res = a;
            }
            a++;
        }
        return res;
    }
}

void prt(void){
    printf("%p\n", maximum(a, n));
}

