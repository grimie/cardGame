/*
 * Deck.cpp
 *
 *  Created on: 7 nov. 2018
 *      Author: xxmostrg
 */

#include "Deck.h"
#include <algorithm>    // std::random_shuffle
#include <numeric>      // std::iota
#include <random>
#include <iostream>
#include <ctime>

Deck::Deck() {
}

Deck::~Deck() {
	// TODO Auto-generated destructor stub
}

void Deck::createDeck(){

	std::vector<int> numbers(13);
	std::iota(numbers.begin(), numbers.end(), 1);
	std::vector<std::string> suits = {"Clubs", "Hearts", "Diamonds", "Spade"};
	for (auto number : numbers) {
		for (auto suit : suits) {
			Card tempCard;
			tempCard.number = number;
			tempCard.suit = suit;
			cards.push_back(tempCard);

		}
	}
	cout << "deck is created" << endl;
}

	void Deck::printDeck()
	{
		for (auto card : cards) {
			card.printCard();
		}
	}
	void Deck::shuffle()
	{
		srand(time(NULL));
		std::random_shuffle ( cards.begin(), cards.end());
	}


