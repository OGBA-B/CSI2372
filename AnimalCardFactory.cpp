#ifndef AnimalCardFactory_cpp
#define AnimalCardFactory_cpp
#include "AnimalCard.h"
#include "Deck.h"
#include <memory>
#include <vector>
#include <algorithm>
using namespace::std;
class AnimalCardFactory{
public:
  static AnimalCardFactory* getFactory();
  Deck<AnimalCard> getDeck();
};

AnimalCardFactory* AnimalCardFactory::getFactory(){
return new AnimalCardFactory;
    
}

Deck<AnimalCard> AnimalCardFactory::getDeck(){
  Deck<AnimalCard>d_cards;
  Animal _animals[] = {BEAR, DEER, WOLF, HARE, MOOSE};
  //add NoSplit
  for(int i = 0; i < 5; i++){
    d_cards.addCard(NoSplit(_animals[i]));
  }
  //add TwoSplit
  for(int i = 0; i < 5; i++){
    for(int ii = i + 1; ii < 5; ii++){
      d_cards.addCard ( SplitTwo(_animals[i], _animals[ii]));
    }
  }
  //add SplitThree
  for(int i = 0; i < 5; i++){
    for(int ii = i+1; ii < 5; ii++){
      for(int iii = ii+1; iii < 5; iii++){
        d_cards.addCard (SplitThree(_animals[i], _animals[ii], _animals[iii]));
        d_cards.addCard (SplitThree(_animals[i], _animals[iii], _animals[ii]));
      }
    }
  }
  //add SplitFour
  for(int i = 0; i < 5; i++){
    for(int ii = i+1; ii < 5; ii++){
      for(int j = ii+1; j < 5; j++){
        for(int jj = j+1; jj<5; jj++){
          d_cards.addCard(SplitFour(_animals[i], _animals[ii], _animals[j], _animals[jj]));
          d_cards.addCard(SplitFour(_animals[j], _animals[ii], _animals[i], _animals[jj]));
          d_cards.addCard(SplitFour(_animals[i], _animals[jj], _animals[j], _animals[ii]));
        }
      }
    }
  }
    d_cards.shuffleDeck();
  return d_cards;
}

#endif /* AnimalCardFactory_cpp */











