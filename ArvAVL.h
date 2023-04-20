#include "NoArv.h"

class ArvAVL {
private:
    NoArv *raiz; 
    void rotSDir(NoArv* p); 
    void rotSEsq(NoArv* p);
    void rotDDir(NoArv* p);
    void rotDEsq(NoArv* p);
    NoArv* auxInsere(NoArv *p, int x);
    void auxPreOrdem(NoArv *p); 


public:
    ArvAVL(); 
    ~ArvAVL(); 

    void insere(int x);
    int altura(NoArv *p);
    void preOrdem();
    

};
