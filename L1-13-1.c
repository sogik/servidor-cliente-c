#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    char peticion[100];
    char respuesta[100];

    strcpy(peticion, "1/Miguel/47/2/Juan/12/3/Maria/22/1/Marcos/19");

    char nombre[20];
    int servicio;
    int edad;
    char palindromo[20];
    char *p = strtok(peticion, "/");

    while(p!=NULL)
    {
        servicio = atoi(p);
        p = strtok (NULL, "/");
        strcpy (nombre, p);
        p = strtok (NULL, "/");
        edad = atoi(p);

        if (servicio == 1)
        {
            if(edad > 18)
            {
                sprintf (respuesta, "%s%s*%d*-", respuesta, nombre, edad);
            }
        }
        else if (servicio == 2)
        {
            int longitud = strlen(nombre);
            strcpy(palindromo, "SI");
            for (int i = 0; i < longitud / 2; i++) 
            {
                if (tolower(nombre[i]) != tolower(nombre[longitud - i - 1])) 
                {
                    strcpy(palindromo, "NO");
                    break;
                }
            }
            sprintf (respuesta, "%s%s*%s*-", respuesta, nombre, palindromo);
        }
        else 
        {
            int longitud = strlen(nombre);
            for (int i = 0; i < longitud; i++) 
            {
                nombre[i] = toupper(nombre[i]);
            }
            sprintf (respuesta, "%s*%s-", respuesta, nombre);
        }
        p = strtok (NULL, "/");
    }
    respuesta [strlen (respuesta) - 1] = '\0';

    printf("Resultado: %s\n", respuesta);
}