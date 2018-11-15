/*
 * Test.h
 *
 *  Created on: 8 nov. 2018
 *      Author: xxmostrg
 */

#ifndef TEST_H_
#define TEST_H_
#include <iostream>
using namespace std;
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include <vector>
#include <algorithm>    // std::random_shuffle
#include <numeric>      // std::iota
class Test {
public:
	Test();
	virtual ~Test();
	Hand testHand;
	void createTestHand(std::string rank);
	void allTest();
};

#endif /* TEST_H_ */
