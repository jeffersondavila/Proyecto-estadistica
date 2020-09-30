#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <Windows.h>
#include <stdio.h>
#include <math.h>
#include <iomanip>

void gotoxy(int x, int y)
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

using namespace std;

int CantidadDatos, i, j, x, sum;
float respuesta[100], frecuencia[100], temp, n, aux, Ancho_Intervalo = 0, nMayor = 0, nMenor, contadorIntervalos, Intervalo;



void INGRESARDATOS() {
	int x = 30, y = 5, x1 = 90, y1 = 5;
	gotoxy(x, 2); cout << "INGRESE LA CANTIDAD TOTAL DE DATOS  NÚMERICOS: \t"; cin >> CantidadDatos;
	gotoxy(x1, 2); cout << "LISTA DE DATOS INGRESADOS:";
	for (i = 0; i < CantidadDatos; i++)
	{
		gotoxy(x, y); cout << "INGRESE EL DATO # " << i + 1 << "\t"; cin >> respuesta[i];
		gotoxy(x1, y1); cout << i + 1 << ".\t" << respuesta[i];
		y++, y1++;
	}
	//CAPTURAR LOS DATOS EN RESPUESTA Y CONTARREPETICONES
	for (i = 0; i < CantidadDatos; i++) {
		for (j = i + 1; j < CantidadDatos; j++) {
			if (respuesta[i] > respuesta[j]) {
				aux = respuesta[i];
				respuesta[i] = respuesta[j];
				respuesta[j] = aux;
			}
		}
	}
	//ORDENAR LOS DATOS
	system("pause>null");
};
void MODIFICARDATOS() {
	int x1 = 10, y1 = 5, posicion;
	gotoxy(x1, 2); cout << "LISTA DE DATOS INGRESADOS:";
	for (i = 0; i < CantidadDatos; i++)
	{
		gotoxy(x1, y1); cout << i << ".\t" << respuesta[i];
		y1++;
	}
	//imprimimos la lista de datos ya ordenados
	gotoxy(70, 5); cout << "INGRESE POSICION DE DATO QUE QUIERA CAMBIAR:"; cin >> posicion;
	if (posicion < CantidadDatos)
	{
		for (i = 0; i <= posicion; i++)
		{
			if (i == posicion)
			{
				gotoxy(70, 6); cout << "INGRESE NUEVO DATO: "; cin >> respuesta[i];
				cout << respuesta[i];
			}
		}
		//se guarda la modificación y en los dos vectores
		system("cls");
		for (i = 0; i < CantidadDatos; i++) {
			for (j = i + 1; j < CantidadDatos; j++) {
				if (respuesta[i] > respuesta[j]) {
					aux = respuesta[i];
					respuesta[i] = respuesta[j];
					respuesta[j] = aux;
				}
			}
		}
		//se ordena los vectores con la modificación ya echa
		gotoxy(x1, 2); cout << "LA NUEVA LISTA DE DATOS INGRESADOS ES:"; x1 = 10, y1 = 5;
		for (i = 0; i < CantidadDatos; i++)
		{
			gotoxy(x1, y1); cout << i << ".\t" << respuesta[i];
			y1++;
		}
		//se imprime la lista del vector con los datos ya ordenados
	}
	else
	{
		system("cls");
		gotoxy(70, 5); cout << "LA POSICIÓN NO FUE ENCONTRADA, INTENTELO NUEVAMENTE";
	}
	system("pause>null");
};
void CONTARREPETICIONES() {
	int j, x = 25, y = 10;
	for (i = 0; i < 300; i++) {
		sum = 0;
		for (j = 0; j < CantidadDatos; j++) {
			if (i == respuesta[j]) {
				sum = sum + 1;
			}
		}
		if (0 < sum && sum < 2) {//si es mayor a 0 el contador es porque se repite el numero
			gotoxy(x, y); cout << "El número " << float(i) << " se repite " << sum << " vez.";
			frecuencia[i] = sum;
			y++;
		}
		if (sum >= 2)
		{
			gotoxy(x, y); cout << "El número " << float(i) << " se repite " << sum << " veces.";
			frecuencia[i] = sum;
			cout << frecuencia[i];
			y++;
		}
	}
};
void DATOSORDENADOS() {
	int  x = 25, y = 5;
	gotoxy(x, 5); cout << "LISTADO DE DATOS ORDENADOS: ";
	x = 55;
	for (i = 0; i < CantidadDatos; i++) {
		gotoxy(x, y); cout << respuesta[i] << ", ";
		x = x + 4;
	}
	//se imprime la lista con los datos ordenados
	CONTARREPETICIONES();
	system("pause>null");
};
void MAYOR_Y_MENOR() {
	int x = 15, y = 5;
	//NUMERO MAYOR
	for (i = 0; i < CantidadDatos; i++)
	{
		if (respuesta[i] > nMayor) {
			nMayor = respuesta[i];
		}
	}
	gotoxy(x, y); cout << "EL NUMERO MAYOR ES: " << nMayor;
	//NUMERO MENOR
	nMenor = nMayor;
	for (i = 0; i < CantidadDatos; i++)
	{
		if (respuesta[i] < nMenor) {
			nMenor = respuesta[i];
		}
	}
	gotoxy(65, y); cout << "Y EL NUMERO MENOR ES: " << nMenor;
};
void CALCULOS_TABLA() {
	int Rango = 0, x = 15, y = 5;
	Rango = nMayor - nMenor;

	//RANGO
	gotoxy(x, 6); cout << "EL RANGO ES DE: " << Rango;

	//INTERVALO
	Intervalo = 1 + 3.3 * log10(CantidadDatos);
	gotoxy(65, 6); cout << "EL INTERVALO ES DE: " << Intervalo;

	//ANCHO DEL INTERVALO
	Ancho_Intervalo = Rango / Intervalo;
	gotoxy(105, 6); cout << "Y EL ANCHO DEL INTERVALO ES DE: " << Ancho_Intervalo << "\n\n";
};
void NUMERO_DE_INTERVALOS() {
	/*for (x = nMenor; x <= nMayor; x++)
	{
		contadorIntervalos = x + Ancho_Intervalo;
		cout << x << "-" << fixed << setprecision(2) << contadorIntervalos << endl;
		x = contadorIntervalos - 1;
	}*/

	/*
	float decimal;
	int entero;
	entero = Ancho_Intervalo;
	cout << endl << "El entero es: " << entero << endl;

	decimal = Ancho_Intervalo - entero;
	cout << endl << "Los decimales son: "<< decimal << endl;*/
	/*float decimal;
	int entero;
	for (x = nMenor; x < nMayor; x++)
	{
		contadorIntervalos = x + Ancho_Intervalo;
		entero = contadorIntervalos;
		decimal = contadorIntervalos - entero;

		frecuencia[x] = contadorIntervalos;

		cout << x << " - " << fixed << setprecision(2) << frecuencia[x] << endl;
		x = float(frecuencia[x]) + decimal - 1;
	}*/

	float Intervalo2[50][2];
	float auxiliar;
	auxiliar = respuesta[0];
	int x, y;

	for (x = 0; x < Intervalo; x++)
	{
		for (y = 0; y < 2; y++)
		{
			Intervalo2[x][y] = auxiliar;
			if (y == 1)
			{
				auxiliar = Intervalo2[x][y];
			}
			else
			{
				auxiliar = auxiliar + Ancho_Intervalo;
			}
			if (Intervalo2[x][y] > nMayor)
			{
				x = 50;
			}
		}
	}

	for (x = 0; x < Intervalo; x++)
	{
		for (y = 0; y < 2; y++)
		{
			cout << Intervalo2[x][y] << "   ";

			if (Intervalo2[x][y] > nMayor)
			{
				x = 50;
			}
		}
		cout << endl;
	}

};
void DISTRIBUCION_DE_FRECUENCIAS() {
	////////////////////CALCULOS////////////////////
	MAYOR_Y_MENOR();
	CALCULOS_TABLA();
	////////////////////TABLA////////////////////
	NUMERO_DE_INTERVALOS();
	system("pause>null");
};
void menu() {
	int opcion = 0;
	do
	{
		system("cls");
		for (int x = 65; x <= 116; x++)
		{
			gotoxy(x, 13);
			putchar('-');
			gotoxy(x, 34);
			putchar('-');
		}
		for (float y = 14; y <= 33; y++)
		{
			gotoxy(65, y);
			putchar('|');
			gotoxy(116, y);
			putchar('|');
		}
		gotoxy(88, 10); cout << "* MENÚ *";
		gotoxy(70, 16); cout << "INGRESAR DATOS.......................... 1";
		gotoxy(70, 18); cout << "MODIFICAR DATOS......................... 2";
		gotoxy(70, 20); cout << "DATOS ORDENADOS DE MENOR A MAYOR........ 3";
		gotoxy(70, 22); cout << "TABLA DE DISTRIBUCION DE FRECUENCIAS.... 4";
		gotoxy(70, 24); cout << "MEDIDAS DE TENDENCIA CENTRAL............ 5";
		gotoxy(70, 26); cout << "MEDIDAS DE DISPERCION................... 6";
		gotoxy(70, 28); cout << "MEDIDAS DE POSICION..................... 7";
		gotoxy(70, 30); cout << "SALIR DEL PROGRAMA...................... 8";
		gotoxy(100, 32); cout << "OPCIÓN:";
		gotoxy(111, 32); cin >> opcion;
		switch (opcion)
		{
		case 1:
			system("cls");
			INGRESARDATOS();
			break;
		case 2:
			system("cls");
			MODIFICARDATOS();
			break;
		case 3:
			system("cls");
			DATOSORDENADOS();
			break;
		case 4:
			system("cls");
			DISTRIBUCION_DE_FRECUENCIAS();
			break;
		default:
			system("cls");
			break;
		};
	} while (opcion != 8);

};
int main()
{
	setlocale(LC_CTYPE, "Spanish");
	menu();
	system("pause>null");
	return 0;
}