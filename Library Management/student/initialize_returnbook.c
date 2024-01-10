#include <stdio.h>
#include <string.h>
// #include <conio.h>
#include <stdlib.h>

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