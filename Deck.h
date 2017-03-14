#ifndef DECK_H
#define DECK_H
#include <vector>
#include <memory>
#include <random>
#include <algorithm>

using namespace std;

template <class T> class Deck: vector<shared_ptr<T>>{
public:
    shared_ptr<T> draw();
    void addCard(T _card);
    void shuffleDeck();
};
template <class T>
shared_ptr<T> Deck<T>::draw(){
    shared_ptr<T> top = this->front();
    this->pop_back();
    return top;
}
template <class T>
void Deck<T>::addCard(T _card){
    shared_ptr<T> _addCard = shared_ptr<T>(&_card);
    this->push_back(_addCard);
}

template <class T>
void Deck<T>::shuffleDeck(){
    auto rnd = default_random_engine();
    shuffle(this->begin(),this->end(), rnd);
}
#endif