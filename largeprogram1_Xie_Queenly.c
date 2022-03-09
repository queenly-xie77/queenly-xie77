//Queenly Xie
//Dr. Steinberg
//COP3223C
//Large Program 1

#define ROUNDS 5
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void greeting(); //display welcome message to user
void playRound(int round); //play one round
int pickOne(); //retrieve the user's guess
int computerPick(); //computer makes its pick
int battle(int player1, int player2); //battle rock...paper...scissor
void result(int player1, int player2); //overall winner of round

int main()
{
	greeting(); //displays greeting message
	
	//setup random generator
	int seed;
	printf("Before we start, pick a number to determine how random I will be.\n");
	scanf("%d", &seed);
    srand(seed);
	printf("All set now!\n");

	for(int x = 0; x < ROUNDS; ++x)
	{
		playRound(x + 1);
	}
	
	printf("********************************************************\n");
	printf("Thank you for playing!\n");
	return 0;
}

void greeting() //First User Defined Function: introduces game
{
	printf("Welcome to rock paper scissor game!\n");
	printf("Here are the rules.\n");
	printf("You and I will get to choose rock, paper, or scissor.\n");
	printf("After we made a decision we will reveal it and determine the winner based on these rules.\n");
	printf("Rock beats Scissor!\n");
	printf("Paper beats Rock!\n");
	printf("Scissor beats Paper!\n");
	printf("If we both pick the same option, then it is a tie.\n");
	printf("Ready to play?...Here we go!\n");
}

void playRound(int round) //Plays a whole round out of 3
{
	printf("Welcome to a new round %d!\n", round);
	printf("Best out of three...Let's go!\n");
	
	int p1wins = 0;
	int p2wins = 0;

	//Prints initial scores
	printf("Player 1 has won %d times.\n", p1wins); 
	printf("Player 2 has won %d times.\n", p2wins);

	
	while(p1wins != 3 && p2wins != 3) //While continues up till winner receives 3 wins
	{
		int player1 = pickOne();
		int player2 = computerPick();
		int roundResult = battle(player1, player2);

		//Adds points to winning scoreboard depending on the winner of round
		if(roundResult == 1)
		{
			printf("Player 1 has won %d times.\n", p1wins);
			printf("Player 2 has won %d times.\n", p2wins);
		}
		else if(roundResult == 2)
		{
			p1wins += 1;
			printf("Player 1 has won %d times.\n", p1wins);
			printf("Player 2 has won %d times.\n", p2wins);
		}
		else if(roundResult == 3)
		{
			p2wins += 1;
			printf("Player 1 has won %d times.\n", p1wins);
			printf("Player 2 has won %d times.\n", p2wins);
		}
		else 
		{
			printf("Player 1 has won %d times.\n", p1wins);
			printf("Player 2 has won %d times.\n", p2wins);
		}

	}

	//prints out result according to winner
	result(p1wins, p2wins); 
}

//Gets the player 1's input
int pickOne() 
{
	int selected;
	printf("1---Rock\n");
	printf("2---Paper\n");
	printf("3---Scissor\n");
	printf("Make your Selection: ");
	scanf("%d", &selected);
	
	//Accounts for incorrect inputs
	if(selected != 1 && selected != 2 && selected !=3) 
	{ 
		printf("Someone made an invalid choice.\n");
	}

	return selected;
}

//Gets the player 2's input
int computerPick()
{
	int lower = 1;
	int upper = 3;

	//randomizes number between 0 and 4
	int computerChoice = (rand() % (upper - lower + 1)) + lower;
	printf("I'm making my decision now.\n");
	return computerChoice;
}

//Executes the accurate print and return number depending on player inputs
int battle(int player1, int player2)
{

	int winnerResult = 0; //return of 1 = tie
						  //return of 2 = player1 win
						  //return of 3 = player2 win

	if(player1 == 1 && player2 == 1)
	{
		printf("Player1 and Player2 both used Rock!\n");
		printf("Draw!\n");
		winnerResult = 1;
	}
	else if(player1 == 2 && player2 == 2)
	{
		printf("Player1 and Player2 both used Paper!\n");
		printf("Draw!\n");
		winnerResult = 1;
	}
	else if(player1 == 3 && player2 == 3) //End of all the tied
	{
		printf("Player1 and Player2 both used Scissor!\n");
		printf("Draw!\n");
		winnerResult = 1;
	}
	else if(player1 == 1 && player2 == 2)
	{
		printf("Player 1 used Rock and Player 2 used Paper!\n");
		printf("Paper beats Rock!\n");
		winnerResult = 3;
	}
	else if(player1 == 1 && player2 == 3) //End of 1 Variations
	{
		printf("Player 1 used Rock and Player 2 used Scissor!\n");
		printf("Rock beats Scissor!\n");
		winnerResult = 2;
	}
	else if(player1 == 2 && player2 == 1)
	{
		printf("Player 1 used Paper and Player 2 used Rock!\n");
		printf("Paper beats Rock!\n");
		winnerResult = 2;
	}
	else if(player1 == 2 && player2 == 3) //End of 2 Variations
	{
		printf("Player 1 used Paper and Player 2 used Scissor!\n");
		printf("Scissor beats Paper!\n");
		winnerResult = 3;
	}
	else if(player1 == 3 && player2 == 1)
	{
		printf("Player 1 used Scissor and Player 2 used Rock!\n");
		printf("Rock beats Scissor!\n");
		winnerResult = 3;
	}
	else if(player1 == 3 && player2 == 2) //End of 3 Variations
	{
		printf("Player 1 used Scissor and Player 2 used Paper!\n");
		printf("Scissor beats Paper!\n");
		winnerResult = 2;
	}
	return winnerResult;
}

//Displays the result depending on the last score in playRound 
void result(int player1, int player2)
{
	//overall winner
	if (player1 == 3 && player2 < 3)
	{
		printf("You won! I'll let you have this one.\n");
	}
	else if(player1 < 3 && player2 == 3)
	{
		printf("I won! Haha better luck next time!\n");
	}
}


