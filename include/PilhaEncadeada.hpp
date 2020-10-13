#ifndef PILHAENCADEADA_HPP_INCLUDED
#define PILHAENCADEADA_HPP_INCLUDED
#include "Pilha.hpp"

template <class ItemType>
class PilhaEncadeada : public Pilha<ItemType> {
    public:
        bool isEmpty();
};

template<class ItemType>
inline bool PilhaEncadeada<ItemType>::isEmpty() {
    return true;
};

#endif //PILHAENCADEADA_HPP_INCLUDED