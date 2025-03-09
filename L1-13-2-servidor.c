#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    int sock_conn, sock_listen, ret;
    struct sockaddr_in serv_adr;
    char peticion[512];
    char respuesta[512];

    if((sock_listen = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        printf("Error creant socket");

    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;

    serv_adr.sin_addr.s_addr = htonal(INADDR_ANY);

    serv_adr.sin_port = htons(9050);

    if(bind(sock_listen, (struct sockdaddr *) &serv_adr, sizeof(serv_adr)) < 0)
        printf("Error al bind");

    if(listen(sock_listen, 3) < 0)
    printf("Error en el listen");


    printf("Eschuchando\n");

    while(1)
    {
        sock_conn = accept(sock_listen, NULL, NULL);
        printf("He recibido conexion\n");

        ret=read(sock_conn, peticion, sizeof(peticion));
        printf("Recibido\n");

        peticion[ret]='\0';

        printf("Peticion: %s\n",peticion);

        float grados;
        int servicio;
        char *p = strtok(peticion, "/");

        while(p!=NULL)
        {   
            servicio = atoi(p);
            p = strtok (NULL, "/");
            grados = atof(p);

            if(servicio==1)
            {
                grados = (grados * 9/5) + 32;
                sprintf (respuesta, "%s%.1f-", respuesta, grados);
            }
            if(servicio==2)
            {
                grados = (grados - 32) * 5/9;
                sprintf (respuesta, "%s%.1f-", respuesta, grados);
            }
            p = strtok (NULL, "/");
        }
        respuesta [strlen (respuesta) - 1] = '\0';

        printf("Resultado: %s\n", respuesta);
        write(sock_conn, respuesta, strlen(respuesta));
    
        close(sock_conn);
        return 0;
    }
}