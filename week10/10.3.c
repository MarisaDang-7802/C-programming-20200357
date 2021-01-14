#include <stdio.h>
#include <math.h>

long long sum(int n) {
    long res = 0;
    printf("The sum of all cubes of integers from 1 to n is: ");
    for (int i = 1; i<= n; i++){
        res += i*i*i;
    }
    return res;
}

void sm(int n) {
    printf("List of submultiples of n: ");
    for (int i = 1; i <= n/2; i++)
    {
        if (n % i == 0) 
            printf("%d ", i);
    }
    printf("%d", n);
    printf("\n");
}

/*int isPerf(int n) {
    if (n % 2 == 1) 
        return 0;
    else if ( (long)power(2,n-1) * ( (long)power(2, n) - 1 ) % n == 0 ) 
        return 1;
    else 
        return 0;
}*/

int isSquare(int n) {
    if ( trunc(sqrt(n))*trunc(sqrt(n)) == n ) 
        return 1;
    else 
        return 0;
}

void listPerfNum(int n){
    printf("List of n first perfect square number: ");
    int i = 0, count = 0;
    while (count <= n)
    {
        if ( 1 ) {
            printf("%d ",i*i);
            count++;
        }
        i++; 
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter number n: ");
    scanf("%d", &n);

    printf("%lld\n", sum(n));
    sm(n);
    listPerfNum(n);

    return 0;
}
