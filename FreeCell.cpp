#include "FreeCell.h"
#include <iostream>
using namespace std;

//Função Construtora
Pilha::Pilha(){
//Pós-Condição:as duas Pilhas são criadas e iniciadas como vazia
    TopoPilha1 = 0;
    TopoPilha2 = 38;
}

//Função Destrutora
Pilha::~Pilha(){
//Pré-Condição: Pilha necessita estar criada

//Pós-Condição: Pilha é destruída
    cout << "Pilha destruida!" << endl;
}

//Função de verificação: Pilha1 Cheia
bool Pilha::CheioPilha1(){
//Pré-Condição: Pilha necessita estar criada

//Pós-Condição: Retorna um valor booleano de true se (TopoPilha1 == 19)
// ou falso se (TopoPilha1 != 19)
    return TopoPilha1 == 19;
}

//Função de verificação: Pilha2 Cheia
bool Pilha::CheioPilha2(){
//Pré-Condição: Pilha necessita estar criada

//Pós-Condição: Retorna um valor booleano de true se (TopoPilha2 == 21)
// ou falso se (TopoPilha2 != 21)
    return TopoPilha2 == 21;
}

//Função de verificação: Pilha1 Vazia
bool Pilha::VazioPilha1(){
//Pré-Condição: Pilha necessita estar criada

//Pós-Condição: Retorna um valor booleano de true se (TopoPilha1 == 0)
// ou falso se (TopoPilha1 != 0)
    return TopoPilha1 == 0;
}

//Função de verificação: Pilha2 Vazia
bool Pilha::VazioPilha2(){
//Pré-Condição: Pilha necessita estar criada

//Pós-Condição: Retorna um valor booleano de true se (TopoPilha1 == 38)
// ou falso se (TopoPilha1 != 38)
    return TopoPilha2 == 38;
}

//Função de Inserir(PUSH) Pilha1
void Pilha::PushPilha1(string x){
//Pré-Condição: Pilha necessita estar criada
//pilha não pode estar cheia

//Pós-Condição: Se a pilha não estiver cheia, a função insere o elemento 'x' no topo da Pilha1.
//Se a pilha estiver cheia, a função imprime uma mensagem de erro e não faz nenhuma inserção.
//Após a inserção, o índice do topo da Pilha1 (TopoPilha1) é incrementado.

    if (CheioPilha1())
    {
        cout << "A pilha está cheia!" << endl;
        return; // Não faz nada, pois a pilha está cheia.
    }

// Incrementa o índice do topo da Pilha1 e insere o elemento 'x'.
    TopoPilha1++;
    estrutura[TopoPilha1] = x;
}

//Função de Inserir(PUSH) Pilha2
void Pilha::PushPilha2(string x){
//Pré-Condição: Pilha necessita estar criada
//pilha não pode estar cheia

//Pós-Condição: Se a pilha não estiver cheia, a função insere o elemento 'x' no topo da Pilha1.
//Se a pilha estiver cheia, a função imprime uma mensagem de erro e não faz nenhuma inserção.
//Após a inserção, o índice do topo da Pilha2 (TopoPilha2) é decrementado.


    if (CheioPilha2())
    {
        cout << "A pilha está cheia!" << endl;
        return; // Não faz nada, pois a pilha está cheia.
    }

    // Decrementa o índice do topo da Pilha2 e insere o elemento 'x'.
    TopoPilha2--;
    estrutura[TopoPilha2] = x;
}

//Função de Retirar(POP) Pilha1
void Pilha::PopPilha1(string &x){
//Pré-Condição: Pilha necessita estar criada
//pilha não pode estar vazia

//Pós-Condição: Se a pilha não estiver vazia, a função remove o elemento do topo da Pilha1 e armazena-o em 'x'.
// Se a pilha estiver vazia, a função imprime uma mensagem de erro e não faz nenhuma remoção.
//Após a remoção, o índice do topo da Pilha1 (TopoPilha1) é decrementado.

    if (VazioPilha1())
    {
        cout << "A pilha esta vazia!!" << endl;
        return; // Não faz nada, pois a pilha está vazia.
    }

// Remove o elemento do topo da Pilha1 e o armazena em 'x'.
    x = estrutura[TopoPilha1];
    TopoPilha1--;
}

//Função de Retirar(POP) Pilha2
void Pilha::PopPilha2(string &x){
//Pré-Condição: Pilha necessita estar criada
//pilha não pode estar vazia

//Pós-Condição: Se a pilha não estiver vazia, a função remove o elemento do topo da Pilha2 e armazena-o em 'x'.
// Se a pilha estiver vazia, a função imprime uma mensagem de erro e não faz nenhuma remoção.
//Após a remoção, o índice do topo da Pilha2 (TopoPilha2) é incrementado.
    if (VazioPilha2())
    {
        cout << "A pilha esta vazia!!" << endl;
        return; // Não faz nada, pois a pilha está vazia.
    }

// Remove o elemento do topo da Pilha2 e o armazena em 'x'.    
    x = estrutura[TopoPilha2];
    TopoPilha2++;
}

//Função de Verificação: Topo da Pilha1
void Pilha::TopPilha1(string &x){
//Pré-condição: Pilha necessita estar criada
//Não pode estar vazia

//Pós-Condição:retorna mensagem de pilha vazia caso não possua nenhuma elemento
// x recebe Topo da pilha1
    if (VazioPilha1())
    {
        x = "vazia";
        return;
    }
    x = estrutura[TopoPilha1];
}

//Função de Verificação: Topo da Pilha2
void Pilha::TopPilha2(string &x){
//Pré-condição: Pilha necessita estar criada
//Não pode estar vazia

//Pós-Condição:retorna mensagem de pilha vazia caso não possua nenhuma elemento
// x recebe Topo da pilha2
    if (VazioPilha2())
    {
        x = "vazia";
        return;
    }
    x = estrutura[TopoPilha2];
}

//Função de Verificação: Tamanho(SIZE) da Pilha1
int Pilha::TamanhoPilha1(){
//Pré-Condição: Pilha necessita estar criada

//Pós-Condição: Retorna o valor inteiro de (TopoPilha1)
    return TopoPilha1;
}

//Função de Verificação: Tamanho(SIZE) da Pilha2
int Pilha::TamanhoPilha2(){
//Pré-Condição: Pilha necessita estar criada

//Pós-Condição: Retorna o valor inteiro de (TopoPilha2)
    return TopoPilha2;
}

//Escreve o elemento da Pilha1 na posição 'x' na saída padrão
void Pilha::EscrevePilha1(int x){
//Pré-Condição: Pilha necessita estar criada
// 'x' necessita ser um índice válido para Pilha1, ou seja, 0 <= x <= TopoPilha1.

//Pós-Condição: Se 'x' é um índice válido para a Pilha1, a função imprime o elemento da posição 'x'.
//Se o elemento tiver um tamanho diferente de 2, ele é impresso entre colchetes "[elemento]".
//Se o elemento tiver um tamanho igual a 2, ele é impresso entre colchetes com um espaço adicional "[ elemento ]".

    if (x <= TopoPilha1) {
    string elemento = estrutura[x];

// Verifica o tamanho do elemento e formata a saída de acordo.
        if (elemento.length() != 2) {
            cout << "[" << elemento << "]";
        } else {
            cout << "[ " << elemento << "]";  
        }
    } else {
        cout << "     " ;
    }
}

void Pilha::EscrevePilha2(int x){
//Pré-Condição: Pilha necessita estar criada
// 'x' necessita ser um índice válido para Pilha2, ou seja, 0 <= x <= TopoPilha2.

//Pós-Condição: Se 'x' é um índice válido para a Pilha2, a função imprime o elemento da posição 'x'.
//Se o elemento tiver um tamanho diferente de 2, ele é impresso entre colchetes "[elemento]".
//Se o elemento tiver um tamanho igual a 2, ele é impresso entre colchetes com um espaço adicional "[ elemento ]".
    x = 38 - x;
    if (x >= TopoPilha2) {
    string elemento = estrutura[x];

// Verifica o tamanho do elemento e formata a saída de acordo.
        if (elemento.length() != 2) {
        cout << "[" << elemento << "]";
        } else {
        cout << "[ " << elemento << "]";  
        }
    } else {
        cout << "     " ;
    }
}
