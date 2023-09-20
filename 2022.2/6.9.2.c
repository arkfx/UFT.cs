#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int i = 1;
float TmediaR = 0;
int alertaPhA8 = 0;
int alertaTA110 = 0;
int temperaturaMA95 = 0;
int alertaGeral = 0;
int keep = 0;

typedef struct {
    float temperatura;
} Mhora;

typedef struct {
    Mhora Mhoras[25];
    float ph;
} Mdia;


typedef struct {
    Mdia Mdias[365];
} Sano;

Sano Manos[10];

void Tmedia() {
    TmediaR = 0;
    float Tsoma = 0;

    for (int m = 1; m <= 24; m++) {
        Tsoma += Mdias[i].Mhoras[m].temperatura;
    }
    TmediaR = Tsoma / 24;
}

int main() {
    do {
        printf("PH: ");
        scanf(" %f", &Mdias[i].ph);

        if (Mdias[i].ph < 6 || Mdias[i].ph > 8) {
            printf("---ALERTA: PH FORA DO DESEJAVEL---");
            printf("\n");
            alertaGeral++;

            if (Mdias[i].ph > 8)
                alertaPhA8++;
        }

        for (int t = 1; t <= 24; t++) {
            printf("\n");
            printf("HORA:");
            printf(" %d", t);
            printf("\n");
            printf("Temperatura: ");
            float readTemp = 0;
            scanf("%f", &readTemp);
            Mdias[i].Mhoras[t].temperatura = readTemp;
            printf("\n");

            if (Mdias[i].Mhoras[t].temperatura > 90 && Mdias[i].Mhoras[t].temperatura <= 110) {
                printf("solicitação de resfriamento");
            }
            if (Mdias[i].Mhoras[t].temperatura > 110) {
                printf("---ALERTA: TEMPERATURA MAIOR QUE 110C---");
                alertaGeral++;
                alertaTA110++;
            }
        }

        printf("Temperatura media: ");
        Tmedia();
        printf("%f", TmediaR);
        printf("\n");

        if (TmediaR > 95) {
            temperaturaMA95++;
        }

        printf("deseja continuar ? (1 para sim, qualquer outro numero para nao): ");
        scanf(" %d", &keep);
        if (keep == 1) {
            i++;
        }
    } while (keep == 1);

    int c = 0;
    printf("deseja consultar um dia ?");
    scanf(" %d", &c);
    if(c == 1){
        int d = 0;
        printf("qual dia deseja consultar ?");
        scanf(" %d", &d);
        printf("PH: ");
        printf("%f", Mdias[d].ph);
        printf("\n");
        printf("Temperaturas: ");
        for(int h = 1; h <= 24; h++){
            printf("%f", Mdias[d].Mhoras[h].temperatura);
            printf("\n");

        }

    }

    printf("dias: ");
    printf("%d", i);
    printf("\n");

    printf("alertas por PH>8: ");
    printf("%d", alertaPhA8);
    printf("\n");

    printf("Alertas por temperatura > 110C: ");
    printf("%d", alertaTA110);
    printf("\n");

    printf("dias com temperatura media acima de 95C: ");
    printf("%d", temperaturaMA95);
    printf("\n");

    if (alertaGeral == 0) {
        printf("\n");
        printf("---APROVADO---");
    }

    return 0;
}
