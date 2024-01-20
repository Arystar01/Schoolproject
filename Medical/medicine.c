#include "medicine.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine *trial_medicine1 = NULL;
struct medicine *create_medicine(struct medicine *trial_medicine1)
{
    char med_name1[100];
    char med_code1[10];
    int med_quantity1;
    float med_price1;
    printf("Enter name of the medicine -    ");
    getchar();
    fgets(med_name1, sizeof(med_name1), stdin);
    med_name1[strcspn(med_name1, "\n")] = '\0';
    printf("Enter code of the medicine -    ");
    getchar();
    fgets(med_code1, sizeof(med_code1), stdin);
    med_code1[strcspn(med_code1, "\n")] = '\0';
    printf("Enter the quantity of the medicine -    ");
    scanf("%d", &med_quantity1);
    printf("Enter the price of the medicine -   ");
    scanf("%f", &med_price1);
    return add_medicine(trial_medicine1, med_name1, med_code1, med_quantity1, med_price1);
}

struct medicine *add_medicine(struct medicine *trial_medicine1, const char *med_name1, const char *med_code1, int med_quantity1, float med_price1)
{
    struct medicine *ptr = (struct medicine *)malloc(sizeof(struct medicine));
    if (ptr == NULL)
    {
        printf("Memory location initialization failed ........ \n");
    }
    strcpy(ptr->med_name, med_name1);
    strcpy(ptr->med_code, med_code1);
    ptr->med_price = med_price1;
    ptr->med_quantity = med_quantity1;
    ptr->next = NULL;
    if (trial_medicine1 == NULL)
    {
        trial_medicine1 = ptr;
        return trial_medicine1;
    }
    struct medicine *temp = (struct medicine *)malloc(sizeof(struct medicine));
    temp = trial_medicine1;
    while (temp != NULL)
    {
        temp = temp->next;
    }
    temp->next = ptr;
    free(ptr);
    return trial_medicine1;
}

struct medicine *search_medicine(struct medicine *trial_medicine, const char *med_name1)
{
    struct medicine *ptr = (struct medicine *)malloc(sizeof(struct medicine));
    struct medicine *temp = (struct medicine *)malloc(sizeof(struct medicine));
    temp = trial_medicine1;
    while (temp != NULL && strcmp(temp->med_name, med_name1) == 0)
    {
        temp = temp->next;
    }
    if (temp != NULL)
    {
        printf("Congratulation medicine is availabel in the system....... \n");
        // display_medicine();
        //  write display function to display the medicines.

        printf("\nMedicine Details:\n");
        printf("Medicine Name: %s\n", temp->med_name);
        printf("Medicine Code: %s\n", temp->med_code);
        printf("Medicine Quantity: %d\n", temp->med_quantity);
        printf("Medicine Price: %.2f\n", temp->med_price);
        printf("\n");
    }
    else
    {
        printf("There is no medicine with such a name");
    }
}
struct medicine *change_medicine(struct medicine *trial_medicine1, const char *med_name1)
{
    struct medicine *ptr = (struct medicine *)malloc(sizeof(struct medicine));
    struct medicine *temp = (struct medicine *)malloc(sizeof(struct medicine));
    temp = trial_medicine1;
    while (temp != NULL && strcmp(temp->med_name, med_name1) == 0)
    {
        temp = temp->next;
    }
    if (temp != NULL)
    {
        printf("Congratulation medicine is availabel in the system....... \n");
        // display_medicine();
        //  write display function to display the medicines.

        printf("\nMedicine Details:\n");
        printf("Medicine Name: %s\n", temp->med_name);
        printf("Medicine Code: %s\n", temp->med_code);
        printf("Medicine Quantity: %d\n", temp->med_quantity);
        printf("Medicine Price: %.2f\n", temp->med_price);
        printf("\n");
        change_medicine_functions(temp);
    }
    else
    {
        printf("There is no medicine with such a name");
    }
    return trial_medicine1;
}
struct medicine *change_medicine_functions(struct medicine *first_medicine)
{

    int choice1a = 1;
    do
    {
        printf("    1. To change name.\n    2. To change the code.\n    3. To change quantity.\n    4. To change price.\n   5. Changes done.\n");
        printf("Choose one of the options-  ");
        int choose;
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            printf("Enter new name -    ");
            getchar();
            fgets(first_medicine->med_name, sizeof(first_medicine->med_name), stdin);
            first_medicine->med_name[strcspn(first_medicine->med_name, "\n")] = '\0';
            break;
        case 2:
            printf("Enter new code -    ");
            getchar();
            fgets(first_medicine->med_code, sizeof(first_medicine->med_code), stdin);
            first_medicine->med_code[strcspn(first_medicine->med_code, "\n")] = '\0';
            break;
        case 3:
            printf("Enter new Quantiy -    ");
            int qnt1;
            scanf("%d", &qnt1);
            first_medicine->med_quantity = qnt1;
            break;
        case 4:
            printf("Enter new price -  ");
            float nprice;
            scanf("%f", &nprice);
            first_medicine->med_price = nprice;
            break;
        case 5:
            printf("Changes are saved in the system .\n");
            choice1a = 0;
        default:
            printf("Enter valid choice.\n");
            break;
        }
    } while (choice1a != 0);
    return first_medicine;
}
struct medicine *initialize_medicine()
{
    struct medicine *trial_medicine1 = NULL;

    trial_medicine1 = add_medicine(trial_medicine1, "Medicine1", "M1", 10, 5.99);
    trial_medicine1 = add_medicine(trial_medicine1, "Medicine2", "M2", 15, 8.49);
    trial_medicine1 = add_medicine(trial_medicine1, "Medicine3", "M3", 20, 12.75);
    trial_medicine1 = add_medicine(trial_medicine1, "Medicine4", "M4", 25, 7.99);
    trial_medicine1 = add_medicine(trial_medicine1, "Medicine5", "M5", 30, 6.49);
    trial_medicine1 = add_medicine(trial_medicine1, "Medicine6", "M6", 18, 10.25);

    return trial_medicine1;
}

void display_medicine(struct medicine *trial_medicine1)
{
    while (trial_medicine1 != NULL)
    {
        printf("\nMedicine Details:\n");
        printf("Medicine Name: %s\n", trial_medicine1->med_name);
        printf("Medicine Code: %s\n", trial_medicine1->med_code);
        printf("Medicine Quantity: %d\n", trial_medicine1->med_quantity);
        printf("Medicine Price: %.2f\n", trial_medicine1->med_price);
        printf("\n");

        // Move to the next node in the linked list
        trial_medicine1 = trial_medicine1->next;
    }
}