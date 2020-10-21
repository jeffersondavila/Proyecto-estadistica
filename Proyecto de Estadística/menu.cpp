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

int CantidadDatos, i, j, x, y;
float respuesta[100], temp, n, aux, Ancho_Intervalo = 0, nMayor = 0, nMenor, sum;
float Intervalo = 0, auxiliar, vectora[100], vectorb[100], marca_de_clase[100], FrecuenciaAcum[100], FrecuenciaRel[100], FrecuenciaRelDesc[100];
float calculoPromedio = 0, mcMprom2, x1, x2, x4;

void INGRESARDATOS() {
	int x = 30, y = 5, x1 = 90, y1 = 5;

	gotoxy(x, 2); cout << "INGRESE LA CANTIDAD TOTAL DE DATOS  NÚMERICOS: \t"; cin >> CantidadDatos;
	for (int x = 88; x <= 117; x++)
	{
		gotoxy(x, 4); putchar('-');
	}
	gotoxy(x1, 2); cout << "LISTA DE DATOS INGRESADOS:";
	for (i = 0; i < CantidadDatos; i++)
	{
		gotoxy(x, y); cout << "INGRESE EL DATO # " << i + 1 << "\t"; cin >> respuesta[i];
		gotoxy(x1, y1); cout << i + 1 << ".\t" << respuesta[i];
		gotoxy(88, y1); putchar('|');
		gotoxy(117, y1); putchar('|');
		y++, y1++;
	}
	for (int x = 88; x <= 117; x++)
	{
		gotoxy(x, y1); putchar('-');
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
}
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
}
void CONTARREPETICIONES() {
	for (int q = 0; q < 300; q++) {
		sum = 0;
		for (j = 0; j < CantidadDatos; j++) {
			if (respuesta[q] == respuesta[j]) {
				sum = sum + 1;
			}
		}
		if (0 < sum && sum < 2) {//si es mayor a 0 el contador es porque se repite el numero
			gotoxy(x, y); cout << "El número " << respuesta[q] << " se repite " << sum << " vez.";
			y++;
		}
		if (sum >= 2)
		{
			gotoxy(x, y); cout << "El número " << respuesta[q] << " se repite " << sum << " veces.";
			y++;
		}
	}

	x = 25, y = 5;
	gotoxy(x, 5); cout << "LISTADO DE DATOS ORDENADOS: ";
	x = 55;
	for (i = 0; i < CantidadDatos; i++) {
		gotoxy(x, y); cout << respuesta[i] << ",";
		x = x + 7;
	}
	//se imprime la lista con los datos ordenados
	system("pause>null");
}
void FRECUENCIAABSOLUTA() {
	int y = 10;
	float inicial = 0, sumador = 0, sumador2;
	inicial = nMenor;
	sumador = nMenor + Ancho_Intervalo;

	for (int i = 0; i < Intervalo; i++)
	{
		gotoxy(15, 9); cout << "No. Intervalos";
		gotoxy(10, y); cout << setprecision(3) << inicial << "\t\t" << setprecision(3) << sumador << endl;
		vectora[i] = inicial;
		vectorb[i] = sumador;

		inicial = sumador;
		sumador = sumador + Ancho_Intervalo;
		y++;
	}
	y = 10;
	for (int i = 0; i < Intervalo; i++)
	{
		sumador2 = 0;
		for (int j = 0; j < CantidadDatos; j++)
		{
			if (respuesta[j] >= vectora[i] && respuesta[j] < vectorb[i])
			{
				sumador2++;
			}
		}
		if (sumador2 > 0)
		{
			gotoxy(40, 9); cout << "fi";
			gotoxy(40, y); cout << sumador2 << endl;
		}
		FrecuenciaAcum[i] = sumador2;
		FrecuenciaRel[i] = sumador2;
		y++;
	}
}
void MARCADECLASE() {
	int intervaloizq = 0, intervaloder = 0, y = 10;
	for (int i = 0; i < Intervalo; i++)
	{
		marca_de_clase[i] = (vectora[i] + vectorb[i]) / 2;
		gotoxy(50, 9); cout << "Xi";
		gotoxy(50, y); cout << marca_de_clase[i];
		y++;
	}
}
void FRECUENCIAABSOLUTAACUMULADA() {
	float acumulador = 0;
	int y = 10;

	for (i = 0; i <= Intervalo; i++)
	{
		acumulador = FrecuenciaAcum[i] + acumulador;
		gotoxy(60, 9); cout << "Fi";
		gotoxy(60, y); cout << acumulador;
		y++;
	}
}
void FRECUENCIARELATIVA() {
	y = 10;
	for (i = 0; i < Intervalo; i++)
	{
		FrecuenciaRelDesc[i] = (FrecuenciaRel[i] / CantidadDatos);
		gotoxy(70, 9); cout << "Fr%";
		gotoxy(70, y); cout << (FrecuenciaRel[i] / CantidadDatos);
		y++;
	}
}
void FRECUENCIAACUMULADA_DESCENDENTE() {
	float acumulador = CantidadDatos;
	y = 10;
	for (i = 0; i <= Intervalo; i++)
	{
		gotoxy(80, 9); cout << "fi desc.";
		gotoxy(80, y); cout << acumulador;
		acumulador = acumulador - FrecuenciaAcum[i];
		y++;
	}
}
void FRECUENCIARELATIVAASCENDENTE() {
	float acumulador;
	int y = 10;
	acumulador = FrecuenciaRelDesc[0];
	for (i = 1; i < Intervalo + 1; i++)
	{
		gotoxy(90, 9); cout << "Fr% asc.";
		gotoxy(90, y); cout << acumulador;
		acumulador = FrecuenciaRelDesc[i] + acumulador;
		y++;
	}
}
void FRECUENCIARELATIVADESCENDENTE() {
	float acumulador = 1;
	y = 10;
	for (i = 0; i <= Intervalo; i++)
	{
		gotoxy(100, 9); cout << "Fr% desc.";
		gotoxy(100, y); cout << acumulador;
		acumulador = acumulador - FrecuenciaRelDesc[i];
		y++;
	}
}
void XIFI() {
	int y = 10;
	for (int i = 0; i < Intervalo; i++)
	{
		gotoxy(110, 9); cout << "fi*xi";
		calculoPromedio = FrecuenciaAcum[i] * marca_de_clase[i];
		gotoxy(110, y); cout << calculoPromedio << endl;
		y++;
	}
}
void PROMEDIO() {
	int y = 10;
	float mcMprom = 0;
	for (int i = 0; i < Intervalo; i++)
	{
		calculoPromedio = FrecuenciaAcum[i] * marca_de_clase[i];
		mcMprom = mcMprom + calculoPromedio;
	}
	mcMprom2 = mcMprom / CantidadDatos;
	cout << "\nX = " << mcMprom << " / " << CantidadDatos << " = " << mcMprom2;
}
void XmenosPROMEDIO() {
	int y = 10;
	for (int i = 0; i < Intervalo; i++)
	{
		gotoxy(120, 9); cout << "|Xi - X|";
		x1 = (marca_de_clase[i] - mcMprom2) * -1;
		gotoxy(120, y); cout << x1 << endl;
		y++;
	}
}
void XmPCUADRADO() {
	int y = 10;
	for (int i = 0; i < Intervalo; i++)
	{
		gotoxy(130, 9); cout << "|Xi - X|^2";
		x2 = (marca_de_clase[i] - mcMprom2) * (marca_de_clase[i] - mcMprom2);
		gotoxy(133, y); cout << x2 << endl;
		y++;
	}
}
void XmPCF() {
	int y = 10;
	for (int i = 0; i < Intervalo; i++)
	{
		gotoxy(143, 9); cout << "|Xi - X|^2 * fi";
		x4 = ((marca_de_clase[i] - mcMprom2) * (marca_de_clase[i] - mcMprom2)) * FrecuenciaAcum[i];
		gotoxy(145, y); cout << x4 << endl;
		y++;
	}
}
void DISTRIBUCION_DE_FRECUENCIAS() {
	float acumulado = 0;
	int Rango = 0, x = 5;

	//NUMERO MAYOR
	for (i = 0; i < CantidadDatos; i++)
	{
		if (respuesta[i] > nMayor) {
			nMayor = respuesta[i];
		}
	}
	gotoxy(x, 5); cout << "EL NUMERO MAYOR ES: " << nMayor;
	//NUMERO MENOR
	nMenor = nMayor;
	for (i = 0; i < CantidadDatos; i++)
	{
		if (respuesta[i] < nMenor) {
			nMenor = respuesta[i];
		}
	}
	gotoxy(30, 5); cout << "EL NUMERO MENOR ES: " << nMenor;
	Rango = nMayor - nMenor;

	//RANGO
	gotoxy(57, 5); cout << "EL RANGO ES DE: " << Rango;

	//INTERVALO
	Intervalo = 1 + 3.3 * log10(CantidadDatos);
	gotoxy(x, 7); cout << "EL INTERVALO ES DE: " << fixed << setprecision(0) << Intervalo;

	//ANCHO DEL INTERVALO
	Ancho_Intervalo = Rango / Intervalo;
	gotoxy(35, 7); cout << "Y EL ANCHO DEL INTERVALO ES DE: " << Ancho_Intervalo << "\n\n";

	////////////////////TABLA////////////////////
	FRECUENCIAABSOLUTA();
	MARCADECLASE();
	FRECUENCIAABSOLUTAACUMULADA();
	FRECUENCIARELATIVA();
	FRECUENCIAACUMULADA_DESCENDENTE();
	FRECUENCIARELATIVAASCENDENTE();
	FRECUENCIARELATIVADESCENDENTE();
	XIFI();
	PROMEDIO();
	XmenosPROMEDIO();
	XmPCUADRADO();
	XmPCF();

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
			CONTARREPETICIONES();
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