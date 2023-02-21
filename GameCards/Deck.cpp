#include "Card.h"
#include "Deck.h"
#include <vector>
#include <ctime>
using std::string;
using std::vector;
using namespace std;



	Deck::Deck() {			
		deck.push_back(Card(Number::King, Suit::Clubs));
		deck.push_back(Card(Number::Queen, Suit::Clubs));
		deck.push_back(Card(Number::Jack, Suit::Clubs));
		deck.push_back(Card(Number::Ten, Suit::Clubs));
		deck.push_back(Card(Number::Nine, Suit::Clubs));
		deck.push_back(Card(Number::Eight, Suit::Clubs));
		deck.push_back(Card(Number::Seven, Suit::Clubs));
		deck.push_back(Card(Number::Six, Suit::Clubs));
		deck.push_back(Card(Number::Five, Suit::Clubs));
		deck.push_back(Card(Number::Four, Suit::Clubs));
		deck.push_back(Card(Number::Three, Suit::Clubs));
		deck.push_back(Card(Number::Two, Suit::Clubs));
		deck.push_back(Card(Number::Ace, Suit::Clubs));
		
		deck.push_back(Card(Number::King, Suit::Diamonds));
		deck.push_back(Card(Number::Queen, Suit::Diamonds));
		deck.push_back(Card(Number::Jack, Suit::Diamonds));
		deck.push_back(Card(Number::Ten, Suit::Diamonds));
		deck.push_back(Card(Number::Nine, Suit::Diamonds));
		deck.push_back(Card(Number::Eight, Suit::Diamonds));
		deck.push_back(Card(Number::Seven, Suit::Diamonds));
		deck.push_back(Card(Number::Six, Suit::Diamonds));
		deck.push_back(Card(Number::Five, Suit::Diamonds));
		deck.push_back(Card(Number::Four, Suit::Diamonds));
		deck.push_back(Card(Number::Three, Suit::Diamonds));
		deck.push_back(Card(Number::Two, Suit::Diamonds));
		deck.push_back(Card(Number::Ace, Suit::Diamonds));
		
		deck.push_back(Card(Number::King, Suit::Hearts));
		deck.push_back(Card(Number::Queen, Suit::Hearts));
		deck.push_back(Card(Number::Jack, Suit::Hearts));
		deck.push_back(Card(Number::Ten, Suit::Hearts));
		deck.push_back(Card(Number::Nine, Suit::Hearts));
		deck.push_back(Card(Number::Eight, Suit::Hearts));
		deck.push_back(Card(Number::Seven, Suit::Hearts));
		deck.push_back(Card(Number::Six, Suit::Hearts));
		deck.push_back(Card(Number::Five, Suit::Hearts));
		deck.push_back(Card(Number::Four, Suit::Hearts));
		deck.push_back(Card(Number::Three, Suit::Hearts));
		deck.push_back(Card(Number::Two, Suit::Hearts));
		deck.push_back(Card(Number::Ace, Suit::Hearts));
		
		deck.push_back(Card(Number::King, Suit::Spades));
		deck.push_back(Card(Number::Queen, Suit::Spades));
		deck.push_back(Card(Number::Jack, Suit::Spades));
		deck.push_back(Card(Number::Ten, Suit::Spades));
		deck.push_back(Card(Number::Nine, Suit::Spades));
		deck.push_back(Card(Number::Eight, Suit::Spades));
		deck.push_back(Card(Number::Seven, Suit::Spades));
		deck.push_back(Card(Number::Six, Suit::Spades));
		deck.push_back(Card(Number::Five, Suit::Spades));
		deck.push_back(Card(Number::Four, Suit::Spades));
		deck.push_back(Card(Number::Three, Suit::Spades));
		deck.push_back(Card(Number::Two, Suit::Spades));
		deck.push_back(Card(Number::Ace, Suit::Spades));
		shuffle();
	}
	
	


	void Deck::swap(int a, int b) {
		Card temp = deck[a];
		deck[a] = deck[b];
		deck[b] = temp;
	}


	void Deck::shuffle() {
		srand((unsigned int)time(NULL));
		for (int i = 0; i < (int)deck.size(); i++) {
			swap(i, rand() % 52);
		}
		for (int i = 0; i < 200; i++) {
			swap(rand() % 52, rand() % 52);
		}
	}

	Card Deck::dealCard(){
		    //takes a card from the pile

		Card a = deck.back();
		deck.pop_back();
		//cout << "card has been dealt: " << wordNum(a.getNumber()) << " " << wordSuit(a.getSuit()) << endl;
		return a;
	}

	int Deck::deckLeft() {
		return (int) deck.size();
	}
















