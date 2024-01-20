#ifndef MEDICINE_H
#define MEDICINE_H

struct medicine
{
    char med_name[100];
    char med_code[10];
    int med_quantity;
    float med_price;
    //  for date
    struct medicine *next;
};
struct medicine *create_medicine(struct medicine *first_medicine);
struct medicine *add_medicine(struct medicine *first_medicine, const char *med_name1, const char *med_code1, int med_quantity, float med_price1);
struct medicine *search_medicine(struct medicine *first_medicine, const char *med_name1);
struct medicine *delete_medicine(struct medicine *first_medicine, const char *med_name1);
struct medicine *change_medicine(struct medicine *first_medicine, const char *med_name1);
struct medicine *change_medicine_functions(struct medicine *first_medicine);
struct medicine *initialize_medicine();
void display_medicine(struct medicine *first_medicine);
#endif