//
//  Table.hpp
//  MakeUp
//
//  Created by bobbie Okparanyote on 2015-11-24.
//  Copyright © 2015 Bobbie Okparanyote. All rights reserved.
//

#ifndef Table_H
#define Table_H
#include <stdio.h>
#include <iostream>
#include <memory>
class StartStack;
class Table {
shared_ptr<AnimalCard>deck[103][103];
shared_ptr<StartStack> startc;
    int wolf;
    int bear;
    int deer;
    int moose;
    int hare;
public:
    Table();
    Table& operator+=(shared_ptr<AnimalCard>);
    Table& operator-=(shared_ptr<AnimalCard>);//Change back to actioncard
    int addAt(shared_ptr<AnimalCard>, int row, int col);
    bool isValid(int row,int col);
    shared_ptr<AnimalCard> pickAt(int row, int col);
    ostream& operator<<(ostream&);
    istream& operator>>(istream&);
    ~Table();
    void print();
    bool won(Animal);
    void checkCard(shared_ptr<AnimalCard>); //checks animals on card and increments identifier
};

#endif /* Table_hpp */
