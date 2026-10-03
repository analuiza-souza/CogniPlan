#include <stdio.h>

#define MAX 50

typedef struct {
    char nome[50];
    char materia[50];
    char prazo[20];
} Tarefa;


void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


int main() {

    char materias[MAX][50];
    int quantidadeMaterias = 0;

    Tarefa tarefas[MAX];
    int quantidadeTarefas = 0;

    int opcao;


    do {

        printf("\n\n##############################\n");
        printf("CogniPlan\n");
        printf("##############################\n\n");

        printf("1 - Cadastrar materias\n");
        printf("2 - Listar materias\n");
        printf("3 - Cadastrar tarefas\n");
        printf("4 - Listar tarefas\n");
        printf("5 - Editar tarefas\n");
        printf("6 - Excluir tarefas\n");
        printf("7 - Adicionar prazos\n");
        printf("0 - Sair\n");

        printf("Escolha: ");
        scanf("%d", &opcao);


        switch (opcao) {

            case 1:

                if (quantidadeMaterias >= MAX) {
                    printf("\nLimite de materias atingido!\n");
                    break;
                }

                printf("Digite o nome da materia: ");
                scanf(" %[^\n]", materias[quantidadeMaterias]);

                quantidadeMaterias++;

                printf("\nMateria cadastrada!\n\n");

            break;


            case 2:

                printf("\n\n###### MATERIAS ######\n");

                if (quantidadeMaterias == 0) {
                    printf("Nenhuma materia cadastrada.\n");
                }

                for (int i = 0; i < quantidadeMaterias; i++) {
                    printf("%d. %s\n", i + 1, materias[i]);
                }

            break;


            case 3:

                if (quantidadeTarefas >= MAX) {
                    printf("\nLimite de tarefas atingido!\n");
                    break;
                }

                printf("Digite a tarefa: ");
                scanf(" %[^\n]", tarefas[quantidadeTarefas].nome);

                printf("Digite a materia: ");
                scanf(" %[^\n]", tarefas[quantidadeTarefas].materia);

                /* Prazo inicial */
                sprintf(
                    tarefas[quantidadeTarefas].prazo,
                    "Nao definido"
                );

                quantidadeTarefas++;

                printf("Tarefa cadastrada!\n");

            break;


            case 4:

                printf("\n\n###### TAREFAS ######\n");

                if (quantidadeTarefas == 0) {
                    printf("Nenhuma tarefa cadastrada.\n");
                }

                for (int i = 0; i < quantidadeTarefas; i++) {

                    printf(
                        "%d. %s [%s] - Prazo: %s\n",
                        i + 1,
                        tarefas[i].nome,
                        tarefas[i].materia,
                        tarefas[i].prazo
                    );
                }

            break;


            case 5: {

                int tarefaEditar;

                if (quantidadeTarefas == 0) {
                    printf("\nNao existem tarefas cadastradas!\n");
                    break;
                }

                printf("\n\n###### TAREFAS ######\n");

                for (int i = 0; i < quantidadeTarefas; i++) {

                    printf(
                        "%d. %s [%s] - Prazo: %s\n",
                        i + 1,
                        tarefas[i].nome,
                        tarefas[i].materia,
                        tarefas[i].prazo
                    );
                }

                printf("\nDigite o numero da tarefa que deseja editar: ");
                scanf("%d", &tarefaEditar);

                if (tarefaEditar < 1 || tarefaEditar > quantidadeTarefas) {
                    printf("\nTarefa invalida!\n");
                    break;
                }

                tarefaEditar--;

                printf("\nDigite o novo nome da tarefa: ");
                scanf(" %[^\n]", tarefas[tarefaEditar].nome);

                printf("Digite a nova materia: ");
                scanf(" %[^\n]", tarefas[tarefaEditar].materia);

                printf("\nTarefa editada com sucesso!\n");

            }

            break;


            case 6: {

                int tarefaExcluir;

                if (quantidadeTarefas == 0) {
                    printf("\nNao existem tarefas cadastradas!\n");
                    break;
                }

                printf("\n\n###### TAREFAS ######\n");

                for (int i = 0; i < quantidadeTarefas; i++) {

                    printf(
                        "%d. %s [%s] - Prazo: %s\n",
                        i + 1,
                        tarefas[i].nome,
                        tarefas[i].materia,
                        tarefas[i].prazo
                    );
                }

                printf("\nDigite o numero da tarefa que deseja excluir: ");
                scanf("%d", &tarefaExcluir);

                if (tarefaExcluir < 1 || tarefaExcluir > quantidadeTarefas) {
                    printf("\nTarefa invalida!\n");
                    break;
                }

                tarefaExcluir--;

                /*
                    Move as tarefas seguintes uma posição para trás.
                */

                for (int i = tarefaExcluir; i < quantidadeTarefas - 1; i++) {
                    tarefas[i] = tarefas[i + 1];
                }

                quantidadeTarefas--;

                printf("\nTarefa excluida com sucesso!\n");

            }

            break;


            case 7: {

                int tarefaPrazo;

                if (quantidadeTarefas == 0) {
                    printf("\nNao existem tarefas cadastradas!\n");
                    break;
                }

                printf("\n\n###### TAREFAS ######\n");

                for (int i = 0; i < quantidadeTarefas; i++) {

                    printf(
                        "%d. %s [%s] - Prazo: %s\n",
                        i + 1,
                        tarefas[i].nome,
                        tarefas[i].materia,
                        tarefas[i].prazo
                    );
                }

                printf(
                    "\nDigite o numero da tarefa que deseja adicionar um prazo: "
                );

                scanf("%d", &tarefaPrazo);

                if (tarefaPrazo < 1 || tarefaPrazo > quantidadeTarefas) {
                    printf("\nTarefa invalida!\n");
                    break;
                }

                tarefaPrazo--;

                printf("Digite o prazo (DD/MM/AAAA): ");
                scanf(" %[^\n]", tarefas[tarefaPrazo].prazo);

                printf("\nPrazo adicionado com sucesso!\n");

            }

            break;


            case 0:

                printf("\nSaindo...\n");

            break;


            default:

                printf("\nOpcao invalida!\n");

        }


        if (opcao != 0) {

            printf("\nPressione Enter Se Quiser Continuar.");

            limparBuffer();

            getchar();
        }


    } while (opcao != 0);


    return 0;
}
