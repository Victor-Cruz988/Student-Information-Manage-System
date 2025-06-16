#include <stdio.h>
#include <stdlib.h>
#include "fun.h"

int main(int argc, char const *argv[])
{
    int option;
    while (1)
    {
        start_menu();
        scanf("%d", &option);
        switch (option)
        {
            case 1:
                add_a_student();
                break;
            case 2:
                delete_a_student();
                break;
            case 3:
                modify_a_student();
                break;
            case 4:
                query_a_student();
                break;
            case 5:
                exit(1);
            default:
                printf("option doesn't exist!\n");
        }
        printf("\nPress Enter to continue...\n");
        getchar();
        getchar();
    }
    return 0;
}
