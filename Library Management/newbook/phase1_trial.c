//  correct code

#include <stdio.h>
#include <string.h>
// #include <conio.h>
#include <stdlib.h>
// #include "trial_book_storage.h"
// #include "trial_issue.h"
// #include "trial_library.h"
// #include "super_header.h"

//  declaration of all staff , student , issue.

//
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

// student
struct student
{
    char username[100];
    char password[100];
    int roll_no;
    int class_no;
    struct issue * next_issue;
    struct return_book * next_return;
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
struct issue *first_issue = NULL;
struct issue *second_issue = NULL;

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
struct return_book *first_return_book = NULL;
struct return_book *second_return_book = NULL;
struct staff1
{

    char username[100];
    char password[100];
    struct staff1 *next;
};
struct staff1 *head1 = NULL;
struct staff1 *head2 = NULL;
struct book *add_new_book(struct book *);
struct book *create_book(struct book *);
struct book *sort_book_by_id(struct book *);
struct book *swap(struct book *ptr1, struct book *ptr2);
struct book *change_book(struct book *, int item_id);
struct book *delete_by_id(int item_id, struct book *);
void display_book_details(struct book *);
void display_supervisor_functions();
struct book *initialize_lib(struct book *);
struct issue *initialize_issue_books(struct issue *second_issue);
struct issue *add_new_issue(struct issue *first_issue);
struct issue *create_issue(struct issue *second_issue);
void display_all_issues(struct issue *first_issue);
struct return_book *initailize_return_book(struct return_book *second_return_book);
struct return_book *add_new_return_book(struct return_book *first_return_book);
struct return_book *create_return_book(struct return_book *second_return_book);
void display_all_return_books(struct return_book *first_return_book);

struct staff1 *insert_staff(struct staff1 *head1);
struct staff1 *delete_staff1(struct staff1 *head1);
struct staff1 *initialize_staff1(struct staff1 *head2);
void display_staff();
void display_functions_library_head();

//  initiali\ze book list
struct book *initialize_lib(struct book *trial_book)
{
    struct book *ptr, *new_book1, *new_book2, *new_book3, *new_book4, *new_book5;

    new_book1 = (struct book *)malloc(sizeof(struct book));
    new_book1->next = NULL;
    first_book = new_book1;
    new_book1->book_id = 1111;
    strcpy(new_book1->book_name, "Concept of Physics");
    strcpy(new_book1->book_author, "H.C. Verma");
    new_book1->book_year = 2025;
    new_book1->book_price = 2334.34;
    new_book1->book_quantity = 10;
    ptr = new_book1;

    new_book2 = (struct book *)malloc(sizeof(struct book));
    new_book2->next = NULL;

    new_book2->book_id = 2341;
    strcpy(new_book2->book_name, "Concept of Physics");
    strcpy(new_book2->book_author, "H.C. Verma");
    new_book2->book_year = 2025;
    new_book2->book_price = 2334.34;
    new_book2->book_quantity = 10;
    ptr->next = new_book2;
    // ptr = new_book2;
    // free(ptr);
    return first_book;
}

//  taking the book details

struct book *create_book(struct book *trial_book)
{
    struct book *new_book = (struct book *)malloc(sizeof(struct book));
    if (new_book == NULL)
    {

        printf("Memory allocation failed.\n");
        return NULL;
    }
    printf("Enter the id of the book.\n");
    scanf("%d", &new_book->book_id);
    printf("Enter the name of the book .\n");
    scanf("%s", new_book->book_name);
    //     fgets(new_book->book_name, sizeof(new_book->book_name), stdin);
    // Remove the newline character at the end if present
    // new_book->book_name[strcspn(new_book->book_name, "\n")] = '\0';
    printf("Enter the name of the author of the book. \n");
    scanf("%s", new_book->book_author);
    printf("Enter the year of the book. \n");
    scanf("%d", &new_book->book_year);
    printf("Enter the price of the book.\n");
    scanf("%f", &new_book->book_price);
    printf("Enter the Quantity of the book .\n");
    scanf("%d", &new_book->book_quantity);
    printf("Thank you ............");
    new_book->next = NULL;
    return new_book;
}
//  creating a add new book
struct book *add_new_book(struct book *first_book)
{
    struct book *new_book = create_book(trial_book);

    // If the list is empty, the new book becomes the first_book
    if (first_book == NULL)
    {
        return new_book;
    }

    // Otherwise, add the new book to the end of the list
    struct book *temp = first_book;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new_book;
    return first_book;
}

//  sorting the books according to the id value from small to larger one
struct book *sort_book_by_id(struct book *first_book)
{
    struct book *temp = (struct book *)malloc(sizeof(struct book));
    temp = first_book;
    while (temp != NULL)
    {
        struct book *new_book = (struct book *)malloc(sizeof(struct book));
        new_book = temp;
        temp = temp->next;
    }
}

//  function to swap two nodes
struct book *swap(struct book *ptr1, struct book *ptr2)
{
    struct book *tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}

// function to delete a book by id
struct book *delete_by_id(int item_id, struct book *first_book)
{
    if (first_book == NULL)
    {
        printf("There  is no book to delete in the system.\n");
    }
    else
    {

        struct book *t = (struct book *)malloc(sizeof(struct book));
        struct book *temp = (struct book *)malloc(sizeof(struct book));
        t = NULL;
        temp = first_book;
        if (first_book->book_id == item_id && temp != NULL)
        {
            first_book = temp->next;
            free(temp);
            return first_book;
        }
        while (temp->book_id != item_id && temp != NULL)
        {
            t = temp;
            temp = temp->next;
        }
        if (temp->book_id == item_id && temp != NULL)
        {
            temp = temp->next;
            t->next = temp;
            // free(temp);
            return first_book;
        }
        else
        {
            printf("There is no book to delete , with such id.\n");
            return first_book;
        }
    }
}
//  function to change the values of the book , the id of the book cant be changed.
struct book *change_book(struct book *first_book, int item_id)
{
    struct book *temp = (struct book *)malloc(sizeof(struct book));
    temp = first_book;
    while (temp->book_id != item_id && temp != NULL)
    {
        temp = temp->next;
    }
    if (temp != NULL)
    {

        printf("The book with the id number %d is found and availabel to change. \n", item_id);
        int book_change_choice;
        do
        {
            struct book *t = (struct book *)malloc(sizeof(struct book));
            t = temp;
            printf("To change the following select the following .\n ");
            printf("1. To change the name of the book. \n");
            printf("2. To change the author of the book. \n");
            printf("3. To change the year of the book. \n");
            printf("4. To change the price of the book. \n");
            printf("5. To change the quantity of the book. \n");
            printf("6. Changes are done \n");
            int choice1;
            scanf("%d", &choice1);
            book_change_choice = 1;
            switch (choice1)
            {
            case 1:

                printf("Current name of the book is %s", t->book_name);
                printf("Enter new name of the book. \n");
                char name12[200];
                scanf("%s", name12);
                //    t->book_name=name;
                strcpy(t->book_name, name12);
                break;
            case 2:
                printf("Current name of the author is %s .\n", t->book_author);
                printf("Enter the new name of the author. \n");
                char author12[200];
                scanf("%s", author12);
                strcpy(t->book_author, author12);
                break;
            case 3:
                printf("Current year of the book is %d .\n", t->book_year);
                printf("Enter the new year for the book.\n");
                int year;
                scanf("%d", &year);
                t->book_year = year;
                break;
            case 4:
                printf("Current price of the book is %f . \n", t->book_price);
                printf("Enter new price. \n");
                float price;
                scanf("%f", &price);
                t->book_price = price;
                break;
            case 5:
                printf("Current quantity of book is %d", t->book_quantity);
                printf("Enter the new quantity of book .\n");
                int quantity;
                scanf("%d", &quantity);
                t->book_quantity = quantity;
                break;
            case 6:
                book_change_choice = 0;
                break;
            default:
                printf("Please choose one of the above number only.\n");
                break;
            }
        } while (book_change_choice != 0);
    }
    else
    {
        printf("Sorry , there is no book with such a number in the system . \n");
    }
}
//  Function to display the whole book list.
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
//  till line 284 of book storage
// initializing of the issued books
struct issue *initialize_issue_books(struct issue *second_issue)
{
    struct issue *ptr, *new_issue_book1, *new_issue_book2, *new_issue_book3, *new_issue_book4, *new_issue_book5;

    new_issue_book1 = (struct issue *)malloc(sizeof(struct issue));
    new_issue_book1->next = NULL;
    first_issue = new_issue_book1;
    new_issue_book1->issue_book_id = 1111;
    strcpy(new_issue_book1->issue_book_name, "Concept of Physics");
    strcpy(new_issue_book1->issue_book_author, "H.C. Verma");
    new_issue_book1->issue_book_year = 2025;
    new_issue_book1->issue_book_price = 2334.34;
    strcpy(new_issue_book1->issue_date, "12/2/2019");

    ptr = new_issue_book1;

    new_issue_book2 = (struct issue *)malloc(sizeof(struct issue));
    new_issue_book2->next = NULL;

    new_issue_book2->issue_book_id = 2341;
    strcpy(new_issue_book2->issue_book_name, "Concept of Physics");
    strcpy(new_issue_book2->issue_book_author, "H.C. Verma");
    new_issue_book2->issue_book_year = 2025;
    new_issue_book2->issue_book_price = 2334.34;
    strcpy(new_issue_book2->issue_date, "11/2/2018");
    ptr->next = new_issue_book2;
    // ptr = new_issue_book2;
    // free(ptr);
    return first_issue;
}
// taking the issue details

struct issue *create_issue(struct issue *second_issue)
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

    int result;
    result = strcmp(ptr->username, issue_username1);
    while (result != 0 && ptr != NULL)
    {
        ptr = ptr->next;
        result = strcmp(ptr->username, issue_username1);
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
// struct return_book *first_return_book = NULL;

struct return_book *initailize_return_book(struct return_book *second_return_book)
{

    struct return_book *ptr, *new_return_book1, *new_return_book2, *new_return_book3, *new_return_book4, *new_return_book5;

    new_return_book1 = (struct return_book *)malloc(sizeof(struct return_book));
    new_return_book1->next = NULL;
    first_return_book = new_return_book1;
    new_return_book1->return_book_id = 1111;
    strcpy(new_return_book1->return_book_name, "Concept of Physics");
    strcpy(new_return_book1->return_book_author, "H.C. Verma");
    new_return_book1->return_book_year = 2025;
    new_return_book1->return_book_price = 2334.34;
    strcpy(new_return_book1->return_book_date, "12/2/2019");
    ptr = new_return_book1;

    new_return_book2 = (struct return_book *)malloc(sizeof(struct return_book));
    new_return_book2->next = NULL;

    new_return_book2->return_book_id = 2341;
    strcpy(new_return_book2->return_book_name, "Concept of Physics");
    strcpy(new_return_book2->return_book_author, "H.C. Verma");
    new_return_book2->return_book_year = 2025;
    new_return_book2->return_book_price = 2334.34;
    strcpy(new_return_book2->return_book_date, "11/2/2018");
    ptr->next = new_return_book2;
    // ptr = new_return_book2;
    // free(ptr);
    return first_return_book;
}

// taking the return_book details

struct return_book *create_return_book(struct return_book *second_return_book)
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
            (new_return_book->return_book_id = return_book_id1);
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
    struct return_book *new_return_book = create_return_book(second_return_book);

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

//  inserting a new entry of staff1
struct staff1 *insert_staff(struct staff1 *head1)
{
    struct staff1 *ptr = (struct staff1 *)malloc(sizeof(struct staff1));
    if (ptr == NULL)
    {
        printf("Memory allocation failed!.\n");
        return NULL;
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
    if (temp == NULL)
    {
        head1 = ptr;
        return head1;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
        return head1;
    }
}

//  delete a staff from the access link.
struct staff1 *delete_staff1(struct staff1 *head1)
{
    if (head1 == NULL)
    {
        printf("There is no staff to remove.\n");
        return NULL;
    }
    struct staff1 *temp = (struct staff1 *)malloc(sizeof(struct staff1));
    struct staff1 *ptr = (struct staff1 *)malloc(sizeof(struct staff1));
    ptr = NULL;
    temp = head1;
    char name_To_delete[100];
    printf("Enter the name of user to be deleted-: ");
    scanf("%s", name_To_delete);
    int result64 = strcmp(temp->username, name_To_delete);
    while (result64 != 0 && temp != NULL)
    {
        ptr = temp;
        temp = temp->next;
        result64 = strcmp(temp->username, name_To_delete);
    }
    if (result64 == 0)
    {
        temp = temp->next;
        ptr->next = temp;
        // free(temp);
        printf("The name is deleted.\n");
        return head1;
    }
    printf("There is no such staff to delete.\n");
    return head1;
}
// initialize the list of staff
struct staff1 *initialize_staff1(struct staff1 *head2)
{
    struct staff1 *ptr, *new_staff10, *new_staff2, *new_staff3;
    new_staff10 = (struct staff1 *)malloc(sizeof(struct staff1));
    if (new_staff10 == NULL)
    {
        printf("Memory allocation failed!.\n");
        return NULL;
    }
    new_staff10->next = NULL;
    head1 = new_staff10;
    strcpy(new_staff10->username, "RAM");
    strcpy(new_staff10->password, "1234");
    ptr = new_staff10;

    new_staff2 = (struct staff1 *)malloc(sizeof(struct staff1));
    new_staff2->next = NULL;
    strcpy(new_staff2->username, "MOHAN");
    strcpy(new_staff2->password, "12345");
    ptr->next = new_staff2;
    ptr = new_staff2;

    new_staff3 = (struct staff1 *)malloc(sizeof(struct staff1));
    new_staff3->next = NULL;
    strcpy(new_staff3->username, "SOHAN");
    strcpy(new_staff3->password, "123456");
    ptr->next = new_staff3;
    // ptr=new_staff3;
    return head1;
}

void display_staff()
{
    struct staff1 *temp = head1;
    if (temp != NULL)
    {
        while (temp != NULL)
        {
            printf("USERNAME -: %s \n", temp->username);
            printf("PASSWORD -: %s \n", temp->password);
            temp = temp->next;
        }
    }
    else
    {
        printf("There is no staff to display. \n");
    }
}

void display_functions_library_head()
{
    initialize_staff1(head1);
    printf("||||                                   WELCOME TO THE LIBRARY PORTAL                                                    ||||\n");
    printf("                                    AUTHORIZED ONLY FOR LIBRARY HEAD                                                 \n");
    printf("\n \n \n");
    int choice4a = 1;
    do
    {
        printf("1 . To insert a new staff member.\n");
        printf("2 . To Delete a staff member.\n");
        printf("3 . To Display all the staff members.\n");
        printf("10. To exit the function. \n");
        int choose_functions_library_head;
        scanf("%d", &choose_functions_library_head);
        switch (choose_functions_library_head)
        {
        case 1:
            insert_staff(head1);
            choice4a = 1;
            break;
        case 2:
            delete_staff1(head1);
            choice4a = 1;
            break;
        case 3:
            display_staff();
            choice4a = 1;
            break;
        case 10:
            choice4a = 0;
            break;
        default:
            printf("PLEASE CHOOSE ONLY ABOVE CHOICES.....\n");
            choice4a = 1;
            break;
        }

        printf("All done in the library head functions.\n");

    } while (choice4a != 0);
    printf("all done till 749..... \n");
}

//  function to display all the functions availabel in the lirary superisor menu.
void display_supervisor_functions()
{
    // initialize_lib(first_book);
    printf("||||                                   WELCOME TO THE LIBRARY PORTAL                                                    ||||\n");
    printf("                                    AUTHORIZED ONLY FOR LIBRARY STAFFS                                                      \n");
    printf("\n \n \n");
    int choice3;
    choice3 = 1;
    do
    {

        printf("1.To add a new book details. \n");
        printf("2.To edit the book detail.\n");
        printf("3.To delete a book from the system. \n");
        printf("4.To display the book list. \n");
        printf("5.To issue a book. \n");
        printf("6.To dislplay all the issued books. \n");
        printf("7.To return a book. \n");
        printf("8.To display all the return books.\n");
        printf("10.To exit the function system.\n");
        int choose_functions_library_staff;
        scanf("%d", &choose_functions_library_staff);
        switch (choose_functions_library_staff)
        {
        case 1:

            add_new_book(first_book);
            // display_book_details(first_book);
            printf("Welcome for the next \n");
            break;
        case 2:

            printf("Enter the id of book to change -: ");
            int item_id_a;
            scanf("%d", &item_id_a);
            change_book(first_book, item_id_a);
            printf("CONGRATULATE , CHANGES ARE MADE IN THE SYSTEM. \n");
            break;
        case 3:
            printf("Enter the id of the book to be delete from a system -: ");
            int item_id_b;
            scanf("%d", &item_id_b);
            delete_by_id(item_id_b, first_book);
            printf(" THANK YOU......");
            break;
        case 4:
            display_book_details(first_book);
            break;
        case 5:
            // place a file name issue here , function name add_new_issue
            printf("Welcome To the issue page... \n");
            add_new_issue(first_issue);
            printf("THANK YOU FOR ISSUING A BOOK.......... \n");
            break;
        case 6:
            // place a file name issue here, function name display_all_issues;
            printf("DISPLAYING ALL THE ISSUED BOOKS.........\n");
            display_all_issues(first_issue);
            printf("END OF THE ISSUE BOOK LIST............\n");
            break;
        case 7:
            printf("WELCOME TO THE RETURN PAGE...........\n");
            add_new_return_book(first_return_book);
            printf("THANK YOU FOR RETURNING THE BOOK........\n");
            break;
        case 8:
            printf("DISPLING ALL THE RETURNED BOOKS.......\n");
            display_all_return_books(first_return_book);
            printf("END OF THE RETURNED BOOK LIST.........\n");
            break;
        case 10:
            choice3 = 0;
            break;
        default:
            break;
        }

    } while (choice3 != 0);
}

void choose_staff_type_login()
{
    // create_book(struct book * trial_book);
    initialize_lib(first_book);
    // display_supervisor_functions();
    printf("||||                                   WELCOME TO THE LIBRARY PORTAL                                                    ||||\n");
    printf("                                    AUTHORIZED ONLY FOR LIBRARY STAFFS                                                      \n");
    printf("\n \n \n");
    printf("                                   CHOOSE THE DESIGNATION FOR LOGIN                                                         \n");
    printf(" 1. As a Supervisor                                                                         2. As a Library head            \n");
    int choice2 = 1;
    do
    {
        int choice_designation;
        printf("ENTER THE CHOICE -: ");
        scanf("%d", &choice_designation);
        int abcd;
        abcd = 1;
        int aaad;
        aaad = 1;
        switch (choice_designation)
        {
        case 1:
            //  initialize the list of the staff members
            initialize_staff1(head1);
            do
            {

                printf("ENTER STAFF USERNAME -: ");
                char user_name1[200];
                scanf("%s", user_name1);
                printf("ENTER STAFF PASSWORD -: ");
                char user_password1[20];
                scanf("%s", user_password1);
                struct staff1 *temp = (struct staff1 *)malloc(sizeof(struct staff1));
                temp = head1;
                int result11, result22;
                result11 = strcmp(temp->username, user_name1);
                result22 = strcmp(temp->password, user_password1);
                while (result11 != 0 && result22 != 0 && temp != NULL)
                {
                    temp = temp->next;
                    result11 = strcmp(temp->username, user_name1);
                    result22 = strcmp(temp->password, user_password1);
                }
                if (result11 == 0 && result22 == 0)
                {
                    //  placing all the functions that the library staff can do, to exit the loop a person need to put correct detail
                    printf("all good 1 \n");
                    display_supervisor_functions(); /* chech here */

                    // exit condition.
                    abcd = 0;
                }
                else
                {
                    printf("Dont know.\n");
                    abcd = 1;
                }

            } while (abcd != 0);

            choice2 = 0;
            break;
        case 2:
            //  here no need to initialize any list

            do
            {
                printf("ENTER USERNAME -: ");
                char user_name2[200];
                scanf("%s", user_name2);
                char actual_username[] = "HEAD";
                printf("ENTER PASSWORD -: ");
                char user_password2[20];
                scanf("%s", user_password2);
                char actual_password[] = "1234";
                int result1 = strcmp(actual_username, user_name2);
                int result2 = strcmp(actual_password, user_password2);
                if (result1 == 0 && result2 == 0)
                {
                    //  placing all the functions of the Library head , assuming there is a single head , and a user need to enter correct detail, there is no other way to exit the loop

                    display_functions_library_head();

                    aaad = 0;
                }
                else
                {
                    printf("INVALID USERNAME OR PASSWORD.........\n");
                    aaad = 1;
                }

            } while (aaad != 0);

            choice2 = 0;

            break;

        default:
            printf("Please choose one of the above only.\n");
            choice2 = 2;
            break;
        }
    } while (choice2 != 0);
    // add_new_book(first_book);
}

void greeting()
{
    printf("|||         AERO LIBRARY MANAGEMENT SYSTEM         |||\n");
    printf("                MEERUT, UTTAR PRADESH                 \n\n\n");
    printf("        WELCOME TO THE LIBRARY MANAGEMENT SYSTEM        \n\n");
}

void choose_type_login()
{
    int choice_choose_type_login;
    choice_choose_type_login = 1;
    do
    {
        printf("PLEASE CHOOSE LOGIN TYPE \n");
        printf("1.As a student                   2.As a library staff\n");

        int choice_a1;
        scanf("%d", &choice_a1);
        switch (choice_a1)
        {
        case 1:
            //  open the student login page

            choice_choose_type_login = 0;
            break;
        case 2:
            //  open the staff login page . ie file name login1.c
            choose_staff_type_login();

            choice_choose_type_login = 0;
            break;

        default:
            printf("PLEASE CHOOSE ABOVE ONE ONLY.. \n");
            break;
        }
    } while (choice_choose_type_login != 0);
}

int main()
{

    greeting();
    choose_type_login();

    return 0;
}
