#ifndef LISTAORDENADA_H_INCLUDED
#define LISTAORDENADA_H_INCLUDED


template<typename Tipo>
struct Node
{
    Tipo coef;
    Tipo expo;
    Node<Tipo> *prox;
};

template <typename Tipo>
struct ListaOrdenada
{
    Node<Tipo> *L;
    ListaOrdenada()
    {
        L = NULL;
    }

    ~ListaOrdenada(){
        while(!listavazia()){
            Node<Tipo> *aux = L;
            L=L->prox;
            delete aux;
        }
    }

    bool listavazia()
    {
        return L==NULL;
    }

    bool insere(Tipo x, Tipo y)
    {
        bool v = false;
        Node<Tipo> *aux = new Node<Tipo>;
        if(aux != NULL)
        {
            v = true;
            aux->coef = x;
            aux->expo = y;
            if(L == NULL || y > L->expo)
            {
                aux->prox = L;
                L=aux;
            }
            else
            {
                Node<Tipo> *aux2 = L;
                while(aux2->prox != NULL && (aux2->prox->expo > y || aux2->prox->expo == y))
                {

                    aux2=aux2->prox;
                }
                if(aux2->expo == y){
                    aux2->coef += aux->coef;
                }
                else{
                   aux->prox = aux2->prox;
                    aux2->prox = aux;
                }
            }
        }
        return v;
    }

    bool Remove(Tipo x, Tipo y){
        bool v = false;
        Node<Tipo> *atual = L;
        Node<Tipo> *anterior = NULL;
        while(atual != NULL){
            if(atual->expo == y && atual->coef == x){
                if(anterior == NULL){
                    L = atual->prox;
                    delete atual;
                    return v = true;
                }
                else{
                    anterior->prox = atual->prox;
                    delete atual;
                    return v = true;
                }
            }
            else if(atual->expo < y){
                return v = false;
            }
            else{
                anterior = atual;
                atual = atual->prox;
            }
        }
    }
};

#endif // LISTAORDENADA_H_INCLUDED
