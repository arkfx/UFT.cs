#include <stdio.h>

int main() {
    int i, n, acima = 0;
    float nota[10], media = 0;
    n = 10;
    for (i = 0; i < n; i++) {
        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%f", &nota[i]);
        media += nota[i];
    }
    media /= n; 
    for (i = 0; i < n; i++) {
        if (nota[i] > media) {
            acima++;
        }
    }
    printf("Media da turma: %.2f\n", media);
    printf("Alunos acima da media: %d\n", acima);

    return 0;
}