#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"
#include <string.h>

char* alocaMatriz(void) {
    return (char*) malloc(sizeof(char) * NCOL * NLIN);
}

char* carregaMapa(Mario* player, int fase, Inimigo* inimigos, int* nInimigos, Moeda* moedas, int* nMoedas, int* dk_r, int* dk_c, Barril* barris, int* nBarris, ItemHP* itensHP, int* nItemsHP) {
    char tmpChar;
    char* matrix = alocaMatriz();

    // Inicializa a matriz com espaços vazios
    for (int i = 0; i < NCOL * NLIN; i++) matrix[i] = ' ';

    char mapaNome[20];
    sprintf(mapaNome, "mapa%d.txt", fase);

    FILE* maps = fopen(mapaNome, "r");
    if (maps == NULL) return NULL;

    int row = 0, col = 0;
    if (nInimigos) *nInimigos = 0;
    if (nMoedas) *nMoedas = 0;
    if (dk_r) *dk_r = -1;
    if (dk_c) *dk_c = -1;
    if (nBarris) *nBarris = 0;
    if (nItemsHP) *nItemsHP = 0;

    while ((tmpChar = (char) fgetc(maps)) != EOF && row < NLIN) {
        if (tmpChar == '/') {
            int next = fgetc(maps);
            if (next == '/') {
                // ignora comentário até o final da linha
                while (next != EOF && next != '\n' && next != '\r') next = fgetc(maps);
                if (next == '\n') {
                    if (col > 0) { row++; col = 0; }
                }
                continue;
            } else if (next != EOF) {
                ungetc(next, maps);
            }
        }

        if (tmpChar == '\n' || tmpChar == '\r') {
            if (col > 0) { row++; col = 0; }
            continue;
        }

        if (col < NCOL) {
            int idx = row * NCOL + col;
            
            if (tmpChar == 'P') {
                player->pos.x = (float) col * TAM_BLOCO;
                player->pos.y = (float) row * TAM_BLOCO;
                matrix[idx] = ' ';
            } else if (tmpChar == 'E' && inimigos && nInimigos && *nInimigos < MAX_INIMIGOS) {
                inimigos[*nInimigos].x = (float)col * TAM_BLOCO;
                inimigos[*nInimigos].y = (float)row * TAM_BLOCO;
                inimigos[*nInimigos].direcao = 'R';
                inimigos[*nInimigos].ativo = true;
                inimigos[*nInimigos].frameCounter = 0;
                inimigos[*nInimigos].direcaoAtual = 1;
                (*nInimigos)++;
                matrix[idx] = ' ';
            } else if (tmpChar == 'D') {
                if (dk_r) *dk_r = row;
                if (dk_c) *dk_c = col;
                matrix[idx] = 'D';
            } else if (tmpChar == 'M') {
                matrix[idx] = 'M';
            } else if (tmpChar == 'X') {
                matrix[idx] = 'X';
            } else if (tmpChar == 'B' && barris && nBarris && *nBarris < MAX_BARRIS) {
                barris[*nBarris].x = (float)col * TAM_BLOCO;
                barris[*nBarris].y = (float)row * TAM_BLOCO;
                barris[*nBarris].direcao = 'L';
                barris[*nBarris].ativo = true;
                barris[*nBarris].frame = 0;
                barris[*nBarris].rolandoEscada = false;
                barris[*nBarris].velVertical = 0.0f;
                (*nBarris)++;
                matrix[idx] = ' ';
            } else if (tmpChar == 'F') {
                matrix[idx] = 'F';
            } else if (tmpChar == 'Q') {
                matrix[idx] = 'Q';
            } else {
                matrix[idx] = tmpChar;
            }
            col++;
        }
    }

    fclose(maps);
    return matrix;
}

bool ehSolido(char bloco) {
    return (bloco == 'F' || bloco == 'Z' || bloco == 'X');
}
