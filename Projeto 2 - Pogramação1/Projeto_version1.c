#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Projeto_version1 {
    int dateRegistre, Cidade, Estado, novosCasosEstado;
    struct Projeto_version1 *proximo;
};

/* convertendo este monte de número desorganizado em data para os seres humanos lerem */
char *transDate(int time) {
    time_t epoch = time;
    struct tm *tm_info = localtime(&epoch);
    char *data = calloc(20, sizeof(char));
    strftime(data, 20, "%d/%m/%Y", tm_info);
    return data;
}

/* registrando = criar histórico de arquivo */
void registra(struct Projeto_version1 *home) {
    struct Projeto_version1 *noActual = home;
    FILE *arqNovo = fopen("historico_Cargas.csv", "w");

    if (arqNovo != NULL) {
        while (noActual != NULL) {
            fprintf(arqNovo, "%d - %d - %d - %d\n", noActual->dateRegistre, noActual->Cidade,
                noActual->Estado, noActual->novosCasosEstado);
            noActual = noActual->proximo;
        }
    } else {
        printf("Não foi possível abrir o arquivo.\n");
    }
    fclose(arqNovo);
}

/* verifica se a cidade e estado já foram adicionados à lista */
int verificaDadosDeCidades(int cidade, int estado, struct Projeto_version1 *home) {
    struct Projeto_version1 *noActual = home;

    while (noActual != NULL) {
        if (noActual->Estado == estado && noActual->Cidade == cidade) {
            return 1;
        }
        noActual = noActual->proximo;
    }
    return 0;
}

/* recebe um nome de arquivo e modifica os dados */
int modificaDados(char arqNovo[], struct Projeto_version1 **cDados,
                  struct Projeto_version1 **rDados, struct Projeto_version1 **kabListaCidades) {
    FILE *arquivo = fopen(arqNovo, "r");

    if (arquivo != NULL){
        while (!feof(arquivo)){
            int data, cidade, estado, novosCasosEstado;
            fscanf(arquivo, "%d - %d - %d - %d\n", &data, &cidade, &estado, &novosCasosEstado);

            /* lado esquerdo novas variáveis */
            int dataBase = data;
            int cCidade = cidade;
            int cEstado = estado;
            int cNovos = novosCasosEstado;

            /* verifica se a cidade já foi adicionada à lista de cidades e renova os dados da cidade */
            if (verificaDadosDeCidades(cCidade, cEstado, *kabListaCidades)) {
                struct Projeto_version1 *noActual = *kabListaCidades;
                while (noActual != NULL) {
                    if (noActual->Estado == cEstado && noActual->Cidade == cCidade) {
                        noActual->novosCasosEstado += cNovos;
                        if (dataBase > noActual->dateRegistre) {
                            noActual->dateRegistre = data;
                        }
                    }
                    noActual = noActual->proximo;
                }
            }
        }
    }
            /* se a cidade ainda não foi adicionada à lista de cidades, adicione uma nova entrada na lista de

/*Recebe um nome de arquivo(...)*/
int modificaDados(char arqNovo[], struct Projeto_version1 ** cDados, struct Projeto_version1 **rDados, struct Projeto_version1 ** kabListaCidades){
    FILE *arqui = fopen(arqui, "r");

    //verificação
    if (arqui != NULL){
        while (!feof(arqui))
        {
            int data, Cidade, Estado, novosCasosEstado;
            fscanf(arqui, "%d - %d - %d - %d\n", &data, &Cidade, &Estado, &novosCasosEstado);

            //*lado esquerdo novas variaveis
            int dataBase = data;
            int cCidade = Cidade;
            int cEstado = Estado;
            int cNovos = novosCasosEstado;

            /*verifica se cidade já foi add à lista de cidades
            Renova os dados da cidade*/
            if (verificaDadosDeCidades(cCidade, cEstado, kabListaCidades) == 1){
                struct Projeto_version1 *noActual = kabListaCidades;
                while (noActual != NULL)
                {
                    if (noActual ->Estado == cEstado){
                        if (noActual ->cCidade == cCidade){
                            noActual ->novosCasosEstado += cNovos;
                            if (dataBase > noActual ->dateRegistre){
                                noActual ->dateRegistre = data;
                            }
                        }
                        noActual = noActual ->proximo;
                    }
                    else {
                        noActual = noActual ->proximo;
                    }
                }
                
            }
            /*VERIFICAÇÃO 2 - Se cidade ainda não foi adicionada à lista de cidades, 
            add uma nova entrada na lista de dados*/
            else{
                struct Projeto_version1 *noNovo = malloc(sizeof(struct Projeto_version1));
                noNovo ->dateRegistre = data;
                noNovo ->Cidade = cCidade;
                noNovo ->Estado = cEstado;
                noNovo ->novosCasosEstado = cNovos;
                noNovo ->proximo = NULL;
                if (*rDados == NULL){
                    *cDados = noNovo;
                    *rDados = noNovo;
                }
                else{
                    (*rDados)->proximo = noNovo;
                    *rDados = noNovo;
                }
            }
        
        }
        
    }
    else{
        return 0; // fim da verificação
    }
    //fecha o arquivo
    fclose(arqui);
    return 1;
}
// fim de função modifica dados


void entrada(int entradadeUsuario){
    FILE *arquivo = fopen("arquivosConsolidado.csv","r");
    int total = 0;

    if (arquivo != NULL){
        while (!feof(arquivo))
        {
            int esp1, esp2, esp3, esp4;
            fscanf(arquivo, "%d - %d - %d - %d", &esp1, &esp2, &esp3, &esp4);
            if (esp2 == entradadeUsuario){
                total += esp3;
            }
        }
        printf("_________Relatorio Estadual__________\n");
        printf("Codigo do Estado %d\n Total de casos no estado: %d\n Por cidade: %d\n", entradadeUsuario, total);
        printf("\n\n Cidade \t Quantidade de Casos \t Ultima atualização\n");
        printf("__________________________________________________________");

        rewind(arquivo);
        while (!feof(arquivo))
        {
            int esp1, esp2, esp3, esp4;
            fscanf(arquivo, "%d - %d - %d - %d", &esp1, &esp2, &esp3, &esp4);
            //verificação
            if (esp2 == entradadeUsuario){
                char *data = transDate(esp4);
                printf("%5d %9d \t %s\n", esp1, esp3, data);
                free(data);
            }
        }
        
    } else{
        puts("Infomrações não existem\n");
    }
    printf("____________________________");
    fclose(arquivo);
}

void listaPrint(struct Projeto_version1 *home){
    struct Projeto_version1 *noActual = home;

    //while caminha até final
    while (noActual != NULL)
    {
        printf("%d %d %d %d\n", noActual ->Cidade, noActual ->Estado, noActual ->cNovos,
        noActual ->dateRegistre);
        noActual = noActual ->proximo;
    }  
}

void exibirMenu() {
    int opcao, entrada;
    char arquivoEnter[50];
    struct Projeto_version1 *percLider = NULL, *percUltimo = NULL;

    do {
        printf("\n\n1 - Fazer carga de arquivos\n2 - Exibir relatório por Estado\n0 - Sair\nDigite sua opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Nome do arquivo que será adicionado (coloque todo nome.csv, exemplo: arquivo.csv): ");
                scanf("%s", arquivoEnter);
                
                if (modificaDados(arquivoEnter, &percLider, &percUltimo, percLider) != 0) {
                    printf("Arquivo carregado com sucesso\n\n");
                } else {
                    printf("Erro ao carregar arquivo\n\n");
                }
                
                break;

            case 2:
                printf("Qual o código do Estado: ");
                scanf("%d", &entrada);

                if (entrada < 1 || entrada > 27) {
                    printf("Código de Estado inválido\n\n");
                    break;
                }

                printf("Relatório do Estado %d:\n", entrada);
                imprimirPorEstado(entrada, percLider);
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida. Por favor, escolha uma opção válida.\n");
                break;
        }
    } while (opcao != 0);
}


int principal(){
    struct Projeto_version1 *percLider = NULL, *percUltimo = NULL;
    exibirMenu();

    modificaDados("cargaUF3.csv", &percLider, &percUltimo, percLider);
    modificaDados("cargaUF4.csv", &percLider, &percUltimo);
    modificaDados("cargaUF5.csv", &percLider, &percUltimo);
    modificaDados("cargaUF6.csv", &percLider, &percUltimo);
    modificaDados("cargaUF7.csv", &percLider, &percUltimo);
    modificaDados("cargaUF8.csv", &percLider, &percUltimo, percLider);
    modificaDados("cargaUF9.csv", &percLider, &percUltimo);
    imprimirPorEstado(percLider);
    entrada(2);
    return 0;
}