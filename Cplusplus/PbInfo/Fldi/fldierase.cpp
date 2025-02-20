#include <fstream>
#include <iostream>
#include <exception>

using namespace std;

struct nod {
    int info;
    nod *ant;
    nod *urm;
};

void Erase(nod *&prim, nod *&ultim);

int main() {
    ifstream f("fldi.in");

    nod *prim, *ultim, *p, *q;
    int k;
    // f >> k;

    prim = new nod;
    f >> prim->info;
    prim->ant = NULL;
    prim->urm = NULL;

    ultim = prim;

    for (int k; f >> k;) {
        p = new nod;
        p->info = k;
        p->ant = ultim;
        p->urm = NULL;
        ultim->urm = p;
        ultim = p;
    }

    cout << "Lista: ";
    for (p = prim; p != NULL; p = p->urm) {
        cout << p->info << " ";
    }
    cout << endl;

    try {
        Erase(prim, ultim);
    } catch (exception &e) {
        cout << "Exceptie";
    }

    cout << "Lista updated: ";
    for (p = prim; p != NULL; p = p->urm) {
        cout << p->info << " ";
    }
    cout << endl;

    return 0;
}

void Erase(nod *&prim, nod *&ultim) {
    nod* current = prim;
    while (current) {
        if (current->info % 2 == 0) {
            nod* anterior = current->ant;
            nod* urmator = current->urm;
            if (anterior && urmator) {
                anterior->urm = urmator;
                urmator->ant = anterior;
                current = urmator;
            } else if (anterior) {
                anterior->urm = urmator;
                ultim = anterior;
                current = NULL;
            } else if (urmator) {
                urmator->ant = anterior;
                prim = urmator;
                current = urmator;
            } else {
                prim = NULL;
                ultim = NULL;
                return;
            }
        } else 
            current = current->urm;
    }
}
