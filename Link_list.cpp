// Implementation of Singly Link list
/* 
Operations in the written code are:
Traversal
Creation of Linklist
Insertion
  Insertion at beginning
  Insertion at the position
  Insertion at the end
Deletion
  Deletion at beginning
  Deletion at Position
  Deletion at the end
*/

#include <iostream>
using namespace std;

// we defined our own data type here
struct node  
{
  int data;
  struct node * next; // this will point towards to the next node
};


//Traversal: this will traverse the entire LL in o(n) 
void traversal(struct node* pointer)
{
  if (pointer == NULL) // if head is 0 list is empty
  {
    printf("Empty list\n");
    return;
  }
  else
  {
    int num,i=1;
    while (pointer != 0)
    {
      
      num = pointer->data;
      printf("%dth no is %d\n",i,num);
      i++;
      pointer = pointer->next; // (*pointer).next == pointer->next

    }
    cout<<endl;
  }
}


// Create the link list of n nodes
struct node* create(int n) // this is one way to create link list
{
  struct node* head, *newnode,*temp; 
  head = NULL;

  if (n ==0)
  {
    return head;
  }

  // creates first node and enters first data in it
  newnode = (struct node*)malloc(sizeof (struct node));
  head = temp = newnode ;
  printf("Enter the number: ");
  int num;
  scanf("%d", &num);
  newnode->data = num;
  /* we did this because temp pointer should be one step behind newnode pointer
  just so it can access previous nodes next pointer area */

  for(int i=1; i<n;i++)
  {
    newnode = (struct node*)malloc(sizeof (struct node));
     //        (type casting)malloc(sizeof the variable)
    printf("Enter the number: ");
    scanf("%d", &num);
    newnode->data = num;  // number gets filled in data part of new node
    temp->next = newnode; // since temp points towards previous node so the next part of previous node is equal to the address of new node
    temp = newnode;  // temp is updated to the address of new node
  }
  temp->next = NULL;  // end node pointers towards nothing hence null 
  return head;
}

// INSERTION

//inserts newnode in the beginning of the linked link
struct node* insertion_at_beg(struct node* head, int num)
{
  struct node * newnode;
  if (head == NULL)
  {
    newnode = (struct node *)malloc(sizeof (struct node));
    head = newnode;
    head->data = num;
    head->next= NULL;
    return head;

  }
  
  newnode = (struct node *)malloc(sizeof (struct node)); // create new node
  newnode->data = num, // assigned num to its data part
  newnode->next = head;// assigned the address stored in the head to next part of new node
  head = newnode; //  assigned address of newnode to head
  return head; // we will have to return head because it gets updated here
}


// inserts number n at the position pos
struct node* insertion_at_pos(struct node* pointer, int num , int pos) 
{
  struct node* head = pointer;
  if(pointer == NULL)
  {
    printf("Empty list\n");
    return pointer;
  }
  // if we need to insert it in the beginning then we will have to change head itself hence corner case
  if (pos == 1|| pos == 0) 
  {
    head = insertion_at_beg(pointer, num );
    return head;
  }

  // this for will take head pointer to the position just before the position where we want to add the number,
  for(int i=1; i< pos-1; i++)
  {
    pointer = pointer->next;
  }

  struct node* newnode;
  newnode = (struct node *)malloc(sizeof (struct node)); // created a newnode
  newnode->data = num; // assigned number to the data part of the newnode
  newnode->next = pointer->next; // this will assign the adress stored in next part of the pointer
  pointer->next = newnode; // now this will assign the next part of pointer the value of newly created node
  return head;
}

// Inserts Element at the end of the link list
struct node* insertion_at_end(struct node* head, int num)
{
  struct node* newnode,*temp,*pointer;
  if(head == NULL)
  {
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next= NULL;
    head = newnode;
    return head;
  }
  else
  {
    temp = head;
    while(temp->next != 0)
    {
      temp = temp->next;
      
    }
    // while(temp != NULL)
    // {
    //   pointer =  temp;
    //   temp = temp -> next;
    //   
    // }
    pointer = temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    pointer->next = newnode;
    newnode->data = num;
    newnode->next = NULL;
    return head;
  }
}

// Deletion of node

struct node* Delete_at_beg(struct node* head)
{
  if (head == NULL) // underflow condition
  {
    printf("Underflow\n");
    return head;
  }
  else
  {
    struct node* temp = head;
    head = head->next;
    free(temp); // memory allocated in heap memory should be freed manually
    return head;
  }
}

struct node* Delete_at_pos(struct node* head, int pos)
{
  if (head == NULL)// underflow condition
  {
    printf("Underflow\n");
    return head;
  }
  else if (pos == 0 || pos == 1) // Deletion in the beg
  {
    struct node* temp = head;
    head = head->next;
    free(temp);
    return head;
  }
  else
  {
    struct node *temp,* pointer;
    temp = pointer = head;
    for (int i =0; i<pos-1 ; i++)  // to reach the desired positionF
    {
      temp = pointer;
      pointer = pointer->next;
    }
    temp ->next = pointer->next;
    free(pointer);
    return head;
  }
}

struct node* Delete_at_end(struct node* head)
{
  if (head == NULL)
  {
    printf("UnderFlow\n");
    return head;
  }
  else
  {
    struct node* temp, *pointer;
    temp = pointer = head;
    while (pointer->next != NULL)
    {
      temp= pointer;
      pointer = pointer->next;
    }
    temp->next = NULL;
    free(pointer);
    return head;
  }
}

// main function
int main()
{
  // take input n as total no of nodes
  printf("Enter the no of nodes: ");
  int n;
  scanf("%d", &n);


  // create link list of size n
  struct node* head = create(n);

  printf("the head is %u\n",head);// prints head of the link list returned bycreate function


  //Traversal of the entire link list
  traversal(head);

  //Insertion
  printf("Insertion of Node\n");
  head = insertion_at_pos(head,5,5);
  traversal(head);
  head = insertion_at_beg(head,6);
  traversal(head);
  head= insertion_at_end(head,9);
  traversal(head);

  //Deletion
  printf("Deletion of Nodes\n");
  head = Delete_at_beg(head);
  traversal(head);
  head = Delete_at_pos(head,6);
  traversal(head);
  head = Delete_at_end(head);
  traversal(head);
  


  return 0;
}
