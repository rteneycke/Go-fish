#pragma once
#include "Card.h"
#include <vector>
#include <ctime>
using std::string;
using std::vector;
using namespace std;


class Deck {
public:
	vector<Card> deck;

	Deck();




	void swap(int a, int b);


	void shuffle();

	Card dealCard();

	int deckLeft();
};