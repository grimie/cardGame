/*
 * Deck.h
 *
 *  Created on: 7 nov. 2018
 *      Author: xxmostrg
 */

#ifndef DECK_H_
#define DECK_H_
#include <iostream>
using namespace std;
#include "Card.h"
#include <vector>
class Deck {
public:
	Deck();
	virtual ~Deck();
	std::vector<Card> cards;
	void createDeck();
	void printDeck();
	void shuffle();
};

#endif /* DECK_H_ */
