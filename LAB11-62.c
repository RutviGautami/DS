#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *adrs;
};

struct node *createlist(int n)
{
    struct node *first = NULL;
    struct node *save = NULL;
    struct node *temp = NULL;
    for (int i = 0; i < n; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter element %d: ", i + 1);
        scanf("%d", &(temp->info));
        temp->adrs = NULL;
        if (first == NULL)
        {
            first = temp;
            save = first;
        }
        else
        {
            save->adrs = temp;
            save = temp;
        }
        temp = NULL;
    }
    return first;
}

// working like save->pred->nextelements
// then free pred  and given address of pred to address of save
struct node *removeduplicate(struct node *first)
{
    struct node *save = first;
    while (save != NULL)
    {
        struct node *pred = save;
        struct node *check = pred->adrs;
        while (check != NULL)
        {
            if (save->info == check->info)
            {
                pred->adrs = check->adrs;
                free(check);
                check = pred->adrs;
            }
            else
            {
                pred = check;
                check = check->adrs;
            }
        }
        save = save->adrs;
    }
    return first;
}

int main()
{
    int n;
    printf("Enter size of list: ");
    scanf("%d", &n);
    struct node *list1 = NULL;
    printf("enter elements of list\n");
    list1 = createlist(n);
    list1 = removeduplicate(list1);
    struct node *save = list1;
    while (save != 0)
    {
        printf("%d,", save->info);
        save = save->adrs;
    }
}