#include <stdio.h>

int countEven(int*, int);

int main()
{
    int a[10000], n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    printf("The number of even number is: %d\n", countEven(a, n));

    return 0;
}

int countEven(int *a, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++){ 
        if (*a % 2 == 0)
            count++;
        a++;
    }
    return count;
}
