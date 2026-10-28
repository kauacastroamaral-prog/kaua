#include <stdio.h>
#include <math.h>


void banco ()
{
char nome[50];
float saldo = 1000;
float depositar;
float sacar;
char operador;
float resultado;
int i;
int opcao;


printf ("======= Banco Central =======\n");
printf ("Escreva o Senha do Responsavel:\n");
scanf ( "%s", &nome);

printf ("Saldo disponivel : $1.000\n");

 do {
printf ("\n1 - Depositar\n");
printf ("\n2 - Sacar\n");
printf ("\n0 - sair\n");
printf ("\nQual opçaõ deseja?");
scanf ( "%d" , &opcao);

switch (opcao) {

case 1:
 printf ("Deseja depositar qual valor?");
 scanf ( "%f" , &depositar);
 saldo = saldo + depositar;
 printf ("Novo saldo %2.f" , saldo);
break;

case 2 :
printf ("Deseja Sacar qual valor?");
 scanf ( "%f" , &sacar);
 saldo = saldo - sacar;
 printf ("Novo saldo %2.f" , saldo);
 break;

 case 3:
 printf ("Seu saldo é: %2.f\n" , saldo);
 break;

 case 0:
 printf("Saindo...\n");
 break;

 default:
 printf("opcao invalida!\n");
 break;
}
}while (opcao !=0);
 

}

