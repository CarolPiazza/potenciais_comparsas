#include <iostream>
#include <vector>
#include "Grafo.h"
#include "Aresta.h"

using namespace std;

int main() {
    int P, L; 
    cin >> P >> L;

    Grafo g(P);

    // le as ligações
    for (int i = 0; i < L; ++i) {
        int u, v;
        char turno;
        cin >> u >> v >> turno;

        // adiciona a aresta se a ligação for de madrugada W
        if (turno == 'W') {
            g.insere_aresta(Aresta(u, v));
        }
    }

    int O; 
    cin >> O;


    for (int i = 0; i < O; ++i) {
        int suspeito;
        cin >> suspeito;
        
        vector<int> comparsas = g.potenciais_comparsas(suspeito);
        
        // imprime o resultado 
        cout << suspeito << ":";
        for (int comparsa : comparsas) {
            cout << " " << comparsa;
        }
        cout << "\n"; 
    }
    
    return 0;
}