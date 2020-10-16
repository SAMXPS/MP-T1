#include "../include/PilhaVetor.hpp"
#include <stdlib.h> // malloc()
#include <new>      // bad_alloc()
#include <string.h> // memcpy()

_PilhaVetor::_base::_base(int elementSize, int capacity) {
    _capacity = capacity;
    _elementSize = elementSize;
    _data = malloc(elementSize * capacity);

    if (_data == nullptr) 
        throw std::bad_alloc();
}

_PilhaVetor::_base::~_base() {
    free(_data);
    _data == nullptr;
}

bool _PilhaVetor::_base::push(void* data) {
    if (_elementCount +1 > _capacity)
        return false;
    _elementCount++;
    memcpy(top(), data, _elementSize);
}

void* _PilhaVetor::_base::pop() {
    void* ptr = top();
    if (ptr != nullptr)
        _elementCount--;
    return ptr;
}

void* _PilhaVetor::_base::top() {
    if (_elementCount < 1)
        return nullptr;
    return (void*)(_data + (_elementCount-1) * _elementSize);
}

int _PilhaVetor::_base::elementCount() {
    return _elementCount;
}

int _PilhaVetor::_base::getCapacity() {
    if (_data != nullptr)
        return _capacity;
    else return 0;
}

bool _PilhaVetor::_base::setCapacity(int capacity) {
    // Capacidade de vetor não pode ser nula
    if (capacity < 0)
        return false;

    // Capacidade tem que suportar todos os elementos atuais
    if (capacity < _elementCount)
        return false;

    return false;
}
