//
//  StackStart.cpp
//  c-Game
//
//  Created by bobbie Okparanyote on 2015-11-26.
//  Copyright © 2015 Bobbie Okparanyote. All rights reserved.
//
#include "ActionCard.h"
#include "StartStack.h"
StartStack::StartStack(){
    *start= *new StartCard();
    d_stack.push_front(*start);
}
StartStack& StartStack::operator +=(shared_ptr<ActionCard> _card){
    d_stack.push_front(*_card);
    return *this;
}

StartStack& StartStack::operator -=(shared_ptr<ActionCard> _card){
    d_stack.push_back(*_card);
    return *this;
}

void StartStack::setOrientation(const Orientation _orient){
    d_stack.front().setOrientation(_orient);
}

void StartStack::setRow(enum EvenOdd _row){
    d_stack.front().setRow(_row);
}

EvenOdd StartStack::getRow()
{
    return d_stack.front().getRow();
}

shared_ptr<StartCard> StartStack:: getStartCard()
{
    return start;
}
void StartStack::printRow(EvenOdd _row){
  //  d_stack.front().printRow(_row);
}
