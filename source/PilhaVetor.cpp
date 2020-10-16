#include "../include/PilhaVetor.hpp"

_PilhaVetor::_base::_base(int elementSize, int capacity) {

}

_PilhaVetor::_base::~_base() {

}

bool _PilhaVetor::_base::push(void* data) {
    return false;
}

void* _PilhaVetor::_base::pop() {
    return nullptr;
}

void* _PilhaVetor::_base::top() {
    return nullptr;
}

int _PilhaVetor::_base::elementCount() {
    return 0;
}

int _PilhaVetor::_base::getCapacity() {
    return 0;
}

bool _PilhaVetor::_base::setCapacity(int capacity) {
    return false;
}
