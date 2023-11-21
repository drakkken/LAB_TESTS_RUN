#include<stdio.h>
#include<stdlib.h>

struct node{
 int exp;
 int coe;
 struct node * next;
}*poly1,*poly2,*result,*result1;

void enter(struct node *p,int f)
	{
   		int n,i = 0;
   		printf("enter the no of terms\n");
   		scanf("%d",&n);
   		int coe,exp;

   		struct node *last = NULL;

   		while(i!=n)
  			 {
       				printf("enter the %dth term exp and coe respectively\n",i);
       				scanf("%d",&coe);
       				printf(" : x raised to : ");
       				scanf("%d",&exp);

      				 struct node *t = (struct node*)malloc(sizeof(struct node));
       				t->exp = exp;
       				t->coe = coe;
       				t->next = NULL;

       				if(p==NULL)
       					{
           					if(f == 1) 
					           {poly1 = t;}
					           else if(f==2)
					           {poly2 = t;}
						    p =t;
						    last = p;
       					}
       				else
       					{
           					last->next = t;
           					last = t;
       					} 
       						i++;
   			}
	}

void display(struct node *p)
	{
  		if(p == NULL)
   			{
       				printf("NO ELEMENTS IN RESULT");
      				 return ;
   			}
   		else
   			{
       				while(p!=NULL)
      					 {
      					 
           					printf("%d x raised to %d + ",p->coe,p->exp);
          					p = p->next;
          					
      					 }
   			}  
	}  

void insert(int coe,int exp)
	{
   		if(result1==NULL)
   			{
       				struct node * temp = (struct node*)malloc(sizeof(struct node));
       				temp -> coe = coe;
       				temp -> exp = exp;
       				result1 = temp;
       				result = temp;
       				result1 -> next = NULL;
   			}
   		else 
   			{
			       struct node * temp = (struct node*)malloc(sizeof(struct node));
			       temp -> coe = coe;
			       temp -> exp = exp;
			       temp->next = NULL;
			       result->next = temp;
			       result = temp;
   			}  
	}  

void add(struct node* p1,struct node* p2)
	{
   		while(p1!=NULL && p2!=NULL)
   			{
			       if(p1->exp == p2 ->exp)
			      	 {
				  	insert((p1->coe+p2->coe),p1->exp);
				   	p1=p1->next;
				   	p2= p2->next;
			      	 }
			       else if(p1->exp<p2->exp)
			       	{
					insert(p2->coe,p2->exp);
					p2=p2->next;
			       	}  
			       else if(p1->exp>p2->exp)
			       {
				        insert(p1->coe,p1->exp);
				        p1=p1->next;
			       }  
     			}

		   while(p1!=NULL)
		   	{
			       insert(p1->coe,p1->exp);
			       p1= p1->next;
		   	}
		   while(p2!=NULL)
		   	{
			       insert(p2->coe,p2->exp);
			       p2=p2->next;
		   	}
	}  

void main()
{
	   printf("Enter the elements for two polynomials \n");
	   printf("Enter the elments for poly 1 \n");
	   enter(poly1,1);
	   printf("Enter the elements for poly 2 \n");
	   enter(poly2,2);
	   add(poly1,poly2);

	  printf("DISPLYING\n");
	  display(result1);
} 

