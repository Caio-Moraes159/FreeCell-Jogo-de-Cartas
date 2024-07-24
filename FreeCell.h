//SALA: 4°A
/*ALUNOS:
Caio Caminitti de Moraes - 2146079
Leonardo Ferreira Colmanetti de Almeida Lima - 2131526*/

#ifndef PILHA_H
#define PILHA_H
#include <string>
using namespace std;
const int quantidade = 39;

class Pilha{
    public:
    Pilha();
    ~Pilha();

    void PushPilha1(string x);
    void PushPilha2(string x);
    void PopPilha1(string &x);
    void PopPilha2(string &x);
    void TopPilha1(string &x);
    void TopPilha2(string &x);
    bool VazioPilha1();
    bool VazioPilha2();
    bool CheioPilha1();
    bool CheioPilha2();
    int TamanhoPilha1();
    int TamanhoPilha2();
    void EscrevePilha1(int x);
    void EscrevePilha2(int x);

    private:
    int TopoPilha1;
    int TopoPilha2;
    string estrutura[quantidade];
};
#endif