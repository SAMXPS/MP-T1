#include "../include/PilhaEncadeada.hpp"
#include <stdlib.h>

namespace _PilhaEncadeada {
    struct _elemento {
        _elemento* next;
        void* data;
    };
}   

bool  _PilhaEncadeada::_base::push(void* elemento, int size) {
    _elemento* e = (_elemento*) malloc(sizeof(_elemento));
    
    if (e == nullptr)
        return false;

    e->next = _top;
    e->data = malloc(size);

    if (e->data == nullptr) {
        free(e);
        return false;
    }

    memcpy(e->data, &elemento, size);

    _top = e;
    _elementCount++;
    return true;
}

void* _PilhaEncadeada::_base::pop() {
    _elemento* e = _top;

    if (e == nullptr)
        return nullptr;

    _top = e->next;
    void* data = e->data;
    free(e);
    _elementCount--;
    return data;
}

void* _PilhaEncadeada::_base::top() {
    if (_top == nullptr)
        return nullptr;

    return _top->data;
}

int _PilhaEncadeada::_base::elementCount() {
    return _elementCount;
}