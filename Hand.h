/*
 * Hand.h
 *
 *  Created on: 7 nov. 2018
 *      Author: xxmostrg
 */

#ifndef HAND_H_
#define HAND_H_
#include <iostream>
using namespace std;
#include "Card.h"
#include <vector>
#include <algorithm>
#include <functional>
#include <array>


class Hand {
public:
	Hand();
	virtual ~Hand();
	std::vector<Card> cards;
	void printHand();
	void assign(int amount, std::vector<Card>& deck);
	void sorter();
	int point = 0;
	std::vector<Card> isRoyalStraightFlush();
	std::vector<Card> isStraightFlush();
	std::vector<Card> isFourOfAKind();
	std::vector<Card> isFullHouse();
	std::vector<Card> isFlush();
	std::vector<Card> isStraight();
	std::vector<Card> isThreeOfAKind();
	std::vector<Card> isTwoPair();
	std::vector<Card> isPair();
	void isHighCard();
	int evaluate();
	void combine(Hand dealerHand);
	int intIsHighCard(std::vector<Card> card1);

};

#endif /* HAND_H_ */
