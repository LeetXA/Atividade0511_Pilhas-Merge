#include <iostream>
using namespace std;

struct No {
    int dado;
    No *ant;
};

struct Pilha {
    No *topo;
};

Pilha* init()
{
    Pilha *p = new Pilha;
    p->topo = NULL;
    return p;
}

int isEmpty(Pilha *p)
{
    return (p->topo == NULL);
}

void push(Pilha *p, int v)
{
    No *no = new No;

    no->dado = v;
    no->ant = p->topo;

    p->topo = no;
}

int pop(Pilha *p)
{
    int v = -1;

    int podeDesempilhar = (!isEmpty(p));

    if (podeDesempilhar)
    {
        No *no = p->topo;

        v = no->dado;

        p->topo = no->ant;

        free(no);
    }

    return v;
}

void print(Pilha *p)
{
    No *no;

    no = p->topo;

    cout << "----------------------" << endl;

    while (no != NULL)
    {
        cout << no->dado << endl;

        no = no->ant;
    }

    cout << "----------------------" << endl;
}

void freePilha(Pilha *p)
{
    No *no;

    no = p->topo;

    while (no != NULL)
    {
        No *temp = no->ant;

        free(no);

        no = temp;
    }

    free(p);
}

int main()
{
    Pilha *pares = init();
    Pilha *impares = init();

    int numero;
    int anterior = -numero;

    cout << "Digite 30 numeros em ordem crescente:" << endl;

    for (int i = 0; i < 30; i++)
    {
        do
        {
            cout << "Numero " << i + 1 << ": ";
            cin >> numero;

            if (numero <= anterior)
            {
                cout << "ERRO! Digite um numero maior que "
                     << anterior << endl;
            }

        } while (numero <= anterior);

        anterior = numero;

        if (numero % 2 == 0)
        {
            push(pares, numero);
        }
        else
        {
            push(impares, numero);
        }
    }

    cout << endl;
    cout << "PARES EM ORDEM DECRESCENTE" << endl;
    print(pares);

    cout << endl;
    cout << "IMPARES EM ORDEM DECRESCENTE" << endl;
    print(impares);

    freePilha(pares);
    freePilha(impares);

    return 0;
}