#include<stdio.h>
#include<string.h>
#include<stdlib.h>

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

struct staff1
{

    char username[100];
    char password[100];
    struct staff1 *next;
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

struct issue *first_issue = NULL;
struct issue *second_issue = NULL;
struct return_book *first_return_book = NULL;
struct return_book *second_return_book = NULL;
struct student *student1 = NULL;
struct student *trial_student = NULL;
struct staff1 *head1 = NULL;
struct staff1 *head2 = NULL;


// struct book *create_book(struct book *trial_book)
// {
//     struct book *new_book = (struct book *)malloc(sizeof(struct book));
//     if (new_book == NULL)
//     {

//         printf("Memory allocation failed.\n");
//         return NULL;
//     }
//     printf("Enter the id of the book.\n");
//     scanf("%d", &new_book->book_id);
//      printf("ENTER USERNAME -: ");
//     char user_name2[200];
//     fgets(user_name2, sizeof(user_name2), stdin);
//     user_name2[strcspn(user_name2, "\n")] = '\0';  // Remove the newline character if present

//     printf("Enter the name of the book .\n");
//     // gets(new_book->book_name);
//         // fgets(new_book->book_name, sizeof(new_book->book_name), stdin);
//     // Remove the newline character at the end if present
//     // new_book->book_name[strcspn(new_book->book_name, "\n")] = '\0';
//     char bookname[200];
//     fgets(bookname,sizeof(bookname),stdin);
//     printf("Enter the name of the author of the book. \n");
//     gets(new_book->book_author);
//     printf("Enter the year of the book. \n");
//     scanf("%d", &new_book->book_year);
//     printf("Enter the price of the book.\n");
//     scanf("%f", &new_book->book_price);
//     printf("Enter the Quantity of the book .\n");
//     scanf("%d", &new_book->book_quantity);
//     printf("Thank you ............");
//     new_book->next = NULL;
//     return new_book;
// }


struct book *create_book()
{
    struct book *new_book = (struct book *)malloc(sizeof(struct book));
    if (new_book == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    printf("Enter the id of the book: ");
    scanf("%d", &new_book->book_id);

    printf("Enter the name of the book: ");
    // fgets(new_book->book_name, sizeof(new_book->book_name), stdin);
    // new_book->book_name[strcspn(new_book->book_name, "\n")] = '\0';  // Remove the newline character if present
char name[222];
gets(name);
    printf("Enter the year of the book: ");
    scanf("%d", &new_book->book_year);
    printf("Enter the name of the author of the book: ");
    fgets(new_book->book_author, sizeof(new_book->book_author), stdin);
    new_book->book_author[strcspn(new_book->book_author, "\n")] = '\0';  // Remove the newline character if present


    printf("Enter the price of the book: ");
    scanf("%f", &new_book->book_price);

    printf("Enter the Quantity of the book: ");
    scanf("%d", &new_book->book_quantity);

    printf("Thank you............\n");
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

int main(){
    add_new_book(first_book);
    return 0;
}