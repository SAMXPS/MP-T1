#include "../include/TestaPilha.hpp"
#include <iostream>

TEST_F(TestaPilha, TestaConstrutor) {
    // Verificando se o construtor da pilha funciona.
    ASSERT_TRUE(pilha != NULL);
}

TEST_F(TestaPilha, TestaPilhaVazia) {
    ASSERT_TRUE(pilha->isEmpty());
    ASSERT_TRUE(pilha->elementCount() == 0);
    ASSERT_TRUE(pilha->top() == nullptr);
    ASSERT_TRUE(pilha->pop() == nullptr);
}

// Implementação de função main do gtest
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}