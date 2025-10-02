#ifndef GRAFO_H
#define GRAFO_H

#include "Aresta.h"
#include <vector> 

class Grafo {
public:
    Grafo(int num_vertices);   
    ~Grafo();
    void insere_aresta(Aresta e);
    std::vector<int> potenciais_comparsas(int suspeito);

private:
    int num_vertices_; 
    int num_arestas_;  
    int** matriz_adj_;


};

#endif /* GRAFO_H */

