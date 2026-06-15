#include <raylib.h>
#include "render.h"

/* 
 * FUNÇÃO: desenhaCenario
 * DESCRIÇÃO: Renderiza o mapa utilizando as texturas curadas e a estética clássica.
 */
void desenhaCenario(char* matrix, Recursos* rec) {
    for (int i = 0; i < NLIN; i++) {
        for (int j = 0; j < NCOL; j++) {
            char celula = matrix[i * NCOL + j];
            Rectangle destino = { j * TAM_BLOCO, i * TAM_BLOCO, TAM_BLOCO, TAM_BLOCO };
            
            switch (celula) {
                case 'Z': // Plataforma Principal (Vermelha)
                case 'F': // Bordas
                    DrawTexturePro(rec->plataformaVermelha, 
                        (Rectangle){0, 0, rec->plataformaVermelha.width, rec->plataformaVermelha.height},
                        destino, (Vector2){0,0}, 0, WHITE);
                    break;
                case 'p': // Base da escada
                    DrawTexturePro(rec->stairsBottom,
                        (Rectangle){0, 0, rec->stairsBottom.width, rec->stairsBottom.height},
                        destino, (Vector2){0,0}, 0, WHITE);
                    break;
                case 'H': { // Escada
                    bool hasAbove = (i - 1 >= 0 && (matrix[(i - 1) * NCOL + j] == 'H' || matrix[(i - 1) * NCOL + j] == 'p'));
                    bool hasBelow = (i + 1 < NLIN && (matrix[(i + 1) * NCOL + j] == 'H' || matrix[(i + 1) * NCOL + j] == 'p'));
                    Texture2D stair = rec->stairsMid;
                    if (!hasAbove && hasBelow) {
                        stair = rec->stairsBottom;
                    } else if (hasAbove && !hasBelow) {
                        stair = rec->stairsTop;
                    }
                    DrawTexturePro(stair,
                        (Rectangle){0, 0, stair.width, stair.height},
                        destino, (Vector2){0,0}, 0, WHITE);
                    break;
                }
                case 'X': // Barril de Óleo com Fogo
                    DrawTexturePro(rec->barrilFogo,
                        (Rectangle){0, 0, rec->barrilFogo.width, rec->barrilFogo.height},
                        destino, (Vector2){0,0}, 0, WHITE);
                    break;
                case 'M': // Martelo
                    DrawTexturePro(rec->martelo, 
                        (Rectangle){0, 0, rec->martelo.width, rec->martelo.height},
                        destino, (Vector2){0,0}, 0, WHITE);
                    break;
                case 'Q': // Pauline
                    DrawTexturePro(rec->pauline,
                        (Rectangle){0, 0, rec->pauline.width, rec->pauline.height},
                        destino, (Vector2){0,0}, 0, WHITE);
                    break;
                case 'D': // Donkey Kong
                    DrawTexturePro(rec->dk,
                        (Rectangle){0, 0, rec->dk.width, rec->dk.height},
                        (Rectangle){j*TAM_BLOCO, i*TAM_BLOCO, TAM_BLOCO*3, TAM_BLOCO*3}, (Vector2){0,0}, 0, WHITE);
                    break;
            }
        }
    }
}
