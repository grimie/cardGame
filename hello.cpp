/*
 * hello.cpp
 *
 *  Created on: 7 nov. 2018
 *      Author: xxmostrg
 */

#include <iostream>
using namespace std;
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Test.h"

#include <vector>

int main() {
Test test;
test.allTest();
//	cout << "Hello, world!" << endl;
	Deck deck;
	deck.createDeck();
	deck.shuffle();
	//deck.printDeck();
	Hand hand;
	hand.assign(2, deck.cards);
	cout << "hand";
	hand.printHand();
	int point = hand.evaluate();
	cout << "point is " << point << endl;
	Hand dealerHand;
	dealerHand.assign(5, deck.cards);
	hand.combine(dealerHand);
	hand.printHand();
	point = hand.evaluate();
	cout << "point is " << point;
	return 0;
}
