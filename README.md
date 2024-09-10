# Sistema de cadastro
Este projeto foi desenvolvido para gerenciar os cadastros dos clientes de uma empresa.
Além disso, foi desenvolvido para eu poder treinar alguns conceitos recentes, como: 
- Ponteiros
- Structs
- Dominio de lists
- Leitura e escrita em arquivos

## Estruturas de Pastas
- /output         --> Pasta de saida da compilação
  - DB.csv        --> Arquivo representando a base de dados
  - main.exe      --> Arquivo principal, com todas as funcionalidades
  - leitura.exe   --> Arquivo apenas com a funcionalidade de leitura do DB
- main.c          --> Código fonte do main.exe
- leitura.c       --> Código fonte de leitura.exe

## Rodando o Projeto na sua máquina
Clone o repositório
```bash
git clone https://github.com/PLorazx1/Sistema-de-cadastro-em-C.git
```
Execute o main.exe
```bash
./output/main.exe
```

## Funcionalidades
- **Ler o DB.csv**: O sistema é capaz de ler o arquivo CSV e transformar em dados dentro da Struct.
- **Criar registros**: O sistema permite criar novos cadastros de clientes.
- **Excluir registros**: O sistema permite excluir cadastros de clientes.
- **Editar registros**: O sistema permite editar qualquer dado de qualquer cadastro a partir do ID do mesmo.
- **Exibir registros**: O sistema é capaz de exibir todos os cadastros salvos na Struct.
- **Escrever no DB.csv**: O sistema é capaz de escrever os dados atualizados da Struct no momento em que encerrar o programa.
