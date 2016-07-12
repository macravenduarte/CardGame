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

	newFace = stoi(face);

	return newFace;
}
#endif