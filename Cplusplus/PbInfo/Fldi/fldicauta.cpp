#include <fstream>
#include <iostream>
#include <exception>

using namespace std;

struct nod {
    int info;
    nod *ant;
    nod *urm;
};

int FLdiCauta(nod *prim, nod *ultim, int k);

int main() {
    ifstream f("fldicauta.in");
    ofstream g("fldicauta.out");

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
        g << FLdiCauta(prim, ultim, k);
    } catch (exception &e) {
        g << "Exceptie";
    }

    return 0;
}

int FLdiCauta(nod *prim, nod *ultim, int k) {
    cout << "prim: " << prim->info << "k: " << k << endl;
    if (k == 1 || prim == ultim) {
        if (k == 1) {
            cout << "k == 1\n";
        } else {
            cout << "prim == ultim\n";
        }
        return prim->info;
    } else if (k == -1) {
        cout << "k == -1\n";
        return ultim->info;
    } else if (k < 0) {
        return FLdiCauta(prim, ultim->ant, ++k);
    } else if (k > 0) {
        return FLdiCauta(prim->urm, ultim, --k);
    } else {
        throw exception();
    }
}

