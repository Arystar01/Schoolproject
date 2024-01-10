#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
// #include "trial_book_storage.h"
// #include "super_header.h"
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
//  declaring all the functions
//  initializing a first node (root node)

struct book *first_book = NULL;

// student
struct student
{
    char username[100];
    char password[100];
    struct student *next;
};
struct student *student1 = NULL;


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


//  initailized structure of the return node
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


//  defining all functions
struct issue *first_issue = NULL;
struct issue *second_issue = NULL;
struct issue *add_new_issue(struct issue *first_issue);
struct issue *create_issue(struct issue * second_issue);
void display_all_issues(struct issue *first_issue);
struct return_book *first_return_book = NULL;
struct return_book *second_return_book = NULL;
struct return_book *add_new_return_book(struct return_book *first_return_book);
struct return_book *create_return_book(struct return_book * second_return_book);
void display_all_return_books(struct return_book *first_return_book);
// struct book *first_book = NULL;
// struct student *student1 = NULL;
struct issue;
struct return_book;
struct book;
struct student;





//  initializing a issue node (first issue node)
// struct issue *first_issue = NULL;

// taking the issue details

struct issue *create_issue(struct issue * second_issue)
{
    struct issue *new_issue = (struct issue *)malloc(sizeof(struct issue));
    // new_issue->next = NULL;
    if (new_issue == NULL)
    {

        printf("Memory allocation failed.\n");
        return first_issue;
    }
    char issue_username1[100];
    printf("Enter the student username-: ");
    scanf("%s", issue_username1);
    struct student *ptr = (struct student *)malloc(sizeof(struct student));
    ptr = student1;
    while (ptr->username != issue_username1 && ptr != NULL)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        printf("Valid username......\n");

        strcpy(new_issue->issue_username, issue_username1);

        // now checking for a valid book id;
        int issue_username1_book_id;
        printf("Enter the book id of the book-: ");
        scanf("%d", &issue_username1_book_id);
        struct book *new_book = (struct book *)malloc(sizeof(struct book));
        new_book = first_book;
        while (new_book->book_id != issue_username1_book_id && new_book != NULL)
        {
            new_book = new_book->next;
        }
        if (new_book != NULL)
        {
            printf("Valid book id. \n");
            new_issue->issue_book_id = issue_username1_book_id;
            strcpy(new_issue->issue_book_author, new_book->book_author);
            new_issue->issue_book_price = new_book->book_price;
            new_issue->issue_book_year = new_book->book_year;
            char issue_date1[10];
            printf("Enter the date-: ");
            scanf("%s", issue_date1);
            strcpy(new_issue->issue_date, issue_date1);
            //  reducing a book quantity by 1 as , on issueing book the no of book would be reduced
            new_book->book_quantity = new_book->book_quantity - 1;
            printf("Congratulate the book is issued.\n");
        }
    }
    else
    {
        printf("INVALID USERNAME.......\n");
    }

    new_issue->next = NULL;
    return new_issue;
}
//  creating a add new issue
struct issue *add_new_issue(struct issue *first_issue)
{
    struct issue *new_issue = create_issue(second_issue);

    // If the list is empty, the new issue becomes the first_issue
    if (first_issue == NULL)
    {
        return new_issue;
    }

    // Otherwise, add the new issue to the end of the list
    struct issue *temp = first_issue;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new_issue;
    return first_issue;
}

//  function to display all the issued books
// Function to display all issued books
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
            printf("temp->ISSUED BOOK DETAIL");
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


//  initializing a return_book node (first return_book node)
struct return_book *first_return_book = NULL;

// taking the return_book details

struct return_book *create_return_book(struct return_book * second_return_book)
{
    struct return_book *new_return_book = (struct return_book *)malloc(sizeof(struct return_book));
    new_return_book->next = NULL;
    if (new_return_book == NULL)
    {

        printf("Memory allocation failed.\n");
        return first_return_book;
    }
    char return_book_username1[100];
    printf("Enter the issue username-: ");
    scanf("%s", return_book_username1);
    struct issue *ptr = (struct issue *)malloc(sizeof(struct issue));
    ptr = first_issue;
    while (ptr->issue_username != return_book_username1 && ptr != NULL)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        printf("Valid  issue username......\n");

        strcpy(new_return_book->return_book_username, return_book_username1);
        int return_book_id1;
        printf("Enter the book id -: ");
        scanf("%d", &return_book_id1);
        if (ptr->issue_book_id == return_book_id1)
        {
            (new_return_book->return_book_id= return_book_id1);
            printf("VALID BOOK ID........\n");
            char return_book_date1[10];
            printf("Enter the date-: ");
            scanf("%s", return_book_date1);
            strcpy(new_return_book->return_book_author, ptr->issue_book_author);
            strcpy(new_return_book->return_book_name, ptr->issue_book_name);
            new_return_book->return_book_price = ptr->issue_book_price;
            new_return_book->return_book_year = ptr->issue_book_year;
            //  now changing data in the actual book list , i.e incremementing the quantity of the book by 1;
            struct book *new_book = (struct book *)malloc(sizeof(struct book));
            new_book = first_book;
            while (new_book->book_id != return_book_id1)
            {
                new_book = new_book->next;
            }
            new_book->book_quantity = new_book->book_quantity + 1;
            printf("BOOK IS ADDED INTO SYSTEM SUCCESSFULLY \n");
        }
        else
        {
            printf("PLEASE ENTER THE VALID BOOK ID.\n");
        }
    }
    else
    {
        printf("INVALID USERNAME.......\n");
    }
    return new_return_book;
}
//  creating a add new return_book
struct return_book *add_new_return_book(struct return_book *first_return_book)
{
    struct return_book *new_return_book = create_return_book( second_return_book);

    // If the list is empty, the new return_book becomes the first_return_book
    if (first_return_book == NULL)
    {
        return new_return_book;
    }

    // Otherwise, add the new return_book to the end of the list
    struct return_book *temp = first_return_book;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new_return_book;
    return first_return_book;
}



//  function to display all the return_bookd books
// Function to display all return_bookd books
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
            printf("temp->return_bookD BOOK DETAIL");
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



