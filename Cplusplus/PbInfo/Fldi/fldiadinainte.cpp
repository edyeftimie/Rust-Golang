#include <fstream>
#include <iostream>
#include <exception>

using namespace std;

struct nod {
    int info;
    nod *ant;
    nod *urm;
};

void FLdiAdInainte(nod *&prim, nod *&ultim, int x);

int main() {
    ifstream f("fldiadinainte.in");

    nod *prim, *ultim, *p, *q;
    int k;
    f >> k;

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
        FLdiAdInainte(prim, ultim, k);
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

void FLdiAdInainte(nod *&prim, nod *&ultim, int x) {
    ofstream g("fldiadinainte.out");
    nod* current = prim;
    nod* minim = prim;
    while (current) {
        if (current->info < minim->info) {
            minim = current;
        }
        current = current->urm;
    }

    g << minim->info;
    
    
    nod* nodNou = new nod;
    nodNou->info = x;
    nodNou->ant = minim->ant;
    nodNou->urm = minim;
    minim->ant = nodNou;

    nod* anteriorulNod = nodNou->ant;
    if (anteriorulNod != NULL)
        anteriorulNod->urm = nodNou;
    else
        prim = nodNou;
}

