#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
struct book * search_book_by_bookid(int item){

    
}