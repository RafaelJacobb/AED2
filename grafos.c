
#include <stdio.h>
#define MAX_VERTICES 20

typedef struct {
    int vertices[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
} Grafo;

void inicializa_grafo(Grafo *g, int num_vertices) {
    g->num_vertices = num_vertices;
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            g->vertices[i][j] = 0;
        }
    }
}

void insere_aresta(Grafo *g, int origem, int destino, int peso) {
    g->vertices[origem][destino] = peso;
}

void imprime_grafo(Grafo *g) {
    printf("\nGrafo Atual:\n");
    for (int i = 0; i < g->num_vertices; i++) {
        for (int j = 0; j < g->num_vertices; j++) {
            printf("%d ", g->vertices[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Grafo g;
    int num_vertices;

    printf("Bem-vindo ao programa de manipulação de grafos!\n");
    printf("Insira o número de vértices: ");
    scanf("%d", &num_vertices);

    inicializa_grafo(&g, num_vertices);

    printf("Agora, vamos inserir as arestas:\n");

    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            if (i != j) {
                int peso;
                printf("Insira o peso da aresta entre o vértice %d e o vértice %d (ou 0 se não houver aresta): ", i, j);
                scanf("%d", &peso);
                insere_aresta(&g, i, j, peso);
            }
        }
    }

    printf("\nGrafo final:\n");
    imprime_grafo(&g);

    printf("Obrigado por usar o programa!\n");

    return 0;
}
