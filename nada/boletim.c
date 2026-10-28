#include <stdio.h>

void boletim (){

char nome[50];
float nota1; 
float nota2; 
float nota3;
float nota4;
float nota5;
float media;


printf ("Escreva o nome do aluno:");
scanf ( "%s", nome);

printf ("Nota da primeira prova:");
scanf ("%f", &nota1);

printf ("Nota da segunda prova:");
scanf ("%f", &nota2);

printf ("Nota da terceira prova:");
scanf ("%f", &nota3);

printf ("Nota da quarta prova:");
scanf ("%f", &nota4);

printf ("Nota da quinta prova:");
scanf ("%f", &nota5);


media =(nota1 + nota2 + nota3 + nota4 + nota5) /5;




printf ("\n----- BOLETIM -----\n");
printf ("Nome: %s\n", nome);
printf("Nota 1: %.2f\n", nota1);
printf("Nota 2: %.2f\n", nota2);
printf("Nota 3: %.2f\n", nota3);
printf("Nota 4: %.2f\n", nota4);
printf("Nota 5: %.2f\n", nota5);
printf ("Media: %.2f\n", media);

if (media >=7)
{
    printf ("Aluno %s Aprovado", nome);
}

if(media >= 5 && media <7)
{
   printf("Aluno %S esta Recuperação", nome);

}
if (media  < 5)
 {
    printf("Aluno %s Reprovado", nome);
 }


}