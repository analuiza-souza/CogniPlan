#include <stdio.h>
#include <string.h>

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


int main() {
    char    materias[10][50];
    int     quantidadeMaterias = 0;
    char    tarefas[20][50];
    int     quantidadesTarefas = 0;
    int     opcao;

    do {

        printf("\n\n##############################\nCogniPlan\n##############################\n\n");
        printf("1 - Cadastrar materias\n");
        printf("2 - Listar materias\n");
        printf("3 - Cadastrar tarefas\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("Digite o nome da materia: ");
            scanf(" %[^\n]", materias[quantidadeMaterias]); quantidadeMaterias++;
            printf("\nMateria cadastrada!\n\n");
        break;

        case 2:
            printf("\n\n###### MATERIAS ######\n");
            for(int i = 0; i < quantidadeMaterias; i++) {
            printf("%d.%s\n", i + 1, materias[i]); 
    }
        break;

        case 3:
        printf("Digite a tarefa: ");
        scanf(" %[^\n]", tarefas[quantidadesTarefas]); quantidadesTarefas++;
        printf("Tarefa cadastrada!\n\n");
        break;
        

        case 0:
            printf("\nSaindo...\n");   

        break;


        default:
            printf("Opcao invalida!\n\n");

    
        }

        if (opcao != 0) {
            printf("Pressione Enter Se Quiser Continuar.");
            limparBuffer();
            getchar(); 
    }

    } while (opcao != 0);



    return 0;
}