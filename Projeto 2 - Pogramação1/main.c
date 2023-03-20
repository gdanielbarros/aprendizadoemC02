#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct main{
    int dateRegistre, Cidade, Estado, novosCasos;
    struct main *proximo;
};

//Converte numeros de computador em data pra humano ler :)
char *ConvertDate(int tempo){
    time_t epoch_time = tempo;
    struct tm *tm_info = localtime(&epoch_time);
    char *data = calloc(20,sizeof(char)); // alocação na memoria 
    strftime(data, 20, "%d/%m/%Y",tm_info);
    return data;
}

// Escreve todos os main
void registrar(struct main *start){ 
    struct main *noCurrent = start;
    FILE *novoArquivo = fopen("historicoCargas.csv", "w");

    if(novoArquivo != NULL)
    {
        //printf("Arquivo copiado com sucesso!");
        while(noCurrent != NULL)
        {
            if (noCurrent->proximo != NULL){
                fprintf(novoArquivo, "%d;%d;%d;%d\n",noCurrent->Cidade,noCurrent->Estado,noCurrent->novosCasos, noCurrent->dateRegistre);
            }else{
                fprintf(novoArquivo, "%d;%d;%d;%d",noCurrent->Cidade,noCurrent->Estado,noCurrent->novosCasos, noCurrent->dateRegistre);
            }
            noCurrent = noCurrent->proximo;
        }
    }
    else
    {
        //printf("Nao foi possível abrir arquivo");
    }
    fclose(novoArquivo);
}

int verificarIguais(int cidade, int estado, struct main *start){
    struct main *noCurrent = start;

    while (noCurrent != NULL){
        if (noCurrent->Estado == estado){
            if (noCurrent->Cidade == cidade){
                return 1;
            }
        }
            noCurrent = noCurrent->proximo;
    }
    return 0;
}

int manipularmain(char nomeArquivo[], struct main **cabeca, struct main **rabo, struct main *cabecaLista) {
    FILE *pontArquivos = fopen(nomeArquivo, "r");

    if (pontArquivos != NULL) {
        while (!feof(pontArquivos)) {
            int campo1, campo2, campo3, campo4;
            fscanf(pontArquivos, "%d;%d;%d;%d", &campo1, &campo2, &campo3, &campo4);

            int data = campo1, codigoCidade = campo2, codigoEstado = campo3, registronovosCasos = campo4;

            if (verificarIguais(codigoCidade,codigoEstado,cabecaLista) == 1){
                struct main *noCurrent = cabecaLista;
                while (noCurrent != NULL){
                    if (noCurrent->Estado == codigoEstado){
                        if (noCurrent->Cidade == codigoCidade){
                            noCurrent->novosCasos += registronovosCasos;
                            if (data > noCurrent->dateRegistre){
                                noCurrent->dateRegistre = data;
                            }
                        }
                        noCurrent = noCurrent->proximo;
                    }else{
                        noCurrent = noCurrent->proximo;
                    }
                }
            }else{
                struct main *novoNo = malloc(sizeof(struct main));
                novoNo->dateRegistre = data;
                novoNo->Cidade = codigoCidade;
                novoNo->Estado = codigoEstado;
                novoNo->novosCasos = registronovosCasos;
                novoNo->proximo = NULL;
                if (*cabeca == NULL) {
                    *cabeca = novoNo;
                    *rabo = novoNo;
                } else {
                    (*rabo)->proximo = novoNo;
                    *rabo = novoNo;
                }
            }
        }
    } else {
        return 0;
    }
    fclose(pontArquivos);
    return 1;
}

// relatorio estadual e verificação 
void imprimir(int entrada){
    FILE *arquivoPronto = fopen("arquivoConsolidado.csv", "r");
    int somaGeral = 0;

    if (arquivoPronto != NULL) {
        while (!feof(arquivoPronto)) {
            int campo1,campo2,campo3,campo4;
            fscanf(arquivoPronto, "%d;%d;%d;%d", &campo1, &campo2, &campo3, &campo4);
            if (campo2 == entrada){
                somaGeral += campo3;
            }
        }
        printf("____________Relatorio Estadual____________\n");
        printf("Codigo Estado %d\n", entrada);
        printf("Total de novosCasos no estado: %d novosCasos\n",somaGeral);
        printf("main por cidade:\n");
        printf("\n");
        printf("CIDADE \t QTD novosCasos \t ULTIMA ATUALIZACAO\n");
        printf("--------------------------------------\n");

        rewind(arquivoPronto);
        while (!feof(arquivoPronto)) {
            int campo1,campo2,campo3,campo4;
            fscanf(arquivoPronto, "%d;%d;%d;%d", &campo1, &campo2, &campo3, &campo4);
            if (campo2 == entrada){
                char *data = ConvertDate(campo4);
                printf("%5d %9d \t %s\n", campo1, campo3, data);
                free(data);
            }
        }

    } else {
        puts("main inexistentes !\n");
    }
    printf("\n");
    fclose(arquivoPronto);
}

void imprimirLista(struct main *start){
    struct main *NoCurrentnoCurrent = start;

    //caminha ate o final
    while (NoCurrentnoCurrent != NULL){
        printf("%d  %d  %d  %d\n", NoCurrentnoCurrent->Cidade, NoCurrentnoCurrent->Estado, NoCurrentnoCurrent->novosCasos, NoCurrentnoCurrent->dateRegistre);
        NoCurrentnoCurrent = NoCurrentnoCurrent->proximo;
    }
}

void exibirMenu() {
    int opcao;
    int entradaSeg;
    char nomeArquivo[50];
    struct main *cabeca = NULL, *rabo = NULL;

    do {
        printf("___________Sistema de Dados Consolidados__________\n\n \
                1 - Fazer carga de arquivos\n \
                2 - Imprimir Relatorio por Estado\n \
                0 - Sair\n \
                Digite sua opção\n:");

        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite o nome do arquivo a ser adicionado: ");
                scanf("%s",nomeArquivo);
                manipularmain(nomeArquivo, &cabeca,&rabo,cabeca);
                //consolidarmain(cabeca);
                (cabeca);
                if(manipularmain(nomeArquivo,&cabeca, &rabo,cabeca) != 0){
                    printf("Arquivo copiado com sucesso !\n\n");
                }else{
                    printf("Arquivo não copiado !\n\n");
                }

                break;
            case 2:
                printf("DIGTE O CODIGO DO ESTADO :\n");
                scanf("%i",&entradaSeg);
                imprimir(entradaSeg);
                break;
            case 3:
                printf("Você selecionou a opção 3.\n");
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while(opcao != 4);
}

int main(){
    struct main *cabeca = NULL, *rabo = NULL;

    //exibirMenu();

    //manipularmain("cargaUF2.csv", &cabeca, &rabo, cabeca);
    //manipularmain("cargaUF4.csv", &cabeca, &rabo);
    //manipularmain("cargaUF10.csv", &cabeca, &rabo);
    //manipularmain("cargaUF12.csv", &cabeca, &rabo);
    //manipularmain("cargaUF13.csv", &cabeca, &rabo);
    manipularmain("cargaUF5.csv", &cabeca, &rabo,cabeca);
    //manipularmain("cargaUF16.csv", &cabeca, &rabo,cabeca);
    //manipularmain("cargaUF22.csv", &cabeca, &rabo);
    imprimirLista(cabeca);

    //consolidarmain(cabeca);
    //imprimir(2);
    return 0;
}