/*First code of the first step of the software */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Registro de usuarios
#define USUARIO "adminsys"
#define CONTRASENA "domingo88"

//registro de longitud
#define Longitud 80

int main()
{
    // my variables are
    char version[] = "1.0";
    char Usuario[Longitud + 1];
    char Contrasena[Longitud +1];
    int intento = 0;
    int ingreso = 0;

    do
    {
    system("clear");
    printf("================================================================================\n");
    printf("\t\t\t\t\033[1m*StockSr*\033[0m\t\n");
    printf("\t\t\t\t   %s\n", version); //decidi quitar el texto version por visibilidad
    printf("================================================================================\n");
    printf("\n\n\n\033[1m\"Bienvenido a StockSr\"\033[0m\n");
    printf("Tu gestor de almacen favorito...");
    printf("\n\n\n\n***********************************Login***********************************\n");
    printf("Usuario: ");
    scanf(Usuario, sizeof(Usuario), stdin);
    Usuario[strcspn(Usuario, "\n")] = '\0';
    printf("Contrasena: ");
    scanf(Contrasena, sizeof(Contrasena), stdin);
    Contrasena[strcspn(Contrasena, "\n")] = '\0';

    if (strcmp(Usuario, USUARIO) == 0 && strcmp(Contrasena, CONTRASENA) == 0)
    {
        ingreso = 1;
    }
    else
    {
        printf("\nUsuario y/o contrasena son incorrectos\n");
        intento++;
        getchar();
    }
    }

    while (intento < 3 && ingreso == 0);

    if (ingreso == 1)
    {
    printf("\nBienvenido al sistema");
    }
    else
    {
        printf("\n Haz sobrepasado el numero de intentos permitidos");
    }
    return 0;

}
//here I'll write the login feature