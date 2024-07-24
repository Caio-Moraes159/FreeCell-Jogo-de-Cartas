//SALA: 4°A
/*ALUNOS:
Caio Caminitti de Moraes - 2146079
Leonardo Ferreira Colmanetti de Almeida Lima - 2131526*/

#include "FreeCell.h"
#include <iostream>
#include <algorithm>
using namespace std;

struct baralho
{
    int Numero; 
    string Naipe; 
    string Cor;
    string NumNaipe; 
};

void menu(struct baralho cartas[], int NumCartas, string freeCells1, string freeCells2, string freeCells3, string freeCells4, string PilhaDeSaida1, string PilhaDeSaida2, string PilhaDeSaida3, string PilhaDeSaida4, Pilha &estrutura1, Pilha &estrutura2, Pilha &estrutura3, Pilha &estrutura4);
void CriaCartas(struct baralho cartas[]);
bool verificação(int &retirar, int &inserir, string auxiliar1, string auxiliar2, struct baralho cartas[], int NumCartas, string freeCells1, string freeCells2, string freeCells3, string freeCells4, string PilhaDeSaida1, string PilhaDeSaida2, string PilhaDeSaida3, string PilhaDeSaida4, Pilha &estrutura1, Pilha &estrutura2, Pilha &estrutura3, Pilha &estrutura4);
void EmbaralhaCartas(Pilha &estrutura1, Pilha &estrutura2, Pilha &estrutura3, Pilha &estrutura4, struct baralho cartas[], int NumCartas);

int main(){
    //Variaveis: 
    string freeCells1, freeCells2, freeCells3, freeCells4;
    string PilhaDeSaida1, PilhaDeSaida2, PilhaDeSaida3, PilhaDeSaida4;
    const int NumCartas = 52;
    baralho cartas[NumCartas];
    Pilha estrutura1, estrutura2, estrutura3, estrutura4;
    bool denovo = false;

    while(denovo == false){
        CriaCartas(cartas);
        EmbaralhaCartas(estrutura1, estrutura2, estrutura3, estrutura4, cartas, NumCartas);
        menu(cartas, NumCartas, freeCells1, freeCells2, freeCells3, freeCells4, PilhaDeSaida1, PilhaDeSaida2, PilhaDeSaida3, PilhaDeSaida4, estrutura1, estrutura2, estrutura3, estrutura4);
        cout << endl << "Voce ganhou!! Deseja jogar novamente? (0=sim/1=nao)" << endl;
        cin >> denovo;
    }

    return 0;
};

//Função que exibe e controla o jogo Free Cell
void menu(struct baralho cartas[], int NumCartas, string freeCells1, string freeCells2, string freeCells3, string freeCells4, string PilhaDeSaida1, string PilhaDeSaida2, string PilhaDeSaida3, string PilhaDeSaida4, Pilha &estrutura1, Pilha &estrutura2, Pilha &estrutura3, Pilha &estrutura4){
//Pré-condição: As estruturas de dados devem estar inicializados antes de chamar a função
//a função de verificação deve estar adequada aos parâmetros do jogo

//Pós-condição: O jogo Free cell é inicializado e jogado dentro desta função
//O jogo termina quando todas as cartas são movidas para as variáveis de saída
//o usuário pode escolher se deseja jogar novamente ou não

bool jogo = false;

//exibe as informações do jogo na tela
cout << endl
     << "---------------------- BEM VINDO AO FREE CELL ----------------------" << endl 
     << "O FreeCell e um jogo de cartas solitario que utiliza um baralho padrao" << endl
     << "de 52 cartas. O objetivo e mover todas as cartas para quatro pilhas" << endl 
     << "de saida, organizando-as em ordem crescente por naipe. O jogo possui" << endl
     << "oito pilhas iniciais, quatro com sete cartas e quatro com seis cartas," << endl
     << "e o jogador pode movimentar cartas entre pilhas seguindo regras especificas." << endl
     << "O desafio reside em planejar os movimentos de forma estrategicas para"  << endl
     << "alcancar a vitoria." << endl << endl << endl;

// exibe o jogo na tela enquanto (jogo == false)
    while (jogo == false)
    {      
        cout << "  -------FREE CELL-------  " << "        " << "  ----PILHAS DE SAIDA----  " << endl;
        cout << "  8  " << "    9   " << "   10   " << "  11  " << "        " << "  12   " << "  13   " << "  14   " << "  15  " << endl;
        if (freeCells1.length() == 0)
        {
             cout << "[ " << freeCells1 << "  ]  ";
        } else if (freeCells1.length() == 2)
        {
            cout << "[ " << freeCells1 << "]  ";
        } else if(freeCells1.length() == 3)
        {
            cout << "[" << freeCells1 << "]  ";
        }

        if (freeCells2.length() == 0)
        {
             cout << "[ " << freeCells2 << "  ]  ";
        } else if (freeCells2.length() == 2)
        {
            cout << "[ " << freeCells2 << "]  ";
        } else if(freeCells2.length() == 3)
        {
            cout << "[" << freeCells2 << "]  ";
        }

        if (freeCells3.length() == 0)
        {
             cout << "[ " << freeCells3 << "  ]  ";
        } else if (freeCells3.length() == 2)
        {
            cout << "[ " << freeCells3 << "]  ";
        } else if(freeCells3.length() == 3)
        {
            cout << "[" << freeCells3 << "]  ";
        }

        if (freeCells4.length() == 0)
        {
             cout << "[ " << freeCells4 << "  ] ";
        } else if (freeCells4.length() == 2)
        {
            cout << "[ " << freeCells4 << "] ";
        } else if(freeCells4.length() == 3)
        {
            cout << "[" << freeCells4 << "] ";
        }
        
        cout << "       ";

        if (PilhaDeSaida1.length() == 0)
        {
            cout << " [ " << PilhaDeSaida1 << "C ] ";
        } else if (PilhaDeSaida1.length() == 2)
        {
            cout << " [ " << PilhaDeSaida1 << "] ";
        } else if (PilhaDeSaida1.length() == 3)
        {
            cout << " [" << PilhaDeSaida1 << "] ";
        }

        if (PilhaDeSaida2.length() == 0)
        {
            cout << " [ " << PilhaDeSaida2 << "E ] ";
        } if (PilhaDeSaida2.length() == 2)
        {
            cout << " [ " << PilhaDeSaida2 << "] ";
        } else if (PilhaDeSaida2.length() == 3)
        {
            cout << " [" << PilhaDeSaida2 << "] ";
        }

        if (PilhaDeSaida3.length() == 0)
        {
            cout << " [ " << PilhaDeSaida3 << "U ] ";
        } if (PilhaDeSaida3.length() == 2)
        {
            cout << " [ " << PilhaDeSaida3 << "] ";
        } else if (PilhaDeSaida3.length() == 3)
        {
            cout << " [" << PilhaDeSaida3 << "] ";
        }

        if (PilhaDeSaida4.length() == 0)
        {
            cout << " [ " << PilhaDeSaida4 << "P ] ";
        } if (PilhaDeSaida4.length() == 2)
        {
            cout << " [ " << PilhaDeSaida4 << "] ";
        } else if (PilhaDeSaida4.length() == 3)
        {
            cout << " [" << PilhaDeSaida4 << "] ";
        }
        cout << endl << endl;

        cout << "  0     " << "  1    " << "   2   " << "    3    " << "   4    " << "   5    " << "   6    " << "   7    " << endl;      

        int indiceCursor = 9;
        if (indiceCursor <= 5)
        {
            indiceCursor = 7;
        }

        for (int i = 1; i <= indiceCursor; i++) 
        {
            estrutura1.EscrevePilha1(i);
            cout << "   ";
            estrutura1.EscrevePilha2(i);
            cout << "   ";
            estrutura2.EscrevePilha1(i);
            cout << "   ";
            estrutura2.EscrevePilha2(i);
            cout << "   ";
            estrutura3.EscrevePilha1(i);
            cout << "   ";
            estrutura3.EscrevePilha2(i);
            cout << "   ";
            estrutura4.EscrevePilha1(i);
            cout << "   ";
            estrutura4.EscrevePilha2(i);
            cout << endl;
        }
 
        int retirar, inserir = 0;
    //variáveis utlizadas na função verificação
        string auxiliar1, auxiliar2;
        bool verifica = false;

    //enquanto a jogada não for válida (verificação == true) a função fica presa no loop
        while (verifica == false)
        {
            verifica =  verificação(retirar, inserir, auxiliar1, auxiliar2, cartas, NumCartas, freeCells1, freeCells2, freeCells3, freeCells4, PilhaDeSaida1, PilhaDeSaida2, PilhaDeSaida3, PilhaDeSaida4, estrutura1, estrutura2, estrutura3, estrutura4);
        }

        string troca;
        //faz o pop(retirar) depois das verificações
        if (retirar >= 0 && retirar <= 7)
        {
            if (retirar == 0)
            {
                estrutura1.PopPilha1(troca);
                indiceCursor--;
            }
            if (retirar == 1)
            {
                estrutura1.PopPilha2(troca);
                indiceCursor--;
            }
            if (retirar == 2)
            {
                estrutura2.PopPilha1(troca);
                indiceCursor--;
            }
            if (retirar == 3)
            {
                estrutura2.PopPilha2(troca);
                indiceCursor--;
            }
            if (retirar == 4)
            {
                estrutura3.PopPilha1(troca);
                indiceCursor--;
            }
            if (retirar == 5)
            {
                estrutura3.PopPilha2(troca);
                indiceCursor--;
            }
            if (retirar == 6)
            {
                estrutura4.PopPilha1(troca);
                indiceCursor--;
            }
            if (retirar == 7)
            {
                estrutura4.PopPilha2(troca);
                indiceCursor--;
            }
        } 
        if (retirar >= 8 && retirar <= 11)
        {
            if (retirar == 8)
            {
                troca = freeCells1;
                freeCells1 = "";
            }
            if (retirar == 9)
            {
                troca = freeCells2;
                freeCells2 = "";
            }
            if (retirar == 10)
            {
                troca = freeCells3;
                freeCells3 = "";
            }
            if (retirar == 11)
            {
                troca = freeCells4;
                freeCells4 = "";
            }
        } 

        //faz o push(inserir) depois das verificações
        if (inserir >= 0 && inserir <= 7)
        {
            if (inserir == 0)
            {
                estrutura1.PushPilha1(troca);
                indiceCursor++;
            }
            if (inserir == 1)
            {
                estrutura1.PushPilha2(troca);
                indiceCursor++;
            }
            if (inserir == 2)
            {
                estrutura2.PushPilha1(troca);
                indiceCursor++;
            }
            if (inserir == 3)
            {
                estrutura2.PushPilha2(troca);
                indiceCursor++;
            }
            if (inserir == 4)
            {
                estrutura3.PushPilha1(troca);
                indiceCursor++;
            }
            if (inserir == 5)
            {
                estrutura3.PushPilha2(troca);
                indiceCursor++;
            }
            if (inserir == 6)
            {
                estrutura4.PushPilha1(troca);
                indiceCursor++;
            }
            if (inserir == 7)
            {
                estrutura4.PushPilha2(troca);
                indiceCursor++;
            }
        } 
        if (inserir >= 8 && inserir <= 11)
        {
            if (inserir == 8)
            {
                freeCells1 = troca;
            }
            if (inserir == 9)
            {
                freeCells2 = troca;
            }
            if (inserir == 10)
            {
                freeCells3 = troca;
            }
            if (inserir == 11)
            {   
                freeCells4 = troca;
            }
        } 
        if (inserir >= 12 && inserir <= 15)
        {
            if (inserir == 12)
            {
                PilhaDeSaida1 = troca;
            }
            if (inserir == 13)
            {
                PilhaDeSaida2 = troca;
            }
            if (inserir == 14)
            {
                PilhaDeSaida3 = troca;
            }
            if (inserir == 15)
            {
                PilhaDeSaida4 = troca;
            }
        }

//verifica se o jogo foi ganho e retorna jogo = true,encerrando a função menu
        if (PilhaDeSaida1 == "KC" && PilhaDeSaida2 == "KE" && PilhaDeSaida3 == "KU" && PilhaDeSaida4 == "KP")
        {
            jogo = true;
        }
    }
}

//Função que verifica se o movimento é válido
bool verificação(int &retirar, int &inserir, string auxiliar1, string auxiliar2, struct baralho cartas[], int NumCartas, string freeCells1, string freeCells2, string freeCells3, string freeCells4, string PilhaDeSaida1, string PilhaDeSaida2, string PilhaDeSaida3, string PilhaDeSaida4, Pilha &estrutura1, Pilha &estrutura2, Pilha &estrutura3, Pilha &estrutura4){
//Pré-condição: Deve ser chamada dentro da função menu

//Pós-condição: Caso o movimento feito pelo usuário caia dentro de algum if,é considerado inválido e retorna falso
//Caso seja válido,retorna true
cin >> retirar;
cin >> inserir; 
cout << "------------------------------------------------------------------" << endl << endl;

//Faz um Top da carta correspondente à escolhida pelo usuário para fazer o pop
if (retirar >= 0 && retirar <= 7)
{
    if (retirar == 0)
    {
        estrutura1.TopPilha1(auxiliar1);
    }
    if (retirar == 1)
    {
        estrutura1.TopPilha2(auxiliar1);
    }
    if (retirar == 2)
    {
        estrutura2.TopPilha1(auxiliar1);
    }
    if (retirar == 3)
    {
        estrutura2.TopPilha2(auxiliar1);
    }
    if (retirar == 4)
    {
        estrutura3.TopPilha1(auxiliar1);
    }
    if (retirar == 5)
    {
        estrutura3.TopPilha2(auxiliar1);
    }
    if (retirar == 6)
    {
        estrutura4.TopPilha1(auxiliar1);
    }
    if (retirar == 7)
    {
        estrutura4.TopPilha2(auxiliar1);
    }
} 
if (retirar >= 8 && retirar <= 11)
{
    if (retirar == 8)
    {
        auxiliar1 = freeCells1;
    }
    if (retirar == 9)
    {
        auxiliar1 = freeCells2;
    }
    if (retirar == 10)
    {
        auxiliar1 = freeCells3;
    }
    if (retirar == 11)
    {
        auxiliar1 = freeCells4;
    }
} 
if (retirar >= 12 && retirar <= 15)
{
    if (retirar == 12)
    {
        auxiliar1 = PilhaDeSaida1;
    }
    if (retirar == 13)
    {
        auxiliar1 = PilhaDeSaida2;
    }
    if (retirar == 14)
    {
        auxiliar1 = PilhaDeSaida3;
    }
    if (retirar == 15)
    {
        auxiliar1 = PilhaDeSaida4;
    }
}

if (auxiliar1 == "vazia"){
    cout << "Pilha vazia!" << endl;
    return false;
} else if (retirar < 0 || retirar > 15){
    cout << "Numero invalido!" << endl;
    return false;
} else if( retirar == inserir){
    cout << "Movimento invalido!" << endl;
    return false;
}

//Faz um Top da carta correspondente à escolhida pelo usuário para fazer o push
if (inserir >= 0 && inserir <= 7)
{
    if (inserir == 0)
    {
        estrutura1.TopPilha1(auxiliar2);
    }
    if (inserir == 1)
    {
        estrutura1.TopPilha2(auxiliar2);
    }
    if (inserir == 2)
    {
        estrutura2.TopPilha1(auxiliar2);
    }
    if (inserir == 3)
    {
        estrutura2.TopPilha2(auxiliar2);
    }
    if (inserir == 4)
    {
        estrutura3.TopPilha1(auxiliar2);
    }
    if (inserir == 5)
    {
        estrutura3.TopPilha2(auxiliar2);
    }
    if (inserir == 6)
    {
        estrutura4.TopPilha1(auxiliar2);
    }
    if (inserir == 7)
    {
        estrutura4.TopPilha2(auxiliar2);
    }
} 
if (inserir >= 8 && inserir <= 11)
{
    if (inserir == 8)
    {
        auxiliar2 = freeCells1;
    }
    if (inserir == 9)
    {
        auxiliar2 = freeCells2;
    }
    if (inserir == 10)
    {
        auxiliar2 = freeCells3;
    }
    if (inserir == 11)
    {
        auxiliar2 = freeCells4;
    }
} 
if (inserir >= 12 && inserir <= 15)
{
    if (inserir == 12)
    {
        auxiliar2 = PilhaDeSaida1;
    }
    if (inserir == 13)
    {
        auxiliar2 = PilhaDeSaida2;
    }
    if (inserir == 14)
    {
        auxiliar2 = PilhaDeSaida3;
    }
    if (inserir == 15)
    {
        auxiliar2 = PilhaDeSaida4;
    }
}

//verifica e atribui as propriedades das cartas que serão utilizadas
if (inserir < 0 || inserir > 15)
{
    cout << "Numero invalido!" << endl;
    return false;
}

int indiceCartas1;
for (int i = 0; i < NumCartas; i++)
{
    if (auxiliar1 == cartas[i].NumNaipe)
    {
        indiceCartas1 = i;
    }
}

int indiceCartas2;
for (int i = 0; i < NumCartas; i++)
{
    if (auxiliar2 == cartas[i].NumNaipe)
    {
        indiceCartas2 = i;
    }
}

//verificações para inserir nas pilhas de jogo
if (inserir >= 0 && inserir <= 7)
{   
    if(cartas[indiceCartas1].Cor == cartas[indiceCartas2].Cor){
        if (auxiliar2 != "vazia")
        {
            cout << "Cor igual! Movimento invalido!" << endl;
            return false;    
        }
    } 

    if ((cartas[indiceCartas1].Numero+1) != cartas[indiceCartas2].Numero)
    {   
        if(auxiliar2 != "vazia")
        {
            cout << "O numero nao e menor! Movimento invalido!" << endl;
            return false;
        } 
    }
}

//verificações para inserir nas Free cells
if (inserir >= 8 && inserir <= 11)
{
    if (inserir == 8)
    {
        if (freeCells1.length() != 0)
        {
            cout << "FreeCell ocupada! Movimento invalido" << endl;
            return false;
        }
    }
    if (inserir == 9)
    {
        if (freeCells2.length() != 0)
        {
            cout << "FreeCell ocupada! Movimento invalido" << endl;
            return false;
        }
    }
    if (inserir == 10)
    {
        if (freeCells3.length() != 0)
        {
            cout << "FreeCell ocupada! Movimento invalido" << endl;
            return false;
        }
    }
    if (inserir == 11)
    {
        if (freeCells4.length() != 0)
        {
            cout << "FreeCell ocupada! Movimento invalido" << endl;
            return false;
        }
    }
}

//verificação das pilhas de saída
static int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0;
if (inserir >= 12 && inserir <= 15)
{
    if (inserir == 12)
    {   
        if (flag1 == 0)
        {
            if (cartas[indiceCartas1].NumNaipe == "AC")
            {
                flag1++;
                return true;
            } else {
                cout << "Movimento invalido!" << endl;
                return false;
            }
        } else if (flag1 == 1)
        {
            if (cartas[indiceCartas1].Naipe == "C" && (cartas[indiceCartas1].Numero-1) == cartas[indiceCartas2].Numero)
            {
                return true;
            } else {
                cout << "Movimento invalido!" << endl;
                return false;     
            }
        }
    }
    if (inserir == 13)
    {   
        if (flag2 == 0)
        {
            if (cartas[indiceCartas1].NumNaipe == "AE")
            {
                flag2++;
                return true;
            } else {
                cout << "Movimento invalido!" << endl;
                return false;
            }
        } else if (flag2 == 1)
        {
            if (cartas[indiceCartas1].Naipe == "E" && (cartas[indiceCartas1].Numero-1) == cartas[indiceCartas2].Numero)
            {
                return true;
            } else {
                cout << "Movimento invalido!" << endl;
                return false;     
            }
        }
    }
    if (inserir == 14)
    {   
       if (flag3 == 0)
        {
            if (cartas[indiceCartas1].NumNaipe == "AU")
            {
                flag3++;
                return true;
            } else {
                cout << "Movimento invalido!" << endl;
                return false;
            }
        } else if (flag3 == 1)
        {
            if (cartas[indiceCartas1].Naipe == "U" && (cartas[indiceCartas1].Numero-1) == cartas[indiceCartas2].Numero)
            {
                return true;
            } else {
                cout << "Movimento invalido!" << endl;
                return false;     
            }
        }
    }
    if (inserir == 15)
    {   
       if (flag4 == 0)
        {
            if (cartas[indiceCartas1].NumNaipe == "AP")
            {
                flag4++;
                return true;
            } else {
                cout << "Movimento invalido!" << endl;
                return false;
            }
        } else if (flag4 == 1)
        {
            if (cartas[indiceCartas1].Naipe == "P" && (cartas[indiceCartas1].Numero-1) == cartas[indiceCartas2].Numero)
            {
                return true;
            } else {
                cout << "Movimento invalido!" << endl;
                return false;     
            }
        } 
    }
}
return true;
}

//Função qe cria as cartas 
void CriaCartas(struct baralho cartas[]){
//Pré-condição:Necessário Receber um vetor de struct como parâmetro

//Pós-condição: Cria as cartas de baralho e joga dentro do vetor baralho cartas
    int count = 0;
    int i, j, k, l;

    for (i = 0; i < 13; ++i) {
        if (count == 0)
        {
            cartas[i].Numero = count + 1;
            cartas[i].Naipe = "E";
            cartas[i].Cor = "preto"; 
            cartas[i].NumNaipe = "AE";
        } else if (count < 10) {
            cartas[i].Numero = count + 1; // Atribui 1 a 10
            cartas[i].Naipe = "E";
            cartas[i].Cor = "preto";
            cartas[i].NumNaipe = to_string(count + 1) + "E";
        } else if (count == 10) {
            cartas[i].Numero = count + 1; 
            cartas[i].Naipe = "E";
            cartas[i].Cor = "preto";
            cartas[i].NumNaipe = "JE";
        } else if (count == 11) {
            cartas[i].Numero = count + 1; 
            cartas[i].Naipe = "E";
            cartas[i].Cor = "preto";
            cartas[i].NumNaipe = "QE";
        } else if (count == 12) {
            cartas[i].Numero = count + 1; 
            cartas[i].Naipe = "E";
            cartas[i].Cor = "preto";
            cartas[i].NumNaipe = "KE";
        }
        count++;
    }

    count = 0;
    
    for (j = i; j < 26; ++j) {
        if (count == 0)
        {
            cartas[j].Numero = count + 1;
            cartas[j].Naipe = "C";
            cartas[j].Cor = "vermelho";
            cartas[j].NumNaipe = "AC";
        } else if (count < 10) {
            cartas[j].Numero = count + 1; // Atribui 1 a 10
            cartas[j].Naipe = "C";
            cartas[j].Cor = "vermelho";
            cartas[j].NumNaipe = to_string(count + 1) + "C";
        } else if (count == 10) {
            cartas[j].Numero = count + 1; 
            cartas[j].Naipe = "C";
            cartas[j].Cor = "vermelho";
            cartas[j].NumNaipe = "JC";
        } else if (count == 11) {
            cartas[j].Numero = count + 1; 
            cartas[j].Naipe = "C";
            cartas[j].Cor = "vermelho";
            cartas[j].NumNaipe = "QC";
        } else if (count == 12) {
            cartas[j].Numero = count + 1; 
            cartas[j].Naipe = "C";
            cartas[j].Cor = "vermelho";
            cartas[j].NumNaipe = "KC";
        }
        count++;
    }

    count = 0;
    
    for (k = j; k < 39; ++k) {
        if (count == 0)
        {
            cartas[k].Numero = count + 1;
            cartas[k].Naipe = "P";
            cartas[k].Cor = "preto";
            cartas[k].NumNaipe = "AP";
        } else if (count < 10) {
            cartas[k].Numero = count + 1; // Atribui 1 a 10
            cartas[k].Naipe = "P";
            cartas[k].Cor = "preto";
            cartas[k].NumNaipe = to_string(count + 1) + "P";
        } else if (count == 10) {
            cartas[k].Numero = count + 1; 
            cartas[k].Naipe = "P";
            cartas[k].Cor = "preto";
            cartas[k].NumNaipe = "JP";
        } else if (count == 11) {
            cartas[k].Numero = count + 1; 
            cartas[k].Naipe = "P";
            cartas[k].Cor = "preto";
            cartas[k].NumNaipe = "QP";
        } else if (count == 12) {
            cartas[k].Numero = count + 1; 
            cartas[k].Naipe = "P";
            cartas[k].Cor = "preto";
            cartas[k].NumNaipe = "KP";
        }
        count++;
    }
    
    count = 0;

    for (l = k; l < 52; ++l) {
        if (count == 0)
        {
            cartas[l].Numero = count + 1;
            cartas[l].Naipe = "U";
            cartas[l].Cor = "vermelho";
            cartas[l].NumNaipe = "AU";
        } else if (count < 10) {
            cartas[l].Numero = count + 1; // Atribui 1 a 10
            cartas[l].Naipe = "U";
            cartas[l].Cor = "vermelho";
            cartas[l].NumNaipe = to_string(count + 1) + "U";
        } else if (count == 10) {
            cartas[l].Numero = count + 1; 
            cartas[l].Naipe = "U";
            cartas[l].Cor = "vermelho";
            cartas[l].NumNaipe = "JU";
        } else if (count == 11) {
            cartas[l].Numero = count + 1; 
            cartas[l].Naipe = "U";
            cartas[l].Cor = "vermelho";
            cartas[l].NumNaipe = "QU";
        } else if (count == 12) {
            cartas[l].Numero = count + 1; 
            cartas[l].Naipe = "U";
            cartas[l].Cor = "vermelho";
            cartas[l].NumNaipe = "KU";
        }
        count++;
    }
}

void EmbaralhaCartas(Pilha &estrutura1, Pilha &estrutura2, Pilha &estrutura3, Pilha &estrutura4, struct baralho cartas[], int NumCartas){
//Pré-condição: Necessita que vetor baralho cartas esteja criado e preenchido
//Necessita que a classe pilha esteja implementada 

//Pós-condição: embaralha as cartas e aloca nas estruturas de pilhas

    srand(time(0));
    string indices[52];
    int NumAleatorio = 0;
    int j = 0;

    for (int i = 0; i < NumCartas; i++)
    {   
        indices[i] = cartas[i].NumNaipe;
    }

    //Embaralha as cartas
    for (int i = 0; i < NumCartas; i++)
    {
        j = rand()%52;
        swap(indices[i], indices[j]);
    }

    //Insere as cartas nas estruturas de pilhas 
    for (int i = 0; i < 7; i++)
    {
        estrutura1.PushPilha1(indices[i]);
    }

    for (int i = 7; i < 14; i++)
    {
        estrutura1.PushPilha2(indices[i]);
    }

    for (int i = 14; i < 21; i++)
    {
        estrutura2.PushPilha1(indices[i]);
    }

    for (int i = 21; i < 28; i++)
    {
        estrutura2.PushPilha2(indices[i]);
    }

    for (int i = 28; i < 34; i++)
    {
        estrutura3.PushPilha1(indices[i]);
    }

    for (int i = 34; i < 40; i++)
    {
        estrutura3.PushPilha2(indices[i]);
    }

    for (int i = 40; i < 46; i++)
    {
        estrutura4.PushPilha1(indices[i]);
    }

    for (int i = 46; i < 52; i++)
    {
        estrutura4.PushPilha2(indices[i]);
    }   
}