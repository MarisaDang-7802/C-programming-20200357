#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#include "student.h"

#define DATA_PATH "SV2021.dat"

void printMenu();
void tableHeader();
void printBreak();
void addStdnt();
void searchStdnt();
void searchEngine(char *query);
void appStdnt(Student stu);
void printStdnt();

int main()
{
    int choice;
    do
    {
        printMenu();
        scanf(" %d", &choice);
        switch (choice)
        {
        case 1:
            printStdnt();
            break;
        case 2:
            addStdnt();
            break;
        case 3:
            searchStdnt();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice. Please try again!\n");
            break;
        }
    } while (choice != 4);
}

void printMenu()
{
    printf("1.See the students list\n");
    printf("2.Add a student\n");
    printf("3.Search students by name\n");
    printf("4.Exit \n");
}

void tableHeader()
{
    printBreak();
    printf("| %29s | %29s | \n", "Name", "Score");
    printBreak();
}

void printBreak()
{
    for (int i = 0; i < 65; i++)
        putchar('=');
    printf("\n");
}

void addStdnt()
{
    Student new_student;
    char name[255];

    printf("Enter name:   ");

    fflush(stdin);
    fgets(name, 255, stdin);
    strtok(name, "\n");
    strcpy(new_student.name, name);

    printf("Enter scrore:  ");

    scanf(" %f", &new_student.score);

    appStdnt(new_student);

    printBreak();
    printf("Add sucessfully student %s with scrore %.2f!  \n", new_student.name, new_student.score);
    printBreak();
}

void searchStdnt()
{
    printf("Enter the student you want to search:   ");
    char tmp[255];

    fflush(stdin);
    fgets(tmp, 255, stdin);
    strtok(tmp, "\n");

    printf("Result: \n");
    tableHeader();
    searchEngine(tmp);
}

void searchEngine(char *query)
{
    FILE *file = fopen(DATA_PATH, "r");
    Student cur_student;
    while (fread(&cur_student, sizeof(Student), 1, file))
    {
        if (!strstr(cur_student.name, query))
            continue;

        printf("| %29s | %29.2f | \n", cur_student.name, cur_student.score);
        printBreak();
    }

    fclose(file);
}

void appStdnt(Student stu)
{
    FILE *file = fopen(DATA_PATH, "ab+");
    int result = fwrite(&stu, sizeof(Student), 1, file);
    assert(result != 0);
    fclose(file);
}

void printStdnt()
{
    tableHeader();
    FILE *file = fopen(DATA_PATH, "r");
    Student tmp;
    while (fread(&tmp, sizeof(Student), 1, file) )
    {
        printf("| %30s| %30.2f| \n", tmp.name, tmp.score);
        printBreak();
    }
    fclose(file);
}
