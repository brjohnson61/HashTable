#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdbool.h>
#include "DataPair.h"

typedef struct HashTable
{
    DataPair** table;
    int size;
} HashTable;

bool insert(HashTable h, int key, int value);

bool erase(HashTable h, int key);

int hashCode(HashTable h, int key);

bool contains(HashTable h, int key);

int getValue(HashTable h, int key);

void printHashTable(HashTable h);

#endif