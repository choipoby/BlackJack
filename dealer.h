#ifndef _DEALER_H_
#define _DEALER_H_

#include <deque>
#include <vector>
#include <memory>

#include "card.h"
#include "player.h"

class Dealer
{
public:
  Dealer();
  virtual ~Dealer();
  void addPlayer(std::shared_ptr<Player> player);
  void shuffleDeck();
  void startNewGame();
  bool winnerDecided();
  void stand();
  void hit();
private:
  std::deque<Card> mDeck;
  std::vector<Card> mDeaderCards;
  std::vector<Card> mPlayerCards;
  std::shared_ptr<Player> mPlayer;
  int mNumGames;
};

#endif
