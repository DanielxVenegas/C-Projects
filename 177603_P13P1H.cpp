/*:(*/
/*Definición de librerías*/
#include<stdio.h> //Librería con funciones de entrada y salida de datos
#include <time.h> //Librería para establecer el tiempo
#include <stdlib.h> //Librería para generar números aleatorios
#include <conio.h> //Librería para la función getch
#include<windows.h> //Librería para funciones de la consola
HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE); //Establecer consola en modo gráfico
/*Función para imprimir el encabezado*/
void encabezado(void) {
	printf("Practica 14\nLaboratorio de Programacion I\n\n");
	printf("Venegas Rivera Daniel Alejandro\nUniversidad Politecnica de San Luis Potosi\nMatricula: 177603\n");
	printf("Ingenieria en Tecnologias de la Informacion\nSemestre: II\nGrupo: H\n");
	printf("Maestra: Atzel Yazmin Rivas Ortega\n\n\n");
	printf("\tGrupos\n\n");
	printf("\tA\tB\tC\tD\tE\n\n"); }
/*Función para generar aleatorios dentro del arreglo bidimensional y checar que no se repitan por grupos*/
void asignar(char grupos[5][10]) {
	int c[26]={0}, letra=0, aux=0;
	srand (time(NULL)); //Generar semilla en base al tiempo
	for (int i=0; i<10; i++) {
		for (int j=0; j<5; j++) {
			do { aux=0;
				letra=(65+rand()%(26)); //Genera un número aleatorio entre 0 y 25 y le suma 65
				for (int k=0; k<10; k++) {
						if (letra==grupos[k][j]) {
							aux=1; } }
			} while (aux==1);
			grupos[i][j]=letra; } } }
/*Ciclo para imprimir matriz*/
void impr(char grupos[5][10]) {
	for (int i=0; i<10; i++) {
		for (int j=0; j<5; j++) {
			printf("\t%c",grupos[i][j]); }
		printf("\n\n"); } }
/*Función gotoxy*/
void gotoxy(int x,int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y= y;
	SetConsoleCursorPosition(hcon,dwPos); }
/*Función para imprimir la tabla*/
void tabla(void) {
	int x, y;
	gotoxy(3,11);
	printf("%c",218); //Imprimir esquina superior izquierda
	x=4,y=11; //Establecemos variables de coordenadas para imprimir el margen superior
	for(int i=x;i<45;i++) { //Ciclo para imprimir margen superior
		gotoxy(i,y);
		printf("%c",196); }
	gotoxy(45,11);
	printf("%c",191); //Imprimir esquina superior derecha
	x=3,y=12; //Establecemos variables de coordenadas para imprimir el margen izquierdo
	for(int i=y;i<36;i++) {
		gotoxy(x,i);
		printf("%c",179); } //Ciclo para imprimir margen izquierdo
	gotoxy(3,35);
	printf("%c",192); //Imprimir esquina inferior izquierda
	x=4, y=35;
	for(int i=x;i<45;i++) { //Ciclo para imprimir margen inferior
		gotoxy(i,y);
		printf("%c",196); }
	x=45,y=12; //Establecemos variables de coordenadas para imprimir el margen derecho
	for(int i=y;i<35;i++) {
		gotoxy(x,i);
		printf("%c",179); } //Ciclo para imprimir margen derecho
	x=4,y=13; //Establecemos variables de coordenadas para imprimir división horizontal
	for(int i=x;i<45;i++) { //Ciclo para imprimir división horizontal
		gotoxy(i,y);
		printf("%c",196); }
	x=4,y=15; //Establecemos variables de coordenadas para imprimir división horizontal
	for(int i=x;i<45;i++) { //Ciclo para imprimir división horizontal
		gotoxy(i,y);
		printf("%c",196); }
	gotoxy(45,35);
	printf("%c",217); } //Imprimir esquina inferior derecha
/*Función para consultar un grupo*/
void Abc(char grupos[5][10], char g) {
	char aux[10];
	do {
		printf("\n\nEscribe el grupo que deseas consultar: ");
		fflush(stdin);
		scanf("%c",&g);
		switch (g) {
			case 'A':
				for (int i=0; i<10; i++) {
					for (int j=0; j<1; j++) {
						if (grupos[i][j] > grupos[i+1][j]){
							aux[i] = grupos[i][j];
							grupos[i][j] = grupos[i+1][j];
							grupos[i+1][j] = aux[i]; }
						printf("\n\t%c",grupos[i][j]); }
					printf("\n\n"); }
				break;
			case 'B':
				for (int i=0; i<10; i++) {
					for (int j=1; j<2; j++) {
						if (grupos[i][j] > grupos[i+1][j]){
							aux[i] = grupos[i][j];
							grupos[i][j] = grupos[i+1][j];
							grupos[i+1][j] = aux[i]; }
						printf("\n\t%c",grupos[i][j]); }
					printf("\n\n"); }
				break;
			case 'C':
				for (int i=0; i<10; i++) {
					for (int j=2; j<3; j++) {
						if (grupos[i][j] > grupos[i+1][j]){
							aux[i] = grupos[i][j];
							grupos[i][j] = grupos[i+1][j];
							grupos[i+1][j] = aux[i]; }
						printf("\n\t%c",grupos[i][j]); }
					printf("\n\n"); }
				break;
			case 'D':
				for (int i=0; i<10; i++) {
					for (int j=3; j<4; j++) {
						if (grupos[i][j] > grupos[i+1][j]){
							aux[i] = grupos[i][j];
							grupos[i][j] = grupos[i+1][j];
							grupos[i+1][j] = aux[i]; }
						printf("\n\t%c",grupos[i][j]); }
					printf("\n\n"); }
				break;
			case 'E':
				for (int i=0; i<10; i++) {
					for (int j=4; j<5; j++) {
						if (grupos[i][j] > grupos[i+1][j]){
							aux[i] = grupos[i][j];
							grupos[i][j] = grupos[i+1][j];
							grupos[i+1][j] = aux[i]; }
						printf("\n\t%c",grupos[i][j]); }
					printf("\n\n"); }
				break;
			case '0': break; 
			default: printf("\nSeleccionaste una opcion no valida");}
	} while (g!='0'); }
/*Función para resaltar las letras A y R*/
void porNombre(char grupos[5][10]) {
	for (int i=0; i<10; i++) {
		for (int j=0; j<5; j++) {
			if (grupos[i][j]=='A') {
				SetConsoleTextAttribute(hd,6);
				printf("\t%c",grupos[i][j]); }
			if (grupos[i][j]=='R') {
				SetConsoleTextAttribute(hd,2);
				printf("\t%c",grupos[i][j]); }
			else {
			SetConsoleTextAttribute(hd,7);
			printf("\t%c",grupos[i][j]); } }
			printf("\n\n"); } }
/*Función para contar todas las letras existentes en la matriz*/
void cuenta(char grupos[5][10]) {
	printf("Veces que se repite cada letra:\n");
	int aux=0;
	for(int a=65; a<91; a++) {
		aux=0;
		for (int i=0; i<10; i++) {
			for (int j=0; j<5; j++) {
				if (a==grupos[i][j]) {
					aux++; } } }
		if(aux != 0)
			printf("%c: %d\n", a,aux); } }
/*Programa principal*/
main() {
	/*Encabezado*/
	encabezado();
	char grupos[5][10],g;
	asignar(grupos);
	impr(grupos);
	tabla();
	Abc(grupos,g);
	system("cls"); //Limpiar pantalla
	encabezado();
	tabla();
	gotoxy(4,16);
	porNombre(grupos);
	cuenta(grupos); }