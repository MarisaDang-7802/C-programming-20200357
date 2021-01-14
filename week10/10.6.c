#include <stdio.h>
#include <math.h>

double C(double F){
    return 5.0/9.0*(F - 32);
}

void table(void){
    printf("Fahreinheit(F)  Celcius(C)\n");
    for (int i = 0; i <= 20; i++){
        printf("%7.0lf%17.2lf\n", (double)i, C( (double)i ));
    }
}

int main() {
    table();
    return 0;
}
