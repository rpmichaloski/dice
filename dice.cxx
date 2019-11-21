/* 
classes *
dice *
doubles challenge *
array storage results messages *!
sqlite storage results messages
then calculator

R. Michaloski

21 Nov 2019
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
	   string userChallenge;
	   int qtyDiceSides;
	   int qtyDies;
	   int i,j,k;
	   int doubles1A, doubles1B;
	   int doubles2A, doubles2B;
	   
	   // results
	   int doublesGamesPlayed;
	   int doublesGamesWon;
	   int topFiveDoublesResults = 20;
	   int userDoublesResults[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	   int userLuckyDoubles;
//	   int userHighRollerResults[];
	   
	   dice()
	   {
	   	cout << "Let's roll!" << endl;
	   }
	   
       void challengeInit()
       {
   	 	cout << "\nHey high roller!  Are you up for the doubles challenge?? ( Y or N ):" << endl;
	    	cin >> userChallenge;  	
        }

	   // challenge 
	   void doublesChallenge()
	   {
           challengeInit();
           doublesGamesPlayed = 0;
           doublesGamesWon = 0;
           //userDoublesResults[0] = 0;
           
	       while ( userChallenge == "Y" )
           {
           	qtyDies = 2;
           	highRoller();
           	challengeRoller();                 	
           	challengeWinner();
           	updateDoublesResults();
           	userChallenge = "N";
           	challengeInit();
           }    
	   }
	   
	   void challengeRoller()
	   {
	   	 j=0;
	   	 
	   	 for (i = 0; i < 2; i++)
	   	 {
	   	 	j = rand() % qtyDiceSides + 1;
	   	 	cout << "With die # " << i+1 << " of 2" << ", your challenger rolled a " << j << "!" << endl;

	   	     if ( qtyDies == 2 )
	   	 	{
	   	 		if ( i == 0 )
	   	 		{
	   	 			doubles2A = j;
	   	 		}
	   	 		else
	   	 		{
	   	 			doubles2B = j;
	   	 		}
	   	 	}
	   	 }
		 }	   
		 
		 void challengeWinner()
		 {
		 	  cout << "   \n\nwho won? \n\n\nwho knows???\n";
		 	  
		 	  if( doubles1A != doubles1B )
		 	  {
		 	  	if( doubles2A == doubles2B )
		 	  	{
		 	  		cout << "\n\n   Your challenger just won!!!!!" << endl;
		 	  	}
		 	  	else
		 	  	{
		 	  		 cout <<  "\n\n   No one rose to the challenge this round ... \n\n";
		 	  	}
		 	  }
		 	  else
		 	  {
		 	  	if ( doubles2A == doubles2B )
		 	  	{
		 	  		cout << "\n\n\n   WOW!!!!! You AND your challenger both rose to the challenge!!! \n\n\n";
		 	  		doublesGamesWon = doublesGamesWon + 1;
		 	          userDoublesResults [ doublesGamesWon -1 ] = doubles1A;
		 	  	}
		 	  	else
		 	  	{
		 	      	cout << "\n\n\n   You go, highroller!!!!  You have won the doubles challenge this round!!!!\n\n\n";
		 	      	
		 	          doublesGamesWon = doublesGamesWon + 1;  
		 	          userDoublesResults [ doublesGamesWon -1 ] = doubles1A;
		 	  	}
		 	  }	  
		 }
		 
		 void finalResults()
		 {
		 	int finalCounter;
		 	cout << "\n\n   Here are your final winning results:" << endl;
		 	
		     for (finalCounter =0; finalCounter < doublesGamesWon; finalCounter++)
		     {
		     	 cout << userDoublesResults[ finalCounter ] << endl;
		     		
		     }	
		 }
		 
	   void findLuckyDoubles()
	   {
	   	int luckiestYet = 0;
	   	int luckyCounter;
	   	int doublesWinners[3][2]= {{0,0}, {0,0}, {0,0}};
	   	// search userDoublesResults for which value occurs the most often
	   	if (userDoublesResults[0] > 0)
	   	{
	        	// search array
                // based on the number of times that the user has won ...
                // grab first winner and count how many times that has been a winner
                luckiestYet = userDoublesResults[0];
                doublesWinners[0][0] = 1;
                doublesWinners[0][1] = userDoublesResults[0];
                
                for ( luckyCounter = 1; luckyCounter < doublesGamesWon; luckyCounter++)
                {
                
                	if ( userDoublesResults[luckyCounter] == doublesWinners[0][1])
                	{
                		doublesWinners[0][0] = doublesWinners[0][0] +1;
                    	luckiestYet = userDoublesResults[luckyCounter];
                	
    	            	userLuckyDoubles = luckiestYet;    
	                
	                }
	            }
	                	
	        	cout << "\nYour luckiest doubles today have been " << userLuckyDoubles << "'s!!!" << endl;
	        	cout << "You have won with them a total of " << doublesWinners[0][0] << " times." << endl;
	   	}
	       else
	       {
	        	cout << "\n :-(  sadly, you haven't been lucky in the doubles challenge yet, but don't give up now!!!!" << endl;
	       }
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
	   	 	cout << "With die # " << i+1 << " of " << qtyDies << ", you rolled a " << j << "!" << endl;

	   	     if ( qtyDies == 2 )
	   	 	{
	   	 		if ( i == 0 )
	   	 		{
	   	 			doubles1A = j;
	   	 		}
	   	 		else
	   	 		{
	   	 			doubles1B = j;		
	   	 		}
	   	 	}
	   	 }
	   	 
	   	 cout << " \n\n Yo, high roller!  I hope that you are having fun!!!!" << endl;
	   }
						
		void rollAgain()
		{
			 cout << "\n That was awesome!  Would you like to roll again?  ( Y or N ): ";
			 cin >> userReady;		
		}
						
		void updateDoublesResults()
		{
			 // results
	         doublesGamesPlayed = doublesGamesPlayed +1;
	         
	         findLuckyDoubles();
	         
	        cout << "\nYou have now won a total of " << doublesGamesWon << " out of a total of " << doublesGamesPlayed << endl;

		}	
		
		void userSession()
		{

		     greetUser();
		     qtySides();
		     doublesChallenge();

             if ( userChallenge != "Y" )
             {
			       qtyDice();
        
                   while ( userReady == "Y" )
                   {
            	         highRoller();
            	         rollAgain();
                   }
              }
              finalResults();
		}
									
	   ~dice()
	   {
	   	cout << "Thank you, " << userFirstName << ".  Goodbye.\n";
	   }
};

int main()
{
		dice user1;
		
		user1.userSession();

		return(0);	
}