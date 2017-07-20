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
    std::unique_ptr<Card> issueCard();

private:
    std::deque<std::unique_ptr<Card>> mDeck;
    std::vector<std::unique_ptr<Card>> mDealerCards;
    std::vector<std::unique_ptr<Card>> mPlayerCards;
    std::vector<std::shared_ptr<Player>> mPlayers;
    int mNumGames;
};

#endif
