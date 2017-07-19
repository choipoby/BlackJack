#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>

#include "card.h"
#include "dealer.h"
#include "player.h"

using namespace std;

int main(int argc, char** argv)
{
  shared_ptr<Dealer> dealer = make_shared<Dealer>();
  shared_ptr<Player> player = make_shared<Player>(dealer);
  dealer->addPlayer(player);

  int gameCount = 0;
  do{
    string answer;
    cout << "Do you want to start a new game? (Y/N)";
    getline (cin, answer);
    if(answer == "n" || answer =="N") {
      cout << "Bye" << endl;
      break;
    }
    gameCount %= 6;
    if (gameCount++ == 0) {
        dealer->shuffleDeck();
    }

    dealer->startNewGame();
    do{
      cout << "stand or hit? (S/H)";
      getline (cin, answer);
      if(answer == "S"){
        dealer->stand();
        break;
      } else if (answer =="H") {
        dealer->hit();
        if(!dealer->winnerDecided()){
          continue;
        }
      } else {
        continue;
      }
    }while(true);
  }while(true);

  return 0;
}
