#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <memory>

class Dealer;

class Player
{
public:
  Player(std::shared_ptr<Dealer> dealer);
  virtual ~Player(){};

private:
  std::weak_ptr<Dealer> mDealer;
};

#endif
