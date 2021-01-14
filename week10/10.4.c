#include <stdio.h>
#include <math.h>

int dataFilt(int n){
    if (n < 10 || n > 65)
        return 0; 
    else return 1;
}

void process(int n){
    if (!dataFilt(n)){
        printf("Invalid input! Exiting.....\n");
        return ;
    }
    long sal;
    if (n <= 40)
        sal = 15000*n;
    else 
        sal = 15000*40 + 15000*3/2*(n-40);
    printf("The salary that the worker receive is: %ld\n", sal);

}

void inp(int *n){
    printf("Enter the number of working hours: ");
    scanf("%d", n);
}

int main() {
    int n;
    inp(&n);
    process(n);
    return 0;
}
