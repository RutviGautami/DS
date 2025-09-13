#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song {
    char name[100];
    struct song *next;
    struct song *prev;
};
 
struct song *firstsong = NULL;
struct song *lastsong = NULL;
struct song *temp = NULL;
struct song *currentSong = NULL;

void Addsong() {
    char title[100];
    printf("Enter title of song you want to add: ");
    fgets(title, sizeof(title), stdin);
    if (fgets(title, sizeof(title), stdin) == NULL) {
        printf("Error reading input.\n");
        return;
    }
    title[strcspn(title, "\n")] = '\0';//take string till \n then \0

    struct song *newsong = (struct song *)malloc(sizeof(struct song));
    if (newsong == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    strcpy(newsong->name, title);
    newsong->next = NULL;
    newsong->prev = NULL;

    if (firstsong == NULL) {
        firstsong = lastsong = newsong;
        currentSong = firstsong;
    } else {
        lastsong->next = newsong;
        newsong->prev = lastsong;
        lastsong = newsong;
    }

    printf("Added song: %s\n", newsong->name);
}

void deletesong() {
    char title[100];
    printf("Enter title of song you want to delete: ");
    fgets(title, sizeof(title), stdin);
    if (fgets(title, sizeof(title), stdin) == NULL) {
        printf("Error reading input.\n");
        return;
    }
    title[strcspn(title, "\n")] = '\0';   //input string till \n

    if (firstsong == NULL) {
        printf("Playlist is empty.\n");
        return;
    }

    temp = firstsong;

    if (strcmp(title, firstsong->name) == 0) {
        struct song *toDelete = firstsong;
        firstsong = firstsong->next;
        if (firstsong != NULL)
            firstsong->prev = NULL;
        else
            lastsong = NULL;
        if (currentSong == toDelete) currentSong = firstsong;
        free(toDelete);
        printf("Deleted successfully\n");
        return;
    }

    if (strcmp(title, lastsong->name) == 0) {
        struct song *toDelete = lastsong;
        lastsong = lastsong->prev;
        if (lastsong != NULL)
            lastsong->next = NULL;
        else
            firstsong = NULL;
        if (currentSong == toDelete) currentSong = lastsong;
        free(toDelete);
        printf("Deleted successfully\n");
        return;
    }

    while (temp != NULL && strcmp(title, temp->name) != 0) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Song not found\n");
    } else {
        if (temp->prev != NULL)
            temp->prev->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;
        if (currentSong == temp) currentSong = temp->next != NULL ? temp->next : temp->prev;
        free(temp);
        printf("Deleted successfully\n");
    }
}

void displayPlaylist() {
    temp = firstsong;
    printf("Forward: ");
    while (temp != NULL) {
        printf("%s ", temp->name);
        temp = temp->next;
    }
    temp = lastsong;
    printf("\nBackward: ");
    while (temp != NULL) {
        printf("%s\n", temp->name);
        temp = temp->prev;
    }
    printf("\n");
}

void playNext() {
    if (currentSong && currentSong->next) {
        currentSong = currentSong->next;
        printf("Playing: %s\n", currentSong->name);
    } else {
        printf("No next song.\n");
    }
}

void playPrevious() {
    if (currentSong && currentSong->prev) {
        currentSong = currentSong->prev;
        printf("Playing: %s\n", currentSong->name);
    } else {
        printf("No previous song.\n");
    }
}

void menu() {
    printf("\nMusic Player Options:\n");
    printf("1. Add Song\n");
    printf("2. Delete Song\n");
    printf("3. Display Playlist\n");
    printf("4. Play Next\n");
    printf("5. Play Previous\n");
    printf("6. Exit\n");
}

int main() {
    int choice;

    do {
        menu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                Addsong();
                break;
            case 2:
                deletesong();
                break;
            case 3:
                displayPlaylist();
                break;
            case 4:
                playNext();
                break;
            case 5:
                playPrevious();
                break;
            case 6:
                printf("Exiting Music Player...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);

    while (firstsong != NULL) {
        temp = firstsong;
        firstsong = firstsong->next;
        free(temp);
    }

    return 0;
}
