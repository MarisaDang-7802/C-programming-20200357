#include <stdio.h>

int on;
int print(int*, int, int);
int printSubArray(int*, int, int);

int main(){
    int arr[10000], n;
    printf("Enter the number of members and contents: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++ ){
        scanf("%d", &arr[i]);
    }
    on = n;
    printSubArray(arr, n, 0);
    return 0;
}

int print(int *a, int n, int j){
    for (int i = j; i < n; i++)
    {
        printf("%d ", *(a + i));
    }
    printf("\n");
}


int printSubArray(int *a, int n, int k){
    for (int i = 0; i < n; i++)
        for (int j = 1; j <= n-i; j++){
            for (int k = 0; k < j; k++)
            {
                printf("%d ", *(a+i+k));
            }
            printf("\n");
        }
}

