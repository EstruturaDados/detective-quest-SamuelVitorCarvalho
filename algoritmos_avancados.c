#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar uma sala
typedef struct Sala {
    char nome[50];
    struct Sala* esquerda;
    struct Sala* direita;  
} Sala;

// Protótipos das funções
Sala* criarSala(char* nome);
void explorarSalas(Sala* salaAtual);
void menu();
void liberarArvore(Sala* raiz);

int main() {
    printf("====================================\n");
    printf("       DETECTIVE QUEST\n");
    printf("====================================\n\n");
    
    // Criação manual da estrutura da mansão (árvore binária)
    Sala* hall = criarSala("Hall de Entrada");
    
    // Primeiro nível
    hall->esquerda = criarSala("Sala de Estar");
    hall->direita = criarSala("Cozinha");
    
    // Segundo nível - ramo esquerdo
    hall->esquerda->esquerda = criarSala("Biblioteca");
    hall->esquerda->direita = criarSala("Escritório");
    
    // Segundo nível - ramo direito
    hall->direita->esquerda = criarSala("Despensa");
    hall->direita->direita = criarSala("Jardim");
    
    // Terceiro nível - folhas da árvore
    hall->esquerda->esquerda->esquerda = criarSala("Sala Secreta");
    hall->esquerda->direita->direita = criarSala("Cofre");
    
    printf("Bem-vindo ao jogo Detective Quest!\n");
    printf("Use 'e' para ir à esquerda, 'd' para ir à direita, ou 's' para sair.\n\n");
    
    // Iniciar a exploração
    explorarSalas(hall);
    
    // Liberar memória
    liberarArvore(hall);
    
    printf("\nObrigado por jogar Detective Quest!\n");
    return 0;
}

Sala* criarSala(char* nome) {
    Sala* novaSala = (Sala*)malloc(sizeof(Sala));
    
    if (novaSala == NULL) {
        printf("Erro: Não foi possível alocar memória para a sala.\n");
        exit(1);
    }
    
    strcpy(novaSala->nome, nome);
    novaSala->esquerda = NULL;
    novaSala->direita = NULL;
    
    return novaSala;
}

void explorarSalas(Sala* salaAtual) {
    char opcao;
    
    while (salaAtual != NULL) {
        printf("====================================\n");
        printf("Você está em: %s\n", salaAtual->nome);
        printf("====================================\n");
        
        // Verificar se é uma sala sem saídas (nó folha)
        if (salaAtual->esquerda == NULL && salaAtual->direita == NULL) {
            printf("Fim da árvore binária.\n\n");
            break;
        }
        
        // Mostrar opções disponíveis
        printf("Caminhos disponíveis:\n");
        if (salaAtual->esquerda != NULL) {
            printf("(e) Esquerda -> %s\n", salaAtual->esquerda->nome);
        }
        if (salaAtual->direita != NULL) {
            printf("(d) Direita -> %s\n", salaAtual->direita->nome);
        }
        printf("(s) Sair do jogo\n");
        
        printf("\nEscolha sua opção: ");
        scanf(" %c", &opcao);
        
        switch (opcao) {
            case 'e':
                if (salaAtual->esquerda != NULL) {
                    printf("Você escolheu ir para a esquerda...\n\n");
                    salaAtual = salaAtual->esquerda;
                } else {
                    printf("Não há caminho à esquerda!\n\n");
                }
                break;
                
            case 'd':
                if (salaAtual->direita != NULL) {
                    printf("Você escolheu ir para a direita...\n\n");
                    salaAtual = salaAtual->direita;
                } else {
                    printf("Não há caminho à direita!\n\n");
                }
                break;
                
            case 's':
                printf("Saindo da exploração...\n");
                return;
                
            default:
                printf("Opção inválida! Use 'e', 'd' ou 's'.\n\n");
                break;
        }
    }
}

void liberarArvore(Sala* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}
