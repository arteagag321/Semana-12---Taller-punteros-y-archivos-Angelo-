 //main.c
#include <stdio.h>
#include "funciones.h"
#include "lecturas.h"
#include "menu.h"  

typedef struct {
    char nombre[100];
    int cantidad;
    float precio;
    float impuesto; 
    char numeroParte[100]; 
} Repuesto;

int main() {
    int opcion;
    Repuesto repuestos[100]; 
    int numRepuestos = 0; 

    do {
        printf("========== MENU ==========\n");
        printf("1. Ingresar repuesto\n"); 
        printf("2. Editar repuesto\n"); 
        printf("3. Eliminar repuesto\n"); 
        printf("4. Listar repuestos\n"); 
        printf("5. Salir\n");
        opcion = leerEnteroEntre("Seleccione una opcion: ", 1, 5);

        switch (opcion) {
            case 1:
                printf("========== INGRESAR REPUESTO ==========\n"); 
                printf("Si desea volver al menú principal, ingrese 10\n");
                printf("Ingrese el nombre del repuesto: "); 
                scanf("%s", repuestos[numRepuestos].nombre); 

                if (strcmp(repuestos[numRepuestos].nombre, "10") == 0) {
                    break;
                }

                printf("Ingrese la cantidad: ");
                scanf("%d", &repuestos[numRepuestos].cantidad);

                if (repuestos[numRepuestos].cantidad == 10) {
                    break;
                }

                printf("Ingrese el precio: ");
                scanf("%f", &repuestos[numRepuestos].precio);

                if (repuestos[numRepuestos].precio == 10.0) {
                    break;
                }

                printf("Ingrese el impuesto: ");
                scanf("%f", &repuestos[numRepuestos].impuesto);

                if (repuestos[numRepuestos].precio == 10.0) {
                    break;
                }

                printf("Ingrese el número de parte: ");
                scanf("%s", repuestos[numRepuestos].numeroParte);

                if (repuestos[numRepuestos].precio == 10.0) {
                    break;
                }
                numRepuestos++;
                break;
            case 2:
                printf("========== EDITAR REPUESTO ==========\n");
                int indiceRepuesto;
                if(numRepuestos == 0){
                    printf("No hay repuestos registrados.\n");
                } else {
                    for (int i = 0; i < numRepuestos; i++) {
                        printf("%d. %s\n", i+1, repuestos[i].nombre);
                    }

                    printf("Si desea volver al menú principal, ingrese 10\n");
                    printf("Seleccione el número del repuesto a editar: ");
                    scanf("%d", &indiceRepuesto);

                    if (indiceRepuesto == 10) {
                        break;
                    }

                    printf("Ingrese el nuevo nombre del repuesto: ");
                    scanf("%s", repuestos[indiceRepuesto].nombre);
                    repuestos[indiceRepuesto].cantidad = leerEnteroPositivo("Ingrese la nueva cantidad: ");
                    repuestos[indiceRepuesto].precio = leerFlotantePositivo("Ingrese el nuevo precio: ");
                }
                break;
            case 3:
                printf("========== ELIMINAR REPUESTO ==========\n");
                if(numRepuestos == 0){
                    printf("No hay repuestos registrados.\n");
                } else {
                    for (int i = 0; i < numRepuestos; i++) {
                        printf("%d. %s\n", i+1, repuestos[i].nombre);
                    }

                    printf("Si desea volver al menú principal, ingrese 10\n");
                    printf("Seleccione el número del repuesto a eliminar: ");
                    scanf("%d", &indiceRepuesto);

                    if (indiceRepuesto == 10) {
                        break;
                    }

                    for (int i = indiceRepuesto; i < numRepuestos - 1; i++) {
                        repuestos[i] = repuestos[i + 1];
                    }
                    numRepuestos--;
                    printf("Repuesto eliminado exitosamente.\n");
                }
                break;
            case 4:
                printf("========== LISTA DE REPUESTOS ==========\n");
                for (int i = 0; i < numRepuestos; i++) {
                    printf("Nombre: %s\n", repuestos[i].nombre);
                    printf("Cantidad: %d\n", repuestos[i].cantidad);
                    printf("Precio: %.2f\n", repuestos[i].precio);
                    printf("impuesto: %.2f\n", repuestos[i].impuesto);
                    printf("Número de parte: %s\n", repuestos[i].numeroParte);
                    printf("--------------------\n");
                }
                break;
            case 5:
                printf("Saliendo del programa...\n");
                break;
        }
    } while (opcion != 5);

    return 0;
}
