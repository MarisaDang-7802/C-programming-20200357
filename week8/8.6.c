#include <stdio.h>

int main() {

    int n, i = 1;

    printf("Enter the number N: ");
    scanf("%i", &n);

    do {
        printf("%i\n",i++);
    }
    while (i < n);

    return 0;
}
