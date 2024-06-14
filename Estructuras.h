#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lata {
    char Marca[20];
    char Color[20];
    float tamaño;
} lata, *p_lata;

typedef struct nodo {
    p_lata elemento;
    struct nodo *siguiente;
} nodo, *p_nodo;

typedef struct lista {
    p_nodo nodo;
    int cantidad_nodos;
} lista, *p_lista;

typedef enum {
    status_ok,
    status_fail
} status;

// Prototipos de funciones
p_lista crear_lista();
p_nodo crear_nodo(p_lata elemento);
int lista_vacia(p_lista lista);
status agregar_elemento_al_inicio(p_lista lista, p_lata elemento);
status agregar_elemento_al_final(p_lista lista, p_lata elemento);
status borrar_elemento(p_lista lista, char *marca, char *color, float tamaño);
void liberar_lista(p_lista lista);
void verificar_disponibilidad(p_lista lista, char *color);
void verificar_color_y_cantidad(p_lista lista, char *color, float tamaño);
void total_color(p_lista lista, char *color);
void total_marca(p_lista lista, char *marca);
void total_por_marca_y_color(p_lista lista, char *marca, char *color);

#endif
