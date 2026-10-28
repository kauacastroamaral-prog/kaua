#include <stdio.h>
#include <math.h>




void calculadora (){

float n1;
float n2;
float resultado;
char operador;
int b;

printf ("===== CALCULADORA =====\n");
printf ("Digite a operação inteira:");
scanf ( "%f %c %f" , &n1 ,  &operador ,  &n2 );


if (operador == '+'){
    resultado = n1 + n2;
 
}

else if (operador == '-')
{

    resultado = n1 - n2;

}

else  if ( operador == '*')
{
    resultado = n1 * n2;
}
 else  if (operador == '/')
 {
    resultado == n1 / n2;
 }

else  {

    printf ("operador invalido");
    return 0;
}
  printf ("Resultado: %.2f\n" , resultado);
  

 printf ("Digite 1 se voçê quer fazer outro calculo ou 2 se não quiser:");
 scanf (" %d", &b );
 
 if (b == 1){
    
     calculadora ();
 }
 
 else{

    printf ("Obrigado por usar o nosso sistema!");
 }
}