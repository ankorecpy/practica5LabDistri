/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "gestionUsuarios.h"


void
gestion_usuario_1(char *host)
{
	CLIENT *clnt;
	bool_t  *result_1;
	proxNodo  registrarusuario_1_arg;
	proxNodo  *result_2;
	char *listarusuarios_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, gestion_usuario, gestion_usuario_version, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
	int opcion = -1;
	struct nodo_usuario nodo;

	do {
		opcion = leerOpcion();
		switch (opcion) {
			case 1:

				printf("Codigo: ");
				scanf("%s", nodo.codigo);
				printf("Nombre: ");
				scanf("%s", nodo.nombres);
				printf("Apellidos: ");
				scanf("%s", nodo.apellidos);
				nodo.nodoSiguiente = NULL; 
				fflush(stdin);
				registrarusuario_1_arg = &nodo;
				result_1 = registrarusuario_1(&registrarusuario_1_arg, clnt);
				if (result_1 == (bool_t *) NULL) {
					clnt_perror (clnt, "call failed");
				}
				
			break;
			case 2:
				result_2 = listarusuarios_1((void*)&listarusuarios_1_arg, clnt);
				if (result_2 == (proxNodo *) NULL) {
					clnt_perror (clnt, "call failed");
				} else {
					while ((*result_2) != NULL) {
						printf("Codigo : %s\n", (*result_2)->codigo);
						printf("Nombre : %s\n", (*result_2)->nombres);
						printf("Apellidos : %s\n", (*result_2)->apellidos);
						result_2 = (*result_2)->nodoSiguiente;
					}
				}
			break;
			case 3:
				printf("Fin del programa\n");
			break;
			default:
				printf("opcion incorrecta\n");
			break;
		}
	} while (opcion != 3);
	
	


#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}

	host = argv[1];
	gestion_usuario_1 (host);
exit (0);
}

int leerOpcion() {
	int opcion = -1;
	printf("\n===============  Menu  ===============\n");
	printf("    1. Registrar usuario\n");
	printf("    2. Listar Usuarios\n");
	printf("    3. Salir\n");
	scanf("%d", &opcion);
	return opcion;
}
