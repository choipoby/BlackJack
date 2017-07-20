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
      cout << "stand or hit? (S/H) or quit(Q)";
      getline (cin, answer);
      if(answer == "S"){
        player->stand();
        break;
      } else if (answer =="H") {
          int result = player->hit(1);

          if (result == 21 ) {
              cout << "player won" << endl;
          } else if (result > 21) {
              cout << "player lost" << endl;
              break;
          }
      } else if (answer == "Q" || answer == "q"){
          cout << "Bye" << endl;
          return 0;
      } else {
        continue;
      }
    }while(true);
  }while(true);
  return 0;
}
