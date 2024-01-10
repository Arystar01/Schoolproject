#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
// #include "trial_issue.h"
#include "trial_library.h"
// #include "super_header.h"
//  defining structure of the book node
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




struct book *first_book=NULL ;


struct book * trial_book=NULL;
struct book *add_new_book(struct book *);
struct book *create_book(struct book * );
struct book *sort_book_by_id(struct book *);
struct book *swap(struct book *ptr1, struct book *ptr2);
struct book *change_book(struct book *, int item_id);
struct book *delete_by_id(int item_id, struct book *);
void display_book_details(struct book *);
void display_supervisor_functions();
struct book *initialize_lib(struct book *);

//  initiali\ze book list
struct book *initialize_lib(struct book * trial_book)
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
free(ptr);
    return first_book;
}
//  creating a add new book
struct book *add_new_book(struct book *first_book)
{
    struct book *new_book = create_book( trial_book);

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

//  taking the book details

struct book *create_book( struct book * trial_book)
{
    struct book *new_book = (struct book *)malloc(sizeof(struct book));
    if (new_book == NULL)
    {

        printf("Memory allocation failed.\n");
        return ;
    }
    printf("Enter the id of the book.\n");
    scanf("%d", &new_book->book_id);
    printf("Enter the name of the book .\n");
    scanf("%s", new_book->book_name);
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
//  sorting the books according to the id value from small to larger one
struct book *sort_book_by_id(struct book *first_book)
{
    struct book *temp = (struct book *)malloc(sizeof(struct book));
    temp = first_book;
    while (temp != NULL)
    {
        struct book *new_book = (struct book *)malloc(sizeof(struct book));
        new_book = temp;
        temp=temp->next;
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
                char name[200];
                scanf("%s", name);
                //    t->book_name=name;
                strcpy(t->book_name, name);
                break;
            case 2:
                printf("Current name of the author is %s .\n", t->book_author);
                printf("Enter the new name of the author. \n");
                char author[200];
                scanf("%s", author);
                strcpy(t->book_author, author);
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
//  function to display all the functions availabel in the lirary superisor menu.
void display_supervisor_functions()
{
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
    initialize_lib( first_book);
    display_supervisor_functions();
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

        switch (choice_designation)
        {
        case 1:
            //  initialize the list of the staff members

            int abcd = 1;
            do
            {
                printf("ENTER USERNAME -: ");
                char user_name1[200];
                scanf("%s", user_name1);
                printf("ENTER PASSWORD -: ");
                char user_password1[20];
                scanf("%s", user_password1);
                struct staff1 *temp = (struct staff1 *)malloc(sizeof(struct staff1));
                temp = head1;
                while (temp->username != user_name1 && temp->password != user_password1 && temp != NULL)
                {
                    temp = temp->next;
                }
                if (temp->username == user_name1 && temp->password == user_password1)
                {
                    //  placing all the functions that the library staff can do, to exit the loop a person need to put correct detail
                    printf("all good 1 \n");
                    display_supervisor_functions();  /* chech here */
                    




                    // exit condition.
                    abcd = 0;
                }
                else
                {
                    abcd = 1;
                }

            } while (abcd != 0);

            choice2 = 0;
            break;
        case 2:
            //  here no need to initialize any list
            int aaad = 1;
            do
            {
                printf("ENTER USERNAME -: ");
                char user_name2[200];
                scanf("%s", user_name2);
                printf("ENTER PASSWORD -: ");
                char user_password2[20];
                scanf("%s", user_password2);
                if (user_name2 == "HEAD" && user_password2 == "12345678")
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
