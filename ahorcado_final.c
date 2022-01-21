#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 
#include <ctype.h> 

void jugarPartida();
void iniciarPartida(char *);
void terminarPartida();
void obtenerNombreJugador(char *);
int jugarJuego();
void iniciarJuego();
void terminarJuego();

void mostrarBienvenida();
void mostrarMenuPrincipal();
void mostrarInstrucciones();
void mostrarTablero(char *, int, int);
void dibujo(int);
void mostrarPalabraAdivinada(char *);
void mostrarFelicitacion();
void mostrarLamentacion();
void mostrarCreditos();

void hacerPausa();
char leerOpcion();
char leerLetra();
char *generarPalabra();
int seguirJugando();
int buscarLetra(char *, char *, char);

#define MAXIMO_PALABRAS 10
#define TAMANO_PALABRA  20


int main(){
    srand(time(0));  // Semilla en una fecha
    system("cls");

    jugarPartida();
    //jugarJuego();
    return 0;
}

void jugarPartida() {
    int juegos_jugados = 0;
    int juegos_ganados = 0;
    char nombre_jugador[20]; 

    iniciarPartida(nombre_jugador);
    
    while (seguirJugando()) {
        juegos_jugados++;
        jugarJuego();
    }

    terminarPartida();
}

void iniciarPartida(char *nombre_jugador){
    mostrarBienvenida();
    obtenerNombreJugador(nombre_jugador);
}

void terminarPartida(){
    mostrarCreditos();
}

void obtenerNombreJugador(char *nombre_jugador) {
    printf("Para jugar proporciona tu nombre: ");
    scanf("%s", nombre_jugador);
}


int seguirJugando() {
    char opcion;
    mostrarMenuPrincipal();
    do {
        opcion = toupper(leerOpcion());	//To upper case cambia a mayuscula 
        switch (opcion) {
            case 'M':
                mostrarMenuPrincipal();
                break;
            case 'I':
                mostrarInstrucciones();
                break;    
            case 'J':
            case 'S':
                break;
        }
    } while (!(opcion=='J' || opcion=='S'));
    
    return (opcion=='J');
}

int jugarJuego() {
    // palabra_oculta es la palabra por adivinar
    char *palabra_oculta;
    // palabra_adivinada es la secuencia de letras 
    char palabra_adivinada[] = "____________________";
    char letra;

    int intentos = 0;
    int errores_permitidos = 6;
    int errores = 0;
    int ocurrencias = 0;
    
    int bandera_ahorcado = 0;
    int bandera_adivinada = 0;

    iniciarJuego();
    
    palabra_oculta = generarPalabra();
    palabra_adivinada[strlen(palabra_oculta)] = NULL;

    errores = 0;
    do { 
        mostrarTablero(palabra_adivinada, intentos, errores);
        
        printf("\nSeleccione una letra (oportunidades: %i): ", 7 - errores);
        letra = leerLetra();

        // terminar el juego presionando la tecla 0
        if (letra == '0') break;

        ocurrencias = buscarLetra(palabra_oculta, palabra_adivinada, letra);
        if (ocurrencias == 0) {
            if (++errores == 7) 
                bandera_ahorcado = 1;
        } else {       
            if (strcasecmp(palabra_oculta, palabra_adivinada) == 0) //strcasecmp convierte las cadenas en minusculas y las compara
                bandera_adivinada = 1;
        }

        if (ocurrencias >= 0) intentos++;

    } while (!(bandera_adivinada || bandera_ahorcado));

    mostrarTablero(palabra_adivinada, intentos, errores);

    if (bandera_adivinada) 
        mostrarFelicitacion();
    
    if (bandera_ahorcado)
        mostrarLamentacion();

    hacerPausa();
    
    return bandera_adivinada;
}

void iniciarJuego(){

}

void terminarJuego(){
    printf("\nPresione cualquier tecla para continuar ...");
    _getch();    
}

// Genera una palabra (palabra_oculta) para adivinar
char *generarPalabra() {
    static char palabras[][20]={"gdbonline","diagrama","recursividad","ciclos","lenguaje","funciones","matrices","vectores","printf","sistemaoperativo","pentabyte","exabyte","almacenamiento","semantico","caracter","algoritmo","graficos","codigo","librerias","variables","constantes","contadores","operadores","entero","flotante","prototipo","llamada","booleano","arreglo","acumuladores"};
    int total_palabras = sizeof(palabras) / sizeof(palabras[0]);
    int indice = rand() % (total_palabras);
    //static int indice = 0;
    if (indice > total_palabras) indice = 0;
    return palabras[indice++];
}

// Busca una letra dentro de la palabra oculta y si la encuentra 
// la pone en la palabra adivinada y 
// regresa el numero de veces que la encontro (ocurrencias)
int buscarLetra(char *palabra_oculta, char *palabra_adivinada, char letra) {
    int ocurrencias = 0;
	int i=0;

    for (i=0; palabra_oculta[i] != NULL; i++) {
        if (toupper(palabra_oculta[i]) == toupper(letra)) {
            if (palabra_adivinada[i] == '_') {
                palabra_adivinada[i] = palabra_oculta[i];
                ocurrencias++;
            } else {
                ocurrencias--;
            }    
        }
    }
    return ocurrencias;
}


void mostrarBienvenida() {
    system("cls");
    printf("Juego del Ahorcado \n");
    printf("\nBienvenido al Juego del Ahorcado \n");
}

void mostrarMenuPrincipal() {
    system("cls");
    printf("Juego del Ahorcado \n");
    printf("\nSeleccione alguna de las siguientes opciones:");
    printf("\n  I : Instrucciones acerca de como jugar este juego");
    printf("\n  J : Jugar");
    printf("\n  S : Salir del juego");
    printf("\n");
}

void mostrarInstrucciones() {
    system("cls");
    printf("Juego del Ahorcado \n");
    printf("\n�Como jugar?\n");
	printf("Ecribe una letra, si es la correcta aparecera en pantalla\nsi no es, se dibujara el ahorcado.");
	printf("Tienes 6 oportunidades para equivocarte.");
    hacerPausa();
}

void mostrarTablero(char *palabra_adivinada, int intentos, int errores) {
    system("cls");
    printf("Juego del Ahorcado \n");
    dibujo(errores);
    mostrarPalabraAdivinada(palabra_adivinada);
    printf("Intentos: %i\t\tErrores: %i\n", intentos, errores);
}

void dibujo(int errores) {
 switch (errores){
 	case 0:
        printf("  ____\n | \n | \n | \n | \n | \n ---------\n\n");
        break;
    
    case 1:
        printf("  ____\n |       0\n | \n | \n | \n | \n ---------\n\n");
        break;
        
    case 2:
        printf("  ____\n |       0\n |       |\n | \n | \n | \n ---------\n\n");
        break;

    case 3:
        printf("  ____\n |       0\n |      /|\n | \n | \n | \n ---------\n\n");
        break;

    case 4:
        printf("  ____\n |       0\n |      /|");
        printf("\\");
        printf("\n");
        printf(" | \n | \n | \n ---------\n\n");
        break;

    case 5:
        printf(" ____\n |       0\n |      /|");
        printf("\\");
        printf("\n");
        printf(" |       |\n | \n | \n ---------\n\n");
        break;
    case 6:
        printf(" ____\n |       0\n |      /|");
        printf("\\");
        printf("\n");
        printf(" |       |\n |      /\n | \n ---------\n\n");

        break;
    case 7:
        printf(" ____\n |       0\n |      /|");
        printf("\\");
        printf("\n");
        printf(" |       |\n |      / ");
        printf("\\");
        printf("\n");
        printf(" | \n ---------\n\n");
        break;
    }
 
}


void mostrarPalabraAdivinada(char *palabra_adivinada) {
    int i =0;
	//https://stackoverflow.com/questions/1961209/making-some-text-in-printf-appear-in-green-and-red
    printf("\n\n%10s", "");
    for (i=0; palabra_adivinada[i] != NULL; i++)
        printf("\033[34m%c \033[0m", toupper(palabra_adivinada[i]) );
    printf("\n\n");
}

void mostrarFelicitacion() {
    printf("\nFelicidades! a ganado el juego ;D");
}

void mostrarLamentacion() {
    printf("\nLo lamento, fue ahorcado! :(");
}

void mostrarCreditos() {
    system("cls");
    printf("------ Universidad Autonoma de Guadalajara ------- Lunes 23 de Noviembre del 2020 ------- Ingenieria en Software ------ \n\t\t\t\t   Maestra: Maria de los Angeles Salazar Olmos \n\n");
    printf("\n\t\t\t\t Proyecto: JUEGO DEL AHORCADO \n\n");
    printf("Integrantes del equipo:\n\t - Celeste Barrera \n\t - Nancy Jimenez \n\t - Valentina Balderas \n\t - Paulina Osuna \n\t - Ana Luisa Vega \n\t - Yamil Hallal \n\t - Juan Pablo Ruelas \n\t - Fabrizzio Rios\n\n");
    
    getch();
}


void hacerPausa(){
    printf("\n\nPresione la tecla M para volver al menu ...");
    _getch();    
}

// Captura un caracter del conjunto de opciones
char leerOpcion() {
    char opciones[] = "IiMmJjSs";
    char opcion;
    while ( strchr( opciones, opcion=_getch() ) == NULL ) {
    }
    return opcion;
}

// Leer letra en minuscula
char leerLetra() {
    char letras[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0";
    char letra;
    while ( strchr( letras, letra=_getch() ) == NULL ) {
    }
    return letra;
}