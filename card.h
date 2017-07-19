#ifndef _CARD_H_
#define _CARD_H_

#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>

class Card
{
  public:
    Card(std::string kind, int number);
    virtual ~Card();
    std::string kind();
    int number();
    void show(bool showFront = true);
  private:
    std::string mKind;
    int mNumber;
};

#endif
