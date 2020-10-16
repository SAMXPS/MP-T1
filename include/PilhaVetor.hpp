#ifndef PILHAVETOR_HPP_INCLUDED
#define PILHAVETOR_HPP_INCLUDED
#include "Pilha.hpp"

#define TAMANHO_DEFAULT 10

namespace _PilhaVetor {

    class _base {
        private:
            int _elementSize;
            int _elementCount = 0;
            int _capacity;
            void* _data;
        public:
            _base(int elementSize, int capacity); 
            ~_base();

            bool  push(void* data);
            void* pop();
            void* top();
            int   elementCount();
            int   getCapacity();
            bool  setCapacity(int capacity);
    };
};

template <class ItemType>
class PilhaVetor : public Pilha<ItemType> {
    private:
        _PilhaVetor::_base* base;

    public:
        PilhaVetor() {
            base = new _PilhaVetor::_base(sizeof(ItemType), TAMANHO_DEFAULT);
        }

        ~PilhaVetor() {
            delete base;
        }

        bool push(ItemType elemento) {
            return base->push(&elemento);
        }

        ItemType* pop() {
            return (ItemType*) base->pop();
        }

        ItemType* top() {
            return (ItemType*) base->top();
        }

        int getCapacity() {
            return base->getCapacity();
        }

        bool setCapacity(int capacity) {
            return base->setCapacity(capacity);
        }
        
        int elementCount() {
            return base->elementCount();
        }
};

#endif //PILHAVETOR_HPP_INCLUDED