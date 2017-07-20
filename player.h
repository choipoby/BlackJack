#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <memory>
#include "card.h"

class Dealer;

class Player
{
public:
    Player(std::shared_ptr<Dealer> dealer);
    virtual ~Player();

    unsigned int stand();
    unsigned int hit(int howmany);

private:
    std::weak_ptr<Dealer> mDealer;
    std::vector<std::unique_ptr<Card>> mCards;
    int mAceCount;
    int mSum;
};

#endif
