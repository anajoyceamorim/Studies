#include <stdio.h>

int main() {

    char l; //8 bits, 1 byte 0 ... 255

    /*
    ASCII man ascii
    10 '\n' new line
    13 '\r' return carriage
    8 '\b' backspace
    */

   printf("Oi\n");
   /*
   QUAL É O TIPO DA FUNÇÃO printf?
   é uma função do tipo int e retorna a quant de char impressos
   */

    char a = 65;
    printf("%c\n", a);

    a = 'A';
    printf("%c %c %c \b %c\n", a, a, a, a);

    return 0;
}
