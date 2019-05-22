#include <iostream>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<conio.h>
#include "ListaOrdenada.h"

using namespace std;

void ExibirLista(struct Node<int> *aux){
    if(aux != NULL){
        if(aux->expo > 1 && (aux->coef > 1 || aux->coef <0)){
            cout<<aux->coef<<"x^"<<aux->expo<<" ";
            if(aux->prox != NULL){
                cout<<" + ";
            }
        }
        if(aux->expo > 1 && aux->coef == 1){
            cout<<"x^"<<aux->expo<<" ";
            if(aux->prox != NULL){
               cout<<" - ";
            }
        }
        if(aux->expo == 1){
            cout<<aux->coef<<"x"<<" ";
            if(aux->prox != NULL){
                cout<<" * ";
            }
        }
        if(aux->expo == 0){
            cout<<aux->coef<<" ";
        }
        ExibirLista(aux->prox);
    }
}

int main()
{
    ListaOrdenada<int> List = ListaOrdenada<int>();

    bool continuar = true;
    int coef, expo, opc;

    while(continuar){
        system("CLS");
        cout<<"Organizador de Polinomio.\n Dado o Polinomio P(x), insira ou remova monomios."<<endl;
        if(!List.listavazia()){
            cout<<"\nP(x) = ";
            ExibirLista(List.L);
            cout<<"\n";
        }
        cout<<"\n1 - Insere     2 - Remove      0 - SAIR\n"<<endl;
        cin>>opc;
        switch(opc){
        case 1:
            cout<<"Coeficiente: ";
            cin>>coef;
            cout<<"Expoente: ";
            cin>>expo;
            if(List.insere(coef,expo)){
                cout<<"Inserio com sucesso"<<endl;
            }
            else{
                cout<<"Falha ao inserir"<<endl;
            }
            break;
        case 2:
            cout<<"Coeficiente: ";
            cin>>coef;
            cout<<"Expoente: ";
            cin>>expo;
            if(List.Remove(coef,expo)){
                cout<<"Removido com sucesso"<<endl;
            }
            else{
                cout<<"Falha ao remover"<<endl;
            }
            break;
        case 0:
            continuar = false;
            break;
        }
    }
    return 0;
}
