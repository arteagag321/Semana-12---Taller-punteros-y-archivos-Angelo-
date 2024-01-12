#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Repuesto {
    char nombre[50];
    int cantidad;
    float precio;
    char numeroParte[50];
};

struct Nodo {
    struct Repuesto repuesto;
    struct Nodo *siguiente;
    int indice; 
};

struct Lista {
    struct Nodo *primero;
    struct Nodo *ultimo;
    int contador; 
};

void crearLista(struct Lista *lista) {
    lista->primero = NULL;
    lista->ultimo = NULL;
    lista->contador = 0; 
}

void insertarRepuesto(struct Lista *lista, struct Repuesto repuesto) {
    struct Nodo *nuevoNodo = (struct Nodo*) malloc(sizeof(struct Nodo));
    nuevoNodo->repuesto = repuesto;
    nuevoNodo->siguiente = NULL;
    nuevoNodo->indice = ++lista->contador; 
    if (lista->primero == NULL) {
        lista->primero = nuevoNodo;
        lista->ultimo = nuevoNodo;
    } else {
        lista->ultimo->siguiente = nuevoNodo;
        lista->ultimo = nuevoNodo;
    }
}

void guardarEnArchivo(struct Lista *lista) {
    FILE *archivo = fopen("repuestos.txt", "w");
    if (!archivo) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }
    struct Nodo *nodoActual = lista->primero;
    while (nodoActual != NULL) {
        fprintf(archivo, "Repuesto %d: Nombre: %s, Cantidad: %d, Precio: %.2f, Numero de Parte: %s\n",
                nodoActual->indice,
                nodoActual->repuesto.nombre,
                nodoActual->repuesto.cantidad,
                nodoActual->repuesto.precio,
                nodoActual->repuesto.numeroParte);
        nodoActual = nodoActual->siguiente;
    }
    fclose(archivo);
    printf("Informacion guardada en 'repuestos.txt'.\n");
}

void listarRepuestos(struct Lista *lista) {
    if (lista->primero == NULL) {
        printf("No hay repuestos ingresados.\n");
    } else {
        struct Nodo *nodoActual = lista->primero;
        while (nodoActual != NULL) {
            printf("Repuesto %d: Nombre: %s, Cantidad: %d, Precio: %.2f, Numero de Parte: %s\n",
                   nodoActual->indice,
                   nodoActual->repuesto.nombre,
                   nodoActual->repuesto.cantidad,
                   nodoActual->repuesto.precio,
                   nodoActual->repuesto.numeroParte);
            nodoActual = nodoActual->siguiente;
        }
    }
}

void editarRepuesto(struct Lista *lista, int indiceRepuesto) {
    struct Nodo *nodoActual = lista->primero;
    while (nodoActual != NULL) {
        if (nodoActual->indice == indiceRepuesto) {
            printf("Editar repuesto %d:\n", indiceRepuesto);

            printf("Ingrese el nuevo nombre del repuesto: ");
            scanf(" %49[^\n]", nodoActual->repuesto.nombre);  // Lee hasta 49 caracteres o hasta un salto de línea

            printf("Ingrese la nueva cantidad del repuesto: ");
            scanf("%d", &nodoActual->repuesto.cantidad);

            printf("Ingrese el nuevo precio del repuesto: ");
            scanf("%f", &nodoActual->repuesto.precio);

            printf("Ingrese el nuevo numero de parte del repuesto: ");
            scanf(" %49s", nodoActual->repuesto.numeroParte); // Lee hasta 49 caracteres

            printf("Repuesto %d editado con exito.\n", indiceRepuesto);
            return;
        }
        nodoActual = nodoActual->siguiente;
    }
    printf("Repuesto no encontrado.\n");
}

void eliminarRepuesto(struct Lista *lista, int indiceRepuesto) {
    struct Nodo *nodoActual = lista->primero;
    struct Nodo *nodoAnterior = NULL;
    while (nodoActual != NULL) {
        if (nodoActual->indice == indiceRepuesto) {
            if (nodoAnterior == NULL) {
                lista->primero = nodoActual->siguiente;
            } else {
                nodoAnterior->siguiente = nodoActual->siguiente;
            }
            free(nodoActual);
            printf("Repuesto %d eliminado con exito.\n", indiceRepuesto);
            return;
        }
        nodoAnterior = nodoActual;
        nodoActual = nodoActual->siguiente;
    }
    printf("Repuesto no encontrado.\n");
}


void ingresarVariosRepuestos(struct Lista *lista) {
    int cantidadRepuestos;
    printf("Cuantos repuestos desea ingresar? ");
    scanf("%d", &cantidadRepuestos);
    getchar(); 

    for (int i = 0; i < cantidadRepuestos; i++) {
        struct Repuesto repuesto;
        printf("Repuesto %d\n", lista->contador + 1);

        printf("Ingrese el nombre del repuesto: ");
        fgets(repuesto.nombre, 50, stdin);
        repuesto.nombre[strcspn(repuesto.nombre, "\n")] = 0; 

        printf("Ingrese la cantidad del repuesto: ");
        scanf("%d", &repuesto.cantidad);
        getchar(); 

        printf("Ingrese el precio del repuesto: ");
        scanf("%f", &repuesto.precio);
        getchar(); 

        printf("Ingrese el numero de parte del repuesto: ");
        fgets(repuesto.numeroParte, 50, stdin);
        repuesto.numeroParte[strcspn(repuesto.numeroParte, "\n")] = 0; 

        insertarRepuesto(lista, repuesto);
    }
}


void seleccionarYEditarRepuesto(struct Lista *lista) {
    listarRepuestos(lista); 
    int indiceRepuesto;
    printf("Ingrese el numero del repuesto a editar: ");
    scanf("%d", &indiceRepuesto);
    editarRepuesto(lista, indiceRepuesto);
}


void seleccionarYEliminarRepuesto(struct Lista *lista) {
    listarRepuestos(lista); 
    int indiceRepuesto;
    printf("Ingrese el numero del repuesto a eliminar: ");
    scanf("%d", &indiceRepuesto);
    eliminarRepuesto(lista, indiceRepuesto);
}

int main() {
    struct Lista lista;
    crearLista(&lista);
    int opcion;
    do {
        printf("\n--- Sistema de Inventarios ---\n");
        printf("1. Ingresar varios repuestos\n");
        printf("2. Listar repuestos\n");
        printf("3. Editar repuesto por numero\n");
        printf("4. Eliminar repuesto por numero\n");
        printf("5. Guardar repuestos en archivo\n");
        printf("6. Salir\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                ingresarVariosRepuestos(&lista);
                break;
            case 2:
                listarRepuestos(&lista);
                break;
            case 3:
                seleccionarYEditarRepuesto(&lista);
                break;
            case 4:
                seleccionarYEliminarRepuesto(&lista);
                break;
            case 5:
                guardarEnArchivo(&lista);
                break;
            case 6:
                printf("Adios. Vuelve pronto\n");
                break;
            default:
                printf("Opcion no valida. Por favor, ingrese una opcion valida.\n");
        }
    } while (opcion != 6);

   
    struct Nodo *current = lista.primero;
    struct Nodo *next;
    while (current != NULL) {
        next = current->siguiente;
        free(current);
        current = next;
    }

    return 0;
}
