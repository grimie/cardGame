/*
 * Hand.cpp
 *
 *  Created on: 7 nov. 2018
 *      Author: xxmostrg
 */

#include "Hand.h"

Hand::Hand() {
	// TODO Auto-generated constructor stub

}

Hand::~Hand() {
	// TODO Auto-generated destructor stub
}

void Hand::printHand() {
	sorter();
	cout << "start of hand" << endl;
	for (auto card : cards) {
		card.printCard();

	}
	cout << "end of hand" << endl;
}

void Hand::assign(int amount, std::vector<Card>& deck) {
	for (int var = 0; var < amount; ++var) {
		cards.push_back(deck[var]);
	}
	deck.erase(deck.begin(), deck.begin() + amount);
}

void Hand::sorter() {
	std::sort(cards.begin(), cards.end(),
			[](Card & one, Card & two) {return one.number < two.number;});
}

std::vector<Card> Hand::isStraightFlush() {
	sorter();
	std::vector<Card> match;
	Card* card4before = nullptr;
	Card* card3before = nullptr;
	Card* card2before = nullptr;
	Card* card1before = nullptr;
	for (auto &card : cards) {
		if (card1before != nullptr && card2before != nullptr
				&& card3before != nullptr && card4before != nullptr) {
			if (card1before->suit == card.suit && card2before->suit == card.suit
					&& card3before->suit == card.suit
					&& card4before->suit == card.suit) {
				if (card1before->number + 1 == card.number
						&& card2before->number + 2 == card.number
						&& card3before->number + 3 == card.number
						&& card4before->number + 12 == card.number) {
					match.push_back(*card4before);
					match.push_back(*card3before);
					match.push_back(*card2before);
					match.push_back(*card1before);
					match.push_back(card);
				}

				else if (card1before->number + 1 == card.number
						&& card2before->number + 2 == card.number
						&& card3before->number + 3 == card.number
						&& card4before->number + 4 == card.number) {
					match.push_back(*card4before);
					match.push_back(*card3before);
					match.push_back(*card2before);
					match.push_back(*card1before);
					match.push_back(card);
				}
			}
		}
		card4before = card3before;
		card3before = card2before;
		card2before = card1before;
		card1before = &card;
	}
	return match;
}

std::vector<Card> Hand::isFourOfAKind() {
	sorter();
	std::vector<Card> match;
	Card* card3before = nullptr;
	Card* card2before = nullptr;
	Card* card1before = nullptr;

	for (auto &card : cards) {
		if (card1before != nullptr && card2before != nullptr
				&& card3before != nullptr && card1before->number == card.number
				&& card2before->number == card.number
				&& card3before->number == card.number) {
			match.push_back(*card1before);
			match.push_back(*card2before);
			match.push_back(*card3before);
			match.push_back(card);
		}
		card3before = card2before;
		card2before = card1before;
		card1before = &card;
	}
	return match;
}

std::vector<Card> Hand::isFullHouse() {
	bool foundTriplet = false;
	bool foundPair = false;
	std::vector<Card> fullHouse;
	int highCard = 0;

	vector<Card> cardscpy = cards;
	sorter();
	Card* card2before = nullptr;
	Card* card1before = nullptr;
	for (auto &card : cardscpy) {
		if (card1before != nullptr && card2before != nullptr
				&& card1before->number == card.number
				&& card2before->number == card.number) {
			foundTriplet = true;
			fullHouse.push_back(card);
			fullHouse.push_back(*card1before);
			fullHouse.push_back(*card2before);

			highCard = card.number;

		}
		card2before = card1before;
		card1before = &card;
	}
	if (foundTriplet) {
		Card* card1before = nullptr;
		for (auto &card : cards) {
			if (card1before != nullptr && card1before->number == card.number
					&& card.number != highCard) {
				foundPair = true;
				fullHouse.push_back(card);
				fullHouse.push_back(*card1before);

				if (highCard < card.number || card.number == 1) {
					highCard = card.number;
				}
			}
			card1before = &card;
		}
	}
	if (foundPair && foundTriplet) {
		return fullHouse;
	} else {
		std::vector<Card> empty;
		return empty;
	}
}
std::vector<Card> Hand::isFlush() {
	sorter();
	std::vector<Card> match;
	Card* card4before = nullptr;
	Card* card3before = nullptr;
	Card* card2before = nullptr;
	Card* card1before = nullptr;

	for (auto &card : cards) {
		if (card1before != nullptr && card2before != nullptr
				&& card3before != nullptr && card4before != nullptr
				&& card1before->suit == card.suit
				&& card2before->suit == card.suit
				&& card3before->suit == card.suit
				&& card4before->suit == card.suit) {
			match.push_back(*card4before);
			match.push_back(*card3before);
			match.push_back(*card2before);
			match.push_back(*card1before);
			match.push_back(card);
		}
		card4before = card3before;
		card3before = card2before;
		card2before = card1before;
		card1before = &card;
	}
	return match;
}
std::vector<Card> Hand::isStraight() {
	sorter();
	std::vector<Card> match;
	Card* card4before = nullptr;
	Card* card3before = nullptr;
	Card* card2before = nullptr;
	Card* card1before = nullptr;

	for (auto &card : cards) {
		if (card1before != nullptr && card2before != nullptr
				&& card3before != nullptr && card4before != nullptr
				&& card1before->number + 1 == card.number
				&& card2before->number + 2 == card.number
				&& card3before->number + 3 == card.number
				&& card4before->number + 4 == card.number) {
			match.push_back(*card4before);
			match.push_back(*card3before);
			match.push_back(*card2before);
			match.push_back(*card1before);
			match.push_back(card);
		}
		card4before = card3before;
		card3before = card2before;
		card2before = card1before;
		card1before = &card;
	}
	return match;
}
std::vector<Card> Hand::isThreeOfAKind() {
	sorter();

	std::vector<Card> match;
	Card* card2before = nullptr;
	Card* card1before = nullptr;
	for (auto &card : cards) {
		if (card1before != nullptr && card2before != nullptr
				&& card1before->number == card.number
				&& card2before->number == card.number) {
			match.push_back(card);
			match.push_back(*card1before);
			match.push_back(*card2before);
		}
		card2before = card1before;
		card1before = &card;
	}
	return match;
}
std::vector<Card> Hand::isTwoPair() {
	sorter();

	std::vector<Card> match;
	int pair = 0;
	Card* card2before = nullptr;
	Card* card1before = nullptr;
	for (auto &card : cards) {
		if (card2before == nullptr) {
			if (card1before != nullptr && card1before->number == card.number) {
				Card temp = *card1before;
				match.push_back(card);
				match.push_back(*card1before);
				pair++;
			}
		} else {
			if (card1before != nullptr && card1before->number == card.number
					&& card2before != nullptr
					&& card2before->number != card.number) {
				Card temp = *card1before;
				match.push_back(card);
				match.push_back(*card1before);
				pair++;
			}
		}

		card2before = card1before;
		card1before = &card;
	}
	if (pair > 1) {
		return match;
	} else {
		std::vector<Card> empty;
		return empty;
	}
}

std::vector<Card> Hand::isPair() {
	sorter();
	std::vector<Card> match;
	Card* card1before = nullptr;
	for (auto &card : cards) {
		if (card1before != nullptr && card1before->number == card.number) {
			if (point < 200) {
				match.push_back(card);
				match.push_back(*card1before);
			}
		}
		card1before = &card;
	}
	return match;
}

void Hand::isHighCard() {
	sorter();
	Card temp;
	temp = cards.back();
	Card front = cards.front();
	if (point <= 99) {
		point = 0;

		if (front.number == 1) {
			point += 14;
		} else {
			point += temp.number;
		}
	}
}

int Hand::intIsHighCard(std::vector<Card> cards) {
	int highCard = 0;
	for (auto card : cards) {
		if (card.number == 1) {
			highCard = 14;
			return highCard;
		}
		if (card.number > highCard) {
			highCard = card.number;
		}
	}
	return highCard;

}

int Hand::evaluate() {
	Hand func;
	func.cards = isStraightFlush();
	if (func.cards.size() > 0) {
		point = (900 + func.intIsHighCard(func.cards));
		return point;
	}
	func.cards = isFourOfAKind();
	if (func.cards.size() > 0) {
		point = (800 + func.intIsHighCard(func.cards));
		return point;
	}
	func.cards = isFullHouse();
	if (func.cards.size() > 0) {
		point = (700 + func.intIsHighCard(func.cards));
		return point;
	}
	func.cards = isFlush();
	if (func.cards.size() > 0) {
		point = (600 + func.intIsHighCard(func.cards));
		return point;
	}
	func.cards = isStraight();
	if (func.cards.size() > 0) {
		point = (500 + func.intIsHighCard(func.cards));
		return point;
	}
	func.cards = isThreeOfAKind();
	if (func.cards.size() > 0) {
		point = (400 + func.intIsHighCard(func.cards));
		return point;
	}
	func.cards = isTwoPair();
	if (func.cards.size() > 0) {
		point = (300 + func.intIsHighCard(func.cards));
		return point;
	}
	func.cards = isPair();
	if (func.cards.size() > 0) {
		point = (200 + func.intIsHighCard(func.cards));
		return point;
	}

	return point;
}

void Hand::combine(Hand dealerHand) {
	for (auto card : dealerHand.cards) {
		this->cards.push_back(card);
	}

}

