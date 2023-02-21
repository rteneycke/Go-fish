#include "Card.h"
#include <iostream>
using std::string;





Card::Card(Number n, Suit s) {
        num = n;
        suit = s;
    }

    Number Card::getNumber() {
        return num;
    }
    Suit Card::getSuit() {
        return suit;
    }


    string word(Number i) {// Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };
        switch (i) {
        case Number::Ace:
            return "Ace"; break;
        case Number::Two:
            return "Two"; break;
        case Number::Three:
            return "Three"; break;
        case Number::Four:
            return "Four"; break;
        case Number::Five:
            return "Five"; break;
        case Number::Six:
            return "Six"; break;
        case Number::Seven:
            return "Seven"; break;
        case Number::Eight:
            return "Eight"; break;
        case Number::Nine:
            return "Nine"; break;
        case Number::Ten:
            return "Ten"; break;
        case Number::Jack:
            return "Jack"; break;
        case Number::Queen:
            return "Queen"; break;
        case Number::King:
            return "King"; break;
        }
    }
    string word(Suit s) {//enum Suit { Clubs, Diamonds, Hearts, Spades };
        switch (s) {
        case Suit::Clubs:
            return "Clubs"; break;
        case Suit::Diamonds:
            return "Diamonds"; break;
        case Suit::Hearts:
            return "Hearts"; break;
        case Suit::Spades:
            return "Spades"; break;
        }
    }

