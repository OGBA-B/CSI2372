//
//  StackStart.hpp
//  c-Game
//
//  Created by bobbie Okparanyote on 2015-11-26.
//  Copyright © 2015 Bobbie Okparanyote. All rights reserved.
//

#ifndef STARTSTACK_h
#define STARTSTACK_h
#include <iostream>
#include <stdio.h>
#include "AnimalCard.h"
//#include "ActionCard.h"
#include <memory>
#include <deque>
using namespace std;
class ActionCard;
class StartStack:public AnimalCard{
private:
    deque<AnimalCard> d_stack;
    shared_ptr<StartCard>start;
public:
    StartStack();
    //overwritting AnimalCard
    void setOrientation(const Orientation _orient);
    void setRow(enum EvenOdd _row);
    EvenOdd getRow();
    void printRow(EvenOdd _row);
    //new operators
    shared_ptr<StartCard> getStartCard();
    StartStack& operator +=(shared_ptr<ActionCard> _card);
    StartStack& operator -=(shared_ptr<ActionCard> _card);
};
#endif /* StartStack_h */
