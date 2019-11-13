#ifndef DATA_PAIR_H
#define DATA_PAIR_H

typedef struct DataPair
{
    int key;
    int value;
    struct DataPair* next;
} DataPair;

void copyDataPair(DataPair from, DataPair* to);

#endif