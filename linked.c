#include<stdio.h>
#include <stdlib.h>
#define max_size 101

struct node{
  int data;
  struct node *next;
}*first;


//for finding length

int node_length(struct node*p)
	{
	  int count = 0;
	  while(p!=NULL)
	  {
	    count++;
	    p=p->next;  
	  }
	return count ;
	}
//for returning p
int return_node(struct node *p)	
	{
	   int x = p->data;
	   free(p);
	   return x;
	
	}
//function to create a linked list 
void createLinked(int a[],int size)
	{
	  struct node *last;
	  struct node *t;
          first = (struct node*)malloc(sizeof(struct node));
          first->data=a[0];
          first->next =NULL;
          last = first;
           int i ; 
           for(i=1;i<size;i++)
           {
             t = (struct node*)malloc(sizeof(struct node));
             t->data = a[i];
             last->next = t;
             t->next = NULL;
             last =t;
             
           }   
	}	

// function to add at end
void add_end(struct node *p,int new_data)
	{
	  while(p->next!=NULL)
	   p = p->next;
	   
	   struct node *t = (struct node*)malloc(sizeof(struct node));
	   t->data = new_data;
	   t->next = NULL;
	   p->next = t;
	       
	}	
	
//adding new before
void add_before(struct node*p,int node_data,int new_data)
	{  
	   struct node*q,*t;
	   while(p->data!=node_data && p!=NULL)
	   {
	     q=p;
	     p=p->next;
	   }
	   
	   if(p==first)
	   {
	     t = (struct node*)malloc(sizeof(struct node));
	     t->next = p;
	     first =t;
	   }
	   else if(p->data == node_data)
	   {
	     t = (struct node*)malloc(sizeof(struct node));
	     t->data = new_data;
	     t->next = p;
	     q->next = t;
	   }
	   else
	   {
	     printf("node data not present in linked list");
	     return;
	   }   
	}

// adding new after
void add_after(struct node *p,int node_data,int new_data)
	{
	  struct node *t;
	  while(p->data != node_data && p!= NULL)
	  {
	     p = p->next;
	  }
	  if(p->data == node_data)
	  {
	    t = (struct node*)malloc(sizeof(struct node));
	    t->data = new_data;
	    t->next = p->next;
	    p->next = t;
	    
	  }
	  else
	   {
	     printf("node data not present in linked list");
	     return;
	   }     
	}

// inserting a new node in the given position
void add_node_any_position(struct node * p , int new_data, int index)
	{
	  if(index <=0||index >node_length(first))
	  {
	    printf("cant insert there/n");
	    return;
	  }
	  else if(index ==1)
	  {
	      
	     struct node * t =  (struct node*)malloc(sizeof(struct node));
	     t->data = new_data;
	     t->next = first;
	     first =t;
	  }
	  else
	  {  
	     struct node*q; 
	     struct node * t =  (struct node*)malloc(sizeof(struct node));
	     for(int i =1;i < index ;i++)
	     {
	       q=p;
	       p=p->next;
	     }
	     t->data = new_data;
	     t->next = p;
	     q->next =t;
	   }  	     
	 }
	  
//delete given key data  value 	  
int del_given_data(struct node *p,int node_data)
	{        
	        struct node *q;
	 	while(p->data!= node_data && p!= NULL)
	 	{
	 	        q=p;
	   		p = p->next;
	 	}
	 	
	 	if(p->data == node_data)
	 	{
	 	     if(p==first)
	 	     {
	 	       int y = return_node(first);
	 	       first = first->next;
	 	       return y;                                                  ////////////// ERROR maybe/////////////////
	 	     }
	          	q->next = p->next;
	 		int y = return_node(p);
	 		return y;
	 	}
	 	else
	 	{
	 		printf("ERROR!!! as no node with that data\n");
	 		return;                                                       /////////////////////////// ERROR///////////////////
	 	}
	 
	}
	
// deleting givcn postion
int del_given_pos(struct node*p,int index)
	{
	struct node *q;
         if(index <=0||index >node_length(first))
         	{
                   printf("ERROR !!!!!!!!!! as no index of that sort exists\n");
                   exit(0);
         	}
         if(index == 1)
         	{
         	   q=first;
         	   first = first->next;
         	   int x = return_node(q);
         	   return x;
         	}		
         else
         {
         	for(int i = 1;i<index;i++)
         	{
         	   q=p;
         	   p=p->next;
         	}  
         	q->next=p->next;
         	int y = return_node(p);
         	return y;
         	    
         }	
	}	
// delete the smallest element from a list
int del_small(struct node *p)
	{ 
	struct node*q;
	int min = 99999;
	  while(p != NULL)
	  	{
	             if(p->data < min)
	             {
	             q=p;
	             min = p->data;
	             }
	             p = p->next;
	  	}
	  
	  int x = del_given_data(first,min);
	  return x;
	  
	  
	  
	  
	}	
	
// reversin an linked list
void inverse(struct node *p)
	{
	  struct node *left,*mid,*right;
	  if (first == NULL)
	  {
	    printf("chetta list empty ane \n");
	  }
	  else
	  {
	  left = NULL;
	  mid = NULL;
	  right = first;
	  while(mid!= NULL)
	  	{
	  		left = mid;
	  		mid = right;
	  		right=right->next;
	  		mid->next = left;
	  	}
	  first = left;	
	  display(first);	
	  }
	  
	}	
// displaying the linked list
void display(struct node *p)
	{
		while(p!=NULL)
			{
				printf("%d\t",p->data);
				p = p->next;
			}
	}	

int main()
{       

       //region  to decalre variables
       int size,a[max_size];
       int add_end_e,node_data,new_data;
       int index,smallest,del;  
       //region for declaration
       
	printf("\n\tTHIS IS LINKED LIST\n") ;
	printf("This is the menu\n");
	/*printf("[1-create a linked list]\n[2-add at end]\n[3 -adding a new node before a given node data]\n[4-adding new node after an given node data]\n[5-inseting a new node at the given poistion]\n[6-delete given key data value]\n[7-delete given index]\n[8-delete the smallest]\n[9 - reverse an linked list]\n[10 - display ]\n[11 - stop] ");*/
	int val = 0;
	while(val != 11)
		{
		printf("[1-create a linked list]\n[2-add at end]\n[3 -adding a new node before a given node data]\n[4-adding new node after an given node data]\n[5-inseting a new node at the given poistion]\n[6-delete given key data value]\n[7-delete given index]\n[8-delete the smallest]\n[9 - reverse an linked list]\n[10 - display ]\n[11 - stop]\n ");
		scanf("%d",&val);
		
		switch (val)
			{
			 	case 1 : 
			 	printf("Enter the size of list to be created\n");
			 	scanf("%d",&size);
			 	for(int i =0;i<size;i++)
			 		{
			 			printf("enter the %dth element to insert in linked list\n");
			 			scanf("%d",&a[i]);
			 		}
			 	createLinked(a,size);
			 	display(first);
			 	break;
			 	
			 	case 2 :
			 	printf("\nEnter the elemnt to add at end\n");
			 	scanf("%d",&add_end_e);
			 	add_end(first, add_end_e);
			 	break;
			 	
			 	case 3 :
			 	printf("enter the node data and new node data to add new node before the given node data");
			 	scanf("%d",&node_data);
			 	scanf("%d",&new_data);
			 	add_before(first, node_data, new_data);
			 	break;
			 	
			 	case 4:
			 	printf("TO add a new node after a given node data\n enter node data and new data");
			 	scanf("%d",&node_data);
			 	scanf("%d",&new_data);
			 	add_after(first, node_data,new_data);
			 	break;
			 	
			 	case 5 :
			 	printf("Inserting a new node in the given position\n");
			 	printf("give NEW NODE and POSITION respectivey : ");
			 	scanf("%d",&new_data);
			 	scanf("%d",&index);
			 	add_node_any_position(first,new_data,index);
			 	printf("DISPLAYING\n");
			 	display(first);
			 	break;
			 	
			 	case 6 :
			 	printf("TO delete given key data value\n");
			 	scanf("%d",&node_data);
			 	del = del_given_data(first, node_data);
			 	printf("DISPLAYING\n");
			 	display(first);
			 	printf("\n the deleted value is %d \n",del);
			 	break;
			 	
			 	case 7 :
			 	printf("DELETE GIVEN INDEX\n");
			 	printf("ENTER INDEX :");
			 	scanf("%d",&index);
			 	del = del_given_pos(first,index);
			 	printf("DISPLAYING\n");
			 	display(first);
			 	printf("\n the deleted value is %d \n",del);
			 	break;
			 	
			 	case 8 :
			 	printf("to delete the smallest and displaying \n");
			 	smallest = del_small(first);
			 	printf("DISPLAYING\n");
			 	display(first);
			 	break;
			 	
			 	case 9 :
			 	printf("TO REVERSE THE LISt\n");
			 	inverse(first);
			 	printf("DISPLAYING\n");
			 	display(first);
			 	break;
			 	 
			 	case 10 :
			 	printf("DISPLAYING THE LINKED LIST\n");
			 	display(first);
			 	break;
			 	
			 	case 11 :
			 	printf("OK STOPPING THE PROCESS\n");
			 	val = 11;
			 	break;
			 	
			 	default :
			 	printf("WRONG INPUT");
			 	break;
			 	
			 	 
			 	
			 	
			 	
			 		
			 	
			
			}
		
		
			
		}
 
 return 0;
 
}			
	
	
	
	
	
	
	// to make it 400 lines hhehehehehe	
