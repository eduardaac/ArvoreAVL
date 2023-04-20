#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include "ArvAVL.h"

using namespace std;

ArvAVL::ArvAVL()
{
    raiz = NULL;
}

ArvAVL::~ArvAVL()
{
    
}

void ArvAVL::insere(int x)
{
    raiz = auxInsere(raiz, x);
}

NoArv* ArvAVL::auxInsere(NoArv *p, int x)
{
    if(p == NULL)
    {
        p = new NoArv();
        p->setInfo(x);
        p->setEsq(NULL);
        p->setDir(NULL);
    }
    else
    {
        char direcao;
        cout << x << " a esquerda (e) ou direita (d) de " << p->getInfo() << ": ";
        cin >> direcao;
        if(direcao == 'e' || direcao == 'E')
            p->setEsq(auxInsere(p->getEsq(), x));
        else
            p->setDir(auxInsere(p->getDir(), x));

        int fator = altura(p->getDir()) - altura(p->getEsq());
        NoArv *q = p->getDir();
        NoArv *r = p->getEsq();
        int fatorDir = altura(q->getDir()) - altura(q->getEsq());
        int fatorEsq = altura(r->getDir()) - altura(r->getEsq());

        if(fator == 2 )
        {
            if(fatorDir == 1 || fatorDir == 0)
            {
                rotSEsq(p);
            }
            else if(fatorDir == -1)
            {
                rotDEsq(p);
            }
        }
        else if(fator == -2)
        {
            if(fatorEsq == -1 || fatorEsq == 0)
            {
                rotSDir(p);
            }
            else if(fatorEsq == 1)
            {
                rotDDir(p);
            }
        }
    }
    return p;
}

void ArvAVL::rotSDir(NoArv *p)
{
    NoArv *q;
    q = p->getEsq();
    p->setEsq(q->getDir());
    q->setDir(p);
}

void ArvAVL::rotSEsq(NoArv *p)
{
    NoArv *q;
    q = p->getDir();
    p->setDir(q->getEsq());
    q->setEsq(p);

}

void ArvAVL::rotDDir(NoArv *p)
{
    NoArv *q;
    NoArv *r;
    q = p->getEsq();
    r = q->getDir();
    p->setEsq(r->getDir());
    q->setDir(r->getEsq());
    r->setDir(p);
    r->setEsq(q);
}

void ArvAVL::rotDEsq(NoArv *p)
{
    NoArv *q = p->getDir();
    NoArv *r = q->getEsq();
    p->setDir(r->getEsq());
    q->setEsq(r->getDir());
    r->setEsq(p);
    r->setDir(q);
}

void ArvAVL::preOrdem()
{
    cout << "Arvore Binaria em Pre-Ordem: ";
    auxPreOrdem(raiz);
}

void ArvAVL::auxPreOrdem(NoArv *p)
{
    if (p != NULL)
    {
        cout << p->getInfo() << " ";
        auxPreOrdem(p->getEsq());
        auxPreOrdem(p->getDir());
    }
}

int ArvAVL::altura(NoArv *p)
{
     if(p == NULL)
     {
         return -1;
     }
     else{
        int he = altura(p->getEsq());
        int hd = altura(p->getDir());

        if(he>hd)
        {
            return he + 1;
        }
        else
        {
            return hd + 1;
        }
     }
}
