#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int sobinhphuong(int);

int main(){

    int a[10000];
    int n = 0;
    int max = INT_MIN;
    
    printf("Enter number of elements of array: ");
    scanf("%d", &n);

    printf("Enter respectively elements of array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("The square elements of array is: ");
    for (int i = 0;i < n; i++)
        if (sobinhphuong(a[i])){
            printf("%d ", a[i]);
            if (max < a[i]) 
                max = a[i];
        }
    printf("\n");
    printf("The largest square element of array is: %d\n", max);

    return 0;
}

int sobinhphuong(int n){
        for (int i = 0; i <= 40000; i++)
            if (i*i == n)
                return 1;
        return 0;
}
