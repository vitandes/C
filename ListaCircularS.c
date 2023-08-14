#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int valor;
    struct Nodo* sig;
} Nodo;

typedef struct List {
    int tamano;
    Nodo* head;
} list;

list createList() {
    list ll;
    ll.tamano = 0;
    ll.head = NULL;
    return ll;
}

void read(list* ll) {
    if (ll->tamano == 0) {
        printf("Esta vacio");
    } else {
        Nodo* recorrer = ll->head;
        int i = 0;
        while (i++ < ll->tamano) {
            printf("%d ", recorrer->valor);
            recorrer = recorrer->sig;
        }
    }
}

void add(list* ll, int valor) {
    if (ll->tamano == 0) {
        Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
        nodo->valor = valor;
        nodo->sig = nodo;
        ll->head = nodo;
    } else {
        Nodo* explorar = ll->head;
        int i = 0;
        while (i++ < ll->tamano - 1) {
            explorar = explorar->sig;
        }
        Nodo* Nuevonodo = (Nodo*)malloc(sizeof(Nodo));
        Nuevonodo->valor = valor;
        explorar->sig = Nuevonodo;
        Nuevonodo->sig = ll->head;
    }
    ll->tamano++;
}

void removed(list* ll, unsigned int indice){
     if (ll->tamano && indice<ll->tamano){
         Nodo* aux;
         if (indice == 0){
             aux = ll->head;
             ll->head = ll->head->sig;
             free(aux);
         } else {
             Nodo* exploradorLista = ll->head;
             int i = 0;
             while (i++ < indice-1)
                 exploradorLista = exploradorLista->sig;
             aux = exploradorLista->sig;
             if (indice == ll->tamano-1){
                 exploradorLista->sig = NULL;
                 exploradorLista->sig = ll->head;
             } else exploradorLista->sig = exploradorLista->sig->sig;
            free(aux);
         }
         
         ll->tamano--;
     }
 }

int main() {
    list List = createList();
    add(&List, 5);
    add(&List, 10);
    add(&List, 15);

    removed(&List, 0);
    read(&List);

    return 0;
}

