#ifndef PILHA_HPP_INCLUDED
#define PILHA_HPP_INCLUDED

template <class ItemType>
class Pilha {
    public:
        /**
         * Retorna true se a pilha não contém nenhum elemento.
         */
        virtual bool isEmpty() = 0;

        /**
         * Retorna verdadeiro se a pilha está cheia, falso caso contrário.
         */
        virtual bool isFull() = 0;

        /**
         * Coloca elemento no topo da pilha.
         * Retorna true em caso de sucesso, false em caso de falha.
         */
        virtual bool push (ItemType elemento) = 0;

        /**
         * Retira elemento do topo da pilha – retorna um elemento.
         */
        virtual ItemType* pop() = 0; 

        /**
         * Retorna elemento do topo da pilha sem modificar a pilha – retorna um elemento.
         */
        virtual ItemType* top() = 0;

        /**
         * Retorna int tamanho da pilha
         */
        virtual int elementCount() = 0;

        /**
         * Retorna int tamanho da pilha
         */
        virtual int getCapacity() = 0;

        /**
         * Muda o tamanho da pilha – retorna True se deu certo, False caso contrário.
         */
        virtual bool setCapacity(int) = 0;
};

#endif //PILHA_HPP_INCLUDED