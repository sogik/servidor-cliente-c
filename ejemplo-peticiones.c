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

    int i;

    for(i=0;i<5;i++)
    {
        printf("Eschuchando\n")
        sock_conn = accept(sock_listen, NULL, NULL);
        printf("He recibido conexion\n");

        ret=read(sock_conn, peticion, sizeof(peticion));
        printf("Recibido\n");

        peticion[ret]='\0';

        printf("Peticion: %s\n",peticion);

        char *p = strtok(peticion, "/");
        int codigo =  atoi(p);
        p = strtok(NULL, "/");
        char nombre[20];
        strcpy(nombre, p);
        printf("Codigo: %d, Nombre: %s\n", codigo, nombre);

        if(codigo == 1)
        {
            sprintf(respuesta, "%d, ", strlen(nombre);
        }
        else if(codigo == 2)
        {
            sprintf(respuesta, "No te entiendo");
        }
        else
        {
            p = strtok(NULL, "/");
            float altura =  atof(p);

            if (a)
        }

        printf("Respuesta: %s\n", respuesta);
        write(sock_conn, respuesta, strlen(respuesta));

        close(sock_conn);
    }
}