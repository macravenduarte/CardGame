#ifndef CARD_H
#define CARD_H
#include <string>
#include <iostream>


using namespace std;

class card{

public:
	card(string cardFace, string cardsuit); //constructor
	string print() const;
	int getFaceValue();
	card(); // default constructor

private:
	string face;
	string suit;

};

card::card(){

}
card::card(string cardFace, string cardSuit){
	face = cardFace;
	suit = cardSuit;
}
string card::print() const{
	return (face + " of " + suit);
}

int card::getFaceValue() {
	
	int newFace;

	//do a check if the face value is J, Q, K, A

	//if a real number
	if (isdigit(face[0])) {
		newFace = stoi(face);
	}
	//if not, compare the Face value to the letter for a value output
	else if (face == "J") {
		newFace = 11;
	}
	else if (face == "Q") {
		newFace = 12;
	}
	else if (face == "K") {
		newFace = 13;
	}
	else if (face == "A") {
		newFace = 1;
	}
	

	return newFace;
}
#endif