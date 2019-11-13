#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashTable.h"
#include "DataPair.h"
#define TABLE_SIZE 7

int main(){
    printf("this is a test output:\n");

    HashTable ht = {.table = NULL, .size = TABLE_SIZE};
    ht.table = (DataPair **) malloc(sizeof(DataPair*)*ht.size);
    if(ht.table == NULL){
        printf("memory allocation failed, exiting...\n");
        return 0;
    }else{
        memset(ht.table, 0, sizeof(ht.table[0])*ht.size);
    }

    DataPair p1 = {.key = 1, .value = 10};
    DataPair p2 = {.key = 2, .value = 20};
    DataPair p3 = {.key = 3, .value = 30};
    DataPair p4 = {.key = 4, .value = 40};
    DataPair p5 = {.key = 5, .value = 50};
    DataPair p6 = {.key = 6, .value = 60};
    DataPair p7 = {.key = 7, .value = 70};
    DataPair p8 = {.key = 8, .value = 80};
    DataPair p9 = {.key = 9, .value = 90};
    DataPair p10 = {.key = 10, .value = 100};

    insert(ht, p1.key, p1.value);
    insert(ht, p2.key, p2.value);
    insert(ht, p3.key, p3.value);
    insert(ht, p4.key, p4.value);
    insert(ht, p5.key, p5.value);
    insert(ht, p6.key, p6.value);
    insert(ht, p7.key, p7.value);
    insert(ht, p8.key, p8.value);
    insert(ht, p9.key, p9.value);
    insert(ht, p10.key, p10.value);

    printHashTable(ht);

    erase(ht, p5.key);
    erase(ht, p6.key);
    erase(ht, p9.key);
    erase(ht, p6.key);

    printHashTable(ht);

    return 0;
}