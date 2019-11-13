/* 
classes
dice 
then calculator

R. Michaloski

12 Nov 2019
*/

#include<iostream>
#include<string>

using namespace std;

class calculator
{
	public:
	   string userFirstName;
	   int operation;
	   
	   calculator()
	   {
	   	cout << "Creating a calculator object!" << endl;
	   }
	   
	   void greetUser()
	   {
	   	cout << "Hello, " << userFirstName << endl;
	   }

void selectOperation()
{
	char response[] = "Y";
	char tempY[] = "Y";
	char tempN[] = "N";			
		
	while(strcmp(response, "Y")==0)
	{
		printf("------------------------\n");
		printf("choose math operation:\n\n");
    	printf("(A) addition\n\n");
    	printf("(S) subtraction\n\n");
    	printf("(D) division\n\n");
    	printf("(M) multiplication\n\n");
    	printf("(Q) quit\n\n");
    	cin>>response;
			
    	if(strcmp(response, "A") == 0)
    	{
     		printf("you chose addition!\n\n");
     		*response = *tempY;
//     		intAddition();
     	}
    	else if(strcmp(response, "S") == 0)
    	{
     		printf("you chose subtraction!\n\n");
     		*response = *tempY;
 // 		intSubtraction();	
    	}
    	else if(strcmp(response, "D") == 0)
    	{
     		printf("you chose division!\n\n");
     		*response = *tempY;
//     		intDivision();
    	}
    	else if(strcmp(response, "M") == 0)
    	{
     		printf("you chose multiplication!\n\n");
     		*response = *tempY;
//     		intMultiplication();
     	}
     	else if(strcmp(response, "Q") == 0)
     	{
     		printf("you chose to quit!\n");
     		printf("ending session.\n\n");
         	*response = *tempN;
      	}
      	else
      	{
  		printf("ending session.\n\n");
        	*response = *tempN;
      	}
   	}
	return;		
}	
				
	   ~calculator()
	   {
	   	cout << "Thankyou, " << userFirstName << ".  Goodbye.\n";
	   }
};

class dice
{
	public:
	   string userFirstName;
	   string userReady;
	   int qtyDiceSides;
	   int qtyDies;
	   int i,j;
	   
	   dice()
	   {
	   	cout << "Let's roll!" << endl;
	   }
	   
	   void greetUser()
	   {
	   	cout<< "Hello, please enter your first name:  ";
		   cin >> userFirstName;
	
	   	cout << "Hello, " << userFirstName << endl;
	   	userReady = "Y";
	   }

	   void qtySides()
	   {
	   	cout << "\nHow many sides per die do you prefer?" << endl;
	   	cin >> qtyDiceSides;	   	
	   }
	   
	   void qtyDice()
	   {
	   	cout << "\nHow many die will you be rolling today?" << endl;
	   	cin >> qtyDies;
	   }
	   
	   void highRoller()
	   {
	   	 j=0;
	   	 
	   	 for (i =0; i < qtyDies; i++)
	   	 {
	   	 	j = rand() % qtyDiceSides + 1;
	   	 	cout << "\nWith die # " << i+1 << " of " << qtyDies << ", you rolled a " << j << "!" << endl;
	   	 }
	   	 
	   	 cout << " \n\n Yo, high roller!  I hope that you are having fun!!!!" << endl;
	   }
						
		void rollAgain()
		{
			 cout << "\n That was awesome!  Would you like to roll again?  ( Y or N ): ";
			 cin >> userReady;		
		}
									
	   ~dice()
	   {
	   	cout << "Thank you, " << userFirstName << ".  Goodbye.\n";
	   }
};

int main()
{
		dice user1;

		user1.greetUser();
		user1.qtySides();
		user1.qtyDice();
        
        while ( user1.userReady == "Y" )
        {
        	user1.highRoller();
        	user1.rollAgain();
        }
        
		return(0);	
}