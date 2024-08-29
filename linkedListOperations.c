#include<stdio.h>
#include<stdlib.h>

struct node {
int data;
struct node* next;
};

void addAtBegin();
void append();
void addAfter();
void delete();
void reverse();
void display();
void displayReverse();
void selectionSort();
void bubbleSort();
int count();

struct node* head = NULL;

int main()
{
int ch;
printf("Enter 1 if you want to add at begin\n");
printf("Enter 2 if you want to add append\n");
printf("Enter 3 if you to add after\n");
printf("Enter 4 to delete a number from the list\n");
printf("Enter 5 to reverse the list\n");
printf("Enter 6 to display the total elements list\n");
printf("Enter 7 to display the list in reverse\n");
printf("Enter 8 if you want to exit\n");
while(1)
{
printf("Enter your choice\n");
scanf("%d", &ch);
switch(ch)
{
case 1 : 
addAtBegin();
break;

case 2 : 
append();
break;

case 3 : 
addAfter();
break;

case 4 :
delete();
break;

case 5 :
reverse();
break;

case 6 :
selectionSort();
break;

case 7 :
bubbleSort();
break;

case 8 : 
display();
break;

case 9 :
displayReverse();
break;

case 10 : 
exit(0);

default : 
printf("Wrong entry. Please Enter Valid choice\n");
}
printf("The size = %d\n", count());
}
return 0;
}

void addAtBegin()
{
struct node* nw = (struct node*)malloc(sizeof(struct node));
int num;
printf("Enter the data to be inserted\n");
scanf("%d", &nw->data);
nw->next = head;
head = nw;
}

void append()
{
struct node* nw = (struct node*)malloc(sizeof(struct node));
int num;
printf("Enter the data to be inserted\n");
scanf("%d", &num);
nw->data = num;
if(head == NULL)
{
nw->next = head;
head = nw;
}
else
{
struct node* current = head;
while(current->next != NULL)
current = current->next;
nw->next = NULL;
current->next = nw;
}
}

void addAfter()
{
if(head!=NULL)
{
struct node* nw = (struct node*)malloc(sizeof(struct node));
int num, pos;
printf("Enter the data to be inserted\n");
scanf("%d", &num);
nw->data = num;
printf("Enter the position after which the data will be inserted\n");
scanf("%d", &pos);
struct node* current = head;
for(int i = 1; i < pos; i++)
{
current = current -> next;
if(current->next == NULL)
{
printf("The list is not that long\n");
return;
}
}
nw->next = current->next;
current->next = nw;
}
else
printf("The list is empty\n");
}

void display()
{
if(head==NULL)
{
printf("The list is empty\n");
return;
}
struct node* current = head;
while(current != NULL)
{
printf("%d\t", current->data);
current = current -> next;
}
printf("\n");
}

void delete()
{
if(head==NULL)
{
printf("The list is empty\n");
return;
}
struct node * current = head, * old = head;
int num;        
printf("Enter the number to be deleted\n");
scanf("%d", &num);
while(current!=NULL)
{
if(current->data == num)
{
if(current == head)
head = current->next;
else
old->next = current->next;
free(current);
return;
}
old = current;
current = current->next;
}
printf("The number cannot be found\n");
}

void displayReverse()
{
if(head==NULL)
{
printf("The list is empty\n");
return;
}
struct node * current = head;
int size = count(), arr[size];
while(current != NULL)
{
size--;
arr[size] = current->data;
current = current->next;
}
printf("The list in reverse : \n");
for(int i = 0; i < count(); i++)
printf("%d\t", arr[i]);
printf("\n");
}

void reverse()
{
if(head == NULL)
{
printf("The list is empty\n");
return;
}
else if(head->next == NULL)
{
printf("There is only one element, nothing to reverse\n");
return;
}
struct node * temp = head, * old = head, * current = temp->next;
while(current!=NULL)
{
head = current;
current = head -> next;
head->next = temp;
old->next = current;
temp = head;
}
printf("The list is reversed\n");
}

void selectionSort() {
    int size = count();
    struct node* current = head;
    struct node* temp;
    for (int i = 0; i < size - 1; i++) {
        struct node* minNode = current;
        struct node* temp = current->next;
        while (temp != NULL) {
            if (temp->data < minNode->data) {
                minNode = temp;
            }
            temp = temp->next;
        }
        if (minNode != current) {
            current->data+= minNode->data;
            minNode->data = current->data - minNode->data ;
            current->data-=minNode->data;
        }
        current = current->next;
    }
    printf("List sorted using Selection Sort\n");
}

void bubbleSort() {
    int size = count();
    struct node* current;
    struct node* nextNode = NULL;
    for (int i = 0; i < size - 1; i++) {
        current = head;
        nextNode = current->next;
        for (int j = 0; j < size - i - 1; j++) {
            if (current->data > nextNode->data) {
                int tempData = current->data;
                current->data = nextNode->data;
                nextNode->data = tempData;
            }
            current = current->next;
            nextNode = nextNode->next;
        }
    }
    printf("List sorted using Bubble Sort\n");
}


int count()
{
struct node * current = head;
int size = 0;
while(current != NULL)
{
current = current->next;
size++;
}
return size;
}

