//
//  Table.cpp
//  MakeUp
//
//  Created by bobbie Okparanyote on 2015-11-24.
//  Copyright © 2015 Bobbie Okparanyote. All rights reserved.
//
#include "StartStack.h"
#include "Table.h"
#include "ActionCard.h"

// places a copy of the action card
//on top of the StartStack in Table

Table::Table()
{
    //Counters for Secret Animals
     wolf=0;
     bear=0;
     deer=0;
     moose=0;
     hare=0;
    for (int row = 0; row < 153; ++row)
    {
        for (int col = 0; col < 153; ++col)
        {
            deck[row][col] =nullptr;
        }
    }
    AnimalCard temp= *(startc->getStartCard());
    shared_ptr<AnimalCard>er(&temp);
    deck[52][52]=er;//store startCard in midddle of Table
};

Table& Table::operator+=(const shared_ptr<AnimalCard> _card)
{
    shared_ptr<ActionCard> temp= dynamic_cast<shared_ptr<ActionCard>&>(*_card);
    startc->operator+=(temp);
    return *this;
}
Table& Table::operator-=(const shared_ptr<AnimalCard> _card)
{
    //shared_ptr<ActionCard> temp= make_shared<ActionCard>(_card);
    //startc->operator-=(temp);
    shared_ptr<ActionCard> temp= dynamic_cast<shared_ptr<ActionCard>&>(*_card);
    startc->operator-=(temp);

return *this;
}

bool Table::isValid(int row,int col)
{
 if(row>152 || row <0 || col>152 || col<0) return false;
    return true;
}

int Table::addAt(shared_ptr<AnimalCard> _card, int row, int col)
{
    if(!isValid(row,col))
    {
        cout<<"The position does not exist"<<endl;
        return 0;
    }
    int matches = 0;
if (row-1>=0 && deck[row - 1][col]!=nullptr) //Skips if _Card is in first row
    {
    if(deck[row - 1][col]->d_corners[0]!='c' && deck[row - 1][col]->d_corners[0]!='j')//if joker or startCard
        {
        if (deck[row - 1][col]->d_corners[2] == deck[row][col]->d_corners[0]|| deck[row - 1][col]->d_corners[3] == deck[row][col]->d_corners[1])
            matches++;
        }
         matches++;
    }
if (col-1 >= 0 && deck[row][col-1]!=nullptr)//Skips if _Card is in first Column
    {
    if(deck[row][col-1]->d_corners[0]!='c' &&deck[row][col-1]->d_corners[0]!='j')//if joker or startCard
        {
        if (deck[row][col-1]->d_corners[1] == deck[row][col]->d_corners[0]|| deck[row][col-1]->d_corners[3]== deck[row][col]->d_corners[2])
            matches++;
        }
        matches++;
    }
if (col+1 < 103 && deck[row][col+1]!=nullptr)//Skips if _Card is in last column
    {
    if(deck[row][col+1]->d_corners[0]!='c' &&deck[row][col+1]->d_corners[0]!='j')//if joker or startCard
        {
        if (deck[row][col+1]->d_corners[0] == deck[row][col]->d_corners[1]|| deck[row][col+1]->d_corners[2]== deck[row][col]->d_corners[3])
            matches++;
        }
        matches++;
    }
if (row+1 < 103 && deck[row + 1][col]!=nullptr)//skips if _Card is in last row
    {
    if(deck[row + 1][col]->d_corners[0]!='c' &&deck[row + 1][col]->d_corners[0]!='j')//if joker or startCard
        {
        if (deck[row + 1][col]->d_corners[0] == deck[row][col]->d_corners[2] || deck[row + 1][col]->d_corners[1] == deck[row][col]->d_corners[3])
            matches++;
        }
        matches++;
    }
    deck[row][col]=_card;
    checkCard(_card);//Increment any Secret Animals
    return matches;
}

shared_ptr<AnimalCard> Table::pickAt(int row, int col)
{
    if((!isValid(row,col))||((row==52)&&(col==52)))
    {
        throw "ILLEGAL PICK";
        return nullptr;
    }
    return deck[row][col];
}
void Table::print()
{
    cout<<"  ";
    for(int i=0;i<153;i++)cout<<i<<" ";
    cout<<""<<endl;
    for (int row = 0; row < 153; ++row)
    {
        cout<<row<<" ";
        for (int col = 0; col < 153; ++col)
        {
            deck[row][col]->printRow(cout,DEFAULT);// Print first Row of Card
            cout<<""<<endl;
            deck[row][col]->printRow(cout,DEFAULT);// Print first Row of Card
        }
    }

}

ostream& Table::operator<<(ostream& dout)
{
    dout<<deck<<"\t"<<startc;
    return dout;
}
 istream& Table::operator>>(istream& dout)
{
  // dout >>deck;
    return dout;
}

Table::~Table()
{
delete[]&deck;
    
}
bool Table::won(Animal _secretAnimal) //check if a counter has reached 12
{
    if (_secretAnimal == BEAR) {
        return (bear >= 12);
    } else if (_secretAnimal == WOLF) {
        return (wolf >= 12);
    } else if (_secretAnimal == MOOSE) {
        return (moose >= 12);
    } else if (_secretAnimal == HARE) {
        return (hare >= 12);
    } else if (_secretAnimal == DEER) {
        return (deer >= 12);
    } else {
        return false;
    }
}
//increments secret Animal Counter when a card is Added
void Table::checkCard(shared_ptr<AnimalCard> _card)
{
    if(_card!=0)
    {
if(_card->d_corners[0]=='h'||_card->d_corners[1]=='h'||_card->d_corners[2]=='h'||_card->d_corners[3]=='h' )
{
            hare++;
        }
if(_card->d_corners[0]=='w'||_card->d_corners[1]=='w'||_card->d_corners[2]=='w'||_card->d_corners[3]=='w' )
{
            wolf++;
        }
if(_card->d_corners[0]=='b'||_card->d_corners[1]=='b'||_card->d_corners[2]=='b'||_card->d_corners[3]=='b' )
        {
            bear++;
        }
if(_card->d_corners[0]=='d'||_card->d_corners[1]=='d'||_card->d_corners[2]=='d'||_card->d_corners[3]=='d' )
        {
            deer++;
        }
if(_card->d_corners[0]=='m'||_card->d_corners[1]=='m'||_card->d_corners[2]=='m'||_card->d_corners[3]=='m' )
        {
            moose++;
        }
        
    }
 
}
















