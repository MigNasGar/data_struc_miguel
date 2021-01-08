/*##############################
# Exercício ED 2
# Autor: Miguel Antonio do Nascimento Garcia
# Data: 07/01/2021
#  Cria um programa que solicita ao usuário a entrada de um nome e faça a pesquisa no arquivo
#  e retorne alguns dados do registro
#################################*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <cadastro.h>

int main() {
  char name[MAXSTR];
  char *p;

    printf("\nDigite um nome: ");
    fgets(name, MAXSTR, stdin);

    for(p=name; *p!='\n' && *p!='\0'; p++);
    *p = '\0';

    busca(name);
}

int busca(char *name){
  FILE *dados, *indice;
  IndCad registro;
  char namebusca[MAXSTR], *p;
  char line[MAXLIN];

  IndCad *encontrados;
  IndCad *espextr;

  int cont=0;
  int limt=100;

  encontrados = malloc(limt * sizeof(IndCad));

  p=namebusca;
  strcpy(namebusca, name);
  while (*p != '\0'){
    *p = toupper(*p);
    p++;
  }

  indice = fopen(INDICE, "r");

  while (1){
    fread (&registro, sizeof(registro), 1, indice);
    if (feof(indice)) break;

    if (strstr(registro.name, namebusca)){
        strcpy(encontrados[cont].name, registro.name);
        encontrados[cont].localiza = registro.localiza;
        cont++;

    if (cont>limt){
      limt = cont+100;
      espextr = malloc(limt * sizeof(IndCad));
      memcpy(espextr, encontrados, cont * sizeof(IndCad));
      free(encontrados);
      encontrados = espextr;
    }
  }
}

  printf("\n%d registros encontrados.\n", cont);

  fclose(indice);
  dados = fopen(DADOS, "r");

  for (int i=0; i<cont; i++){
    fseek(dados, encontrados[i].localiza, 0);
    fgets(line, MAXLIN, dados);

    printf("Nome: %s\n", encontrados[i].name);
    extrai(linha, DESCRICAO_CARGO, dado);
    printf("Cargo: %s\n", dado);
    extrai(linha, UORG_LOTACAO, dado);
    printf("UORG Lotação: %s\n", dado);
  }

}
