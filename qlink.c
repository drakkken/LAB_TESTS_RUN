#include <stdio.h>
#include <stdlib.h>
struct node{
  int data;
  struct node * next;
}*front,*rear;

void en(int e)
	{
	 	struct node * temp = (struct node*)malloc(sizeof(struct node));
	 	temp -> data = e;
		if(front == NULL)
			{
				front = temp;
				rear = temp;
				front->next = NULL;
			}
		else
			{
				rear ->next = temp;
				rear=temp;
			}
			 	 	
	}

int de()
	{
		if(front ==NULL)
			{
				printf("NO element to dequeue\n");
				return;
			}
		else
			{
				struct node * temp = front;
				front = front->next;
				int y = temp->data;
				free(temp);
				return y;
			}	
	}	
	
void display()
	{
                if(front == NULL)
                {
                printf("NO element in q");
                }
                else
                {	
			struct node* temp=front;
		
			while(temp!=NULL)
				{
					printf("%d \t",temp->data);
					temp = temp->next;
				}	 
		}		
	}	
	
	
void main()
	{
		int i = -1,ele;
		
		while(i!=0)
			{
				printf("[1-enq]-[2-deq]-[3-dis]-[0-stop]\n");
				scanf("%d",&i);
				
				switch (i)
					{
					  case 1 :
					  printf("Enter element to enq\n");
					  scanf("%d",&ele);
					  en(ele);
					  break;
					  
					  case 2 :
					  int y = de();
					  printf("the element dequed is %d\n",y);
					  break;
					  
					  case 3 :
					  display();
					  break;
					  
					  case 0 :
					  i = 0;
					  break;
					  
					  default :
					  printf("ERROR !!!! WRONG INPUT\n");
					  break;
					}
				
			}
	}	
