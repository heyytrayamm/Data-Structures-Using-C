#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *newnode;
node *tail = NULL;
node *temp = NULL;
void display()
{
    if (tail == NULL)
    {
        printf("\nList is Empty !!\n");
    }
    else
    {
        temp = tail->next;
        printf("%d", temp->data);
        temp = temp->next;
        while (temp != tail->next)
        {
            printf("\n%d\n", temp->data);
            temp = temp->next;
        }
    }
}
int length()
{
    int count = 0;
    if (tail == NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        count = 1;
        temp = tail->next;
        while (temp != tail)
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
    newnode->data;
    newnode->next = NULL;
    printf("\n Enter the data to insert");
    scanf("%d", &newnode->data);
    if (tail == 0)
    {
        tail = newnode;
        tail->next = newnode;
    }
    else
    {
        newnode->next = tail->next;
        tail->next = newnode;
    }
} 

void insert_at_end()
{
    newnode = (node *)malloc(sizeof(node));
    newnode->data;
    newnode->next = NULL;
    printf("\n Enter the data to insert");
    scanf("%d", &newnode->data);
    if (tail == 0)
    {
        tail = newnode;
        tail->next = newnode;
    }
    else
    {
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
}

void insert_at_position()
{
    int pos;
    int count = length();
    int i = 1;
    printf("Enter the position you want to insert??");
    scanf("%d", &pos);
    if (pos < 1 || pos > count)
    {
        printf("Invalid Position\n");
    }
    else if (pos == 1)
    {
        insert_at_begining();
    }
    else
    {

        temp = tail->next;
        newnode = (node *)malloc(sizeof(node));
        newnode->data;
        newnode->next = NULL;
        printf("\n Enter the data to insert");
        scanf("%d", &newnode->data);
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void delete_from_begining()
{
    temp = tail->next;
    if (tail == NULL)
    {
        printf("List is Empty\n");
    }
    else if (temp == tail)
    {
        tail = 0;
        free(temp);
    }

    else
    {

        tail->next = temp->next;
        free(temp);
    }
}

void delete_from_end()
{
    node *currentnode = NULL;
    node *prevnode = NULL;
    currentnode = tail->next;
    if (tail == NULL)
    {
        printf("List is empty\n");
    }
    else if (currentnode == tail)
    {
        tail = NULL;
        free(currentnode);
    }
    else
    {
        currentnode = tail->next;

        while (currentnode->next != tail->next)
        {
            prevnode = currentnode;
            currentnode = currentnode->next;
        }
        prevnode->next = tail->next;
        tail = prevnode;
        free(currentnode);
    }
}

void delete_from_position()
{

    int pos;
    int count = length();
    int i = 1;
    node *currentnode = NULL;
    node *nextnode = NULL;
    printf("Enter the position from which you want to Delete??\n");
    scanf("%d", &pos);
    if (pos < 1 || pos > count)
    {
        printf("Invalid Position\n");
    }
    else if (pos == 1)
    {
        delete_from_begining();
    }
    else
    {
        currentnode = tail->next;
        while (i < pos - 1)
        {
            currentnode = currentnode->next;
            i++;
        }
        nextnode = currentnode->next;
        currentnode->next = nextnode->next;
        free(nextnode);
    }
}
void reverse()
{
    node *prevnode;
    node *currentnode;
    node *nextnode;
    currentnode = tail->next;
    nextnode = currentnode->next;

    if (tail == 0)
    {
        printf("list is Empty\n");
        return;
    }
    
    else if (currentnode->next == currentnode)
    {
        printf("Single element in the list!!\n");
    }
    else
    {
        while (currentnode != tail)
        {
            prevnode = currentnode;
            currentnode = nextnode;
           // currentnode = prevnode->next;
            nextnode = currentnode->next;
            currentnode->next = prevnode;
        }
        nextnode->next = tail;
        tail = nextnode;
    }
}

void search()
{
    int value;
    int pos = 1;
    printf("Enter the value you want to search?");
    scanf("%d", &value);
    if (tail == NULL)
    {
        printf("List is empty !!\n");
    }

    temp = tail->next;
    do
    {
        if (temp->data == value)
        {
            printf("found the value %d at %d\n", value, pos);
            return;
        }

        temp = temp->next;
        pos++;
    } while (temp != tail->next);
    printf("Value not Found !!\n");
}
int main()
{
    int choice = 1;
    while (choice)
    {
        newnode = (node *)malloc(sizeof(node));
        newnode->data;
        newnode->next = NULL;
        printf("Enter the data to insert :");
        scanf("%d", &newnode->data);

        if (tail == 0)
        {
            tail = newnode;
            tail->next = newnode;
        }
        else
        {
            newnode->next = tail->next;
            tail->next = newnode;
            tail = newnode;
        }
        printf("Do you want to Continue?(1/0)\n");
        scanf("%d", &choice);
    }
    printf("-------------Linked list Menu-------------\n");
    printf("\nWhich Operation you want to perform?\n");
    printf("\n1.Insert a Begining\n2.insert at end \n3.insert at position\n4.Display\n5.delete from begining\n6.delete from end\n7.delete from position\n8.length\n9.search\n10.reverse\n");
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
        length();
        break;
    case 9:
        search();
        break;
    case 10:
        reverse();
        display();
        break;
    default:
        printf("\ninvalid Choice\n");
    }
    return 0;
}