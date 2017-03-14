/*
 * File:   AnimalCard.h
 * Author: NikhilPC
 *
 * Created on November 24, 2015, 9:11 AM
 */

#ifndef ANIMALCARD_H
#define	ANIMALCARD_H

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
class AnimalCard;
istream& operator>>(istream&,AnimalCard&);
ostream& operator>>(ostream&,const AnimalCard& );
class Table;
enum Orientation {
    UP, DOWN, HORIZONTAL, VERTICAL
};

enum EvenOdd {
    EVEN, ODD, DEFAULT
};

enum Animal : char {
    BEAR = 'b',
    DEER = 'd',
    WOLF = 'w',
    HARE = 'h',
    MOOSE = 'm'
};

class AnimalCard {
protected:
    // indexes of corners are presented as follows
    // |0 1|
    // |2 3|
    friend Table;
    char d_corners[4];
    EvenOdd d_printState = EVEN;
    Orientation d_orientation = UP;

public:
    AnimalCard();
    virtual void setOrientation(const Orientation _orient);
    virtual void setRow(enum EvenOdd _row){
        if(_row != DEFAULT){
            d_printState = _row;
        }
    };
    virtual EvenOdd getRow() {return d_printState;};
    virtual void printRow(ostream& _os, EvenOdd _row);
    friend ostream& operator<<(ostream&, const AnimalCard&);
    friend istream& operator>>(istream&, AnimalCard&);
};
AnimalCard::AnimalCard(){}

void AnimalCard::setOrientation(const Orientation _orient) {
    if (_orient != d_orientation) {
        //swap top right with bottom left
        char tmp = d_corners[1];
        d_corners[1] = d_corners[2];
        d_corners[2] = tmp;

        //swap bottom right with top left
        tmp = d_corners[0];
        d_corners[0] = d_corners[3];
        d_corners[0] = tmp;
    }
}

void AnimalCard::printRow(ostream& _os, EvenOdd _row) {
    if (_row == DEFAULT) {
        _row = d_printState;
    }

    if (_row == EVEN) {
        _os << d_corners[0] << " " << d_corners[1];
        d_printState = ODD;
    } else if (_row == ODD) {
        _os << d_corners[2] << " " << d_corners[3];
        d_printState = EVEN;
    }
}

ostream& operator<<(ostream& _os, const AnimalCard& _card) {
    _os << _card.d_corners[0] << "\t" << _card.d_corners[1] << "\t"
    << _card.d_corners[2] << "\t" << _card.d_corners[4];
    _os << static_cast<std::underlying_type<EvenOdd>::type>(_card.d_printState) <<
    "\t"<< static_cast<std::underlying_type<Orientation>::type>(_card.d_orientation);
    return _os;
}
istream& operator>>(istream& _is, AnimalCard& _card) {
    int a, b;
    _is >> _card.d_corners[0] >> _card.d_corners[1] >> _card.d_corners[2]
    >> _card.d_corners[3];
    _is >> a >> b;
    _card.d_printState = static_cast<EvenOdd>(a);
    _card.d_orientation = static_cast<Orientation>(b);
    if (!_is) _card = AnimalCard();
    return _is;
}
class SplitTwo : public AnimalCard {
public:
    inline SplitTwo(Animal _animal1, Animal _animal2) {
        d_corners[0] = d_corners[1] = _animal1;
        d_corners[2] = d_corners[3] = _animal2;
    }
};

class SplitThree : public AnimalCard {
public:
    inline SplitThree(Animal _animal1, char _animal2, char _animal3) {
        d_corners[0] = d_corners[1] = _animal1;
        d_corners[2] = _animal2;
        d_corners[3] = _animal3;
    };
};

class SplitFour : public AnimalCard {
public:
    inline SplitFour(char _animal1, char _animal2, char _animal3, char _animal4) {
        d_corners[0] = _animal1;
        d_corners[1] = _animal2;
        d_corners[2] = _animal3;
        d_corners[3] = _animal4;
    }
};

class NoSplit : public AnimalCard {
public:
    inline NoSplit(char _cardVal){
        d_corners[0] = d_corners[1] = d_corners[2] = d_corners[3] = _cardVal;
    }
    inline NoSplit(Animal _animal1){
        d_corners[0] = d_corners[1] = d_corners[2] = d_corners[3] = _animal1;
    }
};

class Joker : public NoSplit {
public:
    inline Joker() : NoSplit('j'){};
};

class StartCard : public NoSplit {
public:
    inline StartCard() : NoSplit('c'){};
};
#endif	/* ANIMALCARD_H */

