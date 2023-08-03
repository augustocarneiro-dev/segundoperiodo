#include <stdio.h>

struct Livro {
    char titulo[100];
    char autor[100];
    int paginas;
};

struct Biblioteca {
    int num_livros;
    struct Livro livros[10];
};

void lerLivro(struct Livro *livro) {
    printf("Digite o titulo do livro: ");
    scanf(" %[^\n]%*c", livro->titulo);
    printf("Digite o autor do livro: ");
    scanf(" %[^\n]%*c", livro->autor);

    while (1) {
        printf("Digite o numero de paginas do livro: ");
        if (scanf("%d%*c", &livro->paginas) == 1 && livro->paginas >= 0) {
            break;
        } else {
            printf("Numero de paginas invalido. Tente novamente.\n");
            while (getchar() != '\n');
        }
    }
}

void imprimirLivro(struct Livro livro) {
    printf("Titulo: %s, Autor: %s, Numero de Paginas: %d\n", livro.titulo, livro.autor, livro.paginas);
}

void lerBiblioteca(struct Biblioteca *biblioteca) {
    while (1) {
        printf("Digite a quantidade de livros na biblioteca (ate 10): ");
        if (scanf("%d%*c", &biblioteca->num_livros) == 1 && biblioteca->num_livros >= 1 && biblioteca->num_livros <= 10) {
            break;
        } else {
            printf("Quantidade de livros invalida. Deve estar entre 1 e 10. Tente novamente.\n");
            while (getchar() != '\n');
        }
    }

    for (int i = 0; i < biblioteca->num_livros; i++) {
        printf("\nLivro %d:\n", i + 1);
        lerLivro(&biblioteca->livros[i]);
    }
}

void imprimirBiblioteca(struct Biblioteca biblioteca) {
    printf("\nBiblioteca:\n");
    for (int i = 0; i < biblioteca.num_livros; i++) {
        printf("Livro %d: ", i + 1);
        imprimirLivro(biblioteca.livros[i]);
    }
}

void imprimirLivroComMaisPaginas(struct Biblioteca biblioteca) {
    int indice_mais_paginas = 0;
    for (int i = 1; i < biblioteca.num_livros; i++) {
        if (biblioteca.livros[i].paginas > biblioteca.livros[indice_mais_paginas].paginas) {
            indice_mais_paginas = i;
        }
    }
    printf("\nLivro com maior numero de paginas:\n");
    imprimirLivro(biblioteca.livros[indice_mais_paginas]);
}

int main() {
    struct Biblioteca biblioteca;
    lerBiblioteca(&biblioteca);
    imprimirBiblioteca(biblioteca);
    imprimirLivroComMaisPaginas(biblioteca);
    return 0;
} 
