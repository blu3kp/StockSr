///////////////////////////////////////////
//                                       //
// StockSr - Gestor de almacenamiento    //
// Version 1.0                           //
//                                       //
///////////////////////////////////////////

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 

/* ---------- Constantes ---------- */
#define NOMBRE_SW        "StockSr"
#define VERSION_SW       "1.0"
#define MAX_INTENTOS     3
#define STOCK_MINIMO     3          // alerta cuando stock <= 3
#define USUARIO_VALIDO   "admin"
#define CLAVE_VALIDA     "1234"
#define TAM_NOMBRE       50

/* ---------- Estructura de material ---------- */
typedef struct {
    int  id;                   // identificador único
    char nombre[TAM_NOMBRE];   // nombre del material
    int  cantidad;             // piezas en stock
} Material;