#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} node;

node *head = NULL;
node *tail = NULL;
node *temp;
node *newnode;

void display()
{
    temp = head;
    if (temp == 0)
    {
        printf("list is Empty !!");
        return;
    }
    else
    {
        while (temp != 0)
        {
            printf("\n%d\n", temp->data);
            temp = temp->next;
        }
    }
}
int length()
{
    int count = 0;
    temp = head;
    if (head == 0)
    {
        printf("LIST IS EMPTY !!\n");
    }
    else
    {

        while (temp != 0)
        {
            count++;
            temp = temp->next;
        }
    }
    printf("Length of the Linkedlist is %d\n", count);
    return count;
}
void insert_at_begining()
{
    newnode = (node *)malloc(sizeof(node));
    printf("Enter data you want to insert :\n");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}
void insert_at_end()
{
    newnode = (node *)malloc(sizeof(node));
    printf("Enter data you want to insert :\n");
    scanf("%d", &newnode->data);
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}
void insert_at_position()
{
    int pos;
    int i = 1;
    int count = length();
    printf("Enter the position you want to insert");
    scanf("%d", &pos);
    if (pos < 1 || pos > count)
    {
        printf("Invalid Position !!\n");
        return;
    }
    else if (pos == 1)
    {
        insert_at_begining();
        return;
    }
    else
    {
        newnode = (node *)malloc(sizeof(node));
        printf("Enter data you want to insert :\n");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;
        temp = head;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next->prev = newnode;
        temp->next = newnode;
        /*we can write this logic also in this way
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
        newnode->next->prev = newnode;*/
    }
}
void insert_after_position()
{
    int pos;
    int i = 1;
    int count = length();
    printf("Enter the position you want to insert");
    scanf("%d", &pos);
    if (pos < 1 || pos > count)
    {
        printf("Invalid Position !!\n");
        return;
    }
    else
    {
        newnode = (node *)malloc(sizeof(node));
        printf("Enter data you want to insert :\n");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;
        temp = head;
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next->prev = newnode;
        temp->next = newnode;
        /*we can write this logic also in this way
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
        newnode->next->prev = newnode;*/
    }
}
void delete_from_begining()
{
    if (head == 0)
    {
        printf("List is empty\n");
    }
    else if (head == tail)
    {
        head = tail = NULL;
        free(temp);
    }

    else
    {
        temp = head;
        head = temp->next;
        head->prev = NULL;
        free(temp);
    }
}
void delete_from_end()
{
    if (tail == 0)
    {
        printf("LIST IS EMPTY !!");
        return;
    }

    temp = tail;
    if (head == tail)
    {
        head = tail = NULL;
        free(temp);
    }
    else
    {
        tail = tail->prev;
        tail->next = NULL;
        free(temp);
        /*we can write is also by
        tail->next = NULL;
        tail->pre->next = NULL;
        free(temp);
        */
    }
}
void delete_from_position()
{
    int pos;
    int i = 1;
    int count = length();
    printf("Enter the position you want to insert\n");
    scanf("%d", &pos);
    if (pos < 1 || pos > count)
    {
        printf("Invalid Position !!\n");
        return;
    }
    else if (pos == 1)
    {
        delete_from_begining();
        return;
    }
    else
    {
        temp = head;
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}
void reverse()
{
    node *currentnode = NULL;
    node *nextnode = NULL;
    if (head == NULL)
    {
        printf("INvalid \n");
    }
    else
    {
        temp = head;
        currentnode = head;
        while (currentnode != NULL)
        {
            nextnode = currentnode->next;
            currentnode->next = currentnode->prev;
            currentnode->prev = nextnode;
            currentnode = nextnode;
        }
        currentnode = head;
        head = tail;
        tail = currentnode;
    }
}
void search()
{
    int pos = 1;
    temp = head;
    int value;
    printf("Enter value : \n");
    scanf("%d", &value);
    while (temp != 0)
    {
        if (temp->data == value)
        {
            printf("THE VALUE %d IS FOUND AT %d", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
        }
    printf("The data is not found !!\n");
}
int main()
{

    node *newnode;

    int choice = 1;
    while (choice)
    {
        newnode = (node *)malloc(sizeof(node));
        printf("Enter data you want to insert :\n");
        scanf("%d", &newnode->data);
        newnode->prev = NULL;
        newnode->next = NULL;
        if (head == 0)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }

        printf("Do You want to continue?(1/0)");
        scanf("%d", &choice);
    }
    printf("-------------Linked list Menu-------------\n");
    printf("\nWhich Operation you want to perform?\n");
    printf("\n1.Insert a Begining\n2.insert at end \n3.insert at position\n4.insert after position\n 5.Display\n6.delete from begining\n7.delete from end\n8.delete from position\n9.length\n10.search\n11.reverse\n");
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
        insert_after_position();
        display();
        break;
    case 5:
        display();
        break;
    case 6:
        delete_from_begining();
        display();
        break;
    case 7:
        delete_from_end();
        display();
        break;
    case 8:
        delete_from_position();
        display();
        break;
    case 9:
        length();
        break;
    case 10:
        search();
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