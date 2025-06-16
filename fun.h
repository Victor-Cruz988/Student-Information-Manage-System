#ifndef FUN_H
#define FUN_H

#define NAME_LEN 20

typedef struct Student
{
    int id;
    char name[NAME_LEN];
    float score;
    int isdel; //为1表示已删除
}Student;

void start_menu();

void add_a_student();
void delete_a_student();
void modify_a_student();
void query_a_student();


#endif