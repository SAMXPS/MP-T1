#include "../include/TestaPilha.hpp"
#include <iostream>

TEST_F(TestaPilha, TestaConstrutor) {
    // Verificando se o construtor da pilha funciona.
    ASSERT_TRUE(pilha != NULL);
}

// Implementação de função main do gtest
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}