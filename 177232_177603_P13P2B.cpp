#include <stdio.h>
#include <conio.h>
#include <windows.h>

struct DLLNode{
	int id_item;
	char name[20];
	char desc[50];              
	float price;
	int rated;
	struct DLLNode *next;
	struct DLLNode *prev;
}*DLLhead = NULL, *DLLultimo = NULL;

int productos = 0;	//Variables globales que se utilizarán para las compras del producto
float total = 0;
HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);

void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
}
//funcion temporal para que pruebe el programa, borrela
void printArray(int examp[10]){
	for(int i=0;i<10;i++)
		printf("%d  ",examp[i]);
}
/* Genera el nuevo nodo con la estructura DLLNode para la lista doble circular*/
DLLNode* nodeGenerator() {
	DLLNode *newNodeDLL = new DLLNode; //Reserva memoria para el apuntador
	newNodeDLL->prev = NULL;
	newNodeDLL->next = NULL;
	return newNodeDLL; //La función regresa el nuevo nodo
}
/* Genera el nodo y lo inserta al final en una lista de doble enlace circular*/


DLLNode* DoublyLinkedList() {
	DLLNode *newNodeDLL = new DLLNode; //Se reserva memoria para el nuevo nodo
	DLLNode *temp = DLLhead; //Un apuntador temporal para recorrer la lista
	
	newNodeDLL = nodeGenerator(); //Genera el nodo y se almacena
	
	if (temp==NULL) { //Si la lista doble esta vacía
		DLLhead = newNodeDLL; //El nuevo nodo se establece como el primer nodo de la lista
		newNodeDLL->prev = newNodeDLL; //El anterior nodo es el mismo nodo generado
		newNodeDLL->next = newNodeDLL; //El nodo siguiente es el mismo nodo generado
	}
	else { //Si la lista no está vacía, se llega al íltimo nodo con ayuda de un temp y se realiza la inserción
		while (temp->next!=DLLhead)
			temp = temp->next; //Recorremos hasta encontrar el último nodo de la lista
		temp->next = newNodeDLL; //Al salir del ciclo, el temporal obtiene el valor del último nodo, por lo que el nuevo nodo se coloca en el siguiente del temporal
		newNodeDLL->prev = temp; //El nuevo nodo apunta en su anterior al temporal (el último elemento de la lista)
		newNodeDLL->next = DLLhead; //El nuevo nodo, en su siguiente, apunta al inicio de la lista
		DLLhead->prev = newNodeDLL; //El primer nodo apunta en su anterior al nuevo nodo
	}
	return newNodeDLL;
}
/* Impresión de la lista nueva generada - generada en doubly linked list*/


void lista(DLLNode* nodo){
	if(DLLhead == NULL){
		nodo->next = nodo->prev = nodo;
		DLLhead = DLLultimo = nodo;
	}else{
		nodo->next = DLLhead;
		DLLhead->prev = nodo;
		DLLhead = nodo;
		DLLultimo->next = DLLhead;
		DLLhead->prev = DLLultimo;
	}
}

DLLNode* prueba(){
	DLLNode * nodo;
	nodo = DoublyLinkedList();
	return nodo;
}

void lectura(){
	FILE *fp;
	fp = fopen("productos.txt","r");
	if(fp == NULL){
		printf("Error al abrir el archivo");
		exit(1);
	}
	while(!feof(fp)){
	
		DLLNode * nodo = prueba();
		fscanf(fp, "%d\t", &nodo->id_item);
		fscanf(fp, "%[^\t]\t", nodo->name);
		fscanf(fp, "%s\t", nodo->desc);
		fscanf(fp, "%f\t", &nodo->price);
		fscanf(fp, "%d\n", &nodo->rated);
		
	}
}

void printDLList() {
	DLLNode *temp = DLLhead;
	int n=0;
	SetConsoleTextAttribute(hCon, 7); //Establecer color de impresión blanco
	gotoxy(40,1);
	printf("Catalogo de productos");
	SetConsoleTextAttribute(hCon, 2); //Establecer color de impresión verde
	gotoxy(1,3);
	do {
		printf("%s\t", temp->name);
		printf("%.2f\t", temp->price);
		temp = temp->next;
		n++;
		if (n==5) {
			printf("\n");
		}
	} while(temp != DLLhead);
}

/*Función para borrar toda la línea*/
void clear_line(void) {
	printf("%c[2K", (char)27);
	fflush(stdout);
}

int main() {
	HANDLE Con = GetStdHandle(STD_OUTPUT_HANDLE);
	system("mode con cols=100 lines=25"); //Tamaño predeterminado de la pantalla
	int tecla = 0, x=10, y=7;
	
	lectura();
	printDLList();
	printf("\n");
	DLLNode *temp = DLLhead; //Un apuntador temporal para recorrer la lista

	SetConsoleTextAttribute(hCon, 1); //Establecer color de impresión azul
	gotoxy(x,y);
	printf("%c",218); //Imprimir esquina superior izquierda
	/*Ciclo para imprimir margen izquierdo*/
	for (int i=0; i<10; i++) {
			y++;
			gotoxy(x,y);
			printf("%c",179);  }
	y++;
	gotoxy(x,y);
	printf("%c",192); //Imprimir esquina inferior izquierda
	/*Ciclo para imprimir margen inferior*/
	for (int i=0; i<65; i++) {
			x++;
			gotoxy(x,y);
			printf("%c",196);  }
	x++;
	gotoxy(x,y);
	printf("%c",217); //Imprimir esquina inferior derecha
	/*Ciclo para imprimir margen derecho*/
	for (int i=10; i>0; i--) {
			y--;
			gotoxy(x,y);
			printf("%c",179);  }
	y--;
	gotoxy(x,y);
	printf("%c",191); //Imprimir esquina superior izquierda
	/*Ciclo para imprimir margen superior*/
	for (int i=65; i>0; i--) {
			x--;
			gotoxy(x,y);
			printf("%c",196);  }
	x+=10;
	y+=3;
	SetConsoleTextAttribute(hCon, 7); //Establecer color de impresión blanco
	gotoxy(x,y);
	
	do {
		x=15;
		y=10;
		gotoxy(x,y);
		tecla = getch();
		switch(tecla) {
			case 75://left
				temp = temp->prev;
				printf("%d\t",temp->id_item);
				printf("%s\t",temp->name);
				printf("%s\t",temp->desc);
				printf("%.2f\t",temp->price);
				printf("%d\n",temp->rated);
			break;
			case 77://right
				temp = temp->next;
				printf("%d\t",temp->id_item);
				printf("%s\t",temp->name);
				printf("%s\t",temp->desc);
				printf("%.2f\t",temp->price);
				printf("%d\n",temp->rated);
			break;
			case 13:{	//Si se imprime enter se "compra" el producto
				gotoxy(15,21);
				printf("\nEl producto: %s ha sido comprado\n", temp->name);
				productos++;	//Se incrementa la cantidad de productos comprados
				total += temp->price; //Se va sumando el total de cada producto
				break;
			}
		}
		clear_line();
	}while(tecla!=27);
	system("cls");
	SetConsoleTextAttribute(hCon, 13);//Para color de salida de los datos
	gotoxy(25,30); //Se mueve a esa posicion
	printf("COMPRA");
	gotoxy(0,32);
	SetConsoleTextAttribute(hCon, 6);	//Salida de datos
	printf("PRODUCTOS: %d\nSUBTOTAL: $%.2f\nENVIO: $%.2f\n_______________________________\n", productos, total, total * .1);
	SetConsoleTextAttribute(hCon, 7);
	printf("\t\tTOTAL: $%.2f", total + (total * .1));//Operaciones para agregar el impuesto al total
	SetConsoleTextAttribute(hCon, 8);
}
