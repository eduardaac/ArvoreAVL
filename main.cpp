#include <iostream>
#include "ArvAVL.h"
using namespace std;

int main()
{
    ArvAVL arv;
    arv.insere(5);
    arv.insere(7);
    arv.preOrdem();

    return 0;
}