/*
1.insert
2.display
3.seperate
4.exit
1
enter the data
4
1
enter the data
5
1
enter the data
8
1
enter the data
3
1
enter the data
5
1
enter the data
9
1
enter the data
10
2
4
5
8
3
5
9
10
3

4
8
10
5
3
5
9


*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node * next;
};
void insert();
void  display();
int len();
void seperate();
int count=0;
struct node* root=NULL;
int main()
{
  int c;
  printf("1.insert\n2.display\n3.seperate\n4.exit\n");
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
      seperate();break;
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
  temp=root;
  if(temp==NULL)
     printf("list is empty\n");
  else
 { 
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

void seperate()
{
 int a[20],i=0,b[20],j=0;
 struct node *p,*q;
  struct node* temp;
 p=root;
 q=root;
 if((p->data)%2==0)
 {
 
   while(p!=NULL)
   { 
      if((p->data)%2==0)
       {
          a[i]=p->data;
          i++;
       }
       else
        b[j++]=p->data;
    p=p->next;
   }

  for(int k=0;k<i;k++)
  { q->data=a[k];
    q=q->next;
   
  }
  for(int k=0;k<j;k++)
  { q->data=b[k];
    q=q->next;
  }

 }
 else
 {
 
   while(p!=NULL)
   {
      if((p->data)%2!=0)
       {
          a[i]=p->data;
          i++;
       }
       else
        b[j++]=p->data;
    p=p->next;
   }

  for(int k=0;k<i;k++)
  { q->data=a[k];
    q=q->next;
   
  }
  for(int k=0;k<j;k++)
  { q->data=b[k];
    q=q->next;
  }

 
 }
 printf("\n");
 display();
}
