#include "../include/Pilha.hpp"
#include "../include/PilhaEncadeada.hpp"
#include "../include/PilhaVetor.hpp"
#define TipoPilha PilhaEncadeada

#include <iostream>
#include <gtest/gtest.h>

TEST(TesteInicial, Teste1) {
    // Vamos ver se 2+1 = 3
    // Só pra testar se o gtest está funcionando
    ASSERT_EQ(3, 2+1);
}

// Implementação de função main do gtest
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}