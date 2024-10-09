/*Lucas Assun��o Basilio
Estender o c�digo de Lista e implementar uma nova fun��o capaz de receber um elemento e realizar sua inser��o, tal que ao final dessa fun��o a Lista esteja ordenada e sem elementos repetidos.
Apresentar uma mensagem ao usu�rio informando se o elemento foi ou n�o inserido na Lista. Caso a lista j� possua o elemento fornecido, deve-se informar que a inser��o n�o foi realizada.
Fazer as adapta��es necess�rias para que todos os m�todos da lista funcionem com o armazenamento, recupera��o e exclus�o de palavras.
Para a inser��o a Lista deve possuir somente o m�todo de inser��o ordenada e sem repeti��es.
A fun��o principal do programa (main) deve permitir que o usu�rio utilize as fun��es da Lista aleatoriamente.
O usu�rio deve ser capaz de informar uma palavra por vez.
N�o diferenciar letras mai�sculas de min�sculas.*/




//Bibliotecas necess�rias
#include <cstdio>
#include <cstdlib>
#include "Lista.h"
#include <string>
#include <iostream>

using namespace std;


//Fun��o principal para demonstrar o uso da Lista
int main()
{

    string x; //Vari�vel utilizada para receber o valor digitado do usu�rio e colocar na Lista
    int opcao; //vari�vel utilizada no Menu para testar a Lista

    int posicao; //vari�vel utilizada para retornar a posi��o onde o elemento foi encontrado

    Lista_Construtor();  //para iniciar a Lista



    do{  //menu com op��es para testar a implementa��o da Lista


         system("cls");

          printf("Programa para uso da Lista Singularmente Encadeada\n\n");
          printf("Escolha uma das opcoes abaixo.");
          printf("\n\n\nMenu: \n");
          printf("\n1 - Inserir Ordenado"); // Insere uma string na lista de maneira ordenada.
          printf("\n2 - Remover no inicio");
          printf("\n3 - Remover no fim");
          printf("\n4 - Remover dado em uma posicao");
          printf("\n5 - Elemento no inicio");
          printf("\n6 - Elemento no fim");
          printf("\n7 - Procurar elemento");
          printf("\n8 - Numero de elementos na lista");
          printf("\n9 - Exibir elemento em uma posicao");
          printf("\n10 - Exibir elementos da Lista");
          printf("\n11 - Remover e exibir todos os elementos");
          printf("\n12 - Sair\n");
          printf("\nOpcao: ");
          scanf("%d", &opcao);

          system("cls");

          switch(opcao){

             case 1:
                        cout << "\n\nDigite o dado: ";
                        cin >> x;

                        if(Lista_Inserir_Ordenado(x))
                          printf("Elemento inserido\n\n");
                        else printf("Erro ao inserir elemento.\n\n");

                        system("pause");
                        break;


             case 2:
                         if(Lista_Remover_Inicio(x))
                            cout << "\n\nDado" << x << "removido\n\n";
                         else printf("Erro. Lista vazia.\n\n");

                         system("pause");
                         break;


             case 3:
                         if(Lista_Remover_Fim(x))
                             cout << "\n\nDado" << x << "removido\n\n";
                         else printf("Erro. Lista vazia.\n\n");

                         system("pause");
                         break;


             case 4:     printf("Digite a posicao para remover o dado: ");
                         scanf("%d", &posicao);

                         if(Lista_Remover(x, posicao))
                            cout << "\n\nDado" << x << "removido\n\n";
                         else printf("Erro. Posicao nao encontrada.\n\n");

                         system("pause");
                         break;

            case 5:
                       printf("\nElemento no inicio da lista: ");
                       if(Lista_Inicio(x))
                          cout << "\n\n" << x;
                       else
                          printf("\n\nLista vazia\n\n");


                       system("pause");
                       break;

            case 6:
                       printf("\nElemento no fim da lista: ");
                       if(Lista_Fim(x))
                          cout << "\n\n" << x;
                       else
                          printf("\n\nLista vazia\n\n");

                       system("pause");
                       break;


            case 7:     printf("\nDigite o elemento para pesquisa: ");
                        setbuf(stdin, NULL);
                        cin >> x;

                        if(Lista_BuscarPeloElemento(x, posicao))
                           printf("Elemento encontrado na posicao %d.\n\n", posicao);
                        else printf("Erro. Elemento nao encontrado.\n\n");

                        system("pause");
                        break;

            case 8:
                        printf("\n\nNumero de elementos na lista: %d\n\n", Lista_Tamanho());  //exibe o n�mero de elementos da lista
                        system("pause");
                        break;

            case 9:    printf("\n\nEntre com a posicao desejada:\n\n");
                        scanf("%d", &posicao);
                        if(Lista_BuscarPelaPosicao(x, posicao)){

                           cout << "\nValor na posicao " << posicao << ": " << x;
                           posicao++;
                        }
                        else  printf("Lista vazia ou posicao invalida");

                        printf("\n\n");
                        system("pause");
                        break;


            case 10:    printf("\n\nElementos na Lista:\n\n");
                        posicao = 0;
                        while(Lista_BuscarPelaPosicao(x, posicao)){

                           cout << "\nValor na posicao " << posicao << ": " << x;
                           posicao++;
                        }

                        printf("\n\n");
                        system("pause");
                        break;


            case 11:    printf("\nTodos os elementos: \n\n");

                        while(Lista_Remover_Inicio(x)){

                             cout << "\nElemento: " << x;
                        }

                        printf("\n\n");
                        system("pause");
                        break;


            case 12:  Lista_Destrutor();
                      break;

            default: printf("\n\nOpcao invalida\n\n");
                     system("pause");
          }
    }while(opcao != 12);


    return 0;
}
