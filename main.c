#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//textos que declarei como constantes, para acessar mais facilmente:
const char textInit[] = "Escolha entre as opcoes";
const char Opcoes[] = "1 - Criar cadastro\n2 - Excluir cadastro\n3 - Vizualizar cadastro\n4 - Editar cadastro\n5 - Sair\n";

//criaçao da strtuct
typedef struct {
    char nome[50];
    char email[20];
    int idade;
} Cadastro;

//função de erro da leitura do DB
int ErroDB(int situation) {
    if(situation == 0) printf("Erro ao ler o 'banco de dados'\nEncerrando programa...");
    if(situation == 1) printf("Erro ao escrever no 'banco de dados'\nEncerrando programa...");
    exit(1);
}

//Função para leitura:
int leitura(Cadastro *clientes){
    //abertura do arquivo csv
    FILE *DB = fopen("db.csv", "r");
    if(DB == NULL) {
        ErroDB(0);
    }
    //declaração das variaveis:
    char linha[150];
    int total = 0;
    int Is_first = 1;
    while (fgets(linha, sizeof(linha), DB)) { //loop para ler cada linha
        if(Is_first){ //verifica se é o cabeçalho
            Is_first = 0;
            continue;
        }
        //faz a leitura da linha e o tratamento dos dados:
        int retorno = sscanf(linha, "%29[^,], %29[^,], %d", clientes[total].nome, clientes[total].email, &clientes[total].idade);
        if(retorno != 3){ //trata o erro de tratamentos de dados errados
            ErroDB(0);
        }
        total++;
    }
    fclose(DB);
    return total;
}

int Escrita(Cadastro *clientes, int total){
    FILE *DB = fopen("db.csv", "w");
    if(DB == NULL) {
        ErroDB(1);
    }
    fprintf(DB, "Nome,Email,Idade\n");
    for(int i = 0; i<total; i++){
        fprintf(DB, "%s,%s,%d\n", clientes[i].nome, clientes[i].email, clientes[i].idade);
    }
    fclose(DB);
}

int main() {
    //Declarações de variaveis:
    Cadastro clientes[100];
    int n, i, opcao;
    //Declaração do total e leitura do DB:
    int total = leitura(clientes);

    do{
        printf("%s\n%s", textInit, Opcoes);
        scanf("%d", &opcao);
        system("cls");

        switch (opcao){
            case 1: //cadastro de novo cliente:
                printf("Digite os dados do cliente exatamente na seguinte ordem: nome - email - idade (com enter's entre eles)\n");
                scanf("%s%s%d", &clientes[total].nome, &clientes[total].email, &clientes[total].idade);
                total++;
                printf("Cadastro salvo com sucesso.\n");
                break;
            case 2: //exclusão de cadastro:
                printf("Digite qual cadastro voce quer excluir: ");
                scanf("%d", &i);
                for (n = 0;n < strlen(clientes[i].nome);n++){
                    clientes[i].nome[n] = ' ';
                }
                
                for (n = 0; n < strlen(clientes[i].email);n++){
                    clientes[i].email[n] = ' ';
                }
                
                clientes[i].idade = 0;
                break;
            case 3: //Exibição dos cadastros:
                printf("A seguir, os usuarios cadastrados...\n");
                for(i = 0; i<total; i++){
                    printf("ID do cliente: %d\nNome: %s\nEmail: %s\nIdade: %d\n\n", i, clientes[i].nome, clientes[i].email, clientes[i].idade);
                }
                break; 
            case 4: //Edição de cadastro:
                printf("Qual cadastro voce quer editar?\n");
                scanf("%d", &i);
                printf("Agora digite novamente os dados do cliente exatamente na seguinte ordem: nome - cliente - idade (com enter's entre eles)\n");
                scanf("%s%s%d", &clientes[i].nome, &clientes[i].email, &clientes[i].idade);
                printf("Cadastro editado com sucesso.\n");
                break;
            case 5: //Sair do programa:
                printf("Encerrando programa...\n");
                break;
            default: //Caso de leitura de numero fora do intervalo:
                printf("Numero nao reconhecido.. tente novamente\n");
                break;
        }
        Escrita(clientes, total);
    } while(opcao != 5);

    return 0;
}