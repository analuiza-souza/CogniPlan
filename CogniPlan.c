#include <stdio.h>

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


int main() {
    char    materias[50][50];
    int     quantidadeMaterias = 0;
    char    tarefas[50][50];
    int     quantidadesTarefas = 0;
    char    tarefasMaterias[50][50];
    int     opcao;

    do {

        printf("\n\n##############################\nCogniPlan\n##############################\n\n");
        printf("1 - Cadastrar materias\n");
        printf("2 - Listar materias\n");
        printf("3 - Cadastrar tarefas\n");
        printf("4 - Listar tarefas\n");
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
                scanf(" %[^\n]", tarefas[quantidadesTarefas]);

            printf("Digite a materia: ");
                scanf(" %[^\n]", tarefasMaterias[quantidadesTarefas]); quantidadesTarefas++;
            printf("Tarefa cadastrada!\n");
        break;

        case 4: 
            printf("\n\n###### TAREFAS ######\n");

            for(int i = 0; i < quantidadesTarefas; i++) {
                printf("%d.%s.[%s]\n", i + 1, tarefas[i], tarefasMaterias[i]);
        } 
        break;
        
        case 0:
            printf("\nSaindo...\n");   
        break;


        default:
            printf("Opcao invalida!\n\n");

    
        }
        if (opcao != 0) {
            printf("\nPressione Enter Se Quiser Continuar.");
            limparBuffer();
            getchar(); 
    }
    } while (opcao != 0);



    return 0;
}