#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct de cadastro
typedef struct {
    char nome[30];
    char email[30];
    int idade;
} Cadastro;

//função de erro da leitura do DB
int ErroDB() {
    printf("Erro ao ler o 'banco de dados'\nEncerrando programa...");
    exit(1);
}

//Codigo com sscanf - Mais limpo:
int leitura3(Cadastro *clientes){
    //abertura do arquivo csv
    FILE *DB = fopen("db.csv", "r");
    if(DB == NULL) {
        ErroDB();
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
            ErroDB();
        }
        total++;
    }
    fclose(DB);
    return total;
}

//Codigo sem usar sscanf - Não conhecia ainda:
int leitura2(Cadastro *clientes){
    //abertura do arquivo csv
    FILE *DB = fopen("db.csv", "r");
    if(DB == NULL) {
        ErroDB();
    }
    //declaração das variaveis:
    char linha[150], idade[3];
    int i, j, total = 0;
    int Is_first = 1;
    while (fgets(linha, sizeof(linha), DB)) { //loop para ler cada linha
        if(Is_first){ //verifica se é o cabeçalho
            Is_first = 0;
            continue;
        }
        for(j=0, i=0; linha[i] != ','; i++, j++){ //lê item por item até a virgula - Nome
            clientes[total].nome[j] = linha[i];
        }
        clientes[total].nome[j] = '\0'; //finaliza nome
        i++;
        for(j=0; linha[i] != ','; i++, j++){ //lê item por item até a virgula - Email
            clientes[total].email[j] = linha[i];
        }
        clientes[total].email[j] = '\0'; //finaliza email
        i++;
        for(j=0; linha[i] != '\n'; i++, j++){ //lê item por item até o fim da linha - Idade
            idade[j] = linha[i];
        }
        clientes[total].idade = atoi(idade); //transforma idade em int
        total++;
    }
    fclose(DB);
    return total;
}

int main(){ //declaração das variaveis
    Cadastro clientes[100];
    int total = leitura3(clientes); //variavel que aponta para o proximo da lista da struct
    //loop para imprimir os cadastros:
    for(int i=0; i<total; i++){
        printf("ID do cliente: %d\nNome: %s\nEmail: %s\nIdade: %d\n\n", i, clientes[i].nome, clientes[i].email, clientes[i].idade);
    }
    system("pause");
    return 0;
}