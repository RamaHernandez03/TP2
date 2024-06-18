#include "estructuras.h"

p_lista crear_lista() {
    p_lista lista = (p_lista)malloc(sizeof(lista));
    if (lista) {
        lista->nodo = NULL;
        lista->cantidad_nodos = 0;
    }
    return lista;
}

p_nodo crear_nodo(p_lata elemento) {
    p_nodo nuevo_nodo = (p_nodo)malloc(sizeof(nodo));
    if (nuevo_nodo) {
        nuevo_nodo->elemento = elemento;
        nuevo_nodo->siguiente = NULL;
    }
    return nuevo_nodo;
}

int lista_vacia(p_lista lista) {
    return lista->cantidad_nodos == 0;
}

status agregar_elemento_al_inicio(p_lista lista, p_lata elemento) {
    p_nodo nuevo_nodo = crear_nodo(elemento);
    if (!nuevo_nodo) return status_fail;

    nuevo_nodo->siguiente = lista->nodo;
    lista->nodo = nuevo_nodo;
    lista->cantidad_nodos++;
    return status_ok;
}

status agregar_elemento_al_final(p_lista lista, p_lata elemento) {
    p_nodo nuevo_nodo = crear_nodo(elemento);
    if (!nuevo_nodo) return status_fail;

    if (lista_vacia(lista)) {
        lista->nodo = nuevo_nodo;
    } else {
        p_nodo actual = lista->nodo;
        while (actual->siguiente) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo_nodo;
    }
    lista->cantidad_nodos++;
    return status_ok;
}

status borrar_elemento(p_lista lista, char *marca, char *color, float tamaño) {
    p_nodo actual = lista->nodo, anterior = NULL;
    while (actual) {
        if (strcmp(actual->elemento->Marca, marca) == 0 &&
            strcmp(actual->elemento->Color, color) == 0 &&
            actual->elemento->tamaño == tamaño) {
            if (anterior) {
                anterior->siguiente = actual->siguiente;
            } else {
                lista->nodo = actual->siguiente;
            }
            free(actual->elemento);
            free(actual);
            lista->cantidad_nodos--;
            return status_ok;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    return status_fail;
}

void liberar_lista(p_lista lista) {
    p_nodo actual = lista->nodo;
    while (actual) {
        p_nodo temp = actual;
        actual = actual->siguiente;
        free(temp->elemento);
        free(temp);
    }
    free(lista);
}

void mostrar_y_generar_archivo(p_lista lista, char *mensaje_consola, char *mensaje_archivo, char *dato) {
    p_nodo actual = lista->nodo;
    int encontrado = 0;

    while (actual) {
        if (strcmp(actual->elemento->Color, dato) == 0) {
            printf("Marca: %s, Color: %s, Tamaño: %.2f litros\n",
                   actual->elemento->Marca, actual->elemento->Color, actual->elemento->tamaño);
            encontrado = 1;
        }
        actual = actual->siguiente;
    }

    if (!encontrado) {
        printf("No se encontraron productos %s.\n", mensaje_consola);
        return;
    }

    char opcion;
    printf("¿Desea generar un archivo con la información mostrada? (s/n): ");
    getchar();
    scanf("%c", &opcion);

    if (opcion == 's' || opcion == 'S') {
        char nombre_archivo[50];
        printf("Ingrese el nombre del archivo (sin extensión .txt): ");
        scanf("%s", nombre_archivo);

        strcat(nombre_archivo, ".txt");

        FILE *archivo = fopen(nombre_archivo, "w");
        if (!archivo) {
            printf("Error al abrir el archivo %s para escritura.\n", nombre_archivo);
            return;
        }

        actual = lista->nodo;
        while (actual) {
            if (strcmp(actual->elemento->Color, dato) == 0) {
                fprintf(archivo, "Marca: %s, Color: %s, Tamaño: %.2f litros\n",
                        actual->elemento->Marca, actual->elemento->Color, actual->elemento->tamaño);
            }
            actual = actual->siguiente;
        }

        fclose(archivo);
        printf("Archivo generado exitosamente: %s\n", nombre_archivo);
    }
}

void mostrar_y_generar_archivo_por_marca(p_lista lista, char *mensaje_consola, char *mensaje_archivo, char *dato) {
    p_nodo actual = lista->nodo;
    int encontrado = 0;

    while (actual) {
        if (strcmp(actual->elemento->Marca, dato) == 0) {
            printf("Marca: %s, Color: %s, Tamaño: %.2f litros\n",
                   actual->elemento->Marca, actual->elemento->Color, actual->elemento->tamaño);
            encontrado = 1;
        }
        actual = actual->siguiente;
    }

    if (!encontrado) {
        printf("No se encontraron productos %s.\n", mensaje_consola);
        return;
    }

    char opcion;
    printf("¿Desea generar un archivo con la información mostrada? (s/n): ");
    getchar();
    scanf("%c", &opcion);

    if (opcion == 's' || opcion == 'S') {
        char nombre_archivo[50];
        printf("Ingrese el nombre del archivo (sin extensión .txt): ");
        scanf("%s", nombre_archivo);

        strcat(nombre_archivo, ".txt");

        FILE *archivo = fopen(nombre_archivo, "w");
        if (!archivo) {
            printf("Error al abrir el archivo %s para escritura.\n", nombre_archivo);
            return;
        }

        actual = lista->nodo;
        while (actual) {
            if (strcmp(actual->elemento->Marca, dato) == 0) {
                fprintf(archivo, "Marca: %s, Color: %s, Tamaño: %.2f litros\n",
                        actual->elemento->Marca, actual->elemento->Color, actual->elemento->tamaño);
            }
            actual = actual->siguiente;
        }

        fclose(archivo);
        printf("Archivo generado exitosamente: %s\n", nombre_archivo);
    }
}

void mostrar_y_generar_archivo_por_marca_y_color(p_lista lista, char *marca, char *color, int cantidad_latas) {
    printf("Cantidad de latas: %d\n", cantidad_latas);

    p_nodo actual = lista->nodo;
    char informacion[1024] = "";
    char entrada[256];
    
    sprintf(entrada, "Marca: %s, Color: %s\n", marca, color);
    strcat(informacion, entrada);

    while (actual) {
        if (strcmp(actual->elemento->Marca, marca) == 0 && strcmp(actual->elemento->Color, color) == 0) {
            char detalle[256];
            sprintf(detalle, "Marca: %s, Color: %s, Tamaño: %.2f litros\n",
                    actual->elemento->Marca, actual->elemento->Color, actual->elemento->tamaño);
            strcat(informacion, detalle);
        }
        actual = actual->siguiente;
    }

    printf("%s", informacion);

    char opcion;
    printf("¿Desea generar un archivo con la información mostrada? (s/n): ");
    getchar();
    scanf("%c", &opcion);

    if (opcion == 's' || opcion == 'S') {
        char nombre_archivo[50];
        printf("Ingrese el nombre del archivo (sin extensión .txt): ");
        scanf("%s", nombre_archivo);

        strcat(nombre_archivo, ".txt");

        FILE *archivo = fopen(nombre_archivo, "w");
        if (!archivo) {
            printf("Error al abrir el archivo %s para escritura.\n", nombre_archivo);
            return;
        }

        fprintf(archivo, "%s", informacion);
        fprintf(archivo, "Cantidad de latas: %d\n", cantidad_latas);

        fclose(archivo);
        printf("Archivo generado exitosamente: %s\n", nombre_archivo);
    }
}

void mostrar_y_generar_archivo_con_entrada(p_lista lista, char *mensaje_consola, char *mensaje_archivo, char *dato, char *entrada_usuario) {
    p_nodo actual = lista->nodo;
    int encontrado = 0;
    
    printf("%s", entrada_usuario);

    while (actual) {
        if (strcmp(actual->elemento->Color, dato) == 0) {
            printf("Marca: %s, Color: %s, Tamaño: %.2f litros\n",
                   actual->elemento->Marca, actual->elemento->Color, actual->elemento->tamaño);
            encontrado = 1;
        }
        actual = actual->siguiente;
    }

    if (!encontrado) {
        printf("No se encontraron productos %s.\n", mensaje_consola);
        return;
    }

    char opcion;
    printf("¿Desea generar un archivo con la información mostrada? (s/n): ");
    getchar();
    scanf("%c", &opcion);

    if (opcion == 's' || opcion == 'S') {
        char nombre_archivo[50];
        printf("Ingrese el nombre del archivo (sin extensión .txt): ");
        scanf("%s", nombre_archivo);

        strcat(nombre_archivo, ".txt");

        FILE *archivo = fopen(nombre_archivo, "w");
        if (!archivo) {
            printf("Error al abrir el archivo %s para escritura.\n", nombre_archivo);
            return;
        }

        fprintf(archivo, "%s", entrada_usuario);

        actual = lista->nodo;
        while (actual) {
            if (strcmp(actual->elemento->Color, dato) == 0) {
                fprintf(archivo, "Marca: %s, Color: %s, Tamaño: %.2f litros\n",
                        actual->elemento->Marca, actual->elemento->Color, actual->elemento->tamaño);
            }
            actual = actual->siguiente;
        }

        fclose(archivo);
        printf("Archivo generado exitosamente: %s\n", nombre_archivo);
    }
}

void verificar_disponibilidad(p_lista lista, char *color) {
    p_nodo actual = lista->nodo;
    int encontrado = 0;

    char informacion[1024] = "";
    char entrada[256];

    sprintf(entrada, "Color: %s\n", color);
    strcat(informacion, entrada);

    while (actual) {
        if (strcmp(actual->elemento->Color, color) == 0) {
            encontrado = 1;
            break;
        }
        actual = actual->siguiente;
    }

    if (encontrado) {
        mostrar_y_generar_archivo_con_entrada(lista, "disponibles en el color especificado", "Verificar Disponibilidad", color, informacion);
    } else {
        printf("Color no disponible\n");
    }
}

void verificar_color_y_cantidad(p_lista lista, char *color, float tamaño) {
    p_nodo actual = lista->nodo;
    int encontrado = 0;

    char informacion[1024] = "";
    char entrada[256];

    sprintf(entrada, "Color: %s, Tamaño: %.2f\n", color, tamaño);
    strcat(informacion, entrada);

    while (actual) {
        if (strcmp(actual->elemento->Color, color) == 0 && actual->elemento->tamaño == tamaño) {
            encontrado = 1;
            break;
        }
        actual = actual->siguiente;
    }

    if (encontrado) {
        mostrar_y_generar_archivo_con_entrada(lista, "con el color y tamaño especificados", "Verificar Color y Cantidad", color, informacion);
    } else {
        printf("Stock no disponible\n");
    }
}

void total_color(p_lista lista, char *color) {
    p_nodo actual = lista->nodo;
    float total_litros = 0;
    int cantidad_latas = 0;

    char informacion[1024] = "";
    char entrada[256];

    sprintf(entrada, "Color: %s\n", color);
    strcat(informacion, entrada);

    while (actual) {
        if (strcmp(actual->elemento->Color, color) == 0) {
            total_litros += actual->elemento->tamaño;
            cantidad_latas++;
        }
        actual = actual->siguiente;
    }

    if (cantidad_latas > 0) {
        printf("Total Color: %.2f litros\n", total_litros);
        printf("Cantidad de Latas: %d\n", cantidad_latas);
        mostrar_y_generar_archivo_con_entrada(lista, "con el color especificado", "Total Color", color, informacion);
    } else {
        printf("Color no disponible\n");
    }
}

void total_marca(p_lista lista, char *marca) {
    p_nodo actual = lista->nodo;
    int cantidad_latas = 0;

    char informacion[1024] = "";
    char entrada[256];

    sprintf(entrada, "Marca: %s\n", marca);
    strcat(informacion, entrada);

    while (actual) {
        if (strcmp(actual->elemento->Marca, marca) == 0) {
            cantidad_latas++;
        }
        actual = actual->siguiente;
    }

    if (cantidad_latas > 0) {
        printf("Cantidad de latas de la marca %s: %d\n", marca, cantidad_latas);
        mostrar_y_generar_archivo_con_entrada(lista, "de la Marca especificada", "Total Marca", marca, informacion);
    } else {
        printf("Marca no disponible\n");
    }
}

void total_por_marca_y_color(p_lista lista, char *marca, char *color) {
    p_nodo actual = lista->nodo;
    int cantidad_latas = 0;

    while (actual) {
        if (strcmp(actual->elemento->Marca, marca) == 0 && strcmp(actual->elemento->Color, color) == 0) {
            cantidad_latas++;
        }
        actual = actual->siguiente;
    }

    if (cantidad_latas > 0) {
        mostrar_y_generar_archivo_por_marca_y_color(lista, marca, color, cantidad_latas);
    } else {
        printf("Marca y color no disponibles\n");
    }
}
