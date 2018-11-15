/*
 * Card.h
 *
 *  Created on: 7 nov. 2018
 *      Author: xxmostrg
 */

#ifndef CARD_H_

#define CARD_H_
#include <iostream>
using namespace std;
#include <vector>

class Card {
public:
	Card();
	virtual ~Card();
	int number;
	std::string suit;
	Card getCard(Card card);
	void printCard();
	void createCard(int number, std::string suit);
};

#endif /* CARD_H_ */
