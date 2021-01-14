#include <stdio.h>
#include <math.h>

double ke(double m, double v) {
    return m*v*v/2;
}

int main() {
    double mass, speed;
    printf("Enter the value of mass: ");
    scanf("%lf", &mass);

    printf("Enter the value of speed: ");
    scanf("%lf", &speed);

    printf("The value of kinetic energy is: %.2lf", ke(mass, speed));

    return 0;
}
