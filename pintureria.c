#include "Estructuras.h"

void menu(p_lista lista) {
    int opcion;
    char marca[20], color[20];
    float tamaño;

    do {
        printf("\nMenu:\n");
        printf("1. Agregar producto al inicio\n");
        printf("2. Agregar producto al final\n");
        printf("3. Remover producto\n");
        printf("4. Verificar disponibilidad\n");
        printf("5. Verificar color y cantidad\n");
        printf("6. Total por color\n");
        printf("7. Total por marca\n");
        printf("8. Total por marca y color\n");
        printf("9. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese la Marca: ");
                scanf("%s", marca);
                printf("Ingrese el Color: ");
                scanf("%s", color);
                printf("Ingrese el Tamaño de la lata: ");
                scanf("%f", &tamaño);
                p_lata nueva_lata = (p_lata)malloc(sizeof(lata));
                strcpy(nueva_lata->Marca, marca);
                strcpy(nueva_lata->Color, color);
                nueva_lata->tamaño = tamaño;
                if (agregar_elemento_al_inicio(lista, nueva_lata) == status_ok) {
                    printf("Producto Agregado al Inicio\n");
                } else {
                    printf("Error al agregar el producto\n");
                }
                break;
            case 2:
                printf("Ingrese la Marca: ");
                scanf("%s", marca);
                printf("Ingrese el Color: ");
                scanf("%s", color);
                printf("Ingrese el Tamaño de la lata: ");
                scanf("%f", &tamaño);
                nueva_lata = (p_lata)malloc(sizeof(lata));
                strcpy(nueva_lata->Marca, marca);
                strcpy(nueva_lata->Color, color);
                nueva_lata->tamaño = tamaño;
                if (agregar_elemento_al_final(lista, nueva_lata) == status_ok) {
                    printf("Producto Agregado al Final\n");
                } else {
                    printf("Error al agregar el producto\n");
                }
                break;
            case 3:
                printf("Ingrese la Marca: ");
                scanf("%s", marca);
                printf("Ingrese el Color: ");
                scanf("%s", color);
                printf("Ingrese el Tamaño de la lata: ");
                scanf("%f", &tamaño);
                if (borrar_elemento(lista, marca, color, tamaño) == status_ok) {
                    printf("Producto Removido\n");
                } else {
                    printf("Producto no encontrado\n");
                }
                break;
            case 4:
                printf("Ingrese el Color: ");
                scanf("%s", color);
                verificar_disponibilidad(lista, color);
                break;
            case 5:
                printf("Ingrese el Color: ");
                scanf("%s", color);
                printf("Ingrese Tamaño de lata: ");
                scanf("%f", &tamaño);
                verificar_color_y_cantidad(lista, color, tamaño);
                break;
            case 6:
                printf("Ingrese el Color: ");
                scanf("%s", color);
                total_color(lista, color);
                break;
            case 7:
                printf("Ingrese la Marca: ");
                scanf("%s", marca);
                total_marca(lista, marca);
                break;
            case 8:
                printf("Ingrese la Marca: ");
                scanf("%s", marca);
                printf("Ingrese el Color: ");
                scanf("%s", color);
                total_por_marca_y_color(lista, marca, color);
                break;
            case 9:
                liberar_lista(lista);
                printf("Adiós!\n");
                break;
            default:
                printf("Opción inválida\n");
                break;
        }
    } while (opcion != 9);
}

int main() {
    p_lista lista = crear_lista();
    menu(lista);
    return 0;
}