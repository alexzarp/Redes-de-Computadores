#include<stdio.h> //printf
#include<string.h> //memset
#include<stdlib.h> //exit(0);
#include<arpa/inet.h>
#include<sys/socket.h>
#include <unistd.h>

char extractor(char *id, char *archive) {
    FILE *arq;
    char Linha[30];
    char *result;
    char wanted[3][30]; // L C
    // system("cls");

    arq = fopen(archive, "r");
    if (arq == NULL) {
        printf("Problemas na abertura do arquivo\n");
        exit(0);
    }
    i = 1;
    while (!feof(arq)){
        // Lê uma linha (inclusive com o '\n')
        result = fgets(Linha, 30, arq);  // o 'fgets' lê até 99 caracteres ou até o '\n'
        if (result) {
            if (Linha[0] == id) {
                char *token = strtok(Linha, ",");
                int i = 0;
                while (token) {
                    wanted[i] = token;
                    i++;
                }
            }
            // printf("Linha %d : %s",i,Linha);
        } else {
            printf("Não foi possível ler a linha do arquivo %s", archive);
            exit(0);
        }
    }
    fclose(arq);

    return wanted;
}

int main () {
    char Linha[30];
    Linha = extractor("roteador.config", "1");
    printf("%s",Linha);
    return 0;
}