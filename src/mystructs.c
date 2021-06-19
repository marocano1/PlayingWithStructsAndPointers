#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystructs.h"

static inline void ClearInputBuffer()
{
  
    // This variable is merely here to munch the garbage out of the input
    // buffer. As long as the input buffer's current character is not either
    // a new line character or the end of input, keep reading characters. This
    // seems to be the only portable way of clearing the input buffer.
    char c = NUL;
  
    while ((c = getchar()) != '\n' && c != EOF) {
        // Do nothing until input buffer fully flushed.
    }
}

static inline void ErrorInputStringTooLong()
{
  
    // NOTE: Print to stderr, not to stdout.
    fprintf(stderr, "[ERROR]: The input was too long, please try again.\n");
  
    // Having notified the user,
    // clear the input buffer and return.
    ClearInputBuffer();
}

static inline void ReadInputFromUser(char *inputBuffer) {

    char* result = NULL;
  
    while (result == NULL) {
        result = fgets(inputBuffer, BUFFER_SIZE, stdin);
  
        if (inputBuffer[strlen(inputBuffer) - 1] != '\n') {
            ErrorInputStringTooLong();
  
            // Since 'result' is the canary
            // we are using to notify of a failure
            // in execution, set it to NULL, to indicate an error.
            // This is a useful value because
            // if for some reason the fgets f/nction were
            // to fail, the return value would also be NULL.
  
            result = NULL;
        }
        else {
            // replace the newline character with a null terminator.
            inputBuffer[strlen(inputBuffer) - 1] = '\0';
        }
    }
}

void itemRead(struct item *item) {
    char *inputBuffer = (char *)malloc(BUFFER_SIZE);
    memset(inputBuffer, NUL, BUFFER_SIZE);
    printf("Please enter the item's name: ");
    ReadInputFromUser(inputBuffer);
    strncpy(item->itemName, inputBuffer, sizeof(item->itemName) - 1);
    printf("Please enter the item's quantity: ");
    memset(inputBuffer, NUL, BUFFER_SIZE);
    ReadInputFromUser(inputBuffer);
    item->quantity = atoi(inputBuffer);
    printf("Please enter the item's price: ");
    memset(inputBuffer, NUL, BUFFER_SIZE);
    ReadInputFromUser(inputBuffer);
    item->price = atof(inputBuffer);
    item->amount = item->quantity * item->price;
    free(inputBuffer);
}

void itemPrint(struct item *item) {
    printf("\nHere are the details of your item.\n");
    printf("Name: %s\n", item->itemName);
    printf("Price: %.2f\n", item->price);
    printf("Quantity: %d\n", item->quantity);
    printf("Total Amount: %.2f\n\n", item->amount);
}