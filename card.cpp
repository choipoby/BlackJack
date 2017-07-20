#include "card.h"
using namespace std;

Card::Card(string kind, int number)
  : mKind(kind)
  , mNumber(number)
{
    printf("%s:%d\n", kind.c_str(), number);
}

Card::~Card()
{
}

string Card::kind()
{
    return mKind;
}
int Card::number()
{
    return mNumber;
}
void Card::show(bool showFront)
{
    if (showFront){
        switch(mNumber) {
        case 10:
            cout << "j" << endl;
            break;
        case 11:
            cout << "k" << endl;
            break;
        case 12:
            cout << "q" << endl;
            break;
        default:
            cout << mNumber << endl;
        }
    } else{
        cout << "*" <<endl;
    }
}
