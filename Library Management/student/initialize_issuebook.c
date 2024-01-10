#include <stdio.h>
#include <string.h>
// #include <conio.h>
#include <stdlib.h>


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

struct issue *initialize_issue_books(struct issue * second_issue){
     struct issue*ptr, *new_issue_book1, *new_issue_book2, *new_issue_book3, *new_issue_book4, *new_issue_book5;

    new_issue_book1 = (struct issue*)malloc(sizeof(struct issue));
    new_issue_book1->next = NULL;
    first_issue = new_issue_book1;
    new_issue_book1->issue_book_id = 1111;
    strcpy(new_issue_book1->issue_book_name, "Concept of Physics");
    strcpy(new_issue_book1->issue_book_author, "H.C. Verma");
    new_issue_book1->issue_book_year = 2025;
    new_issue_book1->issue_book_price = 2334.34;
    strcpy(new_issue_book1->issue_date,"12/2/2019");
    ptr = new_issue_book1;

    new_issue_book2 = (struct issue*)malloc(sizeof(struct issue));
    new_issue_book2->next = NULL;

    new_issue_book2->issue_book_id = 2341;
    strcpy(new_issue_book2->issue_book_name, "Concept of Physics");
    strcpy(new_issue_book2->issue_book_author, "H.C. Verma");
    new_issue_book2->issue_book_year = 2025;
    new_issue_book2->issue_book_price = 2334.34;
strcpy(new_issue_book2->issue_date,"11/2/2018");
    ptr->next = new_issue_book2;
    // ptr = new_issue_book2;
    // free(ptr);
    return first_issue;
}