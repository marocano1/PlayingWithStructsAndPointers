#include <stdio.h>
#include <stdlib.h>
#include "mystructs.h"


int main() {
    struct item *myitem = (struct item *)malloc(sizeof(struct item));
    myitem->itemName = (char *)malloc(BUFFER_SIZE);

    itemRead(myitem);
    itemPrint(myitem);
    
    free(myitem->itemName);
    free(myitem);

    return 0;
}
