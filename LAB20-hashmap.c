#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 100

typedef struct Node {
    char key[KEY_SIZE];
    int value;
    struct Node* next;
} Node;

typedef struct HashMap {
    int size;
    Node** buckets;
} HashMap;

int hash(char* key, int size) {
    int hash = 0;
    for (int i = 0; key[i]; i++) {
        hash = (hash * 31 + key[i]) % size;
    }
    return hash;
}

Node* createNode(char* key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->key, key);
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

HashMap* createHashMap(int size) {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    map->size = size;
    map->buckets = (Node**)calloc(size, sizeof(Node*));
    return map;
}

void insert(HashMap* map, char* key, int value) {
    int index = hash(key, map->size);
    Node* head = map->buckets[index];

    while (head) {
        if (strcmp(head->key, key) == 0) {
            head->value = value;
            return;
        }
        head = head->next;
    }

    Node* newNode = createNode(key, value);
    newNode->next = map->buckets[index];
    map->buckets[index] = newNode;
}

int search(HashMap* map, char* key) {
    int index = hash(key, map->size);
    Node* head = map->buckets[index];

    while (head) {
        if (strcmp(head->key, key) == 0) {
            return head->value;
        }
        head = head->next;
    }

    return -1;
}

void delete(HashMap* map, char* key) {
    int index = hash(key, map->size);
    Node* head = map->buckets[index];
    Node* prev = NULL;

    while (head) {
        if (strcmp(head->key, key) == 0) {
            if (prev) {
                prev->next = head->next;
            } else {
                map->buckets[index] = head->next;
            }
            free(head);
            printf("Deleted key: %s\n", key);
            return;
        }
        prev = head;
        head = head->next;
    }

    printf("Key not found: %s\n", key);
}

void display(HashMap* map) {
    for (int i = 0; i < map->size; i++) {
        printf("Bucket %d: ", i);
        Node* head = map->buckets[i];
        while (head) {
            printf("(%s: %d) -> ", head->key, head->value);
            head = head->next;
        }
        printf("NULL\n");
    }
}

void freeHashMap(HashMap* map) {
    for (int i = 0; i < map->size; i++) {
        Node* head = map->buckets[i];
        while (head) {
            Node* temp = head;
            head = head->next;
            free(temp);
        }
    }
    free(map->buckets);
    free(map);
}

int main() {
    int size;
    printf("Enter size of HashMap: ");
    scanf("%d", &size);
    getchar(); // consume newline

    HashMap* map = createHashMap(size);

    int choice;
    char key[KEY_SIZE];
    int value;

    do {
        printf("\n--- HashMap Menu ---\n");
        printf("1. Insert key-value\n");
        printf("2. Search key\n");
        printf("3. Delete key\n");
        printf("4. Display HashMap\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter key: ");
                fgets(key, KEY_SIZE, stdin);
                key[strcspn(key, "\n")] = '\0';
                printf("Enter value: ");
                scanf("%d", &value);
                getchar();
                insert(map, key, value);
                break;

            case 2:
                printf("Enter key to search: ");
                fgets(key, KEY_SIZE, stdin);
                key[strcspn(key, "\n")] = '\0';
                value = search(map, key);
                if (value != -1)
                    printf("Value for '%s': %d\n", key, value);
                else
                    printf("Key '%s' not found\n", key);
                break;

            case 3:
                printf("Enter key to delete: ");
                fgets(key, KEY_SIZE, stdin);
                key[strcspn(key, "\n")] = '\0';
                delete(map, key);
                break;

            case 4:
                display(map);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    freeHashMap(map);
    return 0;
}