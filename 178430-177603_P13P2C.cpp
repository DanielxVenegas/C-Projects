#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
int a=1000; //variables globales
int sumaMaquina=0;
int suma2=0;

/*Funcion gotoxy para manipular la consola*/
void gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y= y;
	SetConsoleCursorPosition(hcon,dwPos); }
HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE); //Establecer consola en modo grafico

struct jugadores {//estructura para el almacenamiento de los jugadores
        char nombre[20];
        int ID;
        float dinAc;
        int parGan;
        int parPer;
        float apuesta;
        struct jugadores *siguiente, *ant;
};
struct jugadores *primero=NULL, *ultimo=NULL;//apuntadores para la lista

struct jugadores *temp=NULL;//auxiliar global

//declaracion de funciones 
void cartasMaquina();
void cartasJugador();
void nuevo_elemento();
void mostrar_listaInicio();
void programador();
void juego();
void inicioCartas2();

void validaciones();
void portada();

int main() {
	system("color 2F");//seleccion de color
	system("mode con cols=75 lines=35"); //Tamaño de la pantalla
	srand(time(NULL));//semilla para distintos numeros nulos
	int exit=0;
	int op;
	int exit2=0;
	portada();//funcion de la entrada del juego
	getch();
	system("CLS");//Se limpia pantalla
 	
	nuevo_elemento();//generacion del primer nodo de la lista
	temp=primero;//se ubica el apuntador en el primer nodo
	 do {
 		exit2=0;/*Inicialización de variables*/
 		sumaMaquina=0;
 		suma2=0;
 		
 		getch();
 		inicioCartas2();//se invoca la funcion del juego principal
 		
		while(!exit2) {//ciclo para saber si el jugador quiere jugar mas de una partida 
			printf("Presione 1 para jugar otra vez, 0 para salir\n ");
			scanf("%d",&op);
			switch(op) {//swith para saber si se empieza el juego otra vez
				case 1:
					sumaMaquina=0;
					suma2=0;
					printf("Cuanto quieres apostar?");//ingreso de la apuesta para la jugada 
      				scanf("%f",&temp->apuesta);//se guarda la apuesta
					inicioCartas2();//se vuelve a llamar la funcion del juego
					break;
					
				case 0:
					exit2=1;
					break;
					
			}
		}
 		
 		getch();
 		printf("\n\n1- Nuevo jugador\n0- Salir\n");
 		
 		scanf("%d",&exit);
 		if(exit==1){//si se quiere agregar un nuevo jugador
 			nuevo_elemento();//se genera un nodo nuevo 
 		temp=temp->siguiente;//avanza el auxiliar al siguiente nodo
		}
	}while(exit!=0);
	
	printf("\nRESUMEN DE JUGADORES\n");
	mostrar_listaInicio();//resumen de los jugadores en general
}
/*Funcion para imprimir pantalla de inicio del juego*/
void portada() {
	int x=3, y=1;
	/*Imprimir division superior*/
	gotoxy(x,y);
	printf("%c", 218);
	for(x=4; x<71; x++) {
		gotoxy(x,y);
		printf("%c", 196);
	}
	/*Imprimir division derecha*/
	printf("%c", 191);
	for(y=2; y<33; y++) {
		gotoxy(x,y);
		printf("%c", 179);
	}
	/*Imprimir division inferior*/
	gotoxy(x,y);
	printf("%c", 217);
	for(x=70; x>3; x--) {
		gotoxy(x,y);
		printf("%c", 196);
	}
	/*Imprimir division izquierda*/
	gotoxy(x,y);
	printf("%c", 192);
	for(y=32; y>1; y--) {
		gotoxy(x,y);
		printf("%c", 179);
	}
	/*Imprimir texto con formato*/
	SetConsoleTextAttribute(hd, 38);
	x=36;
	y=10;
	gotoxy(x,y);
	printf("21");
	x=33;
	y++;
	gotoxy(x,y);
	SetConsoleTextAttribute(hd, 39);
	printf("Blackjack");
	/*Impresion de cartas*/
	x=23;
	y+=2;
	gotoxy(x,y);
	SetConsoleTextAttribute(hd, 244);
	printf(" %c %c ", 03, 03);
	x+=8;
	gotoxy(x,y);
	SetConsoleTextAttribute(hd, 240);
	printf(" %c %c ", 06, 06);
	x+=8;
	gotoxy(x,y);
	SetConsoleTextAttribute(hd, 244);
	printf(" %c %c ", 04, 04);
	x+=8;
	gotoxy(x,y);
	SetConsoleTextAttribute(hd, 240);
	printf(" %c %c ", 05, 05);
	/*Impresion de texto*/
	x=23;
	y+=2;
	gotoxy(x,y);
	SetConsoleTextAttribute(hd, 47);
	printf("Pulsa una tecla para jugar...");
	x=16;
	y+=5;
	gotoxy(x,y);
	printf("Universidad Politecnica de San Luis Potosi");
	x=16;
	y++;
	gotoxy(x,y);
	printf("Ingenieria en Tecnologias de la Informacion");
	x=22;
	y++;
	gotoxy(x,y);
	printf("Laboratorio de Programacion II");
	x=21;
	y+=2;
	gotoxy(x,y);
	printf("Estrada Medina Monserrat - 178430");
	x=17;
	y++;
	gotoxy(x,y);
	printf("Venegas Rivera Daniel Alejandro - 177603");

}
/*Funcion para dar de alta a un nuevo jugador*/
void nuevo_elemento()
{
    struct jugadores *nuevo; 
	/*Reserva de memoria para nuevo elemento*/
      nuevo = (struct jugadores *) malloc (sizeof(struct jugadores));
      if (nuevo==NULL) {
      	printf( "No hay memoria disponible!\n");
      	return; 
	  }
    printf("\nNuevo jugador:\n\n");
    printf("Nombre: "); 
    scanf("%s",nuevo->nombre);
    a=a+10;
    nuevo->ID=a;
    nuevo->dinAc=10000;
    nuevo->parGan=0;
    nuevo->parPer=0;
	/*Insercion al final de la lista doblemente enlazada*/
    if (primero==NULL){
         primero = nuevo;
         ultimo = nuevo;
         nuevo->ant=NULL;
         nuevo->siguiente=NULL;
    } 
      else 
      {
           ultimo->siguiente = nuevo;
           nuevo->ant=ultimo;
           nuevo->siguiente=NULL;
           ultimo = nuevo;
           
      }
      printf("Cuanto quieres apostar? ");
      scanf("%f",&nuevo->apuesta);
}

/*Funcion para imprimir las estadisticas de los jugadores*/
void mostrar_listaInicio() {
      struct jugadores *auxiliar; /* lo usamos para recorrer la lista */
      int i;
      i=0;
      auxiliar = primero;
      while (auxiliar!=NULL) {
            printf("ID\tNOMBRE\tDINERO ACUMULADO\tVICTORIAS\tDERROTAS\n");
            printf("%d\t%s\t$%.2f\t\t%d\t\t%d\t\t",auxiliar->ID,auxiliar->nombre,auxiliar->dinAc,auxiliar->parGan,auxiliar->parPer);
			printf("\n");
            auxiliar = auxiliar->siguiente;
            i++;
      }
      if (i==0) printf( "\nLa lista está vacia!\n" );
 }
/*Funcion para repartir las cartas que posee la maquina*/
void cartasMaquina(){
	int mazo=0, carta=0, i=0, exit=0, op=0;
	printf("\t\t\tCARTAS MAQUINA: \n");
	/*Repartir dos cartas inciales a la maquina*/
	for(i=0; i<2; i++) {
		mazo=1+rand()%(4);
 		carta=1+rand()%(13); //Generacion de la carta 
 		sumaMaquina+=carta; //Contador que controla la suma de las cartas
		SetConsoleTextAttribute(hd, 47);
		/*Verificacion de color y simbolo de la carta*/
		if(mazo==1) {
			SetConsoleTextAttribute(hd, 244);
			printf("\t %c %d %c \n", 03, carta, 03);
		}
		if(mazo==2) {
			SetConsoleTextAttribute(hd, 240);
			printf("\t %c %d %c \n", 06, carta, 06);
		}
		if(mazo==3) {
			SetConsoleTextAttribute(hd, 244);
			printf("\t %c %d %c \n", 04, carta, 04);
		}
		if(mazo==4) {
			SetConsoleTextAttribute(hd, 240);
			printf("\t %c %d %c \n", 05, carta, 05);
		}
	}
	SetConsoleTextAttribute(hd, 47);
	printf("Suma total: %d\n\n",sumaMaquina);
}
/*Funcion para repartir las cartas que posee el jugador actual*/
void cartasJugador() {
	int mazo=0, carta=0, i=0, exit=0, op=0;
	printf("\t\t\tCARTAS JUGADOR\n");
	/*Dos cartas iniciales*/
	for(i=0; i<2; i++) {
		mazo=1+rand()%(4);
 		carta=1+rand()%(13); //Generacion de la carta
 		suma2+=carta; //Suma total
 		/*Verificacion de color y simbolo de la carta*/
		switch(mazo) {
			case 1:
				SetConsoleTextAttribute(hd, 244); //Color de texto rojo, fondo blanco
				printf("\t %c %d %c \n", 03, carta, 03); //Carta de corazones
				break;
			case 2:
				SetConsoleTextAttribute(hd, 240); //Color de texto negro, fondo blanco
				printf("\t %c %d %c \n", 06, carta, 06); //Carta de picas
				break;
			case 3:
				SetConsoleTextAttribute(hd, 244); //Color de texto rojo, fondo blanco
				printf("\t %c %d %c \n", 04, carta, 04); //Carta de diamantes
				break;
			case 4:
				SetConsoleTextAttribute(hd, 240); //Color de texto negro, fondo blanco
				printf("\t %c %d %c \n", 05, carta, 05); //Carta de treboles
				break;
			default:
				SetConsoleTextAttribute(hd, 47);
				break;
		}
		SetConsoleTextAttribute(hd, 47); //Restablecer color de fondo verde, texto blanco
	}
	printf("Suma total: %d\n\n",suma2);
}

/*Funcion para controlar cada vez que se eligen cartas*/
void inicioCartas2() {
	int mazo=0, carta=0, i=0, exit=0, op=0,color;
	struct jugadores *temp;
	temp=primero;
	cartasMaquina();
	cartasJugador();
	/*Mientras no se indique una salida de la partida del jugador, continua tomando cartas*/
	while(!exit){
		printf("Presione 1 para tomar otra carta, 0 para detenerse\n ");
		scanf("%d",&op);
		/*La maquina sigue tomando cartas, mientras su suma total sea menor a 15*/
		while(sumaMaquina<15) {
			carta=1+rand()%(13);
			sumaMaquina+=carta;
			printf("Total de la maquina: %d\n",sumaMaquina);
		}
		switch(op) {
			case 1:
				carta=1+rand()%(13);
				SetConsoleTextAttribute(hd, 47);
				printf("Nueva carta:\t",carta);
				color=1+rand()%(4);
				/*Verificacion de color y simbolo de la carta*/
				switch(color) {
					case 1:
						SetConsoleTextAttribute(hd, 244); //Color de texto rojo, fondo blanco
						printf("\t %c %d %c \n", 03, carta, 03); //Carta de corazones
						break;
					case 2:
						SetConsoleTextAttribute(hd, 240); //Color de texto negro, fondo blanco
						printf("\t %c %d %c \n", 06, carta, 06); //Carta de picas
						break;
					case 3:
						SetConsoleTextAttribute(hd, 244); //Color de texto rojo, fondo blanco
						printf("\t %c %d %c \n", 04, carta, 04); //Carta de diamantes
						break;
					case 4:
						SetConsoleTextAttribute(hd, 240); //Color de texto negro, fondo blanco
						printf("\t %c %d %c \n", 05, carta, 05); //Carta de treboles
						break;
					default:
						SetConsoleTextAttribute(hd, 47);
						break;
				}
				SetConsoleTextAttribute(hd, 47); //Restablecer color de fondo verde, texto blanco
				suma2+=carta;
				printf("Suma total: %d\n",suma2);
				validaciones();
				break;
			case 0:
				validaciones();
				exit=1;
				break;
		}
		break;
	}
}
/*Funcion para validar las reglas del juego*/
void validaciones(){
	SetConsoleTextAttribute(hd, 47);
	/*Empate*/
	if(sumaMaquina==21 && suma2==21){
		printf("Empate!!\n");
		printf("Estado de cuenta actual: %.2f\n", temp->dinAc);
		return;
	}
	
	/*Jugador pierde, maquina gana*/
	if(sumaMaquina==21){
		printf("Perdiste!!\n");
		temp->dinAc-=temp->apuesta;
		printf("Estado de cuenta actual: %.2f\n", temp->dinAc);
		temp->parPer++;
		return;
	}
	
	if(suma2 >21) {
		printf("Perdiste!!\n");
		temp->dinAc-=temp->apuesta;
		printf("Estado de cuenta actual: %.2f\n", temp->dinAc);
		temp->parPer++;
		return;
	}
	/*Empate*/
	if(suma2 ==sumaMaquina){
		printf("Empate!!\n");
		printf("Estado de cuenta actual: %.2f\n", temp->dinAc);
		return;
	}
	/*Jugador gana, maquina pierde*/
	if(sumaMaquina>21){
		printf("Ganaste!!\n");
		temp->dinAc+=temp->apuesta*2; //Se gana el doble de lo apostado
		printf("Estado de cuenta actual: %.2f\n", temp->dinAc);
		temp->parGan++;
		return;
	}
	/*Jugador gana*/
	if(suma2 == 21){
		printf("Ganaste!!\n");
		temp->dinAc+=temp->apuesta*2;
		printf("Estado de cuenta actual: %.2f\n", temp->dinAc);
		temp->parGan++;
		return;
	}
	/*Maquina gana*/
	if(sumaMaquina>suma2 && sumaMaquina<21){
		printf("Perdiste!!\n");
		temp->dinAc-=temp->apuesta;
		printf("Estado de cuenta actual: %.2f\n", temp->dinAc);
		temp->parGan++;
		return;
	}	
	/*Jugador gana*/
	if(suma2 > sumaMaquina && suma2 < 21) {
		printf("Ganaste!!\n");
		temp->dinAc+=temp->apuesta;
		printf("Estado de cuenta actual: %.2f\n", temp->dinAc);
		temp->parGan++;
		return;
	}
	return;
}
