#include "dealer.h"
#include "player.h"

using namespace std;

Dealer::Dealer()
{
  vector<string> kinds = {"spade", "heart", "clover", "diamond"};
  vector<string>::iterator itr = kinds.begin();
  for(;itr!=kinds.end(); itr++){
    for(int i=1; i<=12; i++){
      Card card(*itr, i);
      mDeck.push_back(card);
    }
  }
}

Dealer::~Dealer()
{
  mDeck.clear();
}

void Dealer::addPlayer(shared_ptr<Player> player)
{
  mPlayer = player;
}

void Dealer::shuffleDeck()
{
  std::random_shuffle(mDeck.begin(), mDeck.end());
}

void Dealer::startNewGame()
{
  mPlayerCards.push_back(mDeck.front());
  mDeck.front().show();
  mDeck.pop_front();
}

bool Dealer::winnerDecided()
{
  int sum = 0;
  vector<Card>::const_iterator citr = mPlayerCards.begin();
  for(; citr!=mPlayerCards.end(); citr++) {
    sum += citr->number();
  }
  return true;
}

void Dealer::stand()
{
}

void Dealer::hit()
{
}
