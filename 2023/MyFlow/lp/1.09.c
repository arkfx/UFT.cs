
#include <stdio.h>
int main (){
float soma = 0, media;
int idade, cont = 0;
char resp;
do {
resp = 'k';
printf("Digite a idade: ");
scanf(" %d", &idade);
soma = soma + idade;
cont = cont + 1;
media = soma/cont;
if(idade >= 18){
    printf("Maior de idade\n\n");
    //printf("%c", resp);
}
else{
    printf("Menor de idade\n\n");
}
while(resp != 's' && resp != 'n' && resp != 'S' && resp != 'N'){
while((getchar())!='\n');
    
printf("Quer continuar? Digite 's' para sim ou 'n' para nao: ");
scanf(" %c", &resp);
}
} while(resp != 'n');
printf("A media das idades e de %.2f\n", media);
}
