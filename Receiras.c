#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct receita{
    char nome[100];
    char ingredientes[500];
    char instrucoes[1000];
    int tempo_preparo_minutos;
};

void mostrarReceita(struct receita criarReceita) {
    printf("Nome: %s\n", criarReceita.nome);
    printf("Ingredientes: %s\n", criarReceita.ingredientes);
    printf("Instrucoes: %s\n", criarReceita.instrucoes);
    printf("Tempo de preparo: %d\n", criarReceita.tempo_preparo_minutos);
    printf("-------------\n");
}

void adicionarReceita(struct receita criarReceita[], int *total) {
    printf("1. Adicionar receita\n");
    
    printf("Digite o nome da receita: ");
    fgets(criarReceita[*total].nome, 100, stdin);
    criarReceita[*total].nome[strcspn(criarReceita[*total].nome, "\n")] = '\0';
    fflush(stdin);
    
    printf("Digite os ingredientes: ");
    fgets(criarReceita[*total].ingredientes, 100, stdin);
    criarReceita[*total].ingredientes[strcspn(criarReceita[*total].ingredientes, "\n")] = '\0';
    fflush(stdin);
    
    printf("Digite as instrucoes: ");
    fgets(criarReceita[*total].instrucoes, 100, stdin);
    criarReceita[*total].instrucoes[strcspn(criarReceita[*total].instrucoes, "\n")] = '\0';
    fflush(stdin);
    
    printf("Digite o tempo de preparo em minutos: ");
    scanf("%d", &criarReceita[*total].tempo_preparo_minutos);
    fflush(stdin);
      
    (*total)++;
}

void listarReceitas(struct receita criarReceita[], int total){
    printf("2. Listar receitas\n\n");

    if(total == 0){
        printf("Nenhuma receita cadastrada ainda.\n");
        return;
    }

    for ( int i = 0; i < total; i++){
        printf("Receita %d:\n", i + 1);
        mostrarReceita(criarReceita[i]);
    }                
}

void buscarReceita(struct receita criarReceitas[], int total){
    char buscarReceita[100];
    int encontrado = 0;
    int i;

    printf("3. Buscar receita por nome\n");
    
    printf("Digite o nome da receita: ");
    fgets(buscarReceita, 100, stdin);
    buscarReceita[strcspn(buscarReceita, "\n")] = '\0';
    fflush(stdin);
    
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

void categoriaReceita(struct receita criarReceita[], int total){
    int opcao2;
    char categorias[100];

    enum categorias { ENTRADA, PRATO_PRINCIPAL, SOBREMESA, BEBIDA, LANCHE};

    switch (opcao2){
    case ENTRADA:
        
        break;
    
    default:
        printf("Categoria nao encontrada. Tente novamente. ");
        break;
    }
}

int main(){
    int opcao;
    int totalReceitas = 0;
    struct receita nomes[100];

    do{
        printf("\n---MENU---\n");
        printf("1. Adicionar receita\n");
        printf("2. Listar receitas\n");
        printf("3. Buscar receita por nome\n");
        printf("4. Buscar receitas por categoria\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
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
                
            break;
            case 5:
                printf("5. Sair\n");
                printf("Saindo do programa.");
            break;
            default:
                printf("Opcao invalida. Tente novamente.");
            break;
            }
    } while (opcao != 5);

    system("pause");
    return 0;
}