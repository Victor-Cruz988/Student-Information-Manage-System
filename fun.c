#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fun.h"

void start_menu()
{
    printf("-------Students-Management-------\n");
    printf("|           1.  ADD             |\n");
    printf("|           2. DELETE           |\n");
    printf("|           3. MODIFY           |\n");
    printf("|           4. QUERY            |\n");
    printf("|           5.  EXIT            |\n");
    printf("---------------------------------\n");
}

void add_a_student()
{

    Student s;
    s.isdel = 0;

    printf("Input an id: ");
    scanf("%d", &s.id);
    printf("Input name: ");
    scanf("%s", s.name);
    printf("Input score: ");
    scanf("%f", &s.score);

    FILE *fp = fopen("List.dat", "a");
    if (fp == NULL)
    {
        perror("fopen fp error");
        exit(1);
    }
    fwrite(&s, sizeof(s), 1, fp);
    printf("Add SUCCESSFULLY!\n");

    fclose(fp);
}

void delete_a_student()
{
    FILE *fp = fopen("List.dat", "r+");
    if (fp == NULL)
    {
        perror("fopen fp error");
        exit(1);
    }

    Student s;
    printf("\nWho will you delete: ");
    char Dname[20];
    scanf("%s", Dname);

    int flag = 0;
    while(1)
    {
        fread(&s, sizeof(s), 1, fp);
        if (feof(fp))
            break;
        if(strcmp(s.name, Dname) == 0)
        {
            int del = 1;
            fseek(fp, -4, SEEK_CUR);
            int ret = fwrite(&del, 4, 1, fp);
            if (ret < 1)
            {
                perror("fwrite fp error");
                exit(1);
            }
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        printf("Delete SUCCESSFULLY!\n");
    else
        printf("This student doesn't exist!\n");

    fclose(fp);

}

void modify_a_student()
{
    FILE *fp = fopen("List.dat", "r+");
    if (fp == NULL)
    {
        perror("fopen fp error");
        exit(1);
    }

    Student s;
    printf("\nWho Are You Searching: ");
    char Sname[20];
    scanf("%s", Sname);

    int flag = 0;
    while (1)
    {
        fread(&s, sizeof(s), 1, fp);
        if (feof(fp))
            break;
        if (strcmp(s.name, Sname) == 0)
        {
            float newscore;
            printf("Input the new score: ");
            scanf("%f", &newscore);
            fseek(fp, -8, SEEK_CUR);
            int ret = fwrite(&newscore, 4, 1, fp);
            if (ret < 1)
            {
                perror("fwrite fp error");
                exit(1);
            }
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        printf("Update SUCCESSFULLY!\n");
    else
        printf("This student doesn't exist!\n");

    fclose(fp);
}

void query_a_student()
{
    FILE *fp = fopen("List.dat", "r");
    if (fp == NULL)
    {
        perror("fopen fp error");
        exit(1);
    }

    Student s;
    printf("----------------------------------\n");
    while (1)
    {
        fread(&s, sizeof(s), 1, fp);
        if (feof(fp))
            break;
        if (s.isdel == 0)
            printf("%d\t%8s\t%f\n", s.id, s.name, s.score);
    }
    printf("----------------------------------\n");

    fclose(fp);
}
