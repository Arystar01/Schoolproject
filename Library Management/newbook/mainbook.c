#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include "trial_book_storage.h"
#include "trial_issue.h"
#include "trial_library.h"
// #include "super_header.h"

//  declaration of all staff , student , issue.




// 


void greeting(){
    printf("|||         AERO LIBRARY MANAGEMENT SYSTEM         |||\n");
    printf("                MEERUT, UTTAR PRADESH                 \n\n\n");
    printf("        WELCOME TO THE LIBRARY MANAGEMENT SYSTEM        \n\n");
}

void choose_type_login(){
     int choice_choose_type_login;
    choice_choose_type_login=1;
    do{
        printf("PLEASE CHOOSE LOGIN TYPE \n");
    printf("1.As a student                   2.As a library staff\n");
   
        int choice_a1;
        scanf("%d",&choice_a1);
        switch (choice_a1)
        {
        case 1:
        //  open the student login page














        choice_choose_type_login=0;
            break;
        case 2: 
        //  open the staff login page . ie file name login1.c
        choose_staff_type_login();





        choice_choose_type_login=0;
        break;

        default:
        printf("PLEASE CHOOSE ABOVE ONE ONLY.. \n");
            break;
        }
    }while(choice_choose_type_login!=0);

}







int main(){
    printf("hi");
    greeting();
    choose_type_login();

    return 0;
}
