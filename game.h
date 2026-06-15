#ifndef GAME_H
#define GAME_H

#include <raylib.h>
#include <stdbool.h>
#include <stdio.h>

/* 
 * DEFINIÇÕES DE TAMANHO E ESCALA
 */
#define NCOL 31
#define NLIN 31
#define TAM_BLOCO 32
#define ESCALA_JANELA (NCOL * TAM_BLOCO)

/* CONSTANTES DE FÍSICA (unidades por segundo)
    - SPEED: pixels por segundo
    - GRAVITY: pixels por segundo ao quadrado
    - JUMP_FORCE: velocidade inicial vertical (negativa sai para cima)
*/
#define SPEED 150.0f
#define GRAVITY 2000.0f
#define JUMP_FORCE -600.0f

/* LIMITES DO SISTEMA */
#define MAX_BARRIS 50
#define MAX_INIMIGOS 10
#define MAX_MOEDAS 20
#define MAX_FOGOS 5

/* ESTADOS DE JOGO */
typedef enum {
    ESTADO_MENU,
    ESTADO_INTRO,
    ESTADO_CONFIG,
    ESTADO_JOGANDO,
    ESTADO_MORTE,
    ESTADO_GAME_OVER,
    ESTADO_VITORIA,
    ESTADO_DERROTA
} EstadoJogo;

/* ESTRUTURA PARA REGISTRO DE PONTUAÇÃO */
typedef struct {
    char nome[20];
    int pontos;
    float tempo;
} RegistroPontos;

/* ESTRUTURAS DAS ENTIDADES */
typedef struct {
    float x, y;
    float velVertical;
    char direcao;
    bool ativo;
    int frameCounter;
    int direcaoAtual;
} Inimigo;

typedef struct {
    float x, y;
    bool ativo;
} ItemHP;

typedef struct {
    int r, c;
    bool ativo;
} Moeda;

typedef struct {
    float x, y;
    float velVertical;
    char direcao;
    bool ativo;
    int frame;
    bool rolandoEscada;
} Barril;

typedef struct {
    float x, y;
    float velVertical;
    bool ativo;
    bool walking;
    char direcao;
} Fogo;

typedef struct {
    Vector2 pos;
    float velVertical;
    int pulosRestantes;
    int vidas;
    int pontuacao;
    float cronometro; 
    char direcao;
    bool emEscada;
    bool subindo;
    bool descendo;
    bool temMartelo;
    float tempoMartelo;
} Mario;

/* RECURSOS GRÁFICOS E SONOROS */
typedef struct {
    Texture2D titulo;
    Texture2D marioDir, marioEsq;
    Texture2D marioStdLeft;
    Texture2D marioSobe1, marioSobe2;
    Texture2D marioBackStd;
    Texture2D marioBackStding;
    Texture2D marioBackUpL;
    Texture2D marioBackUpR;
    Texture2D marioBackUpping;
    Texture2D marioDamage;
    Texture2D marioGameOver;
    Texture2D marioMarteloDir, marioMarteloEsq;
    Texture2D morto;
    Texture2D plataformaVermelha;
    Texture2D escada;
    Texture2D stairsBottom;
    Texture2D stairsMid;
    Texture2D stairsTop;
    Texture2D barril[4];
    Texture2D inimigo;
    Texture2D inimigoDir, inimigoEsq;
    Texture2D moeda[5];
    Texture2D itemHP;
    Texture2D coracaoVitoria;
    Texture2D coracaoQuebrado;
    Texture2D pauline, paulineAjuda;
    Texture2D dk, dkSobe1, dkSobe2;
    Texture2D barrilFogo;
    Texture2D fogoSprite;
    Texture2D martelo;
    Texture2D gameOverScreen;
    Sound somPulo, somMorte, somIntro, somMartelo;
} Recursos;

/* PROTÓTIPOS DAS FUNÇÕES */
char* alocaMatriz(void);
char* carregaMapa(Mario* player, int fase, Inimigo* inimigos, int* nInimigos, Moeda* moedas, int* nMoedas, int* dk_r, int* dk_c, Barril* barris, int* nBarris, ItemHP* itensHP, int* nItemsHP);
void desenhaCenario(char* matrix, Recursos* rec);
bool ehSolido(char bloco);
void registraPontuacaoBin(RegistroPontos reg);

#endif // GAME_H
