
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define HASH_TABLE_SIZE 101  
#define MAX_KEY_LEN   64
#define MAX_VALUE_LEN 128

typedef struct Entry {
    char key[MAX_KEY_LEN];
    char value[MAX_VALUE_LEN];
    struct Entry *next;
} Entry;

typedef struct Dictionary {
    Entry *buckets[HASH_TABLE_SIZE];
    int size;  
} Dictionary;

int hash(const char *key) {
    long hash = 5381;
    int c;
    while ((c = *key++)) {
        hash = ((hash << 5) + hash) + c;  // hash * 33 + c
    }
    return (unsigned int)(hash % HASH_TABLE_SIZE);
}

Dictionary *dict_create() {
    Dictionary *dict = malloc(sizeof(Dictionary));
    if (!dict) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        dict->buckets[i] = NULL;
    }
    dict->size = 0;
    return dict;
}

void dict_insert(Dictionary *dict, const char *key, const char *value) {
    unsigned int bucket_index = hash(key);
    Entry *current = dict->buckets[bucket_index];
    
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) { 
            strncpy(current->value, value, MAX_VALUE_LEN - 1);
            current->value[MAX_VALUE_LEN - 1] = '\0';
            return;
        }
        current = current->next;
    }
    
    Entry *new_entry = malloc(sizeof(Entry));
    if (!new_entry) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strncpy(new_entry->key, key, MAX_KEY_LEN - 1);
    new_entry->key[MAX_KEY_LEN - 1] = '\0';
    strncpy(new_entry->value, value, MAX_VALUE_LEN - 1);
    new_entry->value[MAX_VALUE_LEN - 1] = '\0';
    new_entry->next = dict->buckets[bucket_index];
    dict->buckets[bucket_index] = new_entry;
    dict->size++;
}

// Lookup value by key
// Returns pointer to value (in dictionary) if found, NULL otherwise
const char *dict_lookup(Dictionary *dict, const char *key) {
    unsigned int bucket_index = hash(key);
    Entry *current = dict->buckets[bucket_index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return NULL;
}

// Delete a key-value pair
bool dict_delete(Dictionary *dict, const char *key) {
    unsigned int bucket_index = hash(key);
    Entry *current = dict->buckets[bucket_index];
    Entry *prev = NULL;
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            // Remove current
            if (prev == NULL) {
                // head of list
                dict->buckets[bucket_index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            dict->size--;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;  // not found
}

// Print all entries
void dict_print(Dictionary *dict) {
    printf("Dictionary contents (size = %d):\n", dict->size);
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        Entry *current = dict->buckets[i];
        if (current) {
            printf("Bucket %d:\n", i);
            while (current != NULL) {
                printf("    Key: '%s' -> Value: '%s'\n", current->key, current->value);
                current = current->next;
            }
        }
    }
}

// Destroy the dictionary, free memory
void dict_destroy(Dictionary *dict) {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        Entry *current = dict->buckets[i];
        while (current != NULL) {
            Entry *next = current->next;
            free(current);
            current = next;
        }
    }
    free(dict);
}

// ------ Example Usage ---------

int main() {
    Dictionary *myDict = dict_create();
    
    dict_insert(myDict, "apple", "A sweet red or green fruit");
    dict_insert(myDict, "banana", "Long yellow fruit");
    dict_insert(myDict, "orange", "Citrus fruit");
    
    // Update existing
    dict_insert(myDict, "banana", "Soft yellow fruit");
    
    const char *v;
    v = dict_lookup(myDict, "banana");
    if (v) {
        printf("banana -> %s\n", v);
    } else {
        printf("banana not found\n");
    }
    
    v = dict_lookup(myDict, "cherry");
    if (v) {
        printf("cherry -> %s\n", v);
    } else {
        printf("cherry not found\n");
    }
    
    dict_delete(myDict, "orange");
    
    dict_print(myDict);
    
    dict_destroy(myDict);
    return 0;
}
