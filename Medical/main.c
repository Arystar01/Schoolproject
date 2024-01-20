#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "user.h"
#include "medicine.h"
#include "bill.h"
struct medicine *first_medicine12 = NULL;
struct bill *new_bill = NULL;

void choose_mode();
void medicine_functions();
void choose_mode()
{
    int choice31;
    do
    {
        printf("1. To make a bill \n 2.To Enter into storage\n");
        scanf("%d", &choice31);
        switch (choice31)
        {
        case 1:
            printf("Welcome to the bill section.\n");
            add_bill(new_bill);
            choice31 = 0;
            break;
        case 2:
            printf("Welcome to the medicine record window.\n");
            medicine_functions();
            choice31 = 0;
        default:
            printf("Please enter a valid number.\n");
            break;
        }

    } while (choice31 != 0);
}

void medicine_functions()
{
    int choice41;
    do
    {
        printf("    1.To add a medicine.\n    2.To search a medicine.\n    3.To delete a medicine.\n   4.To change a medicine.\n   5.To display a medicine.\n   6.To exit.\n");
        scanf("%d", &choice41);
        switch (choice41)
        {
        case 1:
            create_medicine(first_medicine12);

            break;
        case 2:
            printf("Enter the name of the medicine -    ");
            char name_med12[100];
            getchar();
            fgets(name_med12, sizeof(name_med12), stdin);
            name_med12[strcspn(name_med12, "\n")] = '\0';
            search_medicine(first_medicine12, name_med12);
            break;
        case 3:
            printf("Enter the name of the medicine -    ");
            char name_med13[100];
            getchar();
            fgets(name_med13, sizeof(name_med13), stdin);
            name_med13[strcspn(name_med13, "\n")] = '\0';
            delete_medicine(first_medicine12, name_med13);
            break;
        case 4:
            printf("Enter the name of the medicine -    ");
            char name_med14[100];
            getchar();
            fgets(name_med14, sizeof(name_med14), stdin);
            name_med14[strcspn(name_med14, "\n")] = '\0';
            change_medicine(first_medicine12, name_med14);
            break;
        case 5:
            display_medicine(first_medicine12);
            break;
        case 6:
            choice41 = 0;
            break;
        default:
            printf("Please choose valid choice.\n");
            break;
        }

    } while (choice41 != 0);
}
int main()
{

    int choicem1 = 1;
    do
    {
        printf("Welcome to the medical store\n");
        printf("Enter your username -   ");
        char username[20];
        char password[20];
        getchar();
        fgets(username, sizeof(username), stdin);
        username[strcspn(username, "\n")] = '\0';
        printf("Enter your password -   ");
        getchar();
        fgets(password, sizeof(password), stdin);
        password[strcspn(password, "\n")] = '\0';
        if (strcmp(password, "1234") == 1 && strcmp(username, "ARJIT") == 1)
        {
            printf("Welcome to the menu.\n");
            // display_current_medicines(first_medicine);
            choose_mode();

            choicem1 = 0;
        }
        else
        {
            printf("Wrong entry....\n");
        }
    } while (choicem1 != 0);

    return 0;
}
