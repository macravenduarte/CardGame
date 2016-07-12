#include "DeckCards.h"
#include <iostream>

using namespace std;
//prototype
void Result(card, card);

int main(){

	deckCards deck;
	card currentCard;
	//our added code to for human and ai
	card humanHand, aiHand;
	bool game = true;
	int selection;

	//start game loop
	do {

		deck.shuffle();
		cout << endl << endl;

		humanHand = deck.dealCard();
		cout << "Your Current hand is " << humanHand.print() << endl;
		aiHand = deck.dealCard();
		cout << "Your opponents hand is " << aiHand.print() << endl;

		Result(humanHand, aiHand);
		
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

//this method will compare the two hands dealt to the user and ai. 
void Result(card humanHand, card aiHand) {

	//local variable to comare face values
	int human = humanHand.getFaceValue();
	int ai = aiHand.getFaceValue();

	if (human > ai) {

		cout << "Player Wins!!!!" << endl;
	}
	else if (human < ai) {

		cout << "Ai Wins!!!!" << endl;

	}
	else {

		cout << "Tie Game but Ai Wins!!!!" << endl;

	}

}