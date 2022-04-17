/*
 ============================================================================
 Name        : TP_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "funciones.h"

int main(void) {
	setbuf(stdout,NULL);

	char seguir = 'n';

	    float kilometros;
	    float precioAerolineas;
	    float precioLatam;
	    float precioAerolineasDescuento;
	    float precioLatamDescuento;
	    float precioAerolineasInteres;
	    float precioLatamInteres;
	    float precioBitcoinAerolineas;
	    float precioBitcoinLatam;
	    float precioUnitarioAerolineas;
	    float precioUnitarioLatam;

	    int flagKilometros = 0;
	    int flagPrecios = 0;
	    int flagCostosCalculados = 0;


	    do
	    {
	        switch(menu(kilometros, flagKilometros, precioAerolineas, precioLatam, flagPrecios))
	        {
	        case 1:
	            printf("Ingresar kilometros: ");
	            scanf("%f", &kilometros);
	            while(kilometros<1)
	            {
	                printf("Error. Reingresar kilometros: ");
	                scanf("%f", &kilometros);
	            }
	            flagKilometros = 1;

	            break;

	        case 2:
	            if(flagKilometros == 0)
	            {
	                printf("Error. Antes de ingresar precio de vuelos, ingrese kilometros!!\n");
	            }
	            else
	            {
	                printf("    ****Ingresar Precio de Vuelos****    \n");
	                printf("Precio Aerolineas: ");
	                scanf("%f", &precioAerolineas);
	                while(precioAerolineas<1)
	                {
	                    printf("Error, precio no valido. Reingrese Precio Aerolineas: ");
	                    scanf("%f", &precioAerolineas);
	                }

	                printf("Precio Latam: ");
	                scanf("%f", &precioLatam);
	                while(precioLatam<1)
	                {
	                    printf("Error, precio no valido. Reingrese Precio Latam: ");
	                    scanf("%f", &precioLatam);
	                }
	                flagPrecios = 1;

	            }
	            break;

	        case 3:
	            if(flagPrecios == 0)
	            {
	                printf("Error. Para calcular los costos debe ingresar los precios!!\n");
	            }
	            else
	            {
	                precioAerolineasDescuento = calcularDescuentoDebito(precioAerolineas);
	                precioAerolineasInteres = calcularInteresCredito(precioAerolineas);
	                precioBitcoinAerolineas = calcularPrecioBitcoin(precioAerolineas);
	                precioUnitarioAerolineas = calcularPrecioUnitario(precioAerolineas, kilometros);

	                precioLatamDescuento = calcularDescuentoDebito(precioLatam);
	                precioLatamInteres = calcularInteresCredito(precioLatam);
	                precioBitcoinLatam = calcularPrecioBitcoin(precioLatam);
	                precioUnitarioLatam = calcularPrecioUnitario(precioLatam, kilometros);

	                flagCostosCalculados = 1;
	                printf("Costos calculados con exito!!\n");
	            }

	            break;

	        case 4:
	            if(flagCostosCalculados == 0)
	            {
	                printf("Error. Para informar resultados primero debe calcular los costos!!\n");
	            }
	            else
	            {
	                printf("Latam: \n\n");
	                printf("a) Precio con tarjeta de debito: $%.2f\n", precioLatamDescuento);
	                printf("b) Precio con tarjeta de credito: $%.2f\n", precioLatamInteres);
	                printf("c) Precio pagado con Bitcoin: %.8f\n", precioBitcoinLatam);
	                printf("d) Precio unitario: %.2f\n\n", precioUnitarioLatam);
	                printf("Aerolineas: \n\n");
	                printf("a) Precio con tarjeta de debito: $%.2f\n", precioAerolineasDescuento);
	                printf("b) Precio con tarjeta de credito: $%.2f\n", precioAerolineasInteres);
	                printf("c) Precio pagado con Bitcoin: %.8f\n", precioBitcoinAerolineas);
	                printf("d) Precio unitario: %.2f\n", precioUnitarioAerolineas);
	            }
	            break;

	        case 5:
	            if(flagKilometros == 1)
	            {
	                printf("Error. Para realizar una carga forzada no debe ingresar ningun dato!!\n");
	            }
	            else
	            {
	                kilometros = 7090;
	                precioAerolineas = 162965;
	                precioLatam = 159339;

	                printf("KMs Ingresados: %.2f km\n\n", kilometros);
	                printf("Precio Aerolineas: $%.2f\n", precioAerolineas);
	                printf("a) Precio con tarjeta de debito: $%.2f\n", calcularDescuentoDebito(precioAerolineas));
	                printf("b) Precio con tarjeta de credito: $%.2f\n", calcularInteresCredito(precioAerolineas));
	                printf("c) Precio pagado con Bitcoin: %.8f\n", calcularPrecioBitcoin(precioAerolineas));
	                printf("d) Precio unitario: %.2f\n\n", calcularPrecioUnitario(precioAerolineas, kilometros));

	                printf("Precio Latam: $%.2f\n", precioLatam);
	                printf("a) Precio con tarjeta de debito: $%.2f\n", calcularDescuentoDebito(precioLatam));
	                printf("b) Precio con tarjeta de credito: $%.2f\n", calcularInteresCredito(precioLatam));
	                printf("c) Precio pagado con Bitcoin: %.8f\n", calcularPrecioBitcoin(precioLatam));
	                printf("d) Precio unitario: %.2f\n\n", calcularPrecioUnitario(precioLatam, kilometros));
	            }
	            break;

	        case 6:
	            printf("Confirma salida(s/n): ");
	            fflush(stdin);
	            scanf("%c", &seguir);
	            while(seguir!='n' && seguir!='s')
	            {
	                printf("Ingrese opcion valida. Confirma salida(s/n): ");
	                fflush(stdin);
	                scanf("%c", &seguir);
	            }
	            break;

	        default:
	            printf("\nError. Ingrese una opcion valida!!\n");
	            break;
	        }
	        system("pause");
	    }
	    while(seguir != 's');

	return EXIT_SUCCESS;
}
