#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int d, m, y;
} birth;

typedef struct
{
     long long id;
    char *name, *cls, *course;
    birth b;
} stdnt;

stdnt *st, st1;

int n, choice;

//Prototype

//menu and choose
void menu(void);
void choose(void);

//features
void addMulti(void);
void addSingl(void);
void show(void);
void sortAsnd(void);
void searchStdnt(void);
void extPrg(void);

//extensions
void readData(void);
void srt(void);
int comp(const void *, const void *);
void writeData(stdnt);
void writeSort(stdnt);

//Main program
int main(){
    choose();
    return 0;
}

//Implementation
void menu(void){
    printf("Choose the feature below by number (1-6) to use the program: \n");
    printf("1. Enter information the student of HUST\n");
    printf("2. Display the information of the entered students\n");
    printf("3. Sort ascending information the students by student name\n");
    printf("4. Add a new student\n");
    printf("5. Search for students by student name\n");
    printf("6. Exit\n");
    printf("Pick your choice: ");
}

void choose(void){
    do{
        menu();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addMulti();
            break;
        case 2:
            show();
            break;
        case 3:
            sortAsnd();
            break;
        case 4:
            addSingl();
            break;
        case 5:
            searchStdnt();
            break;
        case 6:
            extPrg();
            break;
        default:
            printf("Invalid choice! Please try again!\n");
            break;
        }
    }
    while (choice != 6);
}

void readData(void){
    free(st);
    n = 0;
    char check = 0;
    int count;
    FILE *in = fopen("Student.dat", "a+");
    fscanf(in, "%d", &count);
    fflush(in);
    st = (stdnt*)malloc(count*sizeof(stdnt));

    for (int i = 0; i < count; i++)
    {
        fscanf(in, "%lld", &(st->id));
        fflush(in);
        fgets(st->name, 20, in);
        fflush(in);
        fscanf(in, "%d", &(st->b.d));
        fscanf(in, "%d", &(st->b.d));
        fscanf(in, "%d", &(st->b.d));
        fflush(in);
        fgets(st->cls, 20, in);
        fflush(in);
        fgets(st->course, 20, in);
        fflush(in);

        n++;
        check = fgetc(in);
    }
    if (n != 0)
    {
        n++;
    }
    fclose(in);
}

void writeData(stdnt st){
    char check = 0;
    FILE *in = fopen("Student.dat", "a+");

        fprintf(in, "%lld\n", st.id);
        fprintf(in, "%s\n", st.name);
        fprintf(in, "%d/%d/%d\n", st.b.d, st.b.m, st.b.y);
        fprintf(in, "%s\n", st.cls);
        fprintf(in, "%s\n\n", st.course);
    fclose(in);
}

void writeSort(stdnt st){
    char check = 0;
    FILE *in = fopen("Student2021.dat", "a+");

        fprintf(in, "%lld\n", st.id);
        fprintf(in, "%s\n", st.name);
        fprintf(in, "%d/%d/%d\n", st.b.d, st.b.m, st.b.y);
        fprintf(in, "%s\n", st.cls);
        fprintf(in, "%s\n\n", st.course);
    fclose(in);
}


void addMulti(void){
        printf("Adding the students: \n");
        int ch, count = 0, ch1 = 0;

        printf("Enter number of students you want to add: ");
        scanf("%d", &count);
        FILE *in = fopen("Student2021.dat", "w+");
        fprintf(in, "%d\n", count);
        for (int i = 0; i < count; i++)
        {
            printf("Entering student number %d\n", i+1);
            printf("ID: ");
            scanf("%lld", &(st1.id));
            fflush(stdin);

            printf("Name: ");
            scanf("%s", st1.name);
            fflush(stdin);
            printf("BirthDate: (dd/mm/yyyy) ");
            scanf("%d", &(st1.b.d));
            scanf("%d", &(st1.b.m));
            scanf("%d", &(st1.b.y));
            fflush(stdin);
            printf("Class: ");
            scanf("%s", st1.cls);
            fflush(stdin);
            printf("Course: ");
            scanf("%s", st1.course);
            fflush(stdin);

            writeData(st1);
            printf("Adding one student completed!\n\n");
        }
}

void addSingl(void){
        printf("Adding the student: ");
        int ch, count = 0, ch1 = 0;
        do{
            printf("Entering a student...\n");
            printf("ID: ");
            scanf("%lld", &(st1.id));
            fflush(stdin);

            ch1 = 0;
            for (int i = 0; i < n; i++)
                if (st1.id == st[i].id)
                {
                   ch1 = 1;
                   break;
                }

            if (ch1 == 1)
            {
                printf("Student already exits!\n");
                continue;
            }


            printf("Name: ");
            gets(st1.name);
            fflush(stdin);

            printf("BirthDate: (dd/mm/yyyy) ");
            scanf("%d/%d/%d", &(st1.b.d), &(st1.b.m), &(st1.b.y));
            fflush(stdin);
            printf("Class: ");
            gets(st1.cls);
            fflush(stdin);

            printf("Course: ");
            gets(st1.course);
            fflush(stdin);

            st = (stdnt*)realloc(st, (n+1)*sizeof(stdnt));
            srt();
            writeSort(st1);
            printf("Adding completed!\n\n");
        }
        while (ch1 == 1);
}

int comp(const void *a, const void *b){
    stdnt* A = (stdnt*)a;
    stdnt* B = (stdnt*)b;
    return (A->id - B->id);
}

void srt(void){
    readData();

    qsort(st, n, sizeof(stdnt), comp);
}

void sortAsnd(){
    srt();
    FILE *in = fopen("Student2021.dat", "w+");
    fprintf(in, "%d\n", n);
    for(int i = 0; i < n; i++){
        writeSort(st[i]);
    }

    printf("Sort completed!\n");
    printf("%3s %8s %20s %10s %15s %20s\n", "No", "StudentID", "StudentName", "BirthDate", "ClassName", "CourseName");
    for (int i = 0; i < n; i++){
        printf("%3d %8lld %20s %d/%d/%d %15s %20s\n", i+1 ,st[i].id, st[i].name, st[i].b.d, st[i].b.m, st[i].b.y, st[i].cls, st[i].course);

    }
}

void show(){
    readData();
    printf("%3s %8s %20s %10s %15s %20s\n", "No", "StudentID", "StudentName", "BirthDate", "ClassName", "CourseName");
    for (int i = 0; i < n; i++){
        printf("%3d %8lld %20s %d/%d/%d %15s %20s\n", i+1 ,st[i].id, st[i].name, st[i].b.d, st[i].b.m, st[i].b.y, st[i].cls, st[i].course);
    }
}

void searchStdnt(){
    readData();
    stdnt key, *res;
    srt();
    printf("Enter the key: ");
    scanf("%lld", &(key.id));

    res = (stdnt*) bsearch(&key, st, n, sizeof(stdnt), comp);
    if (res == NULL)
        printf("No student is found!\n");
    else
        printf("%lld, %s, %d/%d/%d, %s, %s\n", res->id, res->name, res->b.d, res->b.m, res->b.y, res->cls, res->course);
}

void extPrg(){
    char ch;
    fflush(stdin);
    do{
        printf("Are you sure to exit?(y/n)");
        scanf("%c", &ch);
        if (ch == 'y')
        {
            free(st);
            exit(0);
        }
        else if (ch == 'n'){
            choice = 1;
            break;
        }
    }
    while (!((ch != 'y') || (ch != 'n')));
}




