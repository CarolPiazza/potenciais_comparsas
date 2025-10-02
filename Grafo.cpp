#include "Grafo.h"
#include <iostream>
#include <string>
#include <queue>    
#include <vector>

using namespace std;

Grafo::Grafo(int num_vertices) {
    num_vertices_ = num_vertices;
    num_arestas_ = 0;
    
    matriz_adj_ = new int*[num_vertices_];
    for (int i = 0; i < num_vertices_; i++) {
        matriz_adj_[i] = new int[num_vertices_];
        // inicializa a matriz com zeros
        for (int j = 0; j < num_vertices_; j++) {
            matriz_adj_[i][j] = 0;
        }
    }
}

Grafo::~Grafo() {
    for (int i = 0; i < num_vertices_; i++) {
        delete[] matriz_adj_[i];
    }
    delete[] matriz_adj_;
}

void Grafo::insere_aresta(Aresta e) {
    if (e.v1 != e.v2 && matriz_adj_[e.v1][e.v2] == 0) {
        matriz_adj_[e.v1][e.v2] = 1;
        matriz_adj_[e.v2][e.v1] = 1; 
        num_arestas_++; 
    }
}

std::vector<int> Grafo::potenciais_comparsas(int suspeito) {
    std::vector<int> comparsas;
    
    // Array para guardar as distâncias do suspeito a todos os outros
    int* dist = new int[num_vertices_];
    for (int i = 0; i < num_vertices_; i++) {
        dist[i] = -1; // -1 significa que o vértice não foi visitado
    }

    std::queue<int> fila;

    // inicia a busca a partir do suspeito.
    dist[suspeito] = 0;
    fila.push(suspeito); 

    while (!fila.empty()) {
        int v_atual = fila.front(); 
        fila.pop();                 

        for (int vizinho = 0; vizinho < num_vertices_; vizinho++) {
            // olha se 'vizinho' é vizinho de 'v_atual' e se ainda não foi visitado.
            if (matriz_adj_[v_atual][vizinho] == 1 && dist[vizinho] == -1) {
                dist[vizinho] = dist[v_atual] + 1;
                fila.push(vizinho); 
            }
        }
    }

    // Coleta os vértices com distância 1, 2 ou 3.
    for (int i = 0; i < num_vertices_; i++) {
        if (dist[i] > 0 && dist[i] <= 3) {
            comparsas.push_back(i);
        }
    }

    delete[] dist;
    
    return comparsas;
}