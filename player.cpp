#include "dealer.h"
#include "player.h"
using namespace std;

Player::Player(shared_ptr<Dealer> dealer)
  : mDealer(dealer)
{
}

Player::~Player()
{
}

unsigned int Player::stand()
{
    return 0;
}

unsigned int Player::hit(int howmany)
{
    shared_ptr<Dealer> dealer = mDealer.lock();
    if ( dealer ) {
        for(int i = 0; i<howmany; i++) {
            unique_ptr<Card> card = move(dealer->issueCard());
            card->show();
            mSum += card->number();
            if (card->number() == 1) {
                mAceCount++;
            }
            cout << "-- sum : " << mSum << endl;
        }
    }

    if ( mSum + mAceCount*10 < 21 ) {
        mSum = mSum + mAceCount*10;
    }

    cout << "sum : " << mSum << endl;

    return mSum;
}
