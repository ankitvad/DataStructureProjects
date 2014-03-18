/*
 ______________________________________
|Sieve of Eratothenes:                 |
|Using a linked list approach:         |
|--------------------------------------| 
|CSE-220 | Data Structure and Algorithm|
|--------------------------------------|
|12BCE0282- Ankit.Vadehra              |
|12BCE0277- Poorva Arora               | 
|--------------------------------------|

LOGIC:
1) Structure has Data to store a list of natural numbers
2) It has info to seperate primes from composites.(By default set as 0)
3) Create a Fucton in main to create a linked list
4)The Function takes in the number till which primes have to be tested.
  "max"-the upper bound.
5)The list is created with naural number from 2 to max-1.
  (0 and 1 are cosidered neither prime nor composite.)
6)The sieve of eratothenes algorithm is performed in main(), and all te multiples of 
  2,3,4.....,max are passed to the function prime()
7)the Prime() function takes in each mutiple value by call-by-value and traverses the list,
  and searches for it.
8)When found the prime() fuction changes the value of info to -1. Thus telling us at a later stage that
  the number is a composite.
9)The pop function is called next, and it traverses the list searching for the info variable and it shows all the 
  data which has info=0.
10)Thus we can take in any number, reate a dynamic list. work on it and then show the prime numbers,
11)Also the program has display() and display2() functions to show at any stage the state of the 
   list ad data and info variables.

*/


#include <iostream>
#include <stdlib.h>
   #include <time.h>
using namespace std;

struct node
{
	int data;//Will store the Natural Numbers in succession
	int info;//a flag variable to store 0 and -1 to tell the type of number.
	node *next;
} *newptr = NULL, *head = NULL, *temp = NULL, *temp2 = NULL;

void create(int number)//Takes in the upper-bound from th main function
{int count=2; //Since 0 and 1 are not prime we start from 2.
	while((number-1)>=count)
	{
		newptr = new(node);
		//checking for memory
		newptr = new(node);
		if(newptr == NULL)                   
		{
			cout<<"\n short of memory! \n EXITING";
			return;
		}
                //Storing the value of natural numbers in data-variable  
                newptr->data=number-1;
                newptr->info=0;//By default all numbers are taken prime.
        		newptr->next = NULL;
        		if(head==NULL)                   // no element in the list
		            {
            			head = newptr;
            		}
		        else        //i.e. insert in beginning
		            {
            			newptr->next=head;
            			head=newptr;
            		}

        

         number=number-1;
	}
	

}

void prime(int number)
{	//traversing list to change info value(deleting-value), depending upon the type.
	  temp = head;
	  while(temp!=NULL)
        {
          	if(temp->data==number)
          	  { 
            	  	temp->info=-1;
            	  	break;
		      }
	        temp=temp->next;
        } 
}

void pop()
/*since the list tarts from numbers 2 and 3, 
which are always prime we need not worry about the beggining conditions,
ie, changing head to the next. List won't become empty, EVER*/
{
	temp = head;
	while(temp !=NULL)               // by the end of this loop the temp will point to node prior to that to be deleted
	{
		if(temp->info==0)
		{
			cout<<temp->data<<" ";
			//array[index]=temp2->data;
	        //index++;
	        
		}
	    temp=temp->next;
    }
	    

}

void display()
{cout<<"\n The list is: ";
	temp = head;
	while(temp != NULL)
	{
		cout<<temp->data<<"  ";
		temp = temp->next;
	}
	
}
void deletelist()
{
	while(head!=NULL)
	{
		temp=head;
		head=head->next;
		delete temp;
	}
	cout<<"\n List Deleted\n ";
}

//To Show info :
/*
void display2()
{temp = head;
	while(temp != NULL)
	{
		cout<<temp->info<<"  ";
		temp = temp->next;
	}
}
*/

int main()
{int max;

clock_t t;//Variable assigning 
cout<<"\n Enter the number of no to check:";
cin>>max;

create(max);
//To Check List:
//display();
cout<<"\n \n";
//multiplier to be popped, later.
t=clock();
for (int p=2; p<=max; p++)
{int c=2;
                int mul = p*c;
                while(mul<max)
                	{   //cout<<mul<<"";
                		prime(mul);
                		//Passing value to list for update.
	 	 	            c++;
                        mul = p*c;
                     }
			

}
t=clock()-t;
cout<<"It took me "<<t<<"clicks which is equal to :"<<((float)t)/CLOCKS_PER_SEC<<" seconds";
//display();
cout<<"\n";
//display2();
cout<<"\n";
//To see the revised prime list:  
//pop();
cout<<"\n";

//display();
deletelist();
return 0;
}