#include "Estructuras.h"

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

void verificar_disponibilidad(p_lista lista, char *color) {
    p_nodo actual = lista->nodo;
    int encontrado = 0;
    while (actual) {
        if (strcmp(actual->elemento->Color, color) == 0) {
            printf("Marca: %s, Tamaño: %.2f litros\n", actual->elemento->Marca, actual->elemento->tamaño);
            encontrado = 1;
        }
        actual = actual->siguiente;
    }
    if (!encontrado) {
        printf("Color no disponible\n");
    }
}

void verificar_color_y_cantidad(p_lista lista, char *color, float tamaño) {
    p_nodo actual = lista->nodo;
    int encontrado = 0;
    while (actual) {
        if (strcmp(actual->elemento->Color, color) == 0 && actual->elemento->tamaño == tamaño) {
            printf("Marca: %s\n", actual->elemento->Marca);
            encontrado = 1;
        }
        actual = actual->siguiente;
    }
    if (!encontrado) {
        printf("Stock no disponible\n");
    }
}

void total_color(p_lista lista, char *color) {
    p_nodo actual = lista->nodo;
    float total_litros = 0;
    int cantidad_latas = 0;
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
    } else {
        printf("Color no disponible\n");
    }
}

void total_marca(p_lista lista, char *marca) {
    p_nodo actual = lista->nodo;
    int cantidad_latas = 0;
    char colores[lista->cantidad_nodos][20];
    int colores_contados = 0;

    while (actual) {
        if (strcmp(actual->elemento->Marca, marca) == 0) {
            int color_ya_contado = 0;
            for (int i = 0; i < colores_contados; i++) {
                if (strcmp(colores[i], actual->elemento->Color) == 0) {
                    color_ya_contado = 1;
                    break;
                }
            }
            if (!color_ya_contado) {
                strcpy(colores[colores_contados++], actual->elemento->Color);
                printf("Color: %s\n", actual->elemento->Color);
            }
            cantidad_latas++;
        }
        actual = actual->siguiente;
    }
    printf("Cantidad de latas: %d\n", cantidad_latas);
}

void total_por_marca_y_color(p_lista lista, char *marca, char *color) {
    p_nodo actual = lista->nodo;
    float total_litros = 0;
    int cantidad_latas = 0;

    while (actual) {
        if (strcmp(actual->elemento->Marca, marca) == 0 && strcmp(actual->elemento->Color, color) == 0) {
            total_litros += actual->elemento->tamaño;
            cantidad_latas++;
        }
        actual = actual->siguiente;
    }
    if (cantidad_latas > 0) {
        printf("Total Color: %.2f litros\n", total_litros);
        printf("Cantidad de latas: %d\n", cantidad_latas);
    } else {
        printf("Marca y color no disponibles\n");
    }
}