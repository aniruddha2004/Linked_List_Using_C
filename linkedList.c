#include <stdio.h>
#include <stdlib.h>

#define p printf
#define s scanf

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void push(int position)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    int data;
    p("\n\nEnter the data to be inserted\n");
    s("%d", &data);
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        if (position != 1)
        {
            p("The data cannot be stored in that position because there are empty positions available before it\n\n");
            return;
        }
        head = newNode;
    }
    else
    {
        struct node *current = head;
        for (int i = 1; i < position; i++)
        {
            if (current->next == NULL && i != (position - 1))
            {
                p("The data cannot be stored in that position because there are empty positions available before it\n\n");
                return;
            }
            current = current->next;
        }
        if (current->next == NULL)
        {
            current->next = newNode;
        }
        else
        {
            struct node *duplicate = current->next;
            current->next = newNode;
            current->next->next = duplicate;
        }
    }
    p("The insertion is successful\n\n");
}

void pop()
{
    if (head == NULL)
    {
        p("\n\nThe list is empty\n\n");
    }
    else
    {
        struct node *current = head;
        while (current->next->next != NULL)
        {
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
        p("\n\nThe deletion is successful\n\n");
    }
}

void display()
{
    struct node *current = head;
    p("\n\nThe list is : \n");
    while (current->next != NULL)
    {
        p("%d\t", current->data);
        current = current->next;
    }
    p("%d\n\n", current->data);
}

int main()
{

    while (1)
    {
        p("Enter 1 to perform input or output operations\nEnter 2 to perform sorting operations\nEnter 3 to perform searching operations\nEnter 4 to exit\nEnter your choice\n");
        int ch;
        s("%d", &ch);
        switch (ch)
        {
        case 1:
            p("Enter 1 to insert an element\nEnter 2 to delete an element\nEnter 3 to display the list\nEnter your choice\n");
            s("%d", &ch);
            switch (ch)
            {
            case 1:
                p("Enter the position for insertion\n");
                int position;
                scanf("%d", &position);
                push(position);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            default:
                p("Wrong Entry. Please try again.\n");
            }
            break;

        case 4:
            p("Thank you for using our application");
            exit(0);

        default:
            p("Wrong Entry! Please try again");
        }
    }
}