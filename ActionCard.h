//
//  ACQR.hpp
//  Game
//
//  Created by bobbie Okparanyote on 2015-11-23.
//  Copyright © 2015 Bobbie Okparanyote. All rights reserved.
//
/*
 The wolf action card allows a player to pick up a card from the table and place it in the player's
 hand.
  //The bear action card allows a player to select another player to switch hands.l
  The moose action card triggers a rotation of secret animals form player 1 to player 2, from 2 to 3,
 etc. in turn.l
  The hare action card allows a player to move an animal card on the table including the joker to a
 different location on the table where the card is valid.
  The deer action card allows a player to select another player to trade goals with.l
 */
#ifndef ACTIONCARD_H
#define ACTIONCARD_H

#include <stdio.h>
#include <iostream>
#include "Player.h"
#include "Table.h"
using namespace std;
struct position{
    int i,j;
};
class QueryResult
{
public:
    position _positions[2];// Two positions on Table
    string otherPlayerN;//The name other player
                        // int numPlayers; //number of players in the game
                         //player *_player;//pointer to the first player
    
};
class ActionCard: public StartCard
{
public:
    virtual QueryResult query()=0; //which will display the action on the console and query theplayer for input if needed. Returns a QueryResult object storing the result.
    virtual void perfom( Table& _table, Player*, QueryResult )=0; // which will perform theaction with the user input stored in QueryResult.
};

class DeerAction:ActionCard
{
    QueryResult query();
    void perfom( Table& _table, Player*, QueryResult);
    
};
class WolfAction:ActionCard
{
    QueryResult query();
    void perfom( Table& _table, Player*, QueryResult);
};
class mooseAction:ActionCard
{
    QueryResult query();
    void perfom( Table& _table, Player*, QueryResult);
};
class hareAction: ActionCard{
    QueryResult query();
   void perfom( Table& _table, Player*, QueryResult);
};
class BearAction:ActionCard{
    QueryResult query();
    void perfom( Table& _table, Player*, QueryResult);
};


#endif /* ActionCard_hpp */
