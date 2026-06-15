#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>
#include "game.h"

// Funções para manipulação do jogador
void calculaCantosInt(Mario* player);
bool coletaMartelo(Mario* jogador, char* matrix);
void atualizaMartelo(Mario* jogador, char* matrix, Fogo* flamas, int nFlamas, Barril* barris, int nBarris, float dt);

#endif // PLAYER_H
