#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct book
{
    int book_id;
    char book_name[200];
    char book_author[200];
    int book_year;
    float book_price;
    int book_quantity;
    struct book *next;
};
struct book *first_book = NULL;
struct book *trial_book = NULL;

struct student
{
    char username[100];
    char password[100];
    int roll_no;
    int class_no;
    struct issue *next_issue;
    struct return_book *next_return;
    struct student *next;
};

struct student *student1 = NULL;
struct student *trial_student = NULL;
struct issue
{
    char issue_username[100];
    int issue_book_id;
    char issue_date[10];
    char issue_book_name[200];
    char issue_book_author[200];
    int issue_book_year;
    float issue_book_price;
    struct issue *next;
};

struct return_book
{
    char return_book_username[100];
    int return_book_id;
    char return_book_date[10];
    char return_book_name[200];
    char return_book_author[200];
    int return_book_year;
    float return_book_price;
    struct return_book *next;
};
struct request_book
{
    char request_book_name[100];
    char request_book_author[100];
    int request_book_year;
    char request_book_date[10];
    struct request_book *next;
};
struct issue * student_trial_issue_book=NULL;
struct return_book * student_trial_return_book=NULL;
struct request_book *first_request_book = NULL;
struct request_book *trial_request_book = NULL;
void display_book_details(struct book *);
struct request_book *initialize_request_book(struct request_book *trial_request_book);
struct request_book *create_request_book(struct request_book *trial_request_book);
struct request_book *add_new_request_book(struct request_book *first_request_book);
struct student *initialize_student_list(struct student *trial_student);
struct book *search_book_by_bookid(int item, struct book *first_book);
void display_student_all_functions(struct student *trial_student);
void choose_student_type_login();
// void display_student_issue_book(struct issue * student_trial_issue_book );
// void dislplay_student_return_book(struct return_book *student_trial_return_book );


void display_all_issues(struct issue *first_issue)
{
    if (first_issue == NULL)
    {
        printf("No issued books.\n");
        return;
    }

    struct issue *temp = first_issue;
    if (temp != NULL)
    {
        while (temp != NULL)
        {
            printf("================================================================================================================ \n \n");
            printf("ISSUED BOOK DETAIL");
            printf("STUDENT USERNAME -: %s \n ", temp->issue_username);
            printf("BOOK ID -: %d \n", temp->issue_book_id);
            printf("BOOK NAME -: %s \n ", temp->issue_book_name);
            printf("BOOK AUTHOR -: %s \n", temp->issue_book_author);
            printf("BOOK YEAR -: %d \n ", temp->issue_book_year);
            printf("BOOK PRICE -: %f \n", temp->issue_book_price);

            printf("\n===============================================================================================================\n");
            temp = temp->next;
        }
    }
    else
    {
        printf("There is no book to issued in the system.\n");
    }
}


void display_all_return_books(struct return_book *first_return_book)
{
    if (first_return_book == NULL)
    {
        printf("No return_bookd books.\n");
        return;
    }

    struct return_book *temp = first_return_book;
    if (temp != NULL)
    {
        while (temp != NULL)
        {
            printf("================================================================================================================ \n \n");
            printf("RETURNED BOOK DETAIL");
            printf("STUDENT USERNAME -: %s \n ", temp->return_book_username);
            printf("BOOK ID -: %d \n", temp->return_book_id);
            printf("BOOK NAME -: %s \n ", temp->return_book_name);
            printf("BOOK AUTHOR -: %s \n", temp->return_book_author);
            printf("BOOK YEAR -: %d \n ", temp->return_book_year);
            printf("BOOK PRICE -: %f \n", temp->return_book_price);

            printf("\n===============================================================================================================\n");
            temp = temp->next;
        }
    }
    else
    {
        printf("There is no book to return_bookd in the system.\n");
    }
}


void display_book_details(struct book *first_book)
{
    struct book *temp = (struct book *)malloc(sizeof(struct book));
    temp = first_book;
    if (temp != NULL)
    {
        while (temp != NULL)
        {
            printf("================================================================================================================ \n \n");
            printf("BOOK ID -: %d \n", temp->book_id);
            printf("BOOK NAME -: %s \n ", temp->book_name);
            printf("BOOK AUTHOR -: %s \n", temp->book_author);
            printf("BOOK YEAR -: %d \n ", temp->book_year);
            printf("BOOK PRICE -: %f \n", temp->book_price);
            printf("BOOK QUANTITY -: %d \n ", temp->book_quantity);
            printf("\n===============================================================================================================\n");
            temp = temp->next;
        }
    }
    else
    {
        printf("There is no book in the system.\n");
    }
}


//  initialize request book list
struct request_book *initialize_request_book(struct request_book *trial_request_book)
{

    struct request_book *ptr, *actual_request_book1, *actual_request_book2, *actual_request_book3;

    actual_request_book1 = (struct request_book *)malloc(sizeof(struct request_book));
    actual_request_book1->next = NULL;
    first_request_book = actual_request_book1;
    strcpy(actual_request_book1->request_book_name, "HARRY PORTER CHAPTER 1");
    strcpy(actual_request_book1->request_book_author, "J.K ROWLING");
    actual_request_book1->request_book_year = 2003;
    strcpy(actual_request_book1->request_book_date, "05/10/2023");
    ptr = actual_request_book1;

    actual_request_book2 = (struct request_book *)malloc(sizeof(struct request_book));
    actual_request_book2->next = NULL;

    strcpy(actual_request_book2->request_book_name, "AFTER RECOGNITION");
    strcpy(actual_request_book2->request_book_author, "RONALD REGAN");
    actual_request_book2->request_book_year = 2006;
    strcpy(actual_request_book2->request_book_date, "04/11/2023");
    ptr = actual_request_book2;

    actual_request_book3 = (struct request_book *)malloc(sizeof(struct request_book));
    actual_request_book3->next = NULL;

    strcpy(actual_request_book3->request_book_name, "WORLD OF FANTASIES");
    strcpy(actual_request_book3->request_book_author, "SUSMITA SEHGIL");
    actual_request_book3->request_book_year = 2013;
    strcpy(actual_request_book3->request_book_date, "12/12/2023");
    ptr->next = actual_request_book3;

    return first_request_book;
}
//  creating and adding a new request
//  taking the request_book details

struct request_book *create_request_book(struct request_book *trial_request_book)
{
    struct request_book *new_request_book = (struct request_book *)malloc(sizeof(struct request_book));
    if (new_request_book == NULL)
    {

        printf("Memory allocation failed.\n");
        return NULL;
    }
    printf("ENTER THE NAME OF BOOK FOR REQUEST-: ");
    char request_bookname11[100];
    scanf("%s", request_bookname11);
    strcpy(new_request_book->request_book_name, request_bookname11);
    printf("ENTER THE AUTHOR OF THE BOOK-: ");
    char request_bookauthor11[100];
    scanf("%s", request_bookauthor11);
    strcpy(new_request_book->request_book_author, request_bookauthor11);
    printf("ENTER THE YEAR OF BOOK-: ");
    scanf("%d", &new_request_book->request_book_year);
    printf("ENTER THE DATE OF REQUESTING BOOK-: ");
    char request_bookdate11[10];
    scanf("%s", request_bookdate11);
    strcpy(new_request_book->request_book_date, request_bookdate11);

    printf("Thank you ............");
    new_request_book->next = NULL;
    return new_request_book;
}
//  creating a add new request_book
struct request_book *add_new_request_book(struct request_book *first_request_book)
{
    struct request_book *new_request_book = create_request_book(trial_request_book);

    // If the list is empty, the new request_book becomes the first_request_book
    if (first_request_book == NULL)
    {
        return new_request_book;
    }

    // Otherwise, add the new request_book to the end of the list
    struct request_book *temp = first_request_book;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new_request_book;
    return first_request_book;
}

// initializing students
struct student *initialize_student_list(struct student *trial_student)
{
    struct student *actual_student1 = (struct student *)malloc(sizeof(struct student));
    struct student *ptr = (struct student *)malloc(sizeof(struct student));
    struct student *actual_student4 = (struct student *)malloc(sizeof(struct student));
    struct student *actual_student2 = (struct student *)malloc(sizeof(struct student));
    struct student *actual_student3 = (struct student *)malloc(sizeof(struct student));
    actual_student1->next = NULL;
    if (actual_student1 == NULL)
    {
        printf("MEMORY ALLOCATION FAILED...\n");
        return NULL;

    }
    student1 = actual_student1;
    actual_student1->class_no = 12;
    actual_student1->roll_no = 43;
    strcpy(actual_student1->username, "AKSHAT");
    strcpy(actual_student1->password, "1234");
    struct issue *new_issue = (struct issue *)malloc(sizeof(struct issue));
    new_issue->issue_book_id=123456;
    new_issue->issue_book_price=23.56;
    new_issue->next = NULL;
    actual_student1->next_issue = new_issue;
    struct return_book *new_return_book_1 = (struct return_book *)malloc(sizeof(struct return_book));
    new_return_book_1->next = NULL;
    actual_student1->next_return = new_return_book_1;
    ptr = actual_student1;

    actual_student2->next = NULL;
    if (actual_student2 == NULL)
    {
        printf("MEMORY ALLOCATION FAILED...\n");
        return NULL;
    }

    actual_student2->class_no = 2;
    actual_student2->roll_no = 13;
    strcpy(actual_student2->username, "ANMOL");
    strcpy(actual_student2->password, "1234");
    struct issue *new_issue_2 = (struct issue *)malloc(sizeof(struct issue));
    new_issue_2->next = NULL;
    actual_student2->next_issue = new_issue;
    struct return_book *new_return_book_2 = (struct return_book *)malloc(sizeof(struct return_book));
    new_return_book_2->next = NULL;
    actual_student2->next_return = new_return_book_2;
    ptr->next = actual_student2;
    ptr = actual_student2;

    actual_student3->next = NULL;
    if (actual_student3 == NULL)
    {
        printf("MEMORY ALLOCATION FAILED...\n");
        return NULL;
    }

    actual_student3->class_no = 2;
    actual_student3->roll_no = 13;
    strcpy(actual_student3->username, "ABHAY");
    strcpy(actual_student3->password, "1234");
    struct issue *new_issue_3 = (struct issue *)malloc(sizeof(struct issue));
    
    new_issue_3->next = NULL;
    actual_student3->next_issue = new_issue;
    struct return_book *new_return_book_3 = (struct return_book *)malloc(sizeof(struct return_book));
    new_return_book_3->next = NULL;
    actual_student3->next_return = new_return_book_3;
    ptr->next = actual_student3;
    ptr = actual_student3;

    actual_student4->next = NULL;
    if (actual_student4 == NULL)
    {
        printf("MEMORY ALLOCATION FAILED...\n");
        return NULL;
    }

    actual_student4->class_no = 2;
    actual_student4->roll_no = 13;
    strcpy(actual_student4->username, "ABHAY");
    strcpy(actual_student4->password, "1234");
    struct issue *new_issue_4 = (struct issue *)malloc(sizeof(struct issue));
    new_issue_4->next = NULL;
    actual_student4->next_issue = new_issue;
    struct return_book *new_return_book_4 = (struct return_book *)malloc(sizeof(struct return_book));
    new_return_book_4->next = NULL;
    actual_student4->next_return = new_return_book_4;
    ptr->next = actual_student4;
    return student1;
}

//  function to display student issued book
// struct issue display_student_issued_book(struct student * second_issue){

// }

// function to search a book by id.

struct book *search_book_by_bookid(int item, struct book *first_book)
{

    struct book *temp = (struct book *)malloc(sizeof(struct book));
    temp = first_book;
    while (temp != NULL && temp->book_id != item)
    {
        temp = temp->next;
    }
    if (temp->book_id == item)
    {
        printf("A BOOK IS FOUND IN THE SYSTEM WITH THIS ID.....\n");
        temp->next = NULL;
        display_book_details(temp);
        // free(temp);
        printf("All good in displaying the book by id......\n");
    }
    else
    {
        printf("INVALID ID....\n");
    }
}
// //  function to display the books issued by the student
// void display_student_issue_book(struct issue * trial_book){
//     struct issue * issue_book_student=(struct issue *)malloc(sizeof(struct issue));
//     issue_book_student=trial_book;
//     if(issue_book_student==NULL){
//         printf("There is no issued book......\n");
//     }
//     else{
//         while(issue_book_student!=NULL){
            
//         }
//     }
    

// }

//  displaying all the functions that the user can check
void display_student_all_functions(struct student *trial_student)
{
    printf("||||        WELCOME TO THE LIBRARY PORTAL        ||||\n");
    initialize_student_list(student1);
    initialize_request_book(first_request_book);
    int choice_display_student = 1;
    do
    {
        printf("1.To search for a book by BOOK ID .\n");
        // printf("2.To search for a book by BOOK NAME . \n");
        printf("2.To request for a book.\n");
        printf("3.To look for your issued book. \n");
        printf("4.To look for your returned book.\n");
        printf("5.To display all the books.\n");
        
        printf("10.To exit.\n");
        int choice13;
        printf("Enter your choice.");
        scanf("%d", &choice13);
        switch (choice13)
        {
        case 1:
            //  function to search for a book by id
            printf("ENTER THE BOOKID -: ");
            int item_idabc;
            scanf("%d", &item_idabc);
            search_book_by_bookid(item_idabc, first_book);

            break;
        case 2:
            // function to request for a book;2

            add_new_request_book(first_request_book);
            break;

        case 3:
            //  function to look for your issued book
            printf("ENTERING INTO ISSUED BOOKS DISPLAY \n");
            // display_student_issue_book(trial_student->next_issue);
            display_all_issues(trial_student->next_issue);
            printf("Exiting issued book student function.\n");

            break;
        case 4:
            //  function to look for your returned book.
            printf("ENTERING INTO RETURNED BOOK DISPLAY \n");
            display_all_return_books(trial_student->next_return);
            printf("Exiting the returned displayed \n");

            break;
        case 5:
            // function to display all books
            //  dont worry about this error it is because of not linking
            // display_book_details(first_book);
            break;
        
        case 10:
            printf("EXITING...........\n");
            choice_display_student = 0;
            break;
        default:
            printf("please choose above choice only.........\n");
            break;
        }

    } while (choice_display_student != 0);
}

void choose_student_type_login()
{
    // initialize the list of the student.
    initialize_student_list(trial_student);
    //  dont worry about this error it is because of not linking
    // initialize_lib(first_book);
    printf("||||        WELCOME TO THE LIBRARY PORTAL        ||||\n");
    printf("                  STUDENT LOGIN PAGE                  \n\n\n");
    int choice_choose_student_type_login;
    choice_choose_student_type_login = 1;
    do
    {
        printf("              CHOOSE THE MODE OF LOGIN                 \n\n");
        printf("1. AS A NEW STUDENT                 2. LOGIN AS A STUDENT \n\n");
        printf("ENTER YOUR CHOICE-: ");
        int choice_abcd;
        scanf("%d", &choice_abcd);
        switch (choice_abcd)
        {
        case 1:

            choice_choose_student_type_login = 0;
            break;
        case 2:
            printf("ENTER YOUR USERNAME-: ");
            char student_username_1a[100];
            scanf("%s", student_username_1a);
            printf("ENTER YOUR STUDENT PASSWORD -: ");
            char student_password1a[100];
            scanf("%s", student_password1a);

            struct student *temp = (struct student *)malloc(sizeof(struct student));
            temp = student1;

            int result123a = strcmp(temp->username, student_username_1a);
            int result223a = strcmp(temp->password, student_password1a);
            while (result123a != 0 && result223a != 0 && temp != NULL)
            {
                temp = temp->next;
                result123a = strcmp(temp->username, student_username_1a);
                result223a = strcmp(temp->password, student_password1a);
            }
            if (result123a == 0 && result223a == 0)
            {
                printf("CONGRATS , YOU ARE A VALID STUDENT USER.....\n");
                display_student_all_functions(temp);

                choice_choose_student_type_login = 0;
            }
            else
            {
                printf("INVALID USERNAME OR PASSWORD....\n");
                choice_choose_student_type_login = 1;
            }

            break;
        default:

            break;
        }
    } while (choice_choose_student_type_login != 0);
}
int main()
{
    choose_student_type_login();
    return 0;
}