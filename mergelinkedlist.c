#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node * next;
};
void insert1();
void  display1();
void insert2();
void  display2();
void  merge();
//int len1();
//int len2();
//int count;
struct node* root1=NULL;
struct node* root2=NULL;
struct node* last1=NULL;
struct node* last2=NULL;
int main()
{
  int c,ch;
  printf("1.insert\n2.display\n3.merge\n4.exit\n");
  while(1)
  { scanf("%d",&c);
   switch(c)
  {
    case 1:
     printf("1.list1\n2.list2\n3.exit\n");
     scanf("%d",&ch); 
     switch(ch)
     { case 1:
       insert1();
       break;
     case 2:
        insert2();
       break;
     case 3:
       exit(1);
     }
      break;
    case 2:
    
     printf("1.list1\n2.list2\n3.exit\n");
     scanf("%d",&ch);
    switch(ch)
    {
     case 1:
       display1();
       break;
     case 2:
       display2();
       break;
     case 3:
       exit(1);
     }
      break;
    case 3:
      merge();break;
    case 4:exit(1);
    default: printf("invalid option\n");
  }
 }
 
 return 0;
}
void insert1()
{
  struct node *cur=root1;
  struct node*t;
  t=(struct node*)malloc(sizeof(struct node));
  printf("enter the data\n");
  scanf("%d",&t->data);
  t->next=NULL;
 
  if(root1==NULL)
    root1=t;
  else  
   {  while(cur->next!=NULL)
      cur=cur->next;
    cur->next=t;
    last1=cur->next;
    
   }

}
void insert2()
{
  struct node *cur=root2;
  struct node*t;
  t=(struct node*)malloc(sizeof(struct node));
  printf("enter the data\n");
  scanf("%d",&t->data);
  t->next=NULL;
 
  if(root2==NULL)
    root2=t;
  else  
   {  while(cur->next!=NULL)
      cur=cur->next;
    cur->next=t;
    last2=cur->next;
   
   }

}
void display1()
{
  struct node* temp=root1;
 
  if(temp==NULL)
   printf("list is empty\n");
   else
   {
    while(temp!=NULL)
    {printf("%d\n",temp->data);
      temp=temp->next;
  
    }
  } 
}
void display2()
{
  struct node* temp=root2;
 
  if(temp==NULL)
   printf("list is empty\n");
   else
   {
    while(temp!=NULL)
    {printf("%d\n",temp->data);
      temp=temp->next;
  
    }
  } 
}
/*int len1()
{count=0;
  struct node* temp=root1;
 if(root1==NULL)
  return 0;
 else
  { while(temp!=NULL)
    {temp=temp->next;
    
     count++;
    }
   
   return count;
  }
}
int len2()
{count=0;
  struct node* temp=root2;
 if(root2==NULL)
  return 0;
 else
  { while(temp!=NULL)
    {temp=temp->next;
     
     count++;
    }
   return count;
  }
}*/
void merge()
{
  //printf("lenght of the list1 is %d\n",len1());
 // printf("lenght of the list2 is %d\n",len2());
// int l1,l2;
 struct node *p,*q,*p1;
 int temp;
 //l1=len1();
 //l2=len2();
 
 //printf("%d %d %d %d %d\n",l1,l2,last1->data,last2->data,last2->next);
    last1->next=root2;
  //last1=last2;
    p1=root1;
  printf("\n****BEFORE SORTING****\n");
  while(p1!=NULL)
  {
     printf("%d\n",p1->data);
     p1=p1->next;
  }
  
 p=root1;
 q=p->next;
   //printf("%d %d\n",p->data,q->data);
 while(p!=NULL)
 {
   while(q!=NULL)
   {//printf("yes %d-%d\n",p->data,q->data);
     if((p->data)>(q->data))
     {
          temp=p->data;
          p->data=q->data;
          q->data=temp;
      //  printf("changed %d-%d\n",p->data,q->data);
       }    
    q=q->next;
   
   }
   p=p->next;
   if(p!=NULL)
     q=p->next;
   else
    break;
 }
 free(p);
 free(q);
 p1=root1;
 root2=NULL;
 printf("\n****AFTER SORTING****\n");
  while(p1!=NULL)
  {
     printf("%d\n",p1->data);
     p1=p1->next;
  }
  
 
}
