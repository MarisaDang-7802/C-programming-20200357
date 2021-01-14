#include <stdio.h>
#include <math.h>

unsigned long lt(int i){
    int res = 1;
    for (int j = 0; j < i; j++)
        res *= 10;
    return res;
}

int k(unsigned long n){
    int i = 10;
    while ( !(n / lt(i)) )
    {
        i--;
    }
    return i+1;
}

int class(unsigned long n){
    int num = k(n), count_odd = 0, count_even = 0;
    for (int i = 0; i < num; i++)
    {
        int extr = n - n / 10 * 10;
        if (extr % 2) 
            count_odd++;
        else if (!(extr % 2))
            count_even++;
        n /= 10;

    }
    if (count_odd == num)
        return 1;
    else if (count_even == num)
        return -1;
    else 
        return 0;
}

void process(int c){
    if (c == 1)
        printf("n is all-odd number\n");
    else if (c == -1)
        printf("n is all-even number\n");
    else
        printf("n is nether all-odd nor all-even number\n");
}

void inp(unsigned long *n){
    printf("Enter the number n: ");
    scanf("%lu", n);
}

int main() {
    unsigned long n;
    inp(&n);
    process(class(n));
    return 0;
}
