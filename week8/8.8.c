#include <stdio.h>

int main() {

    long n = 1;
    long long r = 1;

    printf("Enter number n: ");
    scanf("%ld",&n);

    if (n == 0){
        printf("0! = 1\n");
        return 0;
    } 
    else 
        for (int i = 1; i <= n; i++) {
	    
            r = r*i;
	}
    printf("%ld! = %lld\n", n, r);

    return 0;
}
