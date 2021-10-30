#include<iostream>
#include<conio.h>
#include<stdio.h>

class LinkedList
 {
 	
 	struct node
 	{
 		int info;
 		node *next;
	 };
	 struct node *start,*ptr,*temp,*i;
	 
 	
 	public:
 		LinkedList()
 		{
 			start=NULL;
		 }
 	   void create();
 	   void display();
 	
 	
 };
 
 void LinkedList::create()
 {
 	int no;
 	std::cout<<"\n Enter any number";
 	std::cin>>no;
 	ptr=new node;
 	ptr->info=no;
 	ptr->next=NULL;
 	if(start==NULL)
 	{
 		start=ptr;
 		temp=ptr;
	 }
	 else{
	 	temp->next=ptr;
	 	temp=ptr;
	 }
	 std::cout<<"New Node Inserted....\n";
 }
 


void LinkedList::display()
{
	if(start==NULL)
	{
		std::cout<<"List is Empty";
	}
	else{
		std::cout<<"List Is\n";
		for(i=start;i!=NULL;i=i->next)
		{
			std::cout<<i->info;
		}
		std::cout<<"\n";
		
	}
}

int main()
{
	
	
	LinkedList l;
	int ch = 1;
	while(ch!=0)
	{
		std::cout<<"\n1.Create Node\n";
		std::cout<<"2.display\n";
		std::cout<<"Enter Your Choice (0 for exit)\n";
		std::cin>>ch;
		
		  switch(ch)
		  {
		  	
		  	case 1:
		  		     l.create();
		  		     break;
		  	case 2:
			          l.display();
					  break;
			default:
			        std::cout<<"Illegal Options";		  	     
		  }
		
	}getch();
return 0;	
}
