#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char rank[13][6] = {
        "Ace", "2","3","4","5","6","7","8","9","10","Jack","Queen","King"
        };

char suit[4][9] = {
        "Clubs","Diamonds","Heart","Spades"
        };

char mark[4][13];

int main(){
    printf("Press any key to start distributing playing cards to 4 players (randomly)...\n");
    getchar();
    printf("Starting distributing playing cards to 4 players \n");
    printf("------------------------------------------------\n\n");

    memset(mark , 0 , sizeof(mark)/sizeof(char));

    time_t t;
    srand((unsigned) time(&t));

    for (int i = 1; i <= 4; i++){
        printf("Distributing playing cards for player number %d. ", i);
        printf("Beginning....\n");
        printf("Player number %d will receive these cards: \n", i);
        int count = 0;
        while (count < 13){
            char m = 1;
            char gen = rand() % 52;
            while (m){
                if (mark[gen % 4][gen / 4] == 0){
                    mark[gen % 4][gen / 4] = 1;
                    printf("%s - %s, ", rank + (gen / 4), suit + (gen % 4));
                    m = 0;
                    count++;
                    break;
                }
                else
                    gen = (++gen) % 52;
            }
        }
        printf("\n\n");
    }
    printf("Distributing complete! Program closing...\n");

    return 0;
}
