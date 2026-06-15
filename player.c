#include "player.h"

// Função para calcular os limites inteiros do jogador (útil para colisões com a grade)
void calculaCantosInt(Mario* player) {
    (void)player;
}

bool coletaMartelo(Mario* jogador, char* matrix) {
    if (!jogador || !matrix) return false;

    Rectangle jogadorRect = {
        jogador->pos.x + 8,
        jogador->pos.y + 6,
        TAM_BLOCO - 16,
        TAM_BLOCO - 6
    };

    for (int i = 0; i < NLIN; i++) {
        for (int j = 0; j < NCOL; j++) {
            if (matrix[i * NCOL + j] == 'M') {
                Rectangle marteloRect = { j * TAM_BLOCO, i * TAM_BLOCO, TAM_BLOCO, TAM_BLOCO };
                if (CheckCollisionRecs(jogadorRect, marteloRect)) {
                    matrix[i * NCOL + j] = ' ';
                    jogador->temMartelo = true;
                    jogador->tempoMartelo = 10.0f;
                    return true;
                }
            }
        }
    }

    return false;
}

void atualizaMartelo(Mario* jogador, char* matrix, Fogo* flamas, int nFlamas, Barril* barris, int nBarris, float dt) {
    if (!jogador || !matrix || !jogador->temMartelo) return;

    // Cooldown do martelo em segundos: ajuste este valor para mudar a duração do efeito
    jogador->tempoMartelo -= dt;
    if (jogador->tempoMartelo <= 0.0f) {
        jogador->temMartelo = false;
        jogador->tempoMartelo = 0.0f;
        return;
    }

    Rectangle jogadorRect = {
        jogador->pos.x + 8,
        jogador->pos.y + 6,
        TAM_BLOCO - 16,
        TAM_BLOCO - 6
    };

    // Destrói tambor de óleo estático enquanto o martelo está ativo
    for (int i = 0; i < NLIN; i++) {
        for (int j = 0; j < NCOL; j++) {
            if (matrix[i * NCOL + j] == 'X') {
                Rectangle barrilRect = { j * TAM_BLOCO, i * TAM_BLOCO, TAM_BLOCO, TAM_BLOCO };
                if (CheckCollisionRecs(jogadorRect, barrilRect)) {
                    matrix[i * NCOL + j] = ' ';
                }
            }
        }
    }

    // Destrói barris móveis se o jogador estiver com martelo
    for (int i = 0; i < nBarris; i++) {
        if (barris[i].ativo) {
            Rectangle barrilRect = { barris[i].x, barris[i].y, TAM_BLOCO, TAM_BLOCO };
            if (CheckCollisionRecs(jogadorRect, barrilRect)) {
                barris[i].ativo = false;
            }
        }
    }

    // Destrói flamas se o jogador estiver com martelo
    for (int i = 0; i < nFlamas; i++) {
        if (flamas[i].ativo) {
            Rectangle flamaRect = { flamas[i].x, flamas[i].y, TAM_BLOCO, TAM_BLOCO };
            if (CheckCollisionRecs(jogadorRect, flamaRect)) {
                flamas[i].ativo = false;
            }
        }
    }
}
