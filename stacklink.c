#include <stdio.h>
#include <stdlib.h>
struct node{
   int data;
   struct node * next;
}*head;


void push(int e)
	{
	  	struct node * t = (struct node *)malloc(sizeof(struct node));
	  	t->data = e;
	  	 
		if(head == NULL)
			{
			  	head =t;
			  	head ->next = NULL;
			}
		else
			{
			  	t->next = head;
			  	head = t;
			  		
			}	
	} 
	
int pop()
	{
		if(head==NULL)
		{
			printf("ERROR NO ELEMENT TO POP\n");
			return;
		}
		else
		{
			struct node * temp = head ;
			head = head->next;
		        int re = temp->data;
		        free(temp);
		        return re;
		}
		
				
		
	}
	
int peek()
	{
		if(head == NULL)
		{
			printf("NULL AS NO ELEMTN\n");
			return;
		}
		else	
		{
			int re = head->data;
			return re;
		}
		
	}	

void display()
	{
		struct node * temp = head;
		if(head == NULL)
		{printf("NO element to dispaly\n");}
		while(temp!=NULL)
		{
		 printf("%d \t",temp->data);
		 temp = temp->next;
		}
	}
	
void main()
	{
		int i =-1,ele;
		
		while(i!=0)
		{
		printf("[1-push]-[2-pop]-[3-peek]-[4-display stack][0-stop]\n");
		scanf("%d",&i);
		 
		 switch (i)
		 	{
		 		case 1 :
		 		printf("Enter the emenet to be pushsed\n");
		 		scanf("%d",&ele);
		 		push(ele);
		 		break;
		 		
		 		case 2:
		 		int y = pop();
		 		printf("poped element is %d\n",y);
		 		break;
		 		
		 		case 3:
		 		int x = peek();
		 		printf("The element at top is %d \n",x);
		 		break;
		 		
		 		case 0 :
		 		i = 0;
		 		break;
		 		
		 		case 4:
		 		display();
		 		break;
		 		
		 		default:
		 		printf("Wrong input !!! TRY again");
		 		break;
		 	}
		}
	}	
	
			
