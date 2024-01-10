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
struct book *search_book_by_bookid(int item, struct book *first_book)
{

    struct book *temp = (struct book *)malloc(sizeof(struct book));
    temp = first_book;
    while (temp->book_id != item && temp != NULL)
    {
        temp - temp->next;
    }
    if (temp->book_id == item)
    {
        printf("A BOOK IS FOUND IN THE SYSTEM WITH THIS ID.....\n");
        temp->next = NULL;
        display_book_details(temp);
        printf("All good in displaying the book by id......\n");
    }
    else
    {
        printf("INVALID ID....\n");
    }
    
}