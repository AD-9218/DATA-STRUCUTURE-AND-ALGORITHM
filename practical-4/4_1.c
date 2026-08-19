#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

struct Node *head = NULL;

struct Node *create(int n)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = n;
    temp->link = NULL;

    return temp;
}

void display()
{
    printf("Patient queue: ");
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

void insert_front()
{
    int n;

    printf("Enter Patient Token Number: ");
    scanf("%d", &n);
    struct Node *temp1;
    temp1 = create(n);

    if (head == NULL)
    {
        head = temp1;
    }
    else
    {
        temp1->link = head;
        head = temp1;
    }

    display();
}

void insert_end()
{
    int n;

    printf("Enter Patient Token Number: ");
    scanf("%d", &n);

    struct Node *temp = create(n);

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        struct Node *temp1 = head;

        while (temp1->link != NULL)
        {
            temp1 = temp1->link;
        }

        temp1->link = temp;
    }

    display();
}

void insert_position(int x)
{
    int n;
    printf("Enter Patient Token Number: ");
    scanf("%d", &n);

    struct Node *temp = create(n);

    if (head != NULL && head->data == x)
    {
        temp->link = head;
        head = temp;
        display();
        return;
    }

    struct Node *trav = head;

    while (trav != NULL && trav->link != NULL && trav->link->data != x)
    {
        trav = trav->link;
    }

    if (trav == NULL || trav->link == NULL)
    {
        printf("Token not found!\n");
        free(temp);
        return;
    }

    temp->link = trav->link;
    trav->link = temp;

    display();
}

int main()
{
    int no = 2;
    do
    {
        printf("----------------------------");
        printf("\n1.Critical\n2.Priority\n3.Occasionally\n4.exit");
        printf("----------------------------\n");
        printf("Enter any number: ");
        scanf("%d", &no);

        int x;
        switch (no)
        {
        case 1:
            insert_front();
            break;

        case 2:
            printf("Which token before patient get priority: ");
            scanf("%d", &x);
            insert_position(x);
            break;

        case 3:
            insert_end();
            break;

        default:
            printf("no Patient Found.....");
        }

    } while (no <= 3 && no > 0);

    return 0;
}