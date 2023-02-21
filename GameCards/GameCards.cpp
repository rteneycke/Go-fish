// GameCards.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Card.h"
#include "Deck.h"
#include <iostream>
#include <ctime>
#include <vector>
#include <chrono>
#include <thread>
#include<algorithm>


using namespace std;
using std::vector;
void dealDeck(Deck& d,  vector<vector<Card>>& playerList) {
    for (int i = 0; i < 5; i++) {
        for (int x = 0; x < (signed int)playerList.size(); x++) {
            playerList[x].push_back(d.dealCard());
        }        
    }
}
void showHand(vector<Card>& hand) {
    //cout << "player " << (p + 1) << ": " << player.size() << endl;
    for (int i = 0; i < (signed int)hand.size(); i++) {
        cout << i + 1 << " " << word(hand[i].getNumber()) << " " << word(hand[i].getSuit()) << "\n";
    }
}
void tellPoints(vector<vector<vector<Card>>> vec, int player) {
    cout << "you have this many points(sets of four): " << vec[player].size() << endl;
    for (int i = 0; i < vec[player].size(); i++) {
        cout << "set " << i + 1 << " is made of :" << word(vec[player][i][0].getNumber()) << endl;
    }
}
void noPeaking(int player) {
    cout << string(22, '\n');
    cout << string(22, '\n');
    cout << string(22, '\n');
    cout << string(22, '\n');
    cout << string(22, '\n');

    cout << "Player "<<player<<"'s turn, turn the screen to them and don't peak." <<'\n';
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    cout << 4 << '\n';
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    cout << 3 << '\n';
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    cout << 2 << '\n';
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    cout << 1<<"...." << '\n';
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    cout << string(22, '\n');
    cout << string(22, '\n');
    cout << string(22, '\n');
    cout << string(22, '\n');
    cout << string(22, '\n');
}

Number hasFour(vector<Card> cards) {
    //cout << "size of array : " << cards.size() << endl;
    int num = 0;
    int size = cards.size();
    for (int i = 0; i < size; i++) {
        num = 0;

        for (int b = 0; b < size; b++) {
            if (cards[i].getNumber() == cards[b].getNumber()) {
                num++;
            }                
            if (num == 4) {
                return cards[b].getNumber();
            }
        }

    }
    return Number::Nil;
}
vector<Card> takeSetOfFour(vector<Card>& cards, Number n) {
    vector<Card> set;
    //cout << "size of hand before remove: " << cards.size() << endl;
    for (int i = 0; i < cards.size(); i++) {
        if (cards[i].getNumber() == n) {
            set.push_back(cards[i]);
        }
    }
    for (int b = cards.size()-1; b >= 0; b--) {
        if (cards[b].getNumber() == n) {
            cards.erase(cards.begin()+b);
        }
    }
    //cout << "size of hand after remove: " << cards.size() << endl;
    return set;
}
void checkForFour(vector<vector<Card>>& playerList, vector<vector<vector<Card>>>& playerSetList) {
    //check if player hand does indeed have four of something.
    for (int i = 0; i < playerList.size(); i++) {
        if (hasFour(playerList[i]) != Number::Nil) {
            playerSetList[i].push_back(takeSetOfFour(playerList[i], hasFour(playerList[i])));
            //cout << "there were sets found:" << endl;
        }
        else {
           // cout << " there were no sets to be added to the set list" << endl;
        }
    }
}
void doYouHave(vector<Card>& takingTo, vector<Card>& takingFrom, Number n) {
    //asks player if they have a card and takes ONE if they have ONE.
    for (int i = 0; i < takingFrom.size(); i++) {
        if (takingFrom[i].getNumber() == n) {
            takingTo.push_back(takingFrom[i]);
            takingFrom.erase(takingFrom.begin() + i);
            return;
        }
    }


}
void goFish(Deck& d, vector<vector<Card>>& playerList, int player) {
    //takes a card from the pile

    if (d.deckLeft() > 0) {
        playerList[player].push_back(d.dealCard());
        cout << "Go FISH!";
    }
    else if (d.deckLeft() == 0) {
        cout << "Can't go fish! No more cards left in the pond." << endl;
    }


    
}
void playerTurn(int player, vector<vector<Card>>& playerList, vector<vector<vector<Card>>>& playerSetList) {
    //does the displaying of relevant information for the player who's turn it is
    noPeaking(player + 1);
    tellPoints(playerSetList, player);
    showHand(playerList[player]);    
}
void sortHand(vector<Card>& hand) {
    bool hadSwap = true;

    while (hadSwap) {
        hadSwap = false;
        for (int i = 0; i < hand.size()-1; i++) {
            if ((int)hand[i].getNumber() > (int)hand[i+1].getNumber()) {
                auto temp = hand[i];
                hand[i] = hand[i+1];
                hand[i+1] = temp;
                hadSwap = true;
            }
        }
    }
}
int main()
{
    Deck deck;

    int numPlayers=0;
    int whosTurn=0;
    bool gameover = false;

    vector<vector<Card>> playerList;
    vector<vector<vector<Card>>> playerSetList;
   
    // get the number of players
    while (numPlayers < 2 || numPlayers > 6) {
        cout << "please enter the number of players... below 2 and 3" << endl;
        cin >> numPlayers;
   }
   // create vector structure for the amount of players
    for (int i = 0; i < numPlayers; i++) {
        playerList.push_back(vector<Card>());
        playerSetList.push_back(vector<vector<Card>>());
    }


    dealDeck(deck, playerList);
    
    //playerTurn(whosTurn, playerList, playerSetList);
    noPeaking(whosTurn + 1);
    while (gameover == false) {

        cout << string(22, '\n');
        cout << string(22, '\n');
        cout << string(22, '\n');
        cout << string(22, '\n');
        cout << string(22, '\n');
        cout << "cards left: " << deck.deck.size() << endl;
        cout << "cards left 1: " << playerList[0].size() << endl;
        cout << "cards left 2: " << playerList[1].size() << endl;

        tellPoints(playerSetList, whosTurn);
        sortHand(playerList[whosTurn]);
        showHand(playerList[whosTurn]);
        



        int be;
        int af;
        be = playerSetList[whosTurn].size();
        checkForFour(playerList, playerSetList);
        af = playerSetList[whosTurn].size();
        if (be < af) {
            cout << "congratulations player: " << whosTurn + 1 << " you had four matching cards on the deal!(super lucky), keep playing!";
            std::this_thread::sleep_for(std::chrono::milliseconds(4000));
            cout << string(22, '\n');
            cout << string(22, '\n');
            cout << string(22, '\n');
            cout << string(22, '\n');
            cout << string(22, '\n');
            tellPoints(playerSetList, whosTurn);
            sortHand(playerList[whosTurn]);
            showHand(playerList[whosTurn]);
        }






        int selPlayer=1;
        int selCard=-11;

        cout << "who will you ask for a card?:" << endl;
        for (int i = 0; i < playerList.size(); i++) {
            if (whosTurn != i) {
                cout << "player " << i + 1 << endl;
            }
        }
        Number n;
        
        while (selPlayer == whosTurn+1 || selPlayer > playerList.size() || selPlayer < 1) {
            cin >> selPlayer;//select a player to see if they have the card
        }
        cin.ignore();
        cout << "what card will you ask for?(int)" << endl;
        cout << "1. Ace" << endl;
        cout << "2. Two" << endl;
        cout << "3. Three" << endl;
        cout << "4. Four" << endl;
        cout << "5. Five" << endl;
        cout << "6. Six" << endl;
        cout << "7. Seven" << endl;
        cout << "8. Eight" << endl;
        cout << "9. Nine" << endl;
        cout << "10. Ten" << endl;
        cout << "11. Jack" << endl;
        cout << "12. Queen" << endl;
        cout << "13. King" << endl;
        

        while (selCard < 1 || selCard > 13) {
            cin >> selCard;
        }
        cin.ignore();
        switch (selCard) {
        case 1:
            n= Number::Ace; break;
        case 2:
            n = Number::Two; break;
        case 3:
            n = Number::Three; break;
        case 4:
            n = Number::Four; break;
        case 5:
            n = Number::Five; break;
        case 6:
            n = Number::Six; break;
        case 7:
            n = Number::Seven; break;
        case 8:
            n = Number::Eight; break;
        case 9:
            n = Number::Nine; break;
        case 10:
            n = Number::Ten; break;
        case 11:
            n = Number::Jack; break;
        case 12:
            n = Number::Queen; break;
        case 13:
            n = Number::King; break;
        
        }
        int before;
        int after;
        before = playerList[whosTurn].size();
        doYouHave(playerList[whosTurn], playerList[(int)selPlayer - 1], n);
        after = playerList[whosTurn].size(); 
        if (before == after) {
            goFish(deck, playerList, whosTurn);
            
            std::this_thread::sleep_for(std::chrono::milliseconds(4000));
            int b;
            int a;
            b = playerSetList[whosTurn].size();
            checkForFour(playerList, playerSetList);
            a = playerSetList[whosTurn].size();
            if (b == a) {
                if (whosTurn < playerList.size()-1) {
                    whosTurn++;
                    noPeaking(whosTurn + 1);
                }
                else if (whosTurn==playerList.size()-1) {
                    whosTurn = 0;
                    noPeaking(whosTurn + 1);
                }
                
            }
            else {
                cout << "congratulations player: " << whosTurn + 1 << " you have found a set, keep playing!";
                std::this_thread::sleep_for(std::chrono::milliseconds(4000));
                cout << string(22, '\n');
                cout << string(22, '\n');
                cout << string(22, '\n');
                cout << string(22, '\n');
                cout << string(22, '\n');
                whosTurn = whosTurn;
            }
        }
        else if (before < after) {
            
            int b;
            int a;
            b = playerSetList[whosTurn].size();
            checkForFour(playerList, playerSetList);
            a = playerSetList[whosTurn].size();
            if (b < a) {
                cout << "congratulations player: " << whosTurn + 1 << " you have found a set, keep playing!";
                std::this_thread::sleep_for(std::chrono::milliseconds(4000));
               
            }
            else {
                cout << "you have found a card!, keep playing!";
                std::this_thread::sleep_for(std::chrono::milliseconds(4000));
            }
            cout << string(22, '\n');
            cout << string(22, '\n');
            cout << string(22, '\n');
            cout << string(22, '\n');
            cout << string(22, '\n');

            whosTurn = whosTurn;
        }
        int hasCards = 0;
        for (int i = 0; i < playerList.size(); i++) {
            hasCards += playerList[i].size();
        }
        if (deck.deckLeft() == 0 && hasCards ==0) {
            gameover = true;
        }
    }

    


    cout << "GAME IS OVER" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(4000));

    int winner = 0;
    int points = 0;
    for (int i = 0; i < playerSetList.size(); i++) {
        if (playerSetList[i].size() > points) {
            points = playerSetList[i].size();
            winner = i;
        }
        cout << "Player " << i + 1 << " has " << playerSetList[i].size() << " points." << endl;
    }
    cout << "Player " << winner + 1 << " is the winner!" << endl;






}

