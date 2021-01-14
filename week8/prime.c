#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {

    double k;
    int a = 3;
    srand(time(NULL));

    printf("Enter the number: ");
    scanf("%lf",&k);
    
   // a = (rand()% ((long)k/2-2))*2+1 ;

    for (int i = 1; i < 11; i++) {

    if ( ( (long long)(pow(a, (long long) (k-1)/2)+1) % (long long)k != 0) || ( (long long)(pow(a, (long long) (k-1)/2)-1) % (long long)k != 0 ) ) 
        {
	    printf("%.0lf is not a prime\n", k);
	    return 0;
	}
    }

    printf("%.0lf is a prime\n", k);

    return 0;
}
