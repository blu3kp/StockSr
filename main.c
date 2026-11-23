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

/* ---------- Memoria dinámica local (RAM) ---------- */
static Material *inventario = NULL; // arreglo dinámico de materiales
static int total = 0;               // cuántos materiales hay
static int capacidad = 0;           // cuántos caben antes de pedir más memoria
static int siguienteId = 1;         // para asignar IDs automáticos

/* ============================================================ */
/*                    UTILIDADES DE ENTRADA                     */
/* ============================================================ */

// Lee una línea de texto de forma segura y quita el salto de línea
void leerTexto(const char *mensaje, char *destino, int tam) {
    printf("%s", mensaje);
    if (fgets(destino, tam, stdin) == NULL) {
        destino[0] = '\0';
        return;
    }
    destino[strcspn(destino, "\n")] = '\0';  // reemplaza '\n' por fin de cadena
}

// Lee un entero validado; repite hasta que sea >= minimo
int leerEntero(const char *mensaje, int minimo) {
    char buffer[32];
    char *fin;
    long valor;
    while (1) {
        leerTexto(mensaje, buffer, sizeof(buffer));
        valor = strtol(buffer, &fin, 10);          // convierte texto a número
        if (fin != buffer &&Pseudocódigo de RF01 (Autenticación). *fin == '\0' && valor >= minimo && valor <= 1000000)
            return (int)valor;
        printf("  Entrada invalida. Escribe un numero entero >= %d.\n", minimo);
    }
}

// Convierte a minúsculas (para buscar sin importar mayúsculas)
void aMinusculas(const char *origen, char *destino) {
    int i;
    for (i = 0; origen[i] != '\0'; i++)
        destino[i] = (char)tolower((unsigned char)origen[i]);
    destino[i] = '\0';
}

/* ============================================================ */ 
/*                 UTILIDADES DE INVENTARIO                     */
/* ============================================================ */

// Busca un material por ID. Regresa su posición o -1 si no existe
int buscarIndicePorId(int id) {
    for (int i = 0; i < total; i++)
        if (inventario[i].id == id) return i;
    return -1;
}

// Alerta con sonido ('\a' = beep) si el stock es bajo
void alertaStock(const Material *m) {
    if (m->cantidad <= STOCK_MINIMO) {
        printf("\a\a\a");  // 3 beeps
        printf("  *** ALERTA: \"%s\" tiene stock bajo (%d pieza(s)) ***\n",
               m->nombre, m->cantidad);
    }
}

// Asegura espacio para un material más; duplica la memoria si está llena
int asegurarCapacidad(void) {
    if (total < capacidad) return 1;
    int nueva = (capacidad == 0) ? 4 : capacidad * 2;
    Material *tmp = realloc(inventario, nueva * sizeof(Material));
    if (tmp == NULL) {                    // realloc puede fallar
        printf("  Error: no hay memoria disponible.\n");
        return 0;
    }
    inventario = tmp;
    capacidad = nueva;
    return 1;
}
