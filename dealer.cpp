#include <algorithm>
#include <memory>

#include "dealer.h"
#include "player.h"

using namespace std;

Dealer::Dealer()
{
    vector<string> kinds = {"spade", "heart", "clover", "diamond"};
    vector<string>::iterator itr = kinds.begin();
    for(;itr!=kinds.end(); itr++){
        for(int i=1; i<=12; i++){
            mDeck.push_back(make_unique<Card>(*itr, i));
        }
    }
}

Dealer::~Dealer()
{
    mDeck.clear();
}

void Dealer::addPlayer(shared_ptr<Player> player)
{
    mPlayers.push_back(player);
}

void Dealer::shuffleDeck()
{
    random_shuffle(mDeck.begin(), mDeck.end());
}

void Dealer::startNewGame()
{
    //player->retrieveCards();

    // give one open, one closed cards to dealer
    cout << "dealer deck:" << endl;
    // open card
    unique_ptr<Card> card = move(issueCard());
    card->show(true);
    mDealerCards.push_back(move(card));
    // closed card
    card = move(issueCard());
    card->show(false);
    mDealerCards.push_back(move(card));

    // give two open cards to all players
    cout << "player deck:" << endl;
    vector<shared_ptr<Player>>::iterator itr = mPlayers.begin();
    for(; itr!=mPlayers.end(); itr++) {
        if (21 == (*itr)->hit(2) ) {
            //itr->won();
        };
    }
}

bool Dealer::winnerDecided()
{
    /*
    int sum = 0;
    vector<Card>::iterator itr = mPlayerCards.begin();
    for(; itr!=mPlayerCards.end(); itr++) {
        sum += itr->number();
    }
    */
    return true;
}

unique_ptr<Card> Dealer::issueCard()
{
    unique_ptr<Card> card;
    if(!mDeck.empty()){
        card = move(mDeck.at(0));
        mDeck.pop_front();
    }
    return card;
}
