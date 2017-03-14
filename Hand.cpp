//
//  Hand.cpp
//  Game
//
//  Created by bobbie Okparanyote on 2015-11-24.
//  Copyright © 2015 Bobbie Okparanyote. All rights reserved.
//

#include "Hand.h"
Hand::Hand()
{

}
Hand& Hand:: operator+=(shared_ptr <AnimalCard> _card)
{
    _hand.push_front(_card);
    return *this;
}
Hand& Hand::operator-=(shared_ptr <AnimalCard>  _card)
{
    list<shared_ptr<AnimalCard>>::iterator findIter = std::find(_hand.begin(),_hand.end(), _card);//find card
    if(_hand.empty())
    {
        throw ( "Hand is Empty" );
    }
    else if(findIter==_hand.end())
    {
        throw ("MissingCard");
    }
    else{
        _hand.remove(_card);// remove the card
    }
    return *this;

};

shared_ptr<AnimalCard> Hand::operator[](int index)
{
    if (_hand.size() > index)
    {
        std::list<shared_ptr<AnimalCard>>::iterator it = std::next(_hand.begin(), index);
        return *it;

    }
    else{   throw ("Index does not exist");}
}

int Hand::noCards()
{
    return _hand.size();
}

Hand::~Hand()
{
    _hand.clear();
}
void Hand::print()
{
    for(std::list<shared_ptr<AnimalCard>>::iterator it =_hand.begin();it!=_hand.end();it++)
    {
        shared_ptr<AnimalCard> q= *it;
        q->printRow(cout,DEFAULT); // print the top rows of all the cards
    }
    for(std::list<shared_ptr<AnimalCard>>::iterator it =_hand.begin();it!=_hand.end();it++)
    {
        shared_ptr<AnimalCard> q= *it; // print the bottom rows of all the cards
        q->printRow(cout,DEFAULT);
    }
}
ostream& Hand::operator<<(ostream& _os)
{
   
    return _os;
}
istream& Hand::operator>>(istream& _os)
{
    
    return _os;
}


