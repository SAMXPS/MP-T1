#ifndef PILHAENCADEADA_HPP_INCLUDED
#define PILHAENCADEADA_HPP_INCLUDED
#include "Pilha.hpp"
#include <iostream>
#include <stdlib.h> // maloc
#include <string.h> // memcpy

namespace _PilhaEncadeada {
    struct _elemento;

    class _base {
        private:
            int _elementCount = 0;
            _elemento* _top = nullptr;

        public:
            ~_base();

            bool  push(void* data, int size);
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
            base = new _PilhaEncadeada::_base();
        }

        ~PilhaEncadeada() {
            delete base;
        }

        bool isDynamicAllocated() {
            return true;
        }

        bool push(ItemType elemento) {
            if (Pilha<ItemType>::isFull()) return false;
            base->push(&elemento, sizeof(ItemType));
            return true;
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