#ifndef TESTAPILHA_HPP_INCLUDED
#define TESTAPILHA_HPP_INCLUDED

#include "Pilha.hpp"
#include "PilhaEncadeada.hpp"
#include "PilhaVetor.hpp"

#ifndef TipoPilha
#define TipoPilha PilhaEncadeada
#endif  // TipoPilha

#define TipoItem int

#include <gtest/gtest.h>

class TestaPilha: public ::testing::Test { 
    protected:
        TipoPilha<TipoItem> *pilha;

    public: 
        TestaPilha() { 
        } 

        void SetUp() { 
            // Código que roda antes da execução de teste
            pilha = new TipoPilha<TipoItem>();
        }

        void TearDown() { 
            // Código que roda depois da execução do teste
            delete pilha;
        }
};

#endif //TESTAPILHA_HPP_INCLUDED