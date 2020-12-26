//to detect the loop in the linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node * next;
};
void insert();
void  display();
void  detect();
int len();
 void change();
int count=0;
struct node* root=NULL;
int main()
{
  int c;
  printf("1.insert\n2.detect\n3.exit\n");
  while(1)
  { scanf("%d",&c);
   switch(c)
  {
    case 1:
      insert();
      break;
    case 2:
      display();
      break;
    case 3:
      detect();break;
    case 4:exit(1);
    default: printf("invalid option\n");
  }
 }
 return 0;
}
void insert()
{
  struct node *cur=root;
  struct node*t;
  t=(struct node*)malloc(sizeof(struct node));
  printf("enter the data\n");
  scanf("%d",&t->data);
  t->next=NULL;
 
  if(root==NULL)
    root=t;
  else
  {
     while(cur->next!=NULL)
      cur=cur->next;
    cur->next=t;
  }

}
void display()
{
  struct node* temp;
  if(temp==NULL)
     printf("list is empty\n");
  else
 { temp=root;
    while(temp!=NULL)
    {printf("%d\n",temp->data);
      temp=temp->next;
     count++;
    }
  }
}
int len()
{
 if(root==NULL)
  return 0;
 else
   return count;
}
void detect()
{
 
   change();
  struct node *slow=root,*fast=root;
   int flag=0;
  while(slow && fast && fast->next)
  {
     slow=slow->next;
      fast=fast->next->next;
      if(slow==fast)
        { printf("loop found\n");
           flag=1;
           exit(1);
        } 
 }
  if(flag==0)
    printf("loop not found\n");
}
void change()
{
  int pos,c=0;
  struct node *last=root,*temp=root;
  //root->next->next->next->next->next=root->next->next;
  printf("lenght of the list %d\n",len());
  printf("enter the loop position between 1 to lenght of the list\n");
  scanf("%d",&pos);
  while(last->next!=NULL)
    last=last->next;
  while(c<pos)
   { temp=temp->next;
      c++;
   }
  last->next=temp;

}
