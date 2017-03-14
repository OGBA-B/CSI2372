//
//  Player.h
//  Game
//
//  Created by bobbie Okparanyote on 2015-11-23.
//  Copyright © 2015 Bobbie Okparanyote. All rights reserved.
//
#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include "Hand.h"
#include <iostream>
#include <list>

using namespace std;

class Player
{
private:
    Animal secretAnimal;
    string name;
public:
    Player();
    Hand dhand;
    ostream& operator<<(ostream&);
    Player(string name,Animal _SecretAnimal);
    Animal swapSecretAnimal(Animal&);//changes the current secret animal to the argumentandreturns oldsecretanimal.
    Animal getSecretAnimal(); //gets the current secret animal as a string
    string getName();
    ~Player();//deconstructor
    istream& operator>>(istream&);

};
#endif /* Player_h */
