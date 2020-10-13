#ifndef PILHA_HPP_INCLUDED
#define PILHA_HPP_INCLUDED

/*
Funções a codificar:

Push (pilha, elemento) - coloca elemento no topo da pilha
Pop (pilha) - retira elemento do topo da pilha – retorna um elemento
Top (pilha) – retorna elemento do topo da pilha sem modificar a pilha – retorna um
elemento
Size (pilha) – retorna int tamanho da pilha
SetSize (pilha, int) – muda o tamanho da pilha – retorna True se deu certo, False caso
contrário
IsFull (pilha) – retorna verdadeiro se a pilha está cheia e falso caso contrário
IsEmpty (pilha) - retorna verdadeiro se a pilha está vazia e falso caso contrário
CreateStack () – cria pilha – retorna pilha
DestroyStack (pilha) – destrói pilha 
*/

template <class ItemType>
class Pilha {
    public:
        Pilha() {};

        /**
         * Retorna true se a pilha não contém nenhum elemento.
        */
        bool isEmpty();
};

#endif //PILHA_HPP_INCLUDED