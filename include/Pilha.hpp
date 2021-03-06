/*
    Copyright (c) 2020 Samuel James
    Implementação de Pilha feita por Samuel James.
    https://github.com/SAMXPS
*/
#ifndef PILHA_HPP_INCLUDED
#define PILHA_HPP_INCLUDED

template <class ItemType>
class Pilha {
    public:

        /**
         * Retorna true se a pilha é dinamicamente alocada.
         * Nota: se a pilha for dinamicamente alocada, 
         * o elemento deve ser liberado pela função free()
         * após uso da função pop()
         */
        virtual bool isDynamicAllocated() = 0;

        /**
         * Retorna true se a pilha não contém nenhum elemento.
         */
        bool isEmpty() {
            return elementCount() == 0;
        }

        /**
         * Retorna verdadeiro se a pilha está cheia, falso caso contrário.
         */
        bool isFull() {
            return getCapacity() != -1 && elementCount() == getCapacity();
        }

        /**
         * Copia elemento e o coloca no topo da pilha.
         * Retorna true em caso de sucesso, false em caso de falha.
         */
        virtual bool push(ItemType elemento) = 0;

        /**
         * Retira o elemento do topo da pilha.
         * Retorna ponteiro para o elemento retirado.
         * Caso ocorra falha, é retornado ponteiro para nulo.
         * 
         * Nota: Caso a pilha seja dinamicamente alocada, i.e, isDynamicAllocated() == true,
         * é necessario rodar função free() no elemento retornado.
         */
        virtual ItemType* pop() = 0; 

        /**
         * Retorna elemento do topo da pilha sem modificar a pilha – retorna um elemento.
         */
        virtual ItemType* top() = 0;

        /**
         * Retorna int tamanho da pilha.
         * Pode retornar -1 se a pilha não tiver limite de tamanho (e for dinamicamente alocada).
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