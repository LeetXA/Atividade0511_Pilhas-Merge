#include <iostream>
using namespace std;

#define MAX 30

struct Pilha {
    int qtde;
    int elementos[MAX];
};

Pilha* init()
{
    Pilha *p = new Pilha();
    p->qtde = 0;
    return p;
}

int isEmpty(Pilha *p)
{
    return (p->qtde == 0);
}

int push(Pilha *p, int v)
{
    int podeEmpilhar = (p->qtde < MAX);

    if (podeEmpilhar)
    {
        p->elementos[p->qtde++] = v;
    }

    return podeEmpilhar;
}

int pop(Pilha *p)
{
    int v = -1;

    int podeDesempilhar = (p->qtde > 0);

    if (podeDesempilhar)
    {
        v = p->elementos[p->qtde - 1];
        p->qtde--;
    }

    return v;
}

void print(Pilha *p)
{
    cout << "----------------------" << endl;

    for (int i = p->qtde - 1; i >= 0; i--)
    {
        cout << p->elementos[i] << endl;
    }

    cout << "----------------------" << endl;
}

void freePilha(Pilha *p)
{
    free(p);
}

int main()
{
    Pilha *pares = init();
    Pilha *impares = init();

    int numero;
    int anterior = -numero;

    cout << "Digite 30 numeros em ordem crescente:" << endl;

    for (int i = 0; i < MAX; i++)
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