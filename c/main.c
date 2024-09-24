#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char nome[50];
    struct no *proximo;
} No;

void addPerson(No **lista);
void removePerson(No **lista);
void searchPerson(No *lista);
int menu(No *lista);
int countVisitors(No *lista);



int main(void) {
    No *lista = NULL; // startar a lista como vazia
    int option;

    while (1) {
        option = menu(lista);
        switch (option) {
            case 1:
                addPerson(&lista);
                break;
            case 2:
                removePerson(&lista);
                break;
            case 3:
                searchPerson(lista);
                break;
            case 4:
                printf("Saindo...\n");
                exit(0);
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
    return 0;
}

int menu(No *lista) {
    int option;
    int total = countVisitors(lista);
    printf("\nMenu:\n");
    printf("Quantidade de visitantes: %d\n", total);
    printf("1. Adicionar Pessoa\n");
    printf("2. Remover Pessoa\n");
    printf("3. Procurar Pessoa\n");
    printf("4. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &option);
    getchar();
    return option;
}

int countVisitors(No *lista) {
    int count = 0;
    No *atual = lista;
    while (atual != NULL) {
        count++;
        atual = atual->proximo;
    }
    return count;
}

void addPerson(No **lista) {
    char visitante[50];
    No *novo = malloc(sizeof(No));

    printf("Digite o nome do visitante: ");
    fgets(visitante, sizeof(visitante), stdin); // fgets ao inves de scanf pq é string
    visitante[strcspn(visitante, "\n")] = '\0';

    if (novo) {
        strcpy(novo->nome, visitante);
        novo->proximo = *lista;
        *lista = novo;
        printf("Pessoa adicionada: %s\n", visitante);
    } else {
        printf("Erro ao alocar memoria\n");
    }
}

void removePerson(No **lista) {
    if (*lista == NULL) {
        printf("A lista está vazia. Nada a remover.\n");
        return;
    }

    char nomeProcurado[50];
    printf("Digite o nome da pessoa que deseja remover: ");
    fgets(nomeProcurado, sizeof(nomeProcurado), stdin);
    nomeProcurado[strcspn(nomeProcurado, "\n")] = '\0';

    No *atual = *lista;
    No *anterior = NULL;

        // percorrer a lista
    while (atual != NULL && strcmp(atual->nome, nomeProcurado) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Pessoa não encontrada.\n");
        return;
    }
        // se for o primeiro da lista
    if (anterior == NULL) {
        *lista = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    printf("Pessoa removida: %s\n", atual->nome);
    free(atual);
}

void searchPerson(No *lista) {
    char nomeProcurado[50];
    printf("Digite o nome a ser procurado: ");
    fgets(nomeProcurado, sizeof(nomeProcurado), stdin);
    nomeProcurado[strcspn(nomeProcurado, "\n")] = '\0';

    No *atual = lista;
    while (atual) {
        if (strcmp(atual->nome, nomeProcurado) == 0) {
            printf("Pessoa encontrada: %s\n", atual->nome);
            return;
        }
        atual = atual->proximo;
    }
    printf("Pessoa não encontrada.\n");
}
