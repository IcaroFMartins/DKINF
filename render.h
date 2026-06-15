#ifndef RENDER_H
#define RENDER_H

#include "game.h"

// Funções de renderização de cenário e entidades
void desenhaCenario(char* matriz, Recursos* rec);

// Função legada para compatibilidade (atualizada para o novo tipo Mario)
void drawMatrix(char* matrix, const Mario player, Texture2D atlas);

#endif // RENDER_H
