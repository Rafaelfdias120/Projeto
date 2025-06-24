#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_receitas 50

struct receita{
    char nome[100];
    char ingredientes[500];
    char instrucoes[1000];
    char categorias[100];
    int tempo_preparo_minutos;
};

typedef struct receita receita;

void definirCategoria(int cat, char *categoEcolhida);

void mostrarReceita(receita criarReceita) {
    printf("Nome: %s\n", criarReceita.nome);
    printf("Ingredientes: %s\n", criarReceita.ingredientes);
    printf("Instrucoes: %s\n", criarReceita.instrucoes);
    printf("Tempo de preparo: %d\n", criarReceita.tempo_preparo_minutos);
    printf("-------------\n");
}

void adicionarReceita(receita criarReceita[], int *total) {

    if (*total >= max_receitas) {
    printf("Limite de %d receitas atingido. Nao e possível adicionar mais receitas.\n", max_receitas);
    return;
    }

    printf("1. Adicionar receita\n");

    printf("Digite o nome da receita: ");
    fgets(criarReceita[*total].nome, 100, stdin);
    criarReceita[*total].nome[strcspn(criarReceita[*total].nome, "\n")] = '\0';
    fflush(stdin);
    
    printf("Digite os ingredientes: ");
    fgets(criarReceita[*total].ingredientes, 500, stdin);
    criarReceita[*total].ingredientes[strcspn(criarReceita[*total].ingredientes, "\n")] = '\0';
    fflush(stdin);
    
    printf("Digite as instrucoes: ");
    fgets(criarReceita[*total].instrucoes, 1000, stdin);
    criarReceita[*total].instrucoes[strcspn(criarReceita[*total].instrucoes, "\n")] = '\0';
    fflush(stdin);
    
    printf("Digite o tempo de preparo em minutos: ");
    scanf("%d", &criarReceita[*total].tempo_preparo_minutos);
    getchar();
    fflush(stdin);

    int catEscolhida;
    printf("----Categorias disponiveis----\n");
    printf("1. Entrada.\n");
    printf("2. Prato principal.\n");
    printf("3. Sobremesa.\n");
    printf("4. Bebida\n");
    printf("5. Lanche\n");
    printf("Digite o numero da categoria (1-5): ");
    scanf("%d", &catEscolhida);
    getchar();
    fflush(stdin); 

    definirCategoria(catEscolhida, criarReceita[*total].categorias);

      
    (*total)++;
}

void listarReceitas(receita criarReceita[], int total){
    printf("2. Listar receitas\n\n");

    if(total == 0){
        printf("Nenhuma receita adicionada ainda.\n");
        return;
    }

    for ( int i = 0; i < total; i++){
        printf("Receita %d:\n", i + 1);
        mostrarReceita(criarReceita[i]);
    }                
}

void buscarReceita(receita criarReceitas[], int total){
    char buscarReceita[100];
    int encontrado = 0;
    int i;

    printf("3. Buscar receita por nome\n");
    
    printf("Digite o nome da receita: ");
    fgets(buscarReceita, 100, stdin);
    buscarReceita[strcspn(buscarReceita, "\n")] = '\0';
    
    for ( i = 0; i < total; i++){
        if(strcmp(buscarReceita, criarReceitas[i].nome) == 0){
            mostrarReceita(criarReceitas[i]);
            encontrado = 1;
            break;
        }
    }
    if(!encontrado){
        printf("Receita nao encontrada.\n");
    }
}

void definirCategoria(int cat, char *categoriaStr) {
    switch(cat) {
        case 1: 
            strcpy(categoriaStr, "Entrada"); 
            break;
        case 2: 
            strcpy(categoriaStr, "Prato principal"); 
        break;
        case 3: 
            strcpy(categoriaStr, "Sobremesa"); 
        break;
            case 4: 
            strcpy(categoriaStr, "Bebida"); 
        break;
        case 5: 
            strcpy(categoriaStr, "Lanche"); 
        break;
        default: 
            strcpy(categoriaStr, "Categoria invalida"); 
        break;
    }
}

void categoriaReceita(receita criarReceita[], int total){
    int opcao2;
    char categoriaEscolhida[100];

    enum categorias { ENTRADA = 1, PRATO_PRINCIPAL, SOBREMESA, BEBIDA, LANCHE };

    printf("-----Categorias-----\n");
    printf("1. Entrada\n");
    printf("2. Prato principal\n");
    printf("3. Sobremesa\n");
    printf("4. Bebida\n");
    printf("5. Lanche\n");

    printf("Escolha uma categoria: ");
    scanf("%d", &opcao2);
    getchar();

    switch(opcao2){
    case ENTRADA: 
        strcpy(categoriaEscolhida, "Entrada"); 
    break;
    case PRATO_PRINCIPAL: 
        strcpy(categoriaEscolhida, "Prato principal"); 
    break;
    case SOBREMESA: 
        strcpy(categoriaEscolhida, "Sobremesa"); 
    break;
    case BEBIDA: 
        strcpy(categoriaEscolhida, "Bebida"); 
        break;
    case LANCHE: 
        strcpy(categoriaEscolhida, "Lanche"); 
        break;
    default:
        printf("Opção invalida.\n");
        return;
    }

    int encontrou = 0;
    for (int i = 0; i < total; i++) {
        if (strcmp(criarReceita[i].categorias, categoriaEscolhida) == 0) {
            mostrarReceita(criarReceita[i]);
            encontrou = 1;
        }
    }
    if (!encontrou) {
        printf("Nenhuma receita encontrada para a categoria %s.\n", categoriaEscolhida);
    }
}

int main(){
    int opcao;
    int totalReceitas = 0;
    receita nomes[100];

    do{
        printf("\n---MENU---\n");
        printf("1. Adicionar receita\n");
        printf("2. Listar receitas\n");
        printf("3. Buscar receita por nome\n");
        printf("4. Buscar receitas por categoria\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();
        
        switch (opcao){
            case 1:
                adicionarReceita(nomes, &totalReceitas);
            break;
            case 2:
                listarReceitas(nomes, totalReceitas);
            break;
            case 3:
                buscarReceita(nomes, totalReceitas);
            break;
            case 4:
                categoriaReceita(nomes, totalReceitas);
            break;
            case 5:
                printf("5. Sair\n");
                printf("Saindo do programa.\n");
            break;
            default:
                printf("Opcao invalida. Tente novamente.");
            break;
            }
    } while (opcao != 5);

    system("pause");
    return 0;
}