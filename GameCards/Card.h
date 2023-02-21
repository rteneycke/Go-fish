#pragma once
#include <string>


using std::string;


enum class Suit {Clubs, Diamonds, Hearts, Spades };
enum class Number { Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Nil };
class Card {

public:
    Number num;
    Suit suit;


    Card(Number n, Suit s);

    Number getNumber();
    Suit getSuit();
};

string word(Suit s);
string word(Number i);


