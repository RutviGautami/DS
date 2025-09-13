#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coef;          
    int exp;           
    struct Node *next; 
};

struct Node *createNode(int coef, int exp)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node **head, int coef, int exp)
{
    struct Node *newNode = createNode(coef, exp);
    if (*head == NULL || (*head)->exp < exp)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL && temp->next->exp >= exp)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

struct Node *addPolynomials(struct Node *poly1, struct Node *poly2)
{
    struct Node *result = NULL;
    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->exp > poly2->exp)
        {
            insertNode(&result, poly1->coef, poly1->exp);
            poly1 = poly1->next;
        }
        else if (poly1->exp < poly2->exp)
        {
            insertNode(&result, poly2->coef, poly2->exp);
            poly2 = poly2->next;
        }
        else
        {
            int sumCoef = poly1->coef + poly2->coef;
            if (sumCoef != 0)
            {
                insertNode(&result, sumCoef, poly1->exp);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL)
    {
        insertNode(&result, poly1->coef, poly1->exp);
        poly1 = poly1->next;
    }
    while (poly2 != NULL)
    {
        insertNode(&result, poly2->coef, poly2->exp);
        poly2 = poly2->next;
    }
    return result;
}

void displayPolynomial(struct Node *poly)
{
    if (poly == NULL)
    {
        printf("0\n");
        return;
    }
    while (poly != NULL)
    {
        printf("%dx^%d", poly->coef, poly->exp);
        if (poly->next != NULL && poly->next->coef > 0)
        {
            printf(" + ");
        }
        poly = poly->next;
    }
    printf("\n");
}

int main()
{
    struct Node *poly1 = NULL;
    struct Node *poly2 = NULL;

    insertNode(&poly1, 5, 3);
    insertNode(&poly1, 4, 2);
    insertNode(&poly1, 2, 0);

    insertNode(&poly2, 5, 1);
    insertNode(&poly2, 5, 0);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    struct Node *result = addPolynomials(poly1, poly2);

    printf("Sum of polynomials: ");
    displayPolynomial(result);

    return 0;
}
