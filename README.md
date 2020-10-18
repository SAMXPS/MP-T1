Universidade de Brasília (UnB)

Métodos de Programação - 2020/1

# Trabalho 1
- Aluno: Samuel James de Lima Barroso
- Matrícula: 19/0019948
- Turma: A

## Observações

+ Este trabalho foi feito em C++ e faz uso de classes, métodos virtuais, interfaces e [templates](http://www.cplusplus.com/doc/oldtutorial/templates/).

+ A codificação de pilha foi dividida em duas classes: 
    - PilhaEncadeada 
    - PilhaVetor
    > Cada classe possui seus arquivos de header (.hpp) e implementação (.cpp)


+ Foi desconsiderada a implementação das funções ```CreateStack ()``` e ```DestroyStack ()```, uma vez que o C++ possui métodos construtores e métodos destrutores de objetos de classes.

+ Os métodos ```Size(pilha)``` e ```SetSize(pilha, int)``` foram renomeados, respectivamente, para ```Pilha::getCapacity()``` e ```Pilha::setCapacity(int)```. Isso foi feito com intuito de remover ambiguidade do termo _size_, que poderia ser interpretado tanto como _quantos elementos a pilha contém atualmente_ ou _quantos elementos cabem ao todo na pilha_. Dessa forma, o termo _capacity_ é mais direto e se refere à quantos elementos cabem ao todo na pilha.

## Organização do Trabalho

### Diretórios
#### bin/
Contém os arquivos binários gerados pelo compilador.

#### doxygen/
Contém os arquivos da documentação gerada pelo doxygen.

#### gcov/
Contém os arquivos gerados pelo ```gcov```

#### include/
Contém os cabeçalhos (headers) da minha biblioteca de Pilha.

#### source/
Contém as implementações de Pilha em C++.


### Compilação e execução dos testes

#### Testes

Os testes unitários foram feitos por meio do framework gtest e
podem ser encontrados no arquivo ```source/TestaPilha.cpp```.

Para instalar o gtest, pode-se seguir os comandos (Ubuntu 18.04) 
encontrados [neste gist](https://gist.github.com/Cartexius/4c437c084d6e388288201aadf9c8cdd5).

#### Escolher tipo de pilha
+ Para escolher qual tipo de pilha será testada, basta modificar o arquivo ```TestaPilhaTipo.cpp``` e alterar o header com um dos seguintes valores:
    - ```#define TipoPilha PilhaEncadeada``` para PilhaEncadeada
    - ```#define TipoPilha PilhaVetor``` para PilhaVetor
    > Vale a pena dar uma olhada no script ```gcov/gcov.sh```, pois ele faz esse processo de troca de headers de forma automática.

#### Compilação e execução dos testes

Compilação e execução dos testes pode ser feita rodando o script ```source/make_and_test.sh``` da seguinte forma:

```sh
cd source/
./make_and_test.sh
```

Caso aconteça algum erro de execução do script, será necessário prover permissão de execução a ele.
```sh
chmod +x make_and_test.sh
```

Toda a compilação feita é baseada num arquivo MakeFile.

#### Utilizando script gcov

Neste trabalho, também foi feito um script que automatiza o processo de compilação, execução dos testes e verificação de cobertura.

Para rodar o script, basta seguir os seguintes passos:

```sh
cd gcov/
./gcov.sh
```


>Caso aconteça algum erro de execução do script, será necessário prover permissão de execução a ele. (``` chmod +x gcov.sh```)

Após isso, os seguintes arquivos serão gerados:

| arquivo | descrição |
| - | - |
| gcov.out  | Saída do programa gcov, contém dados resumidos referentes à cobertura de código das duas implementações de pilha. |
| gtest.out | Saída dos testes realizados pelo gtest nessa biblioteca. |
| PilhaEncadeada.cpp.gcov  | Arquivo que contém dados referentes a quantas vezes cada linha do programa PilhaEncadeada.cpp foi executada nos testes. |
| PilhaVetor.cpp.gcov  | Arquivo que contém dados referentes a quantas vezes cada linha do programa PilhaVetor.cpp foi executada nos testes. |






