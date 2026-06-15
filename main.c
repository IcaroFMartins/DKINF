// Inclui a biblioteca principal de gráficos e áudio
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include "game.h"
#include "mapa.h"
#include "render.h"
#include "player.h"

void carregarRecursos(Recursos *res) {
    res->titulo = LoadTexture("DKINFsprites/recursos/title-screen.png");
    res->marioDir = LoadTexture("DKINFsprites/recursos/mario-right.png");
    res->marioEsq = LoadTexture("DKINFsprites/recursos/mario-left.png");
    res->marioStdLeft = LoadTexture("DKINFsprites/mario/mario_std_left.png");
    res->marioSobe1 = LoadTexture("DKINFsprites/recursos/marioClimb1.png");
    res->marioSobe2 = LoadTexture("DKINFsprites/recursos/marioClimb2.png");
    res->marioBackStd = LoadTexture("DKINFsprites/mario/mario_bck_std.png");
    res->marioBackStding = LoadTexture("DKINFsprites/mario/mario_bck_stding.png");
    res->marioBackUpL = LoadTexture("DKINFsprites/mario/mario_bck_upL.png");
    res->marioBackUpR = LoadTexture("DKINFsprites/mario/mario_bck_upR.png");
    res->marioBackUpping = LoadTexture("DKINFsprites/mario/mario_bck_upping.png");
    res->marioDamage = LoadTexture("DKINFsprites/mario/mario_damage.png");
    res->marioGameOver = LoadTexture("DKINFsprites/mario/mario_damage.png");
    res->marioMarteloDir = LoadTexture("DKINFsprites/recursos/mario-right.png");
    res->marioMarteloEsq = LoadTexture("DKINFsprites/recursos/mario-left.png");
    res->morto = LoadTexture("DKINFsprites/recursos/dead.png");
    res->plataformaVermelha = LoadTexture("DKINFsprites/background/platform4.png");
    res->escada = LoadTexture("DKINFsprites/background/withLadder.png");
    res->stairsBottom = LoadTexture("DKINFsprites/background/stair_bottom.png");
    res->stairsMid = LoadTexture("DKINFsprites/background/stair_mid.png");
    res->stairsTop = LoadTexture("DKINFsprites/background/stair_top.png");
    res->pauline = LoadTexture("DKINFsprites/Pauline/pauline-still.png");
    res->paulineAjuda = LoadTexture("DKINFsprites/Pauline/pauline-help.png");
    res->dk = LoadTexture("DKINFsprites/recursos/dkForward.png");
    res->dkSobe1 = LoadTexture("DKINFsprites/recursos/dkClimbEmpty1.png");
    res->dkSobe2 = LoadTexture("DKINFsprites/recursos/dkClimbEmpty2.png");
    res->itemHP = LoadTexture("DKINFsprites/recursos/blue1.png");
    res->coracaoVitoria = LoadTexture("DKINFsprites/recursos/broken-heart.png");
    res->coracaoQuebrado = LoadTexture("DKINFsprites/recursos/broken-heart.png");
    res->barrilFogo = LoadTexture("DKINFsprites/recursos/DK_Arcade_Oil_Drum_with_Flames.png");
    res->fogoSprite = LoadTexture("DKINFsprites/recursos/DK_Arcade_Fire_Sprite.png");
    res->inimigo = LoadTexture("DKINFsprites/recursos/broken-heart.png");
    res->inimigoDir = LoadTexture("DKINFsprites/personagens/inimigo_dir.png");
    res->inimigoEsq = LoadTexture("DKINFsprites/personagens/inimigo_esq.png");
    res->gameOverScreen = LoadTexture("DKINFsprites/recursos/title-screen.png");
    for (int i = 0; i < 4; i++) {
        char path[64];
        sprintf(path, "DKINFsprites/recursos/barrel%d.png", i + 1);
        res->barril[i] = LoadTexture(path);
    }
    for (int i = 0; i < 5; i++) {
        char path[64];
        sprintf(path, "DKINFsprites/recursos/blue%d.png", i);
        res->moeda[i] = LoadTexture(path);
    }
    res->martelo = LoadTexture("DKINFsprites/recursos/DK_Arcade_Hammer_Sprite.png");
    res->somIntro = LoadSound("DKINFsprites/recursos/intro1/intro1.wav");
    res->somPulo = LoadSound("DKINFsprites/recursos/jump/jump.wav");
    res->somMorte = LoadSound("DKINFsprites/recursos/death/death.wav");
    res->somMartelo = LoadSound("DKINFsprites/recursos/jump/jump.wav");
}

void descarregarRecursos(Recursos *res) {
    UnloadTexture(res->titulo);
    UnloadTexture(res->marioDir);
    UnloadTexture(res->marioEsq);
    UnloadTexture(res->marioStdLeft);
    UnloadTexture(res->marioSobe1);
    UnloadTexture(res->marioSobe2);
    UnloadTexture(res->marioBackStd);
    UnloadTexture(res->marioBackStding);
    UnloadTexture(res->marioBackUpL);
    UnloadTexture(res->marioBackUpR);
    UnloadTexture(res->marioBackUpping);
    UnloadTexture(res->marioDamage);
    UnloadTexture(res->marioGameOver);
    UnloadTexture(res->marioMarteloDir);
    UnloadTexture(res->marioMarteloEsq);
    UnloadTexture(res->morto);
    UnloadTexture(res->plataformaVermelha);
    UnloadTexture(res->escada);
    UnloadTexture(res->stairsBottom);
    UnloadTexture(res->stairsMid);
    UnloadTexture(res->stairsTop);
    UnloadTexture(res->pauline);
    UnloadTexture(res->paulineAjuda);
    UnloadTexture(res->dk);
    UnloadTexture(res->dkSobe1);
    UnloadTexture(res->dkSobe2);
    UnloadTexture(res->itemHP);
    UnloadTexture(res->coracaoVitoria);
    UnloadTexture(res->coracaoQuebrado);
    UnloadTexture(res->barrilFogo);
    UnloadTexture(res->fogoSprite);
    UnloadTexture(res->inimigo);
    UnloadTexture(res->inimigoDir);
    UnloadTexture(res->inimigoEsq);
    UnloadTexture(res->gameOverScreen);
    for (int i = 0; i < 4; i++) UnloadTexture(res->barril[i]);
    for (int i = 0; i < 5; i++) UnloadTexture(res->moeda[i]);
    UnloadTexture(res->martelo);
    UnloadSound(res->somIntro);
    UnloadSound(res->somPulo);
    UnloadSound(res->somMorte);
    UnloadSound(res->somMartelo);
}

static Texture2D LoadTextureSafe(const char *path) {
    Texture2D tex = LoadTexture(path);
    if (tex.id == 0) {
        fprintf(stderr, "Falha ao carregar textura: %s\n", path);
    }
    return tex;
}

static Sound LoadSoundSafe(const char *path) {
    Sound snd = LoadSound(path);
    if (snd.frameCount == 0) {
        fprintf(stderr, "Falha ao carregar som: %s\n", path);
    }
    return snd;
}

static void setWorkingDirectoryToExeDir(void) {
    char exePath[4096];
    ssize_t len = readlink("/proc/self/exe", exePath, sizeof(exePath) - 1);
    if (len > 0) {
        exePath[len] = '\0';
        for (ssize_t i = len - 1; i >= 0; i--) {
            if (exePath[i] == '/') {
                exePath[i] = '\0';
                break;
            }
        }
        chdir(exePath);
    }
}

// --- VARIÁVEIS GLOBAIS DE TEXTURAS ADICIONAIS ---
static Texture2D texLogo;
static Texture2D texDKHoldingBarrel;
static Texture2D texDKHoldingBlueBarrel;
static Texture2D texFireball;

static bool ehSolidoNoMapa(char* matrix, int row, int col) {
    if (!matrix || row < 0 || row >= NLIN || col < 0 || col >= NCOL) return false;
    char bloco = matrix[row * NCOL + col];
    return (bloco == 'F' || bloco == 'Z' || bloco == 'X');
}

static void atualizaBarris(Barril* barris, int nBarris, char* matrix, float dt) {
    const float barrelSpeed = 90.0f;
    for (int i = 0; i < MAX_BARRIS; i++) {
        if (!barris[i].ativo) continue;

        float footY = barris[i].y + TAM_BLOCO;
        int belowRow = (int)(footY / TAM_BLOCO);
        int leftCol = (int)(barris[i].x / TAM_BLOCO);
        int rightCol = (int)((barris[i].x + TAM_BLOCO - 1) / TAM_BLOCO);
        bool groundBelow = false;
        for (int c = leftCol; c <= rightCol; c++) {
            if (ehSolidoNoMapa(matrix, belowRow, c)) {
                groundBelow = true;
                break;
            }
        }

        if (!groundBelow) {
            barris[i].velVertical += GRAVITY * dt;
            barris[i].y += barris[i].velVertical * dt;
        } else {
            barris[i].velVertical = 0.0f;
            float targetY = belowRow * TAM_BLOCO - TAM_BLOCO;
            if (barris[i].y > targetY) barris[i].y = targetY;

            int aheadCol = (barris[i].direcao == 'L') ? (int)((barris[i].x - 1) / TAM_BLOCO) : (int)((barris[i].x + TAM_BLOCO) / TAM_BLOCO);
            int frontRow = (int)((barris[i].y + TAM_BLOCO - 1) / TAM_BLOCO);
            bool blocked = ehSolidoNoMapa(matrix, frontRow, aheadCol);
            if (blocked) {
                barris[i].direcao = (barris[i].direcao == 'L' ? 'R' : 'L');
            } else {
                if (barris[i].direcao == 'L') barris[i].x -= barrelSpeed * dt;
                else barris[i].x += barrelSpeed * dt;
            }
        }

        if (barris[i].y > ESCALA_JANELA) barris[i].ativo = false;
    }
}

static void desenhaBarris(Barril* barris, int nBarris, Recursos* res) {
    for (int i = 0; i < MAX_BARRIS; i++) {
        if (!barris[i].ativo) continue;
        DrawTextureEx(res->barril[i % 4], (Vector2){barris[i].x, barris[i].y}, 0.0f, 1.0f, WHITE);
    }
}

static void spawnBarril(Barril* barris, int* nBarris, int dk_r, int dk_c) {
    if (dk_r < 0 || dk_c < 0 || !barris || !nBarris) return;
    for (int i = 0; i < MAX_BARRIS; i++) {
        if (!barris[i].ativo) {
            barris[i].ativo = true;
            barris[i].x = (float)dk_c * TAM_BLOCO + TAM_BLOCO;
            barris[i].y = (float)dk_r * TAM_BLOCO;
            barris[i].direcao = 'R';
            barris[i].velVertical = 0.0f;
            barris[i].frame = 0;
            barris[i].rolandoEscada = false;
            if (i >= *nBarris) *nBarris = i + 1;
            return;
        }
    }
}

static void spawnFlamaDeOilDrum(Fogo* flamas, int nFlamas, char* matrix) {
    for (int i = 0; i < nFlamas; i++) {
        if (!flamas[i].ativo) {
            for (int r = 0; r < NLIN; r++) {
                for (int c = 0; c < NCOL; c++) {
                    if (matrix[r * NCOL + c] == 'X') {
                        flamas[i].ativo = true;
                        flamas[i].x = (float)c * TAM_BLOCO;
                        flamas[i].y = (float)r * TAM_BLOCO;
                        return;
                    }
                }
            }
        }
    }
}

// --- Estruturas de Jogo ---
static Mario jogador = {0};
static Recursos res;
static char* matriz = NULL;
static Inimigo inimigos[MAX_INIMIGOS] = {0};
static int nInimigos = 0;
static ItemHP itensHP[MAX_BARRIS] = {0};
static int nItensHP = 0;
static float tempoMorte = 0.0f;
static bool marioMorreu = false;

int main(void) {
    setWorkingDirectoryToExeDir();
    InitWindow(ESCALA_JANELA, ESCALA_JANELA, "Donkey Kong INF - Arcade Final");
    InitAudioDevice();
    SetTargetFPS(60);

    // Carrega recursos do atlas principal
    carregarRecursos(&res);

    // Carrega texturas extras
    texLogo = LoadTextureSafe("DKINFsprites/DK_Arcade_In-game_Logo.png");
    texDKHoldingBarrel = LoadTextureSafe("DKINFsprites/DK_Arcade_Donkey_Kong_Holding_Barrel_Sprite.png");
    texDKHoldingBlueBarrel = LoadTextureSafe("DKINFsprites/DK_Arcade_Donkey_Kong_Holding_Blue_Barrel.png");
    texFireball = LoadTextureSafe("DKINFsprites/DK_Arcade_Fireball_Sprite.png");

    EstadoJogo estado = ESTADO_MENU;
    jogador.direcao = 'R';
    float animFrame = 0.0f;
    float timerBarril = 0.0f;
    float timerDKSprite = 0.0f;
    float timerFlama = 0.0f;
    bool running = true;
    int dk_r = -1, dk_c = -1;
    Barril barris[MAX_BARRIS] = {0};
    int nBarris = 0;

    // Lista de entidades
    Fogo flamas[5] = {0};

    while (running && !WindowShouldClose()) {
        float dt = GetFrameTime();
        animFrame += dt * 10.0f;
        
        switch (estado) {
            case ESTADO_MENU:
                if (IsKeyPressed(KEY_SPACE)) {
                    char *novaMatriz = carregaMapa(&jogador, 1, inimigos, &nInimigos, NULL, NULL, &dk_r, &dk_c, barris, &nBarris, itensHP, &nItensHP);
                    if (novaMatriz != NULL) {
                        if (matriz) free(matriz);
                        matriz = novaMatriz;
                        // Inicializa estado do jogador (física)
                        jogador.velVertical = 0.0f;
                        jogador.pulosRestantes = 1;
                        jogador.vidas = 3;
                        jogador.temMartelo = false;
                        jogador.tempoMartelo = 0.0f;
                        for (int i = 0; i < MAX_BARRIS; i++) barris[i].ativo = false;
                        for (int i = 0; i < MAX_BARRIS; i++) itensHP[i].ativo = false;
                        timerBarril = 0.0f;
                        timerDKSprite = 0.0f;
                        timerFlama = 0.0f;
                        marioMorreu = false;
                        tempoMorte = 0.0f;
                        estado = ESTADO_JOGANDO;
                    } else {
                        fprintf(stderr, "Erro: nao foi possivel carregar o mapa.");
                    }
                }
                if (IsKeyPressed(KEY_ESCAPE)) {
                    running = false;
                }

                BeginDrawing();
                    ClearBackground(DARKGRAY);
                    if (res.titulo.id != 0) {
                        DrawTexture(res.titulo, ESCALA_JANELA/2 - res.titulo.width/2, 100, WHITE);
                    } else {
                        DrawText("DONKEY KONG INF", ESCALA_JANELA/2 - 160, 120, 40, RAYWHITE);
                    }
                    DrawText("APERTE ESPACO PARA INICIAR", ESCALA_JANELA/2 - 200, 500, 20, RAYWHITE);
                    DrawText("PRESSIONE C PARA CONFIGURACOES", ESCALA_JANELA/2 - 220, 530, 18, GRAY);
                    DrawText("ESC PARA SAIR", ESCALA_JANELA/2 - 90, 560, 18, GRAY);
                EndDrawing();
                break;

            case ESTADO_JOGANDO:
                if (IsKeyPressed(KEY_ESCAPE)) {
                    estado = ESTADO_MENU;
                    if (matriz) {
                        free(matriz);
                        matriz = NULL;
                    }
                    break;
                }

                if (matriz == NULL) {
                    BeginDrawing();
                        ClearBackground(BLACK);
                        DrawText("Erro ao carregar o mapa.", 60, ESCALA_JANELA / 2 - 20, 24, RED);
                        DrawText("Pressione ESC para voltar ao menu.", 40, ESCALA_JANELA / 2 + 20, 20, RAYWHITE);
                    EndDrawing();
                    break;
                }

                // Spawn de fireballs a partir dos oil drums estáticos
                timerFlama += dt;
                if (timerFlama > 5.0f) {
                    spawnFlamaDeOilDrum(flamas, 5, matriz);
                    timerFlama = 0.0f;
                }

                // Spawn de barris lançados pelo DK
                timerBarril += dt;
                if (timerBarril > 3.0f) {
                    spawnBarril(barris, &nBarris, dk_r, dk_c);
                    timerBarril = 0.0f;
                }

                atualizaBarris(barris, nBarris, matriz, dt);

                // Atualiza movimento dos inimigos
                for (int i = 0; i < nInimigos; i++) {
                    if (!inimigos[i].ativo) continue;
                    
                    inimigos[i].frameCounter++;
                    if (inimigos[i].frameCounter >= 12) {  // Muda direção a cada 12 frames (~200ms)
                        inimigos[i].frameCounter = 0;
                        
                        // Tenta mover na direção atual
                        float novaX = inimigos[i].x + (inimigos[i].direcaoAtual * SPEED * 0.5f) * dt;
                        int col = (int)novaX / TAM_BLOCO;
                        
                        // Se bater na parede ou sair dos limites, inverte direção
                        if (col < 0 || col >= NCOL || (matriz && matriz[(int)(inimigos[i].y/TAM_BLOCO)*NCOL + col] == 'Z')) {
                            inimigos[i].direcaoAtual *= -1;
                        } else {
                            inimigos[i].x = novaX;
                        }
                    }
                }

                // Coleta itens HP
                for (int i = 0; i < MAX_BARRIS; i++) {
                    if (!itensHP[i].ativo) continue;
                    Rectangle itemRect = { itensHP[i].x, itensHP[i].y, TAM_BLOCO, TAM_BLOCO };
                    
                    Rectangle jogadorRect = { jogador.pos.x + 8, jogador.pos.y + 6, TAM_BLOCO - 16, TAM_BLOCO - 6 };
                    if (CheckCollisionRecs(jogadorRect, itemRect)) {
                        if (jogador.vidas < 5) jogador.vidas++;
                        itensHP[i].ativo = false;
                    }
                }

                // Colisão com inimigos
                if (!marioMorreu) {
                    for (int i = 0; i < nInimigos; i++) {
                        if (!inimigos[i].ativo) continue;
                        Rectangle inimigoRect = { inimigos[i].x + 8, inimigos[i].y + 6, TAM_BLOCO - 16, TAM_BLOCO - 6 };
                        
                        Rectangle jogadorRect = { jogador.pos.x + 8, jogador.pos.y + 6, TAM_BLOCO - 16, TAM_BLOCO - 6 };
                        if (CheckCollisionRecs(jogadorRect, inimigoRect)) {
                            if (jogador.temMartelo) {
                                // Mata o inimigo e spawna HP
                                inimigos[i].ativo = false;
                                if (nItensHP < MAX_BARRIS) {
                                    itensHP[nItensHP].x = inimigos[i].x;
                                    itensHP[nItensHP].y = inimigos[i].y;
                                    itensHP[nItensHP].ativo = true;
                                    nItensHP++;
                                }
                            } else {
                                // Mario morre
                                jogador.vidas--;
                                if (jogador.vidas < 0) {
                                    marioMorreu = true;
                                    tempoMorte = 0.0f;
                                    estado = ESTADO_MORTE;
                                } else {
                                    // Reset posição se ainda tem vidas
                                    jogador.pos.x = 100;
                                    jogador.pos.y = 300;
                                    jogador.velVertical = 0.0f;
                                }
                                break;
                            }
                        }
                    }
                }

                // Colisão com barris e fireballs
                if (!marioMorreu && !jogador.temMartelo) {
                    for (int i = 0; i < MAX_BARRIS; i++) {
                        if (!barris[i].ativo) continue;
                        Rectangle barrilRect = { barris[i].x, barris[i].y, TAM_BLOCO, TAM_BLOCO };
                        
                        Rectangle jogadorRect = { jogador.pos.x + 8, jogador.pos.y + 6, TAM_BLOCO - 16, TAM_BLOCO - 6 };
                        if (CheckCollisionRecs(jogadorRect, barrilRect)) {
                            jogador.vidas--;
                            if (jogador.vidas < 0) {
                                marioMorreu = true;
                                tempoMorte = 0.0f;
                                estado = ESTADO_MORTE;
                            } else {
                                jogador.pos.x = 100;
                                jogador.pos.y = 300;
                                jogador.velVertical = 0.0f;
                            }
                            break;
                        }
                    }
                    for (int i = 0; i < 5; i++) {
                        if (!flamas[i].ativo) continue;
                        Rectangle chamaRect = { flamas[i].x, flamas[i].y, TAM_BLOCO, TAM_BLOCO };
                        
                        Rectangle jogadorRect = { jogador.pos.x + 8, jogador.pos.y + 6, TAM_BLOCO - 16, TAM_BLOCO - 6 };
                        if (CheckCollisionRecs(jogadorRect, chamaRect)) {
                            jogador.vidas--;
                            if (jogador.vidas < 0) {
                                marioMorreu = true;
                                tempoMorte = 0.0f;
                                estado = ESTADO_MORTE;
                            } else {
                                jogador.pos.x = 100;
                                jogador.pos.y = 300;
                                jogador.velVertical = 0.0f;
                            }
                            break;
                        }
                    }
                }

                if (IsKeyDown(KEY_RIGHT)) { jogador.pos.x += SPEED * dt; jogador.direcao = 'R'; }
                if (IsKeyDown(KEY_LEFT)) { jogador.pos.x -= SPEED * dt; jogador.direcao = 'L'; }

                // Pulo: tecla SPACE ou UP (consome pulo disponível)
                if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_UP)) {
                    if (jogador.pulosRestantes > 0) {
                        jogador.velVertical = JUMP_FORCE;
                        jogador.pulosRestantes--;
                        PlaySound(res.somPulo);
                    }
                }

                // Verifica presença de escada nas células ocupadas pelo jogador
                bool onLadder = false;
                int topRow = (int)((jogador.pos.y) / TAM_BLOCO);
                int bottomRow = (int)((jogador.pos.y + TAM_BLOCO - 1) / TAM_BLOCO);
                int leftCol = (int)((jogador.pos.x) / TAM_BLOCO);
                int rightCol = (int)((jogador.pos.x + TAM_BLOCO - 1) / TAM_BLOCO);
                if (matriz) {
                    for (int r = topRow; r <= bottomRow && !onLadder; r++) {
                        if (r < 0 || r >= NLIN) continue;
                        for (int c = leftCol; c <= rightCol; c++) {
                            if (c < 0 || c >= NCOL) continue;
                            if (matriz[r * NCOL + c] == 'H') { onLadder = true; break; }
                        }
                    }
                }

                if (onLadder) {
                    // Quando na escada, permite subir/descer sem gravidade
                    jogador.subindo = true;
                    jogador.velVertical = 0.0f;
                    if (IsKeyDown(KEY_UP)) {
                        // Antes de subir, bloqueia se houver plataforma acima
                        int acimaRow = (int)((jogador.pos.y - 1) / TAM_BLOCO);
                        int colCentro = (int)((jogador.pos.x + TAM_BLOCO/2) / TAM_BLOCO);
                        if (acimaRow >= 0 && colCentro >= 0 && colCentro < NCOL && matriz[acimaRow * NCOL + colCentro] == 'Z') {
                            // não sobe através da plataforma; fixa posição abaixo dela
                            jogador.pos.y = (acimaRow + 1) * TAM_BLOCO;
                            jogador.subindo = false;
                        } else {
                            jogador.pos.y -= SPEED * dt;
                        }
                    } else if (IsKeyDown(KEY_DOWN)) {
                        jogador.pos.y += SPEED * dt;
                    }
                } else {
                    // Física vertical: gravidade e integração por dt
                    jogador.subindo = false;
                    jogador.velVertical += GRAVITY * dt;
                    jogador.pos.y += jogador.velVertical * dt;

                    // Colisão simples com o chão (base da janela)
                    if (jogador.pos.y > ESCALA_JANELA - TAM_BLOCO) {
                        jogador.pos.y = ESCALA_JANELA - TAM_BLOCO;
                        jogador.velVertical = 0.0f;
                        jogador.pulosRestantes = 1; // reset do pulo ao tocar no chão
                    }
                }
                if (coletaMartelo(&jogador, matriz)) {
                    PlaySound(res.somMartelo); // Som do martelo ativado
                }
                atualizaMartelo(&jogador, matriz, flamas, 5, barris, nBarris, dt);

                // Renderização
                BeginDrawing();
                    ClearBackground(BLACK);
                    desenhaCenario(matriz, &res);

                    // Logo removido durante a partida (não desenhar no meio do jogo)

                    // Desenha flamas
                    for(int i = 0; i < 5; i++) {
                        if (flamas[i].ativo && texFireball.id != 0) {
                            DrawTextureEx(texFireball, (Vector2){flamas[i].x, flamas[i].y}, 0.0f, 1.0f, WHITE);
                        }
                    }

                    // Desenha barris lançados pelo DK
                    desenhaBarris(barris, nBarris, &res);

                    // Desenha inimigos
                    for (int i = 0; i < nInimigos; i++) {
                        if (!inimigos[i].ativo) continue;
                        Texture2D inimigoSprite = (inimigos[i].direcaoAtual > 0 ? res.inimigoDir : res.inimigoEsq);
                        if (inimigoSprite.id != 0) {
                            DrawTextureEx(inimigoSprite, (Vector2){inimigos[i].x, inimigos[i].y}, 0.0f, 1.0f, WHITE);
                        }
                    }

                    // Desenha itens HP
                    for (int i = 0; i < MAX_BARRIS; i++) {
                        if (!itensHP[i].ativo) continue;
                        if (res.itemHP.id != 0) {
                            DrawTextureEx(res.itemHP, (Vector2){itensHP[i].x, itensHP[i].y}, 0.0f, 1.0f, WHITE);
                        }
                    }

                    bool climbingUp = onLadder && IsKeyDown(KEY_UP);
                    bool climbingDown = onLadder && IsKeyDown(KEY_DOWN);
                    bool ladderTop = false;
                    if (onLadder && matriz) {
                        int rowAbove = (int)((jogador.pos.y - 1) / TAM_BLOCO);
                        int colCentro = (int)((jogador.pos.x + TAM_BLOCO / 2) / TAM_BLOCO);
                        if (rowAbove >= 0 && colCentro >= 0 && colCentro < NCOL) {
                            ladderTop = (matriz[rowAbove * NCOL + colCentro] != 'H');
                        }
                    }

                    Texture2D marioSprite;
                    if (jogador.vidas <= 0) {
                        marioSprite = res.marioDamage;
                    } else if (jogador.temMartelo) {
                        marioSprite = (jogador.direcao == 'L' ? res.marioMarteloEsq : res.marioMarteloDir);
                    } else if (onLadder) {
                        if (IsKeyPressed(KEY_UP)) {
                            marioSprite = res.marioBackStding;
                        } else if (climbingUp) {
                            if (ladderTop) {
                                marioSprite = res.marioBackUpping;
                            } else {
                                marioSprite = (jogador.direcao == 'L' ? res.marioBackUpL : res.marioBackUpR);
                            }
                        } else {
                            marioSprite = res.marioBackStd;
                        }
                    } else {
                        marioSprite = (jogador.direcao == 'L' ? res.marioStdLeft : res.marioDir);
                    }
                    DrawTextureEx(marioSprite, jogador.pos, 0.0f, 1.0f, WHITE);

                    if (jogador.temMartelo) {
                        DrawText(TextFormat("INVENCIVEL: %.1f", jogador.tempoMartelo), 10, 50, 20, YELLOW);
                    }

                    // Lógica Donkey Kong
                    timerDKSprite += dt;
                    Texture2D dkSprite = res.dk;
                    if (timerDKSprite > 2.5f) { dkSprite = texDKHoldingBlueBarrel; timerDKSprite = 0.0f; }
                    else if (timerDKSprite > 1.5f) dkSprite = texDKHoldingBarrel;
                    Vector2 dkPos = {100, 100};
                    if (dk_r >= 0 && dk_c >= 0) {
                        dkPos.x = (float)dk_c * TAM_BLOCO;
                        dkPos.y = (float)dk_r * TAM_BLOCO;
                    }
                    if (dkSprite.id != 0) {
                        DrawTextureEx(dkSprite, dkPos, 0.0f, 1.5f, WHITE);
                    }

                    // Verifica colisão com Pauline ('Q') para vitória
                    Rectangle jogadorRect = { jogador.pos.x + 8, jogador.pos.y + 6, TAM_BLOCO - 16, TAM_BLOCO - 6 };
                    for (int i = 0; i < NLIN; i++) {
                        for (int j = 0; j < NCOL; j++) {
                            if (matriz[i * NCOL + j] == 'Q') {
                                Rectangle paulineRect = { j * TAM_BLOCO, i * TAM_BLOCO, TAM_BLOCO, TAM_BLOCO };
                                if (CheckCollisionRecs(jogadorRect, paulineRect)) {
                                    estado = ESTADO_VITORIA;
                                    // libera mapa e sai do laço de checagem
                                    free(matriz);
                                    matriz = NULL;
                                    goto end_frame;
                                }
                            }
                        }
                    }

                EndDrawing();
                end_frame:
                break;

            case ESTADO_MORTE:
                tempoMorte += dt;
                BeginDrawing();
                    ClearBackground(BLACK);
                    desenhaCenario(matriz, &res);
                    desenhaBarris(barris, nBarris, &res);
                    
                    // Desenha Mario em estado fatal
                    DrawTextureEx(res.marioDamage, jogador.pos, 0.0f, 1.0f, WHITE);
                    
                    // Coração quebrado acima de Pauline
                    for (int i = 0; i < NLIN; i++) {
                        for (int j = 0; j < NCOL; j++) {
                            if (matriz[i * NCOL + j] == 'Q') {
                                DrawTextureEx(res.coracaoQuebrado, (Vector2){j*TAM_BLOCO, (i-1)*TAM_BLOCO}, 0.0f, 1.0f, WHITE);
                            }
                        }
                    }
                    
                    if (tempoMorte > 4.0f) {
                        estado = ESTADO_GAME_OVER;
                        tempoMorte = 0.0f;
                    }
                EndDrawing();
                break;

            case ESTADO_GAME_OVER:
                BeginDrawing();
                    ClearBackground(BLACK);
                    if (res.gameOverScreen.id != 0) {
                        DrawTexture(res.gameOverScreen, 0, 0, WHITE);
                    } else {
                        DrawText("GAME OVER", ESCALA_JANELA/2 - 120, ESCALA_JANELA/2 - 100, 60, RED);
                    }
                    DrawText(TextFormat("VIDAS RESTANTES: %d", jogador.vidas < 0 ? 0 : jogador.vidas), ESCALA_JANELA/2 - 200, ESCALA_JANELA/2, 24, RAYWHITE);
                    DrawText(TextFormat("TEMPO: %.1f s", jogador.cronometro), ESCALA_JANELA/2 - 150, ESCALA_JANELA/2 + 60, 24, RAYWHITE);
                    DrawText("PRESSIONE ESPACO PARA VOLTAR AO MENU", ESCALA_JANELA/2 - 250, ESCALA_JANELA/2 + 150, 20, YELLOW);
                EndDrawing();
                
                if (IsKeyPressed(KEY_SPACE)) {
                    estado = ESTADO_MENU;
                    if (matriz) {
                        free(matriz);
                        matriz = NULL;
                    }
                }
                break;

            default: break;
        }
    }

    // Limpeza
    UnloadTexture(texLogo);
    UnloadTexture(texDKHoldingBarrel);
    UnloadTexture(texDKHoldingBlueBarrel);
    UnloadTexture(texFireball);
    descarregarRecursos(&res);
    if (matriz) free(matriz);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}