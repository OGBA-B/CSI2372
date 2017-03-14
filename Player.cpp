//
//  Player.cpp
//  Game
//
//  Created by bobbie Okparanyote on 2015-11-24.
//  Copyright © 2015 Bobbie Okparanyote. All rights reserved.
//
#include "Player.h"

#include <stdio.h>
#include <iostream>
#include <list>

using namespace std;

Animal Player:: swapSecretAnimal(Animal& newAnimal)
{
    Animal t;
    t= secretAnimal;
    secretAnimal= newAnimal;
    return t;
}
string Player::getName()
{
    return name;
}

Player::Player(string _name, Animal _SecretAnimal):name(_name),secretAnimal(_SecretAnimal)
{
    dhand=Hand();
};
Animal Player::getSecretAnimal()
{
    return secretAnimal;
}
Player::Player()
{

}
ostream& Player::operator<<(ostream& dout)
{
    return dout;
}


Player:: ~Player() {}

istream& Player::operator>>(istream &dout)
{
    //cout<<"";
    return dout;
}
