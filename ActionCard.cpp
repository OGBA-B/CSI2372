//
//  ACQR.cpp
//  Game
//
//  Created by bobbie Okparanyote on 2015-11-24.
//  Copyright © 2015 Bobbie Okparanyote. All rights reserved.
//

#include "ActionCard.h"
#include "playerList.h"
//The bear action card allows a player to select another player to switch hands.
QueryResult BearAction::query()
{
    cout<<" Please Select a player to Switch Cards With";
    string name;
    cin>> name;
    while(playerList.find(name) != playerList.end())//check global list of player Names for name
    {
    cout<<name<<" is not in the Game"<<endl;
        cin>>name;
    }
    QueryResult result;
    result.otherPlayerN=name;
    return result;
    
};
void BearAction::perfom(Table & _table, Player * _player, QueryResult result)
{
    string thisPlayerName = _player->getName();

while (result.otherPlayerN== thisPlayerName ) //You can't switch with yourself
{
    cout<<"You can't switch with yourself"<<endl;
    result=query();
}
   Player oPlayer=playerList.at(result.otherPlayerN);//Get the other Player
    Hand temp=_player->dhand;
    _player->dhand= oPlayer.dhand;
    oPlayer.dhand=temp;
    cout<<thisPlayerName<<" and "<<oPlayer.getName()<<" switched Cards"<<endl;
};
//The deer action card allows a player to select another player to trade goals with.
QueryResult DeerAction::query()
{
    cout<<" Please Select a player to Switch goals With";
    string name;
    cin>> name;
    while(playerList.find(name) != playerList.end())//check global list of player Names for name
    {
        cout<<name<<" is not in the Game"<<endl;
        cin>>name;
    }
    QueryResult result;
    result.otherPlayerN=name;
    return result;
    
};
void DeerAction::perfom(Table & _table, Player * _player, QueryResult result)
{
    string thisPlayerName = _player->getName();
    
    while (result.otherPlayerN== thisPlayerName ) //You can't switch with yourself
    {
        cout<<"You can't switch with yourself"<<endl;
        result=query();
    }
    Player oPlayer=playerList.at(result.otherPlayerN);//Get the other Player
    Animal otherSecret= oPlayer.getSecretAnimal();//Get Secret Animal of other Player
    Animal temp=_player->swapSecretAnimal(otherSecret);// Swap with other player's secret Animal
    otherSecret =oPlayer.swapSecretAnimal(temp);
    cout<<thisPlayerName<<" your animal is "<<otherSecret<<"and "<<oPlayer.getName()<<" your animal is "<<temp<<endl;
};
//The moose action card triggers a rotation of secret animals form player 1 to player 2, from 2 to 3 etc
QueryResult mooseAction::query()
{
    cout<<"Everyone's secret Animal is now the secret Animal of the Player before you"<<endl;
    QueryResult result;
    return result;
}
void mooseAction::perfom(Table & _table, Player * _player, QueryResult result)
{    
    Animal temp= playerPointer->getSecretAnimal();// _player must be the first Player.
    Animal firstPlayerAnimal = _player->getSecretAnimal();
    map<string,Player>::iterator it;
    
//switch will start from second iteration
//At the end of iteration,it->second will point to the last player
//Temp will have the secret animal of the last Player
for ( it = playerList.begin(); it != playerList.end(); it++ )
    {
        temp=it->second.swapSecretAnimal(temp);
    }
    it=playerList.begin();
    temp=it->second.swapSecretAnimal(temp);//Change the secret Animal of the first Player
    cout<<"Secret Animals Have been rotated"<<endl;
}
//The hare action card allows a player to move an animal card on the table including the joker to a
//different location on the table where the card is valid
QueryResult hareAction::query()
{
    int row1,col1,row2,col2;//Table positions
    cout<<"Please enter the location of the Card you want to Move"<<endl;
    cout<<"The row:"; cin>>row1;
    cout<<"The column:";cin>>col1;
    cout<<"Please enter the location where you want to the card to be moved"<<endl;
    cout<<"The row:"; cin>>row2;
    cout<<"The column:";cin>>col2;
    QueryResult result;
    result._positions[0]={row1,col1};
    result._positions[1]={row2,col2};
    return result;
}

void hareAction::perfom(Table & _table, Player * _player, QueryResult result)
{
    bool check1=_table.isValid(result._positions[0].i,result._positions[0].j);//check if positions are Valid
    bool check2=_table.isValid(result._positions[1].i,result._positions[1].j);

    while(!(check1||check2))
    {
        cout<<"An invalid Location was inputed, Please Try AGain"<<endl;
       result = query();
      check1=_table.isValid(result._positions[0].i,result._positions[0].j);//check if positions are Valid
      check2=_table.isValid(result._positions[1].i,result._positions[1].j);
    }
    int row1,col1,row2,col2;
    row1=result._positions[0].i;
    col1=result._positions[0].j;
    row2=result._positions[1].i;
    col2=result._positions[1].j;
    auto card= _table.pickAt(row1,col1); //Remove Card at this Location
    int done=_table.addAt(card,row2,col2);//Add card at new Location
    cout<<"Card has been Moved"<<endl;
}

QueryResult WolfAction::query()
{
    int row1,col1;//Table positions
    cout<<"Please enter the location of the Card you want to Move"<<endl;
    cout<<"The row:"; cin>>row1;
    cout<<"The column:";cin>>col1;
    QueryResult result;
    result._positions[0]={row1,col1};
    return result;
}
void WolfAction::perfom(Table & _table, Player *_player, QueryResult result)
{
    int row1,col1;
bool check1=_table.isValid(result._positions[0].i,result._positions[0].j);//check if positions are Valid
    while(!(check1))
    {
        cout<<"An invalid Location was inputed, Please Try AGain"<<endl;
        result = query();
        check1=_table.isValid(result._positions[0].i,result._positions[0].j);//check if positions are Valid
    }
    row1=result._positions[0].i;
    col1=result._positions[0].j;
    auto card= _table.pickAt(row1,col1); //Remove Card at this Location
    _player->dhand+=card; //Add Card to this Players Hand
}
















