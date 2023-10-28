#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

int main(){

    int choice;
    do{
        
    printf("1. Login in the system .\n");
    printf("2. Book management system. \n");
    printf("3. Logout \n");
    printf("4. Exit. \n");
    printf("Enter your choice- ");
    scanf("%d",&choice);
    switch(choice) {
        case 1: 
        printf("------------------------------------------------------------------------Welcome to the login page  -----------------------------------------------\n");
        int choice1;
        printf("1. New user as a student.\n");
        // code of this is added in file choice1selection.
        break;
        case 2:
        printf("------------------------------------------------------------------------Welcome to the Book Management System-------------------------------------\n");
        int choice2;
        // code of this is added in file choice2selection.
        break;

        case 3:
        // code of this is added in the file logout
        break;
        case 4:
        // code of this is added in the file exit.
        choice=5;
        break;
        default:
        printf("Enter valid choice.\n");
        break;
    }
    }while(choice!=4);

    return 0;

}