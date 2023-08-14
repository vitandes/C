
#include <stdio.h>
#include <stdlib.h>

typedef struct tnodo{
    int valor;
    struct  tnodo* sig;
}Nodo;

typedef struct tlist{
    int tamano;
    Nodo* primerItem;
    Nodo* ultimoItem;
}listaLigada;

Nodo* getNode(int Valor){
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->valor=Valor;
    nodo->sig= NULL;
    return nodo;
}

listaLigada* getList(){
    listaLigada* LL = (listaLigada*)malloc(sizeof(listaLigada));
    LL->tamano=0;
    LL->primerItem=0;
    LL->ultimoItem=0;
    return LL;
}

void add(listaLigada* LL, Nodo* nodo){
    if (LL->primerItem == 0) {LL->primerItem = nodo;
        LL->tamano ++;}
    else LL->ultimoItem->sig = nodo;
        LL->ultimoItem = nodo;
        LL->tamano ++;
       
}

 Nodo* read(listaLigada* LL, unsigned int indice){
    if (LL->tamano && indice<LL->tamano){
        Nodo* exploradorLista = LL->primerItem;
        int i = 0;
        while (i++ < indice)
            exploradorLista = exploradorLista->sig;
        return exploradorLista;
    }
    
 }

void start(listaLigada* LL, Nodo* nodo){
    if (LL->primerItem==0) LL->primerItem = nodo;
        
    else nodo->sig = LL->primerItem;
        LL->primerItem = nodo;
        LL->tamano ++;
 }

void ind(listaLigada* LL, Nodo* nodo, unsigned int indice){
    if(LL->tamano && indice < LL-> tamano){
        Nodo* explorar = LL->primerItem;
        int i = 0;
        while(i++ < indice-1){
            explorar = explorar->sig;
        }
        nodo->sig = explorar->sig;
        explorar->sig = nodo;
        
    }
}

void update(listaLigada* LL, Nodo* nodo, unsigned int indice){
    if(LL->tamano && indice < LL->tamano){
        Nodo* explorar = LL->primerItem;
        int i = 0;
        while(i++ < indice){
            explorar = explorar->sig;
        }
        explorar->valor = nodo->valor;
    }
}

int main() {
    listaLigada* List = getList();
    Nodo* a = getNode(5);
    Nodo* b = getNode(10);
    Nodo* f = getNode(25);
    Nodo* c = getNode(3);
    Nodo* d = getNode(2);
    Nodo* g = getNode(12);
    add(List, a);
    add(List, b);
    start(List, c);
    ind(List, d, 1);
    add(List, f);
    update(List, g, 1);
    
    printf("El valor es %d\n",read(List,1)->valor);
    printf("El tamanño es %d\n", List->tamano);

    return 0;
}