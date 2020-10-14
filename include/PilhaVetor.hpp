#ifndef PILHAVETOR_HPP_INCLUDED
#define PILHAVETOR_HPP_INCLUDED
#include "Pilha.hpp"

template <class ItemType>
class PilhaVetor : public Pilha<ItemType> {
    public:
        PilhaVetor();
        ~PilhaVetor();

        bool isEmpty();
        bool isFull();
        bool push(ItemType elemento);
        ItemType* pop(); 
        ItemType* top();
        int getCapacity();
        bool setCapacity(int);
};

#endif //PILHAVETOR_HPP_INCLUDED