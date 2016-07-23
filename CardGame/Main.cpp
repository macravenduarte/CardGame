#include "DeckCards.h"
#include <iostream>

using namespace std;
//prototype
void gameStart();
void cardResult(card, card);
bool getGameResult(bool);
void addPlayerPoints();
void addAiPoints();
int getPlayerPoints();
int getAiPoints();
int playerPoints, aiPoints;

int main(){

	bool game = true;
	int selection;

	//start game loop
	do {
		playerPoints = 0;
		aiPoints = 0;

		gameStart();

		cout << "Do You Want To Play Again?" << endl;
		cout << "1 = yes, 0 = no" << endl;
		cin >> selection;
		if (selection != 1) {
			game = false;
		}
	
	} while (game);

	system("PAUSE");
	return 0;

}

//This method will run the game
void gameStart() {
	
	deckCards deck;
	card currentCard;

	//our added code to for human and ai
	card humanHand, aiHand;
	bool winner = false;
	
	//run a loop that will continue the game 
	do {

		deck.shuffle();
		cout << endl << endl;
		//deal to the player
		humanHand = deck.dealCard();
		cout << "Your Current hand is " << humanHand.print() << endl;
		//deal to the ai
		aiHand = deck.dealCard();
		cout << "Your opponents hand is " << aiHand.print() << endl;

		cardResult(humanHand, aiHand);	//check who has the winning hand
		winner = getGameResult(winner);	//check to see who has the most points, best 2 out of 3
		
	} while(!winner);

}

//this method will compare the two hands dealt to the user and ai. 
void cardResult(card humanHand, card aiHand) {

	//local variable to comare face values
	int human = humanHand.getFaceValue(), ai = aiHand.getFaceValue();

	//checks if the player scored a point
	if (human > ai) {
		addPlayerPoints();
		cout << "Player Scores a Point!!!!" << endl;
		cout << "Player has " << getPlayerPoints() << " point(s)." << endl;
		system("PAUSE");
	}
	//checks if the ai scored a point
	else if (human < ai) {
		addAiPoints();
		cout << "Ai Scores a Point!!!!" << endl;
		cout << "Ai has " << getAiPoints() << " point(s)." << endl;
		system("PAUSE");
	}
	//tie and no points awarded
	else {
		cout << "Tie no points awarded!!!!" << endl;
		cout << "The score is:" << endl;
		cout << "Player: " << getPlayerPoints() << " point(s)." << endl;
		cout << "Ai: " << getAiPoints() << " point(s)." << endl;
		system("PAUSE");
	}

}

//This method will get the game result and set the point limit to win
bool getGameResult(bool winner) {

	int const POINTSTOWIN = 10;
	bool result = false; 

	//checks if the player won
	if (playerPoints == POINTSTOWIN) {
		cout << "Player has " << getPlayerPoints() << " point(s)." << endl;
		cout << "Player Wins!!" << endl;
		result = true;
		playerPoints = 0;
		system("PAUSE");
	}
	//checks if the ai won
	else if (aiPoints == POINTSTOWIN) {
		cout << "Ai has " << getAiPoints() << " point(s)." << endl;
		cout << "Ai Wins!!" << endl;
		result = true;
		aiPoints = 0;
		system("PAUSE");
	}
	//continue the game
	else {
		result = false;
	}

	winner = result;

	return winner;
}

//This method adds a point for the Player
void addPlayerPoints() {
	playerPoints++;
}

//This method adds a point for the Ai
void addAiPoints() {
	aiPoints++;
}

//This method returns the player points
int getPlayerPoints() {
	return playerPoints;
}

//This method returns the Ai points
int getAiPoints() {
	return aiPoints;
}