#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <string>
#include <iostream>

using namespace std;

typedef string TipoDado; //Define o tipo de dado que será armazenado na Lista


struct TipoCelula{

   TipoDado Item;
   TipoCelula *Prox;
};


void Lista_Construtor();
void Lista_Destrutor();
bool Lista_Vazia();
int Lista_Tamanho();
bool Lista_Inserir_Ordenado(string Elemento);
bool Lista_Remover_Inicio(string &Elemento);
bool Lista_Remover_Fim(string &Elemento);
bool Lista_Remover(string &Elemento, int Posicao);
bool Lista_Inicio(string &Elemento);
bool Lista_Fim(string &Elemento);
bool Lista_BuscarPeloElemento(string Elemento, int &Posicao);
bool Lista_BuscarPelaPosicao(string &Elemento, int Posicao);


#endif // LISTA_H_INCLUDED
