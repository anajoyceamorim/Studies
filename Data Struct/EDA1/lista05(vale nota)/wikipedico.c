//Questão com problema
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINHAS 100
#define MAX_CARACTERES 100000

typedef struct {
  char caractere;
  int posicao;
} Tag;

int main() {
  int n, i, j;
  char linha[MAX_CARACTERES + 1];
  char texto[MAX_LINHAS * MAX_CARACTERES + 1];
  Tag pilha[MAX_LINHAS];
  int topo = 0;
  char resultado;

  // Leitura da entrada
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s", linha);
    strcat(texto, linha);
    if (i < n - 1) {
      strcat(texto, "\n");
    }
  }

  // Validação das tags
  for (i = 0; texto[i] != '\0'; i++) {
    switch (texto[i]) {
      case '*':
      case '/':
      case '_':
        pilha[topo].caractere = texto[i];
        pilha[topo].posicao = i;
        topo++;
        break;
      default:
        break;
    }

    if (texto[i] == '*' || texto[i] == '/' || texto[i] == '_') {
      if (topo == 0) {
        resultado = 'E';
        goto fim;
      }

      char ultimo_caractere = pilha[topo - 1].caractere;
      int ultima_posicao = pilha[topo - 1].posicao;

      if ((texto[i] == '*' && ultimo_caractere != '*') ||
          (texto[i] == '/' && ultimo_caractere != '/') ||
          (texto[i] == '_' && ultimo_caractere != '_')) {
        resultado = 'E';
        goto fim;
      }

      topo--;
    }
  }

  if (topo != 0) {
    resultado = 'E';
  } else {
    resultado = 'C';
  }

fim:
  // Retorno do resultado
  printf("%c\n", resultado);

  return 0;
}
