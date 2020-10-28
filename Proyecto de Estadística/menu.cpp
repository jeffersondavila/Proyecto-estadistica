#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <Windows.h>
#include <stdio.h>
#include <cmath>
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
int i, j, x, y;
float Respuesta[100];
float Datos[100], CantidadDatos, aux;
float nMenor, nMayor, Ancho_Intervalo, Intervalo, acumulado, Rango;
float vectora[100], vectorb[100], FrecuenciaAbsoluta[100], inicial = 0, sumador = 0, sumador2;
float marca_de_clase[100];
float FrecuenciaAbsolutaAcumulada[100], acumulador = 0;
float FrecuenciaRel[100];
float FrecuenciaRelDesc[100];
float calculoPromedio = 0;
float mcMprom2 = 0;
float Media;
float posicion;
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
		gotoxy(x, y); cout << "INGRESE EL DATO # " << i + 1 << "\t"; cin >> Datos[i];
		gotoxy(x1, y1); cout << i + 1 << ".\t" << Datos[i];
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
			if (Datos[i] > Datos[j]) {
				aux = Datos[i];
				Datos[i] = Datos[j];
				Datos[j] = aux;
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
		gotoxy(x1, y1); cout << i << ".\t" << Datos[i];
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
				gotoxy(70, 6); cout << "INGRESE NUEVO DATO: "; cin >> Datos[i];
				cout << Datos[i];
			}
		}
		//se guarda la modificación y en los dos vectores
		system("cls");
		for (i = 0; i < CantidadDatos; i++) {
			for (j = i + 1; j < CantidadDatos; j++) {
				if (Datos[i] > Datos[j]) {
					aux = Datos[i];
					Datos[i] = Datos[j];
					Datos[j] = aux;
				}
			}
		}
		//se ordena los vectores con la modificación ya echa
		gotoxy(x1, 2); cout << "LA NUEVA LISTA DE DATOS INGRESADOS ES:"; x1 = 10, y1 = 5;
		for (i = 0; i < CantidadDatos; i++)
		{
			gotoxy(x1, y1); cout << i << ".\t" << Datos[i];
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
void NumeroMayor() {
	x = 30;
	for (i = 0; i < CantidadDatos; i++)
	{
		if (Datos[i] > nMayor) {
			nMayor = Datos[i];
		}
	}
	gotoxy(x, 5); cout << "EL NUMERO MAYOR ES: " << nMayor;
}
void NumeroMenor() {
	nMenor = nMayor;
	for (i = 0; i < CantidadDatos; i++)
	{
		if (Datos[i] < nMenor) {
			nMenor = Datos[i];
		}
	}
	gotoxy(60, 5); cout << "EL NUMERO MENOR ES: " << nMenor;
}
void RANGO() {
	Rango = nMayor - nMenor;
	gotoxy(90, 5); cout << "EL RANGO ES DE: " << Rango;
}
void INTERVALO() {
	Intervalo = 1 + 3.3 * log10(CantidadDatos);
	gotoxy(30, 7); cout << "EL INTERVALO ES DE: " << fixed << setprecision(0) << Intervalo;
}
void ANCHO_DE_INTERVALO() {
	Ancho_Intervalo = Rango / Intervalo;
	gotoxy(60, 7); cout << "Y EL ANCHO DEL INTERVALO ES DE: " << setprecision(2) << Ancho_Intervalo << "\n\n";
}
void IMPRIMIR_INTERVALOS() {
	y = 10;
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
}
void FRECUENCIA_ABSOLUTA() {
	y = 10;
	for (int i = 0; i < Intervalo; i++)
	{
		sumador2 = 0;
		for (int j = 0; j < CantidadDatos; j++)
		{
			if (Datos[j] >= vectora[i] && Datos[j] < vectorb[i])
			{
				sumador2++;
			}
		}
		if (sumador2 > 0)
		{
			gotoxy(40, 9); cout << "fi";
			gotoxy(40, y); cout << sumador2 << endl;
			FrecuenciaAbsoluta[i] = sumador2;
			FrecuenciaRel[i] = sumador2;
		}
		y++;
	}
}
void MARCA_DE_CLASE() {
	int intervaloizq = 0, intervaloder = 0, y = 10;
	for (int i = 0; i < Intervalo; i++)
	{
		marca_de_clase[i] = (vectora[i] + vectorb[i]) / 2;
		gotoxy(50, 9); cout << "Xi";
		gotoxy(50, y); cout << marca_de_clase[i];
		y++;
	}
}
void FRECUENCIA_ABSOLUTA_ACUMULADA() {
	y = 10;
	for (i = 0; i <= Intervalo; i++)
	{
		acumulador = FrecuenciaAbsoluta[i] + acumulador;
		FrecuenciaAbsolutaAcumulada[i] = acumulador;
		gotoxy(60, 9); cout << "Fi";
		gotoxy(60, y); cout << FrecuenciaAbsolutaAcumulada[i];
		y++;
	}
}
void FRECUENCIA_RELATIVA() {
	y = 10;
	for (i = 0; i < Intervalo; i++)
	{
		FrecuenciaRelDesc[i] = (FrecuenciaRel[i] / CantidadDatos);
		gotoxy(70, 9); cout << "Fr%";
		gotoxy(70, y); cout << (FrecuenciaRel[i] / CantidadDatos);
		y++;
	}
}
void FRECUENCIA_ACUMULADA_DESCENDENTE() {
	float auxi = 0;
	acumulador = CantidadDatos;
	y = 10;
	for (i = 0; i <= Intervalo; i++)
	{
		gotoxy(80, 9); cout << "fi desc.";
		gotoxy(80, y); cout << acumulador;
		auxi = auxi + acumulador;
		acumulador = acumulador - FrecuenciaAbsoluta[i];
		y++;
	}
	gotoxy(80, y); cout << "--------"; y++;
	gotoxy(80, y); cout << auxi;
}
void FRECUENCIA_RELATIVA_ASCENDENTE() {
	y = 10;
	acumulador = FrecuenciaRelDesc[0];
	for (i = 1; i < Intervalo + 1; i++)
	{
		gotoxy(90, 9); cout << "Fr% asc.";
		gotoxy(90, y); cout << acumulador;
		acumulador = FrecuenciaRelDesc[i] + acumulador;
		y++;
	}
}
void FRECUENCIA_RELATIVA_DESCENDENTE() {
	acumulador = 1;
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
		calculoPromedio = FrecuenciaAbsoluta[i] * marca_de_clase[i];
		gotoxy(110, y); cout << calculoPromedio << endl;
		y++;
	}
}
void PROMEDIO() {
	float mcMprom = 0;
	for (int i = 0; i < Intervalo; i++)
	{
		calculoPromedio = FrecuenciaAbsoluta[i] * marca_de_clase[i];
		mcMprom = mcMprom + calculoPromedio;
	}
	mcMprom2 = mcMprom / CantidadDatos;
	cout << "\nX = " << mcMprom << " / " << CantidadDatos << " = " << mcMprom2;
}
void XmenosPROMEDIO() {
	float x1;
	y = 10;
	for (int i = 0; i < Intervalo; i++)
	{
		gotoxy(120, 9); cout << "|Xi - X|";
		x1 = abs(marca_de_clase[i] - mcMprom2);
		gotoxy(120, y); cout << x1 << endl;
		y++;
	}
}
void XmPCUADRADO() {
	float x2;
	y = 10;
	for (int i = 0; i < Intervalo; i++)
	{
		gotoxy(130, 9); cout << "|Xi - X|^2";
		x2 = (marca_de_clase[i] - mcMprom2) * (marca_de_clase[i] - mcMprom2);
		gotoxy(133, y); cout << x2 << endl;
		y++;
	}
}
void XmPCF() {
	float x3;
	y = 10;
	for (int i = 0; i < Intervalo; i++)
	{
		gotoxy(143, 9); cout << "|Xi - X|^2 * fi";
		x3 = ((marca_de_clase[i] - mcMprom2) * (marca_de_clase[i] - mcMprom2)) * FrecuenciaAbsoluta[i];
		gotoxy(145, y); cout << x3 << endl;
		y++;
	}
}
void DISTRIBUCION_DE_FRECUENCIAS() {
	NumeroMayor();
	NumeroMenor();
	RANGO();
	INTERVALO();
	ANCHO_DE_INTERVALO();
	IMPRIMIR_INTERVALOS();
	FRECUENCIA_ABSOLUTA();
	MARCA_DE_CLASE();
	FRECUENCIA_ABSOLUTA_ACUMULADA();
	FRECUENCIA_RELATIVA();
	FRECUENCIA_ACUMULADA_DESCENDENTE();
	FRECUENCIA_RELATIVA_ASCENDENTE();
	FRECUENCIA_RELATIVA_DESCENDENTE();
	XIFI();
	PROMEDIO();
	XmenosPROMEDIO();
	XmPCUADRADO();
	XmPCF();
	system("pause>null");
};
void MEDIA() {
	y = 10;
	float mcMprom = 0;
	for (int i = 0; i < Intervalo; i++)
	{
		calculoPromedio = FrecuenciaAbsoluta[i] * marca_de_clase[i];
		mcMprom = mcMprom + calculoPromedio;
	}
	Media = mcMprom / CantidadDatos;
	cout << "\n\n----------------------";
	cout << "\nX = " << mcMprom << " / " << CantidadDatos << " = " << Media;
	cout << "\n----------------------\n";
}
void MEDIANA() {
	float calculo1, calculo2, calculo3, totalMediana, auxi[100], encontrado2 = 0;
	bool encontrado = false;
	aux = 650;
	posicion = CantidadDatos / 2;
	cout << "\n\nPosicion = " << CantidadDatos << " / 2 = " << posicion << endl;
	for (int i = 0; i < Intervalo; i++)
	{
		if (posicion == FrecuenciaAbsolutaAcumulada[i])
		{
			cout << "\n\n**********MEDIANA**********\n\n";
			cout << " FRECUENCIA ABSOLUTA: " << FrecuenciaAbsoluta[i] << endl;
			cout << " FRECUENCIA ABSOLUTA ACUMULADA - 1: " << FrecuenciaAbsolutaAcumulada[i - 1] << endl;
			cout << " LIMITE INFERIOR: " << vectora[i] << endl;
			cout << " POSICIÓN: " << posicion << endl;
			cout << " ANCHO DE INTERVALO: " << Ancho_Intervalo << endl;
			calculo1 = posicion - FrecuenciaAbsolutaAcumulada[i - 1];
			calculo2 = calculo1 / FrecuenciaAbsoluta[i];
			calculo3 = calculo2 * Ancho_Intervalo;
			totalMediana = vectora[i] + calculo3;
			cout << " MEDIANA: " << totalMediana << endl;
			encontrado = true;
			encontrado = 1;
		}
		if (FrecuenciaAbsolutaAcumulada[i] > posicion)
		{
			if (aux > FrecuenciaAbsolutaAcumulada[i])
			{
				aux = FrecuenciaAbsolutaAcumulada[i];
			}
		}
	}
	if (encontrado == false && encontrado2 == 0)
	{
		float acum = 0;
		acum = aux - posicion;
		cout << " A la posicion " << posicion << " Se le suma " << acum << " para encontrar su posición en la tabla: " << aux << endl;
		for (int i = 0; i < Intervalo; i++)
		{
			if (aux == FrecuenciaAbsolutaAcumulada[i])
			{
				cout << "\n\n**********MEDIANA**********\n\n";
				cout << " FRECUENCIA ABSOLUTA: " << FrecuenciaAbsoluta[i] << endl;
				cout << " FRECUENCIA ABSOLUTA ACUMULADA - 1: " << FrecuenciaAbsolutaAcumulada[i - 1] << endl;
				cout << " LIMITE INFERIOR: " << vectora[i] << endl;
				cout << " POSICIÓN: " << posicion << endl;
				cout << " ANCHO DE INTERVALO: " << Ancho_Intervalo << endl;
				calculo1 = posicion - FrecuenciaAbsolutaAcumulada[i - 1];
				calculo2 = calculo1 / FrecuenciaAbsoluta[i];
				calculo3 = calculo2 * Ancho_Intervalo;
				totalMediana = vectora[i] + calculo3;
				cout << " MEDIANA: " << totalMediana << endl;
			}
		}
	}
}
void MODA() {
	float calculo1, calculo2, calculo3, calculo4, totalModa, auxi[100], encontrado2 = 0;
	bool encontrado = false;
	aux = 650;
	posicion = CantidadDatos / 2;
	cout << "\n\nPosicion = " << CantidadDatos << " / 2 = " << posicion << endl;
	for (int i = 0; i < Intervalo; i++)
	{
		if (posicion == FrecuenciaAbsolutaAcumulada[i])
		{
			cout << "\n\n**********MODA**********\n\n";
			cout << " FRECUENCIA ABSOLUTA: " << FrecuenciaAbsoluta[i] << endl;
			cout << " FRECUENCIA ABSOLUTA - 1: " << FrecuenciaAbsoluta[i - 1] << endl;
			cout << " FRECUENCIA ABSOLUTA + 1: " << FrecuenciaAbsoluta[i + 1] << endl;
			cout << " LIMITE INFERIOR: " << vectora[i] << endl;
			cout << " ANCHO DE INTERVALO: " << Ancho_Intervalo << endl;
			calculo1 = FrecuenciaAbsoluta[i] - FrecuenciaAbsoluta[i - 1];
			calculo2 = (FrecuenciaAbsoluta[i] - FrecuenciaAbsoluta[i - 1]) + (FrecuenciaAbsoluta[i] - FrecuenciaAbsoluta[i + 1]);
			calculo3 = calculo1 / calculo2;
			calculo4 = calculo3 * Ancho_Intervalo;
			totalModa = vectora[i] + calculo4;
			cout << " MODA: " << totalModa << endl;
			encontrado = true;
			encontrado = 1;
		}
		if (FrecuenciaAbsolutaAcumulada[i] > posicion)
		{
			if (aux > FrecuenciaAbsolutaAcumulada[i])
			{
				aux = FrecuenciaAbsolutaAcumulada[i];
			}
		}
	}
	if (encontrado == false && encontrado2 == 0)
	{
		float acum = 0;
		acum = aux - posicion;
		cout << " A la posicion " << posicion << " Se le suma " << acum << " para encontrar su posición en la tabla: " << aux << endl;
		for (int i = 0; i < Intervalo; i++)
		{
			if (aux == FrecuenciaAbsolutaAcumulada[i])
			{
				cout << "\n\n**********MODA**********\n\n";
				cout << " FRECUENCIA ABSOLUTA: " << FrecuenciaAbsoluta[i] << endl;
				cout << " FRECUENCIA ABSOLUTA - 1: " << FrecuenciaAbsoluta[i - 1] << endl;
				cout << " FRECUENCIA ABSOLUTA + 1: " << FrecuenciaAbsoluta[i + 1] << endl;
				cout << " LIMITE INFERIOR: " << vectora[i] << endl;
				cout << " ANCHO DE INTERVALO: " << Ancho_Intervalo << endl;
				calculo1 = FrecuenciaAbsoluta[i] - FrecuenciaAbsoluta[i - 1];
				calculo2 = (FrecuenciaAbsoluta[i] - FrecuenciaAbsoluta[i - 1]) + (FrecuenciaAbsoluta[i] - FrecuenciaAbsoluta[i + 1]);
				calculo3 = calculo1 / calculo2;
				calculo4 = calculo3 * Ancho_Intervalo;
				totalModa = vectora[i] + calculo4;
				cout << " MODA: " << totalModa << endl;
			}
		}
	}
}
void CUARTIL() {
	float calculo1, calculo2, calculo3, calculo4, totalCuartil, auxi[100], encontrado2 = 0, numero, posicion2;
	bool encontrado = false;
	aux = 650;

	gotoxy(69, 21); cout << "INGRESE EL NÚMERO DEL CUARTIL: ";
	gotoxy(101, 21); cin >> numero;

	posicion2 = numero * CantidadDatos / 4;

	gotoxy(68, 24); cout << "Posicion = " << numero << " * " << CantidadDatos << " / 4 = " << posicion2 << endl;
	
	for (int i = 0; i < Intervalo; i++)
	{
		for (int x = 60; x <= 112; x++)
		{
			gotoxy(x, 18);
			putchar('-');
			gotoxy(x, 26);
			putchar('-');
			gotoxy(x, 39);
			putchar('-');
		}

		if (posicion2 == FrecuenciaAbsolutaAcumulada[i])
		{
			gotoxy(72, 28); cout << "**********CUARTIL**********";
			gotoxy(65, 30); cout << " FRECUENCIA ABSOLUTA ACUMULADA: " << FrecuenciaAbsolutaAcumulada[i] << endl;
			gotoxy(65, 31); cout << " FRECUENCIA ABSOLUTA ACUMULADA - 1: " << FrecuenciaAbsolutaAcumulada[i - 1] << endl;
			gotoxy(65, 32); cout << " LIMITE INFERIOR: " << vectora[i] << endl;
			gotoxy(65, 33); cout << " POSICIÓN: " << posicion2 << endl;
			gotoxy(65, 34); cout << " ANCHO DE INTERVALO: " << Ancho_Intervalo << endl;
			calculo1 = posicion2 - FrecuenciaAbsolutaAcumulada[i - 1];
			calculo2 = FrecuenciaAbsolutaAcumulada[i] - FrecuenciaAbsolutaAcumulada[i - 1];
			calculo3 = calculo1 / calculo2;
			calculo4 = calculo3 * Ancho_Intervalo;
			totalCuartil = vectora[i] + calculo4;
			gotoxy(65, 36); cout << " CUARTIL: " << totalCuartil << endl;
			encontrado = true;
			encontrado = 1;
		}
		if (FrecuenciaAbsolutaAcumulada[i] > posicion2)
		{
			if (aux > FrecuenciaAbsolutaAcumulada[i])
			{
				aux = FrecuenciaAbsolutaAcumulada[i];
			}
		}
	}
	if (encontrado == false && encontrado2 == 0)
	{
		float acum = 0;
		acum = aux - posicion2;
		for (int i = 0; i < Intervalo; i++)
		{
			if (aux == FrecuenciaAbsolutaAcumulada[i])
			{
				gotoxy(72, 28); cout << "**********CUARTIL**********";
				gotoxy(65, 30); cout << " FRECUENCIA ABSOLUTA ACUMULADA: " << FrecuenciaAbsolutaAcumulada[i] << endl;
				gotoxy(65, 31); cout << " FRECUENCIA ABSOLUTA ACUMULADA - 1: " << FrecuenciaAbsolutaAcumulada[i - 1] << endl;
				gotoxy(65, 32); cout << " LIMITE INFERIOR: " << vectora[i] << endl;
				gotoxy(65, 33); cout << " POSICIÓN: " << posicion2 << endl;
				gotoxy(65, 34); cout << " ANCHO DE INTERVALO: " << Ancho_Intervalo << endl;
				calculo1 = posicion2 - FrecuenciaAbsolutaAcumulada[i - 1];
				calculo2 = FrecuenciaAbsolutaAcumulada[i] - FrecuenciaAbsolutaAcumulada[i - 1];
				calculo3 = calculo1 / calculo2;
				calculo4 = calculo3 * Ancho_Intervalo;
				totalCuartil = vectora[i] + calculo4;
				gotoxy(65, 36); cout << " CUARTIL: " << totalCuartil << endl;
			}
		}
	}

	system("pause>null");
}
void DECIL() {
	float calculo1, calculo2, calculo3, calculo4, totalDecil, auxi[100], encontrado2 = 0, numero, posicion2;
	bool encontrado = false;
	aux = 650;

	gotoxy(69, 21); cout << "INGRESE EL NÚMERO DEL DECIL: ";
	gotoxy(101, 21); cin >> numero;

	posicion2 = numero * CantidadDatos / 10;

	gotoxy(68, 24); cout << "Posicion = " << numero << " * " << CantidadDatos << " / 10 = " << posicion2 << endl;

	for (int i = 0; i < Intervalo; i++)
	{
		for (int x = 60; x <= 112; x++)
		{
			gotoxy(x, 18);
			putchar('-');
			gotoxy(x, 26);
			putchar('-');
			gotoxy(x, 39);
			putchar('-');
		}

		if (posicion2 == FrecuenciaAbsolutaAcumulada[i])
		{
			gotoxy(72, 28); cout << "**********DECIL**********";
			gotoxy(65, 30); cout << " FRECUENCIA ABSOLUTA ACUMULADA: " << FrecuenciaAbsolutaAcumulada[i] << endl;
			gotoxy(65, 31); cout << " FRECUENCIA ABSOLUTA ACUMULADA - 1: " << FrecuenciaAbsolutaAcumulada[i - 1] << endl;
			gotoxy(65, 32); cout << " LIMITE INFERIOR: " << vectora[i] << endl;
			gotoxy(65, 33); cout << " POSICIÓN: " << posicion2 << endl;
			gotoxy(65, 34); cout << " ANCHO DE INTERVALO: " << Ancho_Intervalo << endl;
			calculo1 = posicion2 - FrecuenciaAbsolutaAcumulada[i - 1];
			calculo2 = FrecuenciaAbsolutaAcumulada[i] - FrecuenciaAbsolutaAcumulada[i - 1];
			calculo3 = calculo1 / calculo2;
			calculo4 = calculo3 * Ancho_Intervalo;
			totalDecil = vectora[i] + calculo4;
			gotoxy(65, 36); cout << " DECIL: " << totalDecil << endl;
			encontrado = true;
			encontrado = 1;
		}
		if (FrecuenciaAbsolutaAcumulada[i] > posicion2)
		{
			if (aux > FrecuenciaAbsolutaAcumulada[i])
			{
				aux = FrecuenciaAbsolutaAcumulada[i];
			}
		}
	}
	if (encontrado == false && encontrado2 == 0)
	{
		float acum = 0;
		acum = aux - posicion2;
		for (int i = 0; i < Intervalo; i++)
		{
			if (aux == FrecuenciaAbsolutaAcumulada[i])
			{
				gotoxy(72, 28); cout << "**********DECIL**********";
				gotoxy(65, 30); cout << " FRECUENCIA ABSOLUTA ACUMULADA: " << FrecuenciaAbsolutaAcumulada[i] << endl;
				gotoxy(65, 31); cout << " FRECUENCIA ABSOLUTA ACUMULADA - 1: " << FrecuenciaAbsolutaAcumulada[i - 1] << endl;
				gotoxy(65, 32); cout << " LIMITE INFERIOR: " << vectora[i] << endl;
				gotoxy(65, 33); cout << " POSICIÓN: " << posicion2 << endl;
				gotoxy(65, 34); cout << " ANCHO DE INTERVALO: " << Ancho_Intervalo << endl;
				calculo1 = posicion2 - FrecuenciaAbsolutaAcumulada[i - 1];
				calculo2 = FrecuenciaAbsolutaAcumulada[i] - FrecuenciaAbsolutaAcumulada[i - 1];
				calculo3 = calculo1 / calculo2;
				calculo4 = calculo3 * Ancho_Intervalo;
				totalDecil = vectora[i] + calculo4;
				gotoxy(65, 36); cout << " DECIL: " << totalDecil << endl;
			}
		}
	}

	system("pause>null");
}
void PERCENTIL() {
	float calculo1, calculo2, calculo3, calculo4, totalPercentil, auxi[100], encontrado2 = 0, numero, posicion2;
	bool encontrado = false;
	aux = 650;

	gotoxy(69, 21); cout << "INGRESE EL NÚMERO DEL PERCENTIL: ";
	gotoxy(101, 21); cin >> numero;

	posicion2 = numero * CantidadDatos / 100;

	gotoxy(68, 24); cout << "Posicion = " << numero << " * " << CantidadDatos << " / 100 = " << posicion2 << endl;

	for (int i = 0; i < Intervalo; i++)
	{
		for (int x = 60; x <= 112; x++)
		{
			gotoxy(x, 18);
			putchar('-');
			gotoxy(x, 26);
			putchar('-');
			gotoxy(x, 39);
			putchar('-');
		}

		if (posicion2 == FrecuenciaAbsolutaAcumulada[i])
		{
			gotoxy(72, 28); cout << "**********PERCENTIL**********";
			gotoxy(65, 30); cout << " FRECUENCIA ABSOLUTA ACUMULADA: " << FrecuenciaAbsolutaAcumulada[i] << endl;
			gotoxy(65, 31); cout << " FRECUENCIA ABSOLUTA ACUMULADA - 1: " << FrecuenciaAbsolutaAcumulada[i - 1] << endl;
			gotoxy(65, 32); cout << " LIMITE INFERIOR: " << vectora[i] << endl;
			gotoxy(65, 33); cout << " POSICIÓN: " << posicion2 << endl;
			gotoxy(65, 34); cout << " ANCHO DE INTERVALO: " << Ancho_Intervalo << endl;
			calculo1 = posicion2 - FrecuenciaAbsolutaAcumulada[i - 1];
			calculo2 = FrecuenciaAbsolutaAcumulada[i] - FrecuenciaAbsolutaAcumulada[i - 1];
			calculo3 = calculo1 / calculo2;
			calculo4 = calculo3 * Ancho_Intervalo;
			totalPercentil = vectora[i] + calculo4;
			gotoxy(65, 36); cout << " PERCENTIL: " << totalPercentil << endl;
			encontrado = true;
			encontrado = 1;
		}
		if (FrecuenciaAbsolutaAcumulada[i] > posicion2)
		{
			if (aux > FrecuenciaAbsolutaAcumulada[i])
			{
				aux = FrecuenciaAbsolutaAcumulada[i];
			}
		}
	}
	if (encontrado == false && encontrado2 == 0)
	{
		float acum = 0;
		acum = aux - posicion2;
		for (int i = 0; i < Intervalo; i++)
		{
			if (aux == FrecuenciaAbsolutaAcumulada[i])
			{
				gotoxy(72, 28); cout << "**********PERCENTIL**********";
				gotoxy(65, 30); cout << " FRECUENCIA ABSOLUTA ACUMULADA: " << FrecuenciaAbsolutaAcumulada[i] << endl;
				gotoxy(65, 31); cout << " FRECUENCIA ABSOLUTA ACUMULADA - 1: " << FrecuenciaAbsolutaAcumulada[i - 1] << endl;
				gotoxy(65, 32); cout << " LIMITE INFERIOR: " << vectora[i] << endl;
				gotoxy(65, 33); cout << " POSICIÓN: " << posicion2 << endl;
				gotoxy(65, 34); cout << " ANCHO DE INTERVALO: " << Ancho_Intervalo << endl;
				calculo1 = posicion2 - FrecuenciaAbsolutaAcumulada[i - 1];
				calculo2 = FrecuenciaAbsolutaAcumulada[i] - FrecuenciaAbsolutaAcumulada[i - 1];
				calculo3 = calculo1 / calculo2;
				calculo4 = calculo3 * Ancho_Intervalo;
				totalPercentil = vectora[i] + calculo4;
				gotoxy(65, 36); cout << " PERCENTIL: " << totalPercentil << endl;
			}
		}
	}

	system("pause>null");
}
void menu() {
	int opcion = 0, opcion2 = 0;
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
			break;
		case 4:
			system("cls");
			DISTRIBUCION_DE_FRECUENCIAS();
			break;
		case 5:
			system("cls");
			MEDIA();
			MEDIANA();
			MODA();
			system("pause>null");
			break;
		case 7:
			do {
				system("cls");
				for (int x = 65; x <= 93; x++)
				{
					gotoxy(x, 13);
					putchar('-');
					gotoxy(x, 27);
					putchar('-');
				}
				for (float y = 14; y <= 26; y++)
				{
					gotoxy(65, y);
					putchar('|');
					gotoxy(93, y);
					putchar('|');
				}
				gotoxy(70, 10); cout << "* MENÚ DISPERCIÓN *";
				gotoxy(70, 16); cout << "CUARTIL.......... 1";
				gotoxy(70, 18); cout << "DECIL............ 2";
				gotoxy(70, 20); cout << "PERCENTIL........ 3";
				gotoxy(70, 22); cout << "REGRESAR......... 4";
				gotoxy(80, 24); cout << "OPCIÓN: ";
				gotoxy(88, 24); cin >> opcion2;
				switch (opcion2) {
				case 1:
					system("cls");
					CUARTIL();
					break;
				case 2:
					system("cls");
					DECIL();
					break;
				case 3:
					system("cls");
					PERCENTIL();
					break;
				default:
					system("cls");
					break;
				}
			} while (opcion2 != 4);
			break;
		default:
			system("cls");
			break;
		};
	} while (opcion != 8);

};
int main() {
	setlocale(LC_CTYPE, "Spanish");
	menu();
	system("pause>null");
	return 0;
}