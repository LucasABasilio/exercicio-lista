//Bibliotecas necessárias
#include <cstdio>
#include <cstdlib>
#include "Lista.h"
#include <string>
#include <iostream>

using namespace std;

TipoCelula *Frente, *Tras;

int Contador;


void Lista_Construtor() {


    Frente = Tras = NULL;
    Contador = 0;
}


void Lista_Destrutor() {


    TipoCelula *Temp;

    while (Frente != NULL) {
        Temp = Frente;
        Frente = Frente->Prox;

        Temp->Prox = NULL;
        free(Temp);
    }

    Tras = NULL;
    Contador = 0;
}


bool Lista_Vazia() {

    return Tras == NULL;
}


int Lista_Tamanho() {
    return Contador;
}


bool Lista_Inserir_Ordenado(string Elemento){
    TipoCelula *Novo;
    TipoCelula *Temp;
    int Posicao;

    Novo = (TipoCelula *) malloc(sizeof(TipoCelula));
    if (Novo == NULL) {
        return false;
    }
    else {

        if(Lista_Vazia()){
            Novo->Item = Elemento;
            Novo->Prox = NULL;

            Tras = Novo;
            Frente = Novo;
            Contador++;

            return true;
        }
        else{
            if(!Lista_BuscarPeloElemento(Elemento, Posicao)){

                Temp = Frente;

                while(Temp->Item > Elemento){
                    Temp = Temp->Prox;
                }

                Novo->Item = Temp->Item;
                Temp->Item = Elemento;
                Novo->Prox = Temp->Prox;
                Temp->Prox = Novo;

                if (Tras == Temp){
                    Tras = Novo;
                }

                Contador++;

                return true;
            }
            else{
                return false;
            }
        }
    }
}


bool Lista_Remover_Inicio(string &Elemento) {

    if (!Lista_Vazia()) {

        TipoCelula *Temp = Frente;

        Elemento = Frente->Item;
        Frente = Frente->Prox;
        Temp->Prox = NULL;

        free(Temp);

        if (Frente == NULL)
            Tras = NULL;

        Contador--;

        return true;
    } else
        return false;
}


bool Lista_Remover_Fim(string &Elemento) {

    if (!Lista_Vazia()) {

        TipoCelula *Temp = Frente;

        if (Frente == Tras) {

            Elemento = Tras->Item;
            Contador--;
            free(Tras);
            Frente = Tras = NULL;
            return true;
        }

        while (Temp->Prox != Tras) {

            Temp = Temp->Prox;
        }


        Elemento = Tras->Item;
        Tras = Temp;
        Temp = Temp->Prox;
        Tras->Prox = NULL;

        free(Temp);
        Contador--;

        return true;
    } else
        return false;
}


bool Lista_Remover(string &Elemento, int Posicao) {

    TipoCelula *Temp, *Temp2;

    if (!Lista_Vazia()) {

        if (Posicao < 0 || Posicao >= Contador) return false;


        if (Frente == Tras) {

            Elemento = Tras->Item;
            Contador--;
            free(Tras);
            Frente = Tras = NULL;
            return true;
        }

        Temp = Frente;

        for (int i = 0; i < Posicao; i++) {

            Temp2 = Temp;
            Temp = Temp->Prox;
        }


        if (Frente == Temp)
            Frente = Frente->Prox;
        else
            Temp2->Prox = Temp->Prox;

        if (Tras == Temp)
            Tras = Temp2;
        else
            Temp->Prox = NULL;


        Elemento = Temp->Item;
        free(Temp);
        Contador--;
        return true;
    }
    return false;
}


bool Lista_Inicio(string &Elemento) {


    if (!Lista_Vazia()) {
        Elemento = Frente->Item;
        return true;
    } else
        return false;
}


bool Lista_Fim(string &Elemento) {


    if (!Lista_Vazia()) {

        Elemento = Tras->Item;
        return true;
    } else
        return false;
}


bool Lista_BuscarPeloElemento(string Elemento, int &Posicao) {


    TipoCelula *Temp = Frente;
    int i = 0;

    if (!Lista_Vazia()) {

        while (Temp != NULL && Temp->Item != Elemento) {

            i++;
            Temp = Temp->Prox;
        }

        if (Temp != NULL) {

            Posicao = i;
            return true;
        } else
            return false;
    } else
        return false;
}


bool Lista_BuscarPelaPosicao(string &Elemento, int Posicao) {


    TipoCelula *Temp = Frente;
    int i = 0;

    if (!Lista_Vazia()) {


        if (Posicao < 0 || Posicao >= Contador) return false;

        while (i < Posicao) {

            i++;
            Temp = Temp->Prox;
        }


        Elemento = Temp->Item;
        return true;
    } else
        return false;
}
