#include <stdio.h>

int e_vogal(char c) {
    if (c == 'a' || c == 'A' ||
        c == 'e' || c == 'E' ||
        c == 'i' || c == 'I' ||
        c == 'o' || c == 'O' ||
        c == 'u' || c == 'U')
        return 1;
    else
        return 0;
}

int qtdvogal(char frase[], int *encontro) {
    int qtd = 0;
    int i = 0;
    int qtdencontro = 0;

    while (frase[i] != '\0') {

        // Conta as letras 'o'
        if (frase[i] == 'o' || frase[i] == 'O') {
            qtd++;
        }

        // Verifica se há duas vogais seguidas
        if (e_vogal(frase[i]) && e_vogal(frase[i + 1])) {
            qtdencontro++;
        }

        i++;
    }

    // Passa a quantidade de encontros para a variável original
    *encontro = qtdencontro;

    // Retorna a quantidade de 'o'
    return qtd;
}

int main() {
    char frase[100];
    int encontro;

    printf("Digite uma frase: ");
    fgets(frase, 100, stdin);

    int quantidade_o = qtdvogal(frase, &encontro);

    printf("Quantidade de letras 'o': %d\n", quantidade_o);
    printf("Quantidade de encontros vocalicos: %d\n", encontro);

    return 0;
}
