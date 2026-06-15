#ifndef MAPA_H
#define MAPA_H

#include "game.h"

// Protótipos das funções de manipulação do mapa.
char* alocaMatriz(void);
char* carregaMapa(Mario* player, int fase, Inimigo* inimigos, int* nInimigos, Moeda* moedas, int* nMoedas, int* dk_r, int* dk_c, Barril* barris, int* nBarris, ItemHP* itensHP, int* nItemsHP);

// Função para imprimir a matriz no terminal (para depuração)
void printaMatriz(char* matrix);

#endif // MAPA_H