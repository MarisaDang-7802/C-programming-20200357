#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cachdeu(int, int, int);

int main(){
    int x, y, z;
    printf("Nhap 3 so: ");
    scanf("%d %d %d", &x, &y, &z);

    if (cachdeu(x, y, z))
        printf("3 so nay cach deu nhau\n");
    else 
        printf("3 so nay ko cach deu nhau\n");
    return 0;
}

int cachdeu(int x, int y, int z){
    int dis_xy = abs(x - y), dis_yz = abs(y-z), dis_xz = abs(x - z);
    if (((dis_xy==dis_yz) || (dis_yz == dis_xz) || (dis_xy == dis_xz)) /*&& ((dis_xy != 0)&&(dis_yz != 0)&&(dis_xz != 0))*/ )
        return 1;
    else return 0;
}
