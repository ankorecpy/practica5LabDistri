/*Declaracion de datos a transferir entre el cliente y el servidor*/

/*Declaracion de constantes*/
const MAXNOM = 30;
const MAXAPEL = 30;

typedef struct nodo_usuario *proxNodo;

/*Declaracion de la estructura que permite almacenar los datos del usuario*/

struct nodo_usuario{
	char nombres[MAXNOM];
	char apellidos[MAXAPEL];	
	char codigo[MAXAPEL];
	proxNodo nodoSiguiente;/*Atributo de usuario que le permite guardar la referencia al siguiente nodo*/
};

/*Definicion de las operaciones que se pueden realizar*/
program gestion_usuario{
	version gestion_usuario_version{
		bool registrarUsuario(proxNodo usuario)=1;
		proxNodo listarUsuarios(void)=2;		
	}=1;
}=0x20000001;
