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

int main() {
    list List = createList();
    add(&List, 5);
    add(&List, 10);
    add(&List, 15);

    read(&List);

    return 0;
}

