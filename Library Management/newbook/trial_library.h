#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
// #include "super_header.h"
struct staff1
{

    char username[100];
    char password[100];
    struct staff1 *next;
};
struct staff1 *head1 = NULL;


//  inserting a new entry of staff1
struct staff1 *insert_staff(struct staff1 *head1)
{
    struct staff1 *ptr = (struct staff1 *)malloc(sizeof(struct staff1));
    if (ptr == NULL)
    {
        printf("Memory allocation failed!.\n");
        return;
    }
    char username1[100];
    printf("Enter your username: ");
    scanf("%s", username1);
    strcpy(ptr->username, username1);
    char password1[100];
    printf("Enter your password : ");
    scanf("%s", password1);
    strcpy(ptr->password, password1);
    ptr->next = NULL;
    struct staff1 *temp = (struct staff1 *)malloc(sizeof(struct staff1));
    temp = head1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = ptr;
    return head1;
}


//  delete a staff from the access link.
struct staff1 *delete_staff1()
{
    if (head1 == NULL)
    {
        printf("There is no staff to remove.\n");
        return;
    }
    struct staff1 *temp = (struct staff1 *)malloc(sizeof(struct staff1));
    struct staff1 *ptr = (struct staff1 *)malloc(sizeof(struct staff1));
    ptr = NULL;
    temp = head1;
    char name_To_delete[100];
    scanf("%s", name_To_delete);
    while (temp->username != name_To_delete && temp != NULL)
    {
        ptr = temp;
        temp = temp->next;
    }
    if (temp != NULL)
    {
        temp = temp->next;
        ptr->next = temp;
        free(temp);
        return head1;
    }
    printf("There is no such staff to delete.\n");
    return head1;
}
// initialize the list of staff
struct staff1 * initialize_staff1(){
    struct staff1 *ptr, *new_staff1, *new_staff2, *new_staff3;
    struct staff1 *new_staff1 = (struct staff1 *)malloc(sizeof(struct staff1));
    if (new_staff1 == NULL)
    {
        printf("Memory allocation failed!.\n");
        return;
    }
    new_staff1->next=NULL;
    head1=new_staff1;
    strcpy(new_staff1->username, "RAM");
    strcpy(new_staff1->password, "1234");
        ptr=new_staff1;

     new_staff2 = (struct staff1*)malloc(sizeof(struct staff1));
    new_staff2->next = NULL;
     strcpy(new_staff2->username, "MOHAN");
    strcpy(new_staff2->password, "12345");
    ptr->next=new_staff2;
    ptr=new_staff2;

     new_staff3 = (struct staff1*)malloc(sizeof(struct staff1));
    new_staff3->next = NULL;
     strcpy(new_staff3->username, "SOHAN");
    strcpy(new_staff3->password, "123456");
    ptr->next=new_staff3;
    // ptr=new_staff3;
}

void display_staff(){
    struct staff1 * temp=head1;
    if(temp!=NULL){
        while(temp!=NULL){
            printf("USERNAME -: %s \n",temp->username );
            printf("PASSWORD -: %s \n",temp->password);
            temp=temp->next;
        }
    }
    else{
        printf("There is no staff to delete. \n");
    
    }
}

void display_functions_library_head(){
 printf("||||                                   WELCOME TO THE LIBRARY PORTAL                                                    ||||\n");
    printf("                                    AUTHORIZED ONLY FOR LIBRARY HEAD                                                 \n");
    printf("\n \n \n");
    int choice4a=1;
    do{
        printf("1 . To insert a new staff member.\n");
        printf("2 . To Delete a staff member.\n");
        printf("3 . To Display all the staff members.\n");
        printf("10. To exit the function. \n");
        int choose_functions_library_head;
        scanf("%d",&choose_functions_library_head);
        switch (choose_functions_library_head)
        {
        case 1:
        insert_staff(head1);
        choice4a=1;
            break;
        case 2:
        delete_staff1();
        choice4a=1;
        break;
        case 3:
        display_staff();
        choice4a=1;
        break;
        case 10:
        choice4a=0;
        default:
        printf("PLEASE CHOOSE ONLY ABOVE CHOICES.....\n");
        choice4a=1;
            break;
        }

printf("All done in the library head functions.\n");




    }while(choice4a!=0);
}