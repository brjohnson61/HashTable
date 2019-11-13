#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashTable.h"
#include "DataPair.h"

bool insertDataPair(HashTable h, DataPair dp);

bool insertAtBeginning(HashTable h, DataPair dp){
    int index = hashCode(h, dp.key);
    h.table[index] = (DataPair*)malloc(sizeof(DataPair));
    if(h.table[index] == NULL){
        return false;
    }
    copyDataPair(dp, h.table[index]);
    return true;
}

bool insert(HashTable h, int key, int value){
    DataPair dp = {.key=key, .value=value};
    return insertDataPair(h, dp);
}

bool insertDataPair(HashTable h, DataPair dp){
    int index = hashCode(h, dp.key);
    if(contains(h, dp.key)){
        if(getValue(h, dp.key) != dp.value){
            erase(h, dp.key);
            return insertDataPair(h, dp);
        }
    }else{
        if(h.table[index] == NULL){
            insertAtBeginning(h, dp);
        }else{
            DataPair* head = h.table[index];
            while(head->next != NULL){
                head = head->next;
            }
            head->next = (DataPair*)malloc(sizeof(DataPair));
            if(head->next == NULL){
                return false;
            }
            copyDataPair(dp, head->next);
        }
    }
    return true;
}

int hashCode(HashTable h, int key){
    return key % h.size;
}

void printHashTable(HashTable h){
    for(int i=0; i<h.size; i++){
        printf("index %d:", i);
        DataPair* head = h.table[i];
        while(head != NULL){
            printf(" key=%d value=%d ->", head->key, head->value);
            head = head->next;
        }
        printf("\n");
    }
    printf("\n");
}

bool erase(HashTable h, int key){
    int index = hashCode(h, key);
    DataPair* head = h.table[index];
    //Head is null, return immediately.
    if(h.table[index] == NULL){
        return false;
    }
    //Head is not null and element is the first one.
    if(h.table[index]->key == key){
        h.table[index] = h.table[index]->next;
        head->next = NULL;
        free(head);
        head = NULL;
        return true;
    }
    //Key to delete is not the first 
    //element and head is not null
    while(head->next != NULL){
        if(head->next->key == key){
            DataPair* tempToDelete = head->next;
            head->next = head->next->next;
            tempToDelete->next = NULL;
            tempToDelete->key = 0;
            tempToDelete->value = 0;
            free(tempToDelete);
            tempToDelete = NULL;
            return true;
        }else{
            head = head->next;
        }
    }
    //Element was not found
    return false;
}

bool contains(HashTable h, int key){
    int index = hashCode(h, key);
    if(h.table[index] == NULL){
        return false;
    }else{
        DataPair* head = h.table[index];
        while(head != NULL){
            if(head->key == key){
                return true;
            }
            head = head->next;
        }
        return false;
    }
}

int getValue(HashTable h, int key){
    int index = hashCode(h, key);
    if(h.table[index] != NULL){
        DataPair* head = h.table[index];
        while(head != NULL){
            if(head->key == key){
                return head->value;
            }
            head = head->next;
        }
    }
    return 0;
}