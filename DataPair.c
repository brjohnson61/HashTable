#include "DataPair.h"

void copyDataPair(DataPair from, DataPair* to){
    to->key = from.key;
    to->value = from.value;
    to->next = from.next;
    return;
}