//
//  Hand.hpp
//  Game
//
//  Created by bobbie Okparanyote on 2015-11-24.
//  Copyright © 2015 Bobbie Okparanyote. All rights reserved.
//

#ifndef HAND_H
#define HAND_H
#include <stdexcept>
#include <stdio.h>
#include <iostream>
#include <list>
#include "AnimalCard.h"
#include <vector>
using namespace std;
#include <memory>
class Hand{
protected:
    list<shared_ptr<AnimalCard>> (_hand);
public:
    Hand();// Default constructor for Hand
    Hand& operator+=(shared_ptr<AnimalCard>); //adds a pointer to the AnimalCard
    // void operator+=(shared_ptr<AnimalCard>); //adds a pointer to the AnimalCard
    Hand& operator-=(shared_ptr<AnimalCard>); //removes a card
    // void operator-=(shared_ptr<AnimalCard>); //removes a card
    shared_ptr<AnimalCard> operator[](int); //returns the AnimalCard at a given index.
    int noCards();//Returns number of cards in hand
    ~Hand();//deconstructor
    ostream& operator<<(ostream&);
    istream& operator>>(istream&);
    void print();
};
#endif /* Hand_hpp */
