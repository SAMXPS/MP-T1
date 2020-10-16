#define TipoPilha PilhaVetor
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

// Teste em que se adiciona 2 elementos depois os retiram
TEST_F(TestaPilha, TestaAdicionaRetiraAB) {
    const int a = 90;
    const int b = 50;
    int* topo = nullptr;
    int* retirada = nullptr;

    // Acrescentando elemento A
    ASSERT_TRUE(pilha->push(a));
    ASSERT_TRUE(pilha->elementCount() == 1);
    ASSERT_TRUE(!pilha->isEmpty());
    ASSERT_TRUE(pilha->top() != nullptr);

    topo = pilha->top();
    ASSERT_TRUE(topo != nullptr);
    
    // DEBUG std::cout << *topo << std::endl;
    
    ASSERT_TRUE(*topo == a);

    // Acrescentando elemento B
    ASSERT_TRUE(pilha->push(b));
    ASSERT_TRUE(pilha->elementCount() == 2);

    topo = pilha->top();

    ASSERT_TRUE(topo != nullptr);

    ASSERT_TRUE(*topo == b);
    ASSERT_TRUE(pilha->elementCount() == 2);
    ASSERT_TRUE(pilha->top() == topo);

    retirada = pilha->pop();
    ASSERT_TRUE(retirada == topo);
    ASSERT_TRUE(pilha->elementCount() == 1);

    free(retirada);
    retirada = topo = nullptr;

    topo = pilha->top();

    ASSERT_TRUE(topo != nullptr);
    ASSERT_TRUE(*topo == a);
    ASSERT_TRUE(pilha->elementCount() == 1);
    ASSERT_TRUE(pilha->top() == topo);

    retirada = pilha->pop();
    ASSERT_TRUE(retirada == topo);
    ASSERT_TRUE(pilha->elementCount() == 0);
    ASSERT_TRUE(pilha->isEmpty());

    free(retirada);
    retirada = topo = nullptr;
}

TEST_F(TestaPilha, TestaMudarTamanho1) {
    ASSERT_TRUE(pilha->setCapacity(2));
    
    const int A = 99, B = 77; // Valores quaisquer

    ASSERT_TRUE(pilha->push(A));
    ASSERT_TRUE(pilha->push(B));

    // A pilha deve estar cheia com 2 elementos
    ASSERT_TRUE(pilha->isFull());

    // Não deve ser possível adicionar mais um elemento
    ASSERT_FALSE(pilha->push(B));
    ASSERT_EQ(pilha->elementCount(), 2);

    free(pilha->pop());
    free(pilha->pop());

    ASSERT_TRUE(pilha->isEmpty());
}

// Implementação de função main do gtest
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}