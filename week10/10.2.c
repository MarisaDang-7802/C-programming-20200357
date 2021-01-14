#include <stdio.h>
#include <math.h>

int isPrime(int n) {
    if (n < 2) return 0;
    else if (n == 2 ||n == 3 ) return 1;
    else
    {
        for (int i = 2; i<= trunc(sqrt(n)); i++)
        {
            if (n % i == 0) return 0;
        }
        return 1;
    }

}

int process(int n) {
    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i)) 
            printf("%d ", i);
    }
    printf("\n");
}



int main() {
    int n;
    printf("Enter the number n: ");
    scanf("%d", &n);
    printf("List of prime number from 2 to n: ");
    process(n);
    return 0;
}
