/*
 * Card.cpp
 *
 *  Created on: 7 nov. 2018
 *      Author: xxmostrg
 */

#include "Card.h"
#include "Deck.h"
Card::Card() {
	number = 0;
	suit = "";

}

Card::~Card() {
	// TODO Auto-generated destructor stub
}

Card Card::getCard(Card card){
	return card;
}

void Card::printCard()
{
std::string high;
if(number == 1){high = "Ace";}
if(number == 11){high = "Jack";}
if(number == 12){high = "Queen";}
if(number == 13){high = "King";}

if(high == ""){std::cout << "Card: "<< number << " of "<< suit << endl;}
else {
	std::cout << "Card: "<< high << " of "<< suit << endl;
}

}

void Card::createCard(int number, std::string suit)
{
this->number = number;
this->suit = suit;
}



