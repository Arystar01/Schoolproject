#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    int choice1a;
    do{
    printf("1. Login as a student\n");
    printf("2. Login as a teacher \n");
    printf("3. Register as a new student \n");
    printf("4. Register as a new teacher.\n");
    printf("5. Exit \n");
    printf("Enter your choice:");
    scanf("%d",&choice1a);
    switch(choice1a){
        case 1:

        break;
        case 2:

        break;
        case 3:

        break;
        case 4 :

        break;
        case 5:

        break;
        default:
        printf("Enter Valid choice. \n");
        break;

    }
}while(choice1a!=5);

}