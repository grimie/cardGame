/*
 * Test.cpp
 *
 *  Created on: 8 nov. 2018
 *      Author: xxmostrg
 */

#include "Test.h"

Test::Test() {
	// TODO Auto-generated constructor stub

}

Test::~Test() {
	// TODO Auto-generated destructor stub
}

void Test::createTestHand(std::string rank) {
	Card card1;
	Card card2;
	Card card3;
	Card card4;
	Card card5;
	std::vector<Card> tempHand;
	if (rank == "pair") {
		cout << "creating pair" << endl;

		card1.createCard(1, "Clubs");
		card2.createCard(1, "Diamonds");
		card3.createCard(4, "Hearts");
		card4.createCard(2, "Hearts");
		card5.createCard(3, "Hearts");
		tempHand.push_back(card1);
		tempHand.push_back(card2);
		tempHand.push_back(card3);
		tempHand.push_back(card4);
		tempHand.push_back(card5);
		testHand.assign(5, tempHand);

	}

	if (rank == "threeOfAKind") {
//		cout << "creating triplet" << endl;

		card1.createCard(1, "Diamonds");

		card2.createCard(1, "Clubs");
		card3.createCard(1, "Hearts");
		card4.createCard(2, "Hearts");
		card5.createCard(3, "Hearts");
		tempHand.push_back(card1);
		tempHand.push_back(card2);
		tempHand.push_back(card3);
		tempHand.push_back(card4);
		tempHand.push_back(card5);
		testHand.assign(5, tempHand);



	}
	if (rank == "twoPair") {
			cout << "creating two pair" << endl;

			card1.createCard(1, "Clubs");

			card2.createCard(1, "Diamonds");
			card3.createCard(2, "Hearts");
			card4.createCard(2, "Hearts");
			card5.createCard(3, "Hearts");
			tempHand.push_back(card1);
			tempHand.push_back(card2);
			tempHand.push_back(card3);
			tempHand.push_back(card4);
			tempHand.push_back(card5);
			testHand.assign(5, tempHand);



		}
	if (rank == "straight") {
//			cout << "creating straight" << endl;

			card1.createCard(1, "Clubs");

			card2.createCard(2, "Diamonds");
			card3.createCard(3, "Hearts");
			card4.createCard(4, "Hearts");
			card5.createCard(5, "Hearts");
			tempHand.push_back(card1);
			tempHand.push_back(card2);
			tempHand.push_back(card3);
			tempHand.push_back(card4);
			tempHand.push_back(card5);
			testHand.assign(5, tempHand);

		}
	if (rank == "flush") {
//			cout << "creating straight" << endl;

			card1.createCard(1, "Hearts");

			card2.createCard(2, "Hearts");
			card3.createCard(5, "Hearts");
			card4.createCard(6, "Hearts");
			card5.createCard(8, "Hearts");
			tempHand.push_back(card1);
			tempHand.push_back(card2);
			tempHand.push_back(card3);
			tempHand.push_back(card4);
			tempHand.push_back(card5);
			testHand.assign(5, tempHand);

		}
	if (rank == "fullHouse") {
			card1.createCard(1, "Hearts");
			card2.createCard(1, "Hearts");
			card3.createCard(1, "Hearts");
			card4.createCard(2, "Hearts");
			card5.createCard(2, "Hearts");
			tempHand.push_back(card1);
			tempHand.push_back(card2);
			tempHand.push_back(card3);
			tempHand.push_back(card4);
			tempHand.push_back(card5);
			testHand.assign(5, tempHand);

		}
	if (rank == "fourOfAKind") {
			card1.createCard(1, "Hearts");
			card2.createCard(1, "Hearts");
			card3.createCard(1, "Hearts");
			card4.createCard(1, "Hearts");
			card5.createCard(2, "Hearts");
			tempHand.push_back(card1);
			tempHand.push_back(card2);
			tempHand.push_back(card3);
			tempHand.push_back(card4);
			tempHand.push_back(card5);
			testHand.assign(5, tempHand);

		}
	if (rank == "straightFlush") {
				card1.createCard(10, "Hearts");
				card2.createCard(11, "Hearts");
				card3.createCard(12, "Hearts");
				card4.createCard(13, "Hearts");
				card5.createCard(9, "Hearts");
				tempHand.push_back(card1);
				tempHand.push_back(card2);
				tempHand.push_back(card3);
				tempHand.push_back(card4);
				tempHand.push_back(card5);
				testHand.assign(5, tempHand);

			}
//	testHand.printHand();

}

void Test::allTest()
{
	//testing Pair
		Test testPair;
		testPair.createTestHand("pair");
	//	testPair.testHand.sorter();
		testPair.testHand.evaluate();
		cout << "hand point is: " << testPair.testHand.point
				<< " and should be 200 + high card" << endl;
	//testing triplet
		Test testTreeOfAKind;
		testTreeOfAKind.createTestHand("threeOfAKind");
	//	testTreeOfAKind.testHand.sorter();
		testTreeOfAKind.testHand.evaluate();
		cout << "hand point is: " << testTreeOfAKind.testHand.point
				<< " and should be 400 + high card" << endl;
	//testing twoPair
		Test twoPair;
		twoPair.createTestHand("twoPair");
	//	twoPair.testHand.sorter();
	//	twoPair.testHand.printHand();
		twoPair.testHand.evaluate();
		cout << "hand point is: " << twoPair.testHand.point
				<< " and should be 300 + high card" << endl;
		//testing straight
		Test straight;
		straight.createTestHand("straight");
	//	twoPair.testHand.sorter();
	//	straight.testHand.printHand();
		straight.testHand.evaluate();
		cout << "hand point is: " << straight.testHand.point
				<< " and should be 500 + high card" << endl;
		//testing flush
		Test flush;
		flush.createTestHand("flush");
	//	twoPair.testHand.sorter();
		flush.testHand.printHand();
		flush.testHand.evaluate();
		cout << "hand point is: " << flush.testHand.point
				<< " and should be 600 + high card" << endl;
		//testing fullHouse
		Test fullHouse;
		fullHouse.createTestHand("fullHouse");
	//	twoPair.testHand.sorter();
	//	fullHouse.testHand.printHand();
		fullHouse.testHand.evaluate();
		cout << "hand point is: " << fullHouse.testHand.point
				<< " and should be 700 + high card" << endl;
		//testing fourOfAKind
		Test fourOfAKind;
		fourOfAKind.createTestHand("fourOfAKind");
	//	twoPair.testHand.sorter();
	//	fullHouse.testHand.printHand();
		fourOfAKind.testHand.evaluate();
		cout << "hand point is: " << fourOfAKind.testHand.point
				<< " and should be 800 + high card" << endl;
		//testing straightFlush
		Test straightFlush;
		straightFlush.createTestHand("straightFlush");
		straightFlush.testHand.sorter();
		straightFlush.testHand.printHand();
		straightFlush.testHand.evaluate();
		cout << "hand point is: " << straightFlush.testHand.point
				<< " and should be 900 + high card" << endl;


	}
