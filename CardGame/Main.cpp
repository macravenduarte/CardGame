#include "DeckCards.h"

using namespace std;
//prototype
void Result(card, card);

int main(){

	deckCards deck;
	card currentCard;
	//our added code to for human and ai
	card humanHand, aiHand;

	
	//deck.printDeck();
	deck.shuffle();
	//cout << endl << endl;
	//deck.printDeck();
	deck.shuffle();
	cout << endl << endl;

	for (int i = 0; i < 1; i++){
		//currentCard = deck.dealCard();
		humanHand = deck.dealCard();
		//cout << "Your Current hand is " << humanHand.print() << endl;
		aiHand = deck.dealCard();
		//cout << "Your opponents hand is " << aiHand.print() << endl;

		Result(humanHand, aiHand);
	}

	system("PAUSE");
	return 0;

}

//this method will compare the two hands dealt to the user and ai. 
void Result(card humanHand, card aiHand) {

	cout << humanHand.getFaceValue();
	cout << aiHand.getFaceValue();
}