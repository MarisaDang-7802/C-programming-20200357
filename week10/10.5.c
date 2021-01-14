#include <stdio.h>
#include <math.h>

void printchars(int ch, int n){
    for (int i = 0; i <= n; i++){
        printf("%c", ch);
    }
    printf("\n");
}

void triangle(int n){
    for (int i = 0; i < n ; i++){
        printchars('*',i);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter number n: ");
    scanf("%d", &n);

    triangle(n);

    return 0;
}
