#include <iostream>
#include "ListaOrdenada.h"
#include<stdlib.h>
#include<conio.h>

using namespace std;


void ExibirLista(struct Node<int> *aux){
    if(aux != NULL){
        cout<<aux->info<<" ";
        ExibirLista(aux->prox);
    }
}

int NumeroDeElementos(struct Node<int> *aux){
    int cont = 0;
    while(aux != NULL){
        cont ++;
        aux = aux->prox;
    }
    return cont;
}

int main()
{
    ListaOrdenada<int> List = ListaOrdenada<int>();

    bool continuar = true;
    int valor;

    while(continuar){
        system("CLS");
        cout << "Estrutura de Dados: Lista Ligada Ordenada" << endl;
        cout<<"INFORMACOES SOBRE A LISTA: "<<endl;
        if(List.listavazia()){
            cout<<"Nao ha nenhum elemento na lista."<<endl;
        }else{
            cout<<"Numero de elementos na lista: "<<NumeroDeElementos(List.L)<<endl;
            cout<<"Elementos: ";
            ExibirLista(List.L);
        }
        cout<<"\n\nMENU"<<endl;
        cout<<"1-Insere 2-Remove 0-Sair"<<endl;
        int opc;
        cout<<"Opcao escolhida: ";
        cin>>opc;
        switch(opc){
        case 1:
            cout<<"Valor a ser inserido: ";
            cin>>valor;
            if(List.insere(valor)){
              cout<<"Valor inserido com sucesso"<<endl;
                //getch();
            }
            else{
               cout<<"Lista cheia"<<endl;
                //getch();
            }
            break;
        case 2:
            cout<<"Valor a ser removido: ";
            cin>>valor;
            if(List.Remove(valor)){
                cout<<"valor removido"<<endl;
                //getch();
            }
            else{
                cout<<"Valor nao existe na lista"<<endl;
                //getch();
            }
            break;
        case 0:
            cout<<"SAIR!"<<endl;
            continuar = false;
            break;
        default:
            cout<<"A opcao '"<<opc<<"' nao existe. Aperte qualquer tecla para voltar ao MENU"<<endl;
            getch();
        }

    }

    return 0;
}
