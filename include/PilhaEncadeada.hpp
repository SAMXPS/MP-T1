#ifndef PILHAENCADEADA_HPP_INCLUDED
#define PILHAENCADEADA_HPP_INCLUDED
#include "Pilha.hpp"

namespace _PilhaEncadeada {
    
    struct _elemento;

    class _base {
        private:
            int _elementSize;
            int _elementCount = 0;
            _elemento* _top = nullptr;

        public:
            _base(int elementSize) {
                this->_elementSize = elementSize;
            };

            bool  push(void* data);
            void* pop();
            void* top();
            int   elementCount();
    };

};

template <class ItemType>
class PilhaEncadeada : public Pilha<ItemType> {
    private:
        _PilhaEncadeada::_base* base;
        int capacity = -1;

    public:
        PilhaEncadeada() {
            base = new _PilhaEncadeada::_base(sizeof(ItemType));
        }

        ~PilhaEncadeada() {
            delete base;
        }

        bool isEmpty() {
            return elementCount() == 0;
        }

        bool isFull() {
            return capacity != -1 && elementCount() == capacity;
        }

        bool push(ItemType elemento) {
            base->push(&elemento);
        }

        ItemType* pop() {
            return (ItemType*) base->pop();
        }

        ItemType* top() {
            return (ItemType*) base->top();
        }

        int elementCount() {
            return base->elementCount();
        }

        int getCapacity() {
            return this->capacity;
        }

        bool setCapacity(int capacity) {
            if (capacity == -1 || elementCount() <= capacity) {
                this->capacity = capacity;
                return true;
            }
            return false;
        }
};

#endif //PILHAENCADEADA_HPP_INCLUDED