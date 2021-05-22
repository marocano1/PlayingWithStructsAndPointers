#ifndef MY_STRUCT_H
#define MY_STRUCT_H

#define CHAR_BUFFER (50 * sizeof(char))
#define NUL 0

struct item {
    char *itemName;
    int quantity;
    double price;
    double amount;
};


void itemRead(struct item *item);
void itemPrint(struct item *item);

#endif