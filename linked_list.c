#include <stdio.h>
#include <stdlib.h>

// Function declaration
void insert_at_begining();
void insert_at_end();
void insert_at_position();
void delete_from_begining();
void delete_from_end();
void delete_from_position();
int getlength();
void search();
void reverse();
void display();

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *head = NULL;
node *temp;
// head = NULL;

void insert_at_begining()
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    printf("\nEnter the data you want to insert\n");
    scanf("%d", &newnode->data);
    temp = head;
    newnode->next = temp;
    head = newnode;
}
void insert_at_end()
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    printf("\nEnter the data you want to insert\n");
    scanf("%d", &newnode->data);
    temp = head;
    while (temp->next != 0)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = NULL;
    temp = newnode; // lat added
}
void insert_at_position()
{

    int i = 1;
    int pos;
    int count = getlength();
    node *newnode;
    printf("Enter the position you want to insert:");
    scanf("%d", &pos);
    if (pos < 1 || pos > count)
    {
        printf("Invalid Position");
        return;
    }
    else
    {
        newnode = (node *)malloc(sizeof(node));
        printf("\nEnter the data you want to insert\n");
        scanf("%d", &newnode->data);
        temp = head;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        temp = newnode; // last added
    }
}
void delete_from_begining()
{
    if (head == 0)
    {
        printf("NULL!!\n");
    }
    else if (head->next == 0)
    {
        temp = head;
        head = 0;
    }
    else
    {
        temp = head;
        head = head->next;
    }
    free(temp);
}
void delete_from_end()
{
    node *prevnode;
    temp = head;
    while (temp->next != 0)
    {
        prevnode = temp;
        temp = temp->next;
    }
    if (temp == head)
    {
        head = NULL;
    }
    else
    {
        prevnode->next = NULL;
    }
    free(temp);
}
void delete_from_position()
{

    int pos;
    int i = 1;
    int count = getlength();
    node *nextnode;
    printf("Enter the position you want to delete\n :");
    scanf("%d", &pos);
    if (pos < 1 || pos > count)
    {
        printf("Invalid position\n");
        return;
    }
    else if (pos == 1)
    {
        delete_from_begining();
        free(nextnode);
    }
    else
    {
        temp = head;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
    }
    nextnode = temp->next;
    temp->next = nextnode->next;
    free(nextnode);
}
int getlength()
{
    int count = 0;
    temp = head;
    while (temp != 0)
    {
        count++;
        temp = temp->next;
    }
    printf("The Length is %d\n", count);
    return count;
}
void display()
{
    temp = head;
    while (temp != 0)
    {
        printf("\n%d\n", temp->data);
        temp = temp->next;
    }
}
void search()
{
    int pos = 1;
    int value;
    printf("\nEnter a value to search\n");
    scanf("%d", &value);
    temp = head;
    while (temp != 0)
    {
        if (temp->data == value)
        {
            printf("found %d data at %d position", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("\nValue Not Found\n");
}
void max_min()
{
    int max, min;
    if (head == 0)
    {
        printf("No Element in List\n");
    }
    else
    {
        temp = head;
        max = temp->data;
        min = temp->data;

        temp = temp->next;

        while (temp != NULL)
        {
            if (temp->data > max)
            {
                max = temp->data;
            }
            if (temp->data < min)
            {
                min = temp->data;
            }
            temp = temp->next;
        }
    }
    printf("The Maximum element is %d\n", max);
    printf("The Minimum element is %d\n", min);
}
void reverse()
{
    node *prevnode;
    node *currentnode;
    node *nextnode;
    prevnode = 0;
    currentnode = nextnode = head;
    while (nextnode != 0)
    {
        nextnode = nextnode->next;
        currentnode->next = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    }
    head = prevnode;
}
int main()
{
    int choice = 1;
    node *newnode;
    while (choice)
    {
        // CreateNode
        newnode = (node *)malloc(sizeof(node));
        printf("Enter data :\n");
        scanf("%d", &newnode->data);
        newnode->next = 0;

        if (head == 0)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Do you want to continue?(0/1)\n");
        scanf("%d", &choice);
    }
    printf("-------------Linked list Menu-------------\n");
    printf("\nWhich Operation you want to perform?\n");
    printf("\n1.Insert a Begining\n2.insert at end \n3.insert at position\n4.Display\n5.delete from begining\n6.delete from end\n7.delete from position\n8.Max/Min\n9.length\n10.search\n11.reverse\n");
    printf("\nEnter Choice\n");
    scanf("%d", &choice);
    printf("\n------------\n");
    switch (choice)
    {
    case 1:
        insert_at_begining();
        display();
        break;
    case 2:
        insert_at_end();
        display();
        break;
    case 3:
        insert_at_position();
        display();
        break;
    case 4:
        display();
        break;
    case 5:
        delete_from_begining();
        display();
        break;
    case 6:
        delete_from_end();
        display();
        break;
    case 7:
        delete_from_position();
        display();
        break;
    case 8:
        max_min();
        break;
    case 9:
        getlength();
        break;
    case 10:
        search();
        display();
        break;
    case 11:
        reverse();
        display();
        break;
    default:
        printf("\ninvalid Choice\n");
    }
    return 0;
}