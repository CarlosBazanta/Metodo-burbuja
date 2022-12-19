#include <stdio.h> 
#include <math.h>
#include <conio.h>
#include <stdlib.h>

void clearBuf(void);
int validFormat(const char*, void*);
int validar=1;

int main(){

int valor[10],suma,aux; //se declaran las variables
int a,b,i;

suma=0;

for(a=0;a<=9;a++){
	
	verificacion: //marca un punto en el programa para poder retornar a el
				
		do{//empieza un ciclo para reiniciar en caso de que una opcion este mala
				printf("Ingrese el valor %i = ",a+1);			
				if(validFormat("%i",&valor[a])) continue; //validformat nos sirve para ingresar los datos y validarlos
			
				validar=valor[a]<-999999;//valida la opcion y si es menor saltara un error
			
				if(validar){//if que sirve para imprimir en pantalla el error
				
					printf("\n\nIngreso un numero invalido\n");
					printf("No se aceptan numeros menores o iguales 0\n\n"); //imprime en pantalla el error
			
				}
		}while(validar); //que retorna despues de mostrar el error
			
		if(valor[a]>=999999){ //if que sirve para imprimir en pantalla el error de numeros muy grandes
				
			printf("\n\nIngreso un numero demasiado alto o invalido\n");
			printf("Ingrese una opcion valida\n\n"); //imprime en pantalla el error
			
			goto verificacion; //da la orden para que el programa vaya a un punto de este
				
		}

}
for(a=0;a<=9;a++){
	
	for(b=0;b<=8;b++){
		
		if(valor[b]<valor[b+1]){
			
			aux=valor[b];
			valor[b]=valor[b+1];
			valor[b+1]=aux;
			
		}
	}
}

for(a=0;a<=9;a++){
	
	suma=suma+valor[a];
	
}
for(i=0;i<10;i++){
	
printf("\n\tEste es su valor ordenado de mayor a menor = %i\n",valor[i]);

}

printf("Resultado de la suma total %i",suma);


getch();	
}
int validFormat(const char* formato, void* variable){ /* Esto es para verificar variables */
	
	validar=1;//reseteamos la comprobacion de la opcion
    /* si se retorna 0 fue porque ocurrio un error*/
    
    if(!scanf(formato, variable) || (getchar() != '\n'))
    {
        
        clearBuf();/* Se utiliza para limpiar el buffer */
        
        printf("\n\n\tError\n\n");
        printf("\n\tUsted Ingreso una opcion no valida\n"); /* Se imprime en pantalla el error */
        printf("\n\tPor favor ingrese una opcion valida\n");
        system("pause");
		
        return 1;
    }
    
    return 0;
}

void clearBuf()
{
    int ch;
    /* Se utiliza para limpiar el buffer */
    while((ch = getchar()) != '\n' && ch != EOF);
}

