#include "TestaPilhaTipo.cpp"
#include "../include/TestaPilha.hpp"
#include <stdlib.h> // rand()

// Função que faz free no ponterio baseado se a pilha é dinamicamente alocada.
template<class T>
void _coditionalFree(Pilha<T>* pilha, T* pointer) {
    if (pilha->isDynamicAllocated())
        free(pointer);
}

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

TEST_F(TestaPilha, TestaAdicionaA) {
    const int a = 77;
    int* topo = nullptr;
    int* retirada = nullptr;

    // Acrescentando elemento A
    ASSERT_TRUE(pilha->push(a));
    ASSERT_TRUE(pilha->elementCount() == 1);
    ASSERT_TRUE(!pilha->isEmpty());
    ASSERT_TRUE(pilha->top() != nullptr);

    topo = pilha->top();
    ASSERT_TRUE(topo != nullptr);
    ASSERT_TRUE(*topo == a);

    retirada = pilha->pop();
    ASSERT_TRUE(retirada == topo);
    ASSERT_TRUE(*retirada == a);

    _coditionalFree(pilha, retirada);

    ASSERT_TRUE(pilha->isEmpty());
    ASSERT_TRUE(pilha->top() == nullptr);
}

// Teste em que se adiciona 2 elementos depois os retiram
TEST_F(TestaPilha, TestaAdicionaRetiraAB) {
    const int a = 90;
    const int b = 50;
    int* topo = nullptr;
    int* retirada = nullptr;

    // Acrescentando elemento A
    pilha->push(a);

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

    _coditionalFree(pilha,retirada);
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

    _coditionalFree(pilha, retirada);
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

    _coditionalFree(pilha, pilha->pop());
    _coditionalFree(pilha, pilha->pop());

    ASSERT_TRUE(pilha->isEmpty());
}

TEST_F(TestaPilha, TestaAdicionaAteLimite) {
    int tamanho_inicial = pilha->getCapacity();

    int tamanho_teste = tamanho_inicial == -1 ? 25 : tamanho_inicial;

    int valores_aleatorios[tamanho_teste];
    for (int i = 0; i < tamanho_teste; i++) {
        valores_aleatorios[i] = rand();
        ASSERT_TRUE(pilha->push(valores_aleatorios[i]));
    }
    
    ASSERT_TRUE(tamanho_inicial == -1 || pilha->isFull());
    ASSERT_FALSE(tamanho_inicial != -1 && pilha->push(rand()));

    for (int i = 0; i < tamanho_teste; i++) {
        int* pop = pilha->pop();
        ASSERT_EQ(*pop, valores_aleatorios[tamanho_teste - i - 1]);
        _coditionalFree(pilha, pop);
    }

    ASSERT_TRUE(pilha->isEmpty());
}

TEST(TestaPilhaVetor, TestaMudarTamanho) {
    TipoPilha<TipoItem>* pilha = new TipoPilha<TipoItem>();

    if (!pilha->isDynamicAllocated()) {

        int tamanho_inicial = pilha->getCapacity();
        int tamanho_teste = tamanho_inicial * 5;

        int valores_aleatorios[tamanho_teste];
        for (int i = 0; i < tamanho_teste; i++) {
            valores_aleatorios[i] = rand();
        }
        
        for (int i = 0; i < pilha->getCapacity(); i++) {
            ASSERT_TRUE(pilha->push(valores_aleatorios[i]));
        }

        ASSERT_FALSE(pilha->setCapacity(tamanho_inicial - 1)) << "O tamanho da pilha não pode ser menor que a quantidade de elementos contidos nela.";
        ASSERT_TRUE(pilha->setCapacity(tamanho_teste)) << "Algo errado ocorreu ao dobrar o tamanho da pilha.";

        for (int i = tamanho_inicial; i < tamanho_teste; i++) {
            ASSERT_TRUE(pilha->push(valores_aleatorios[i]));
        }

        for (int i = 0; i < tamanho_teste; i++) {
            int* pop = pilha->pop();
            ASSERT_EQ(*pop, valores_aleatorios[tamanho_teste - i - 1]);
        }

        ASSERT_TRUE(pilha->isEmpty());
    } else {
        // teste ignorado para pilhas dinamicamente alocadas
    }

    delete pilha;
}

// Implementação de função main do gtest
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}