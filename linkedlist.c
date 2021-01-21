//to print element from reverse
/*
1.insert
2.display
3.rprint
4.exit
1
4
1
5
1
6
1

7
2
4->5->6->7->
3
2
6
4
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node * next;
};
struct node* head=NULL;
void insert();
void display();
void rprint();
int main()
{
  int c;
  printf("1.insert\n2.display\n3.rprint\n4.exit\n");
  while(1)
  {
    scanf("%d",&c);
    switch(c)
    {
   case 1:insert();break;
   case 2:display();break;
   case 3:rprint();break;
   case 4:exit(1);
   default:printf("invalid option\n");
    }
  }
}
void insert()
{
  struct node* t,*temp;
  int ele;
  scanf("%d",&ele);
  t=(struct node*)malloc(sizeof(struct node));
  t->data=ele;
  t->next=NULL;
   if(head==NULL)
     head=t;
   else
   {temp=head;
    while(temp->next!=NULL)
       temp=temp->next;
    temp->next=t;
   }
}
void display()
{
  struct node* temp;
   temp=head;
    while(temp!=NULL)
    {
    printf("%d->",temp->data);  
      temp=temp->next; 
    }
  printf("\n");
}
void rprint()
{
  int n,c=0;
  struct node*p,*t;
  scanf("%d",&n);
  t=head;
  while(t!=NULL)
  {
  c++;
  if(c==n)
    p=head;
  if(c>n)
   p=p->next;
  t=t->next;
  }
  printf("%d\n",p->data);
}


