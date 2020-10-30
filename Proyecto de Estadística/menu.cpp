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
float ejey;
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
int opcion2;
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
	int x1 = 25, y1 = 4, posicion;
	for (int x = 25; x <= 51; x++)
	{
		gotoxy(x, 1); putchar('-');
	}
	gotoxy(x1, 2); cout << "|LISTA DE DATOS INGRESADOS|";
	for (int x = 25; x <= 51; x++)
	{
		gotoxy(x, 3); putchar('-');
	}
	for (i = 0; i < CantidadDatos; i++)
	{
		gotoxy(x1, y1); cout << "|" << i << ".\t" << Datos[i];
		gotoxy(51, y1); cout << "|";
		y1++;
	}
	for (int x = 25; x <= 51; x++)
	{
		gotoxy(x, y1); putchar('-');
	}
	//imprimimos la lista de datos ya ordenados
	gotoxy(25, y1 + 1); cout << "INGRESE POSICION DE DATO QUE QUIERA CAMBIAR:"; cin >> posicion;
	if (posicion < CantidadDatos)
	{
		for (i = 0; i <= posicion; i++)
		{
			if (i == posicion)
			{
				gotoxy(25, y1 + 2); cout << "INGRESE NUEVO DATO: "; cin >> Datos[i];
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
		for (int x = 25; x <= 43; x++)
		{
			gotoxy(x, 1); putchar('-');
		}
		gotoxy(x1, 2); cout << "|LA NUEVA LISTA ES|"; x1 = 25, y1 = 4;
		for (int x = 25; x <= 43; x++)
		{
			gotoxy(x, 3); putchar('-');
		}
		for (i = 0; i < CantidadDatos; i++)
		{
			gotoxy(x1, y1); cout << "|" << i << ".\t" << Datos[i];
			gotoxy(43, y1); cout << "|";
			y1++;
		}
		for (int x = 25; x <= 43; x++)
		{
			gotoxy(x, y1); putchar('-');
		}
		//se imprime la lista del vector con los datos ya ordenados
	}
	else
	{
		system("cls");
		gotoxy(25, 5); cout << "LA POSICIÓN NO FUE ENCONTRADA, INTENTELO NUEVAMENTE\a";
	}
	system("pause>null");
}
void CONTAREPE() {
	float sum, auxiliar = 0;
	int y = 3;
	int x = 0;
	for (int x = 0; x <= 171; x++)
	{
		gotoxy(x, 0); putchar('-');
	}
	gotoxy(79, 1); cout << "REPETICIONES";
	for (int x = 0; x <= 171; x++)
	{
		gotoxy(x, 2); putchar('-');
	}
	for (int q = 0; q < 300; q++) {
		sum = 0;
		if (Datos[q] > auxiliar)
		{
			auxiliar = Datos[q];
			for (j = 0; j < CantidadDatos; j++) {
				if (Datos[q] == Datos[j]) {
					sum = sum + 1;
				}
			}
		}
		if (0 < sum && sum < 2) {//si es mayor a 0 el contador es porque se repite el numero
			gotoxy(67, y); cout << "El número " << Datos[q];
			gotoxy(82, y); cout << " se repite " << sum;
			gotoxy(98, y); cout << " vez.";
			y++;
		}
		if (sum >= 2)
		{
			gotoxy(67, y); cout << "El número " << Datos[q];
			gotoxy(82, y); cout << " se repite " << sum;
			gotoxy(98, y); cout << " veces.";
			y++;
		}
	}
	for (int x = 0; x <= 171; x++)
	{
		gotoxy(x, y); putchar('-');
	}
	y++;
	gotoxy(73, y); cout << "LISTADO DE DATOS ORDENADOS";
	y++;
	for (int x = 0; x <= 171; x++)
	{
		gotoxy(x, y); putchar('-');
	}
	y++;
	for (i = 0; i < CantidadDatos; i++) {
		gotoxy(x, y); cout << Datos[i] << ",";
		x = x + 7;
	}
	//se imprime la lista con los datos ordenados
}
void NumeroMayor() {
	x = 5;
	for (i = 0; i < CantidadDatos; i++)
	{
		if (Datos[i] > nMayor) {
			nMayor = Datos[i];
		}
	}
	gotoxy(x, 5); cout << "|NUMERO MAYOR: " << nMayor;
}
void NumeroMenor() {
	nMenor = nMayor;
	for (i = 0; i < CantidadDatos; i++)
	{
		if (Datos[i] < nMenor) {
			nMenor = Datos[i];
		}
	}
	gotoxy(28, 5); cout << "|NUMERO MENOR: " << nMenor;
}
void RANGO() {
	Rango = nMayor - nMenor;
	gotoxy(51, 5); cout << "|RANGO: " << setprecision(2) << Rango;
}
void INTERVALO() {
	Intervalo = 1 + 3.3 * log10(CantidadDatos);
	gotoxy(67, 5); cout << "|INTERVALO: " << fixed << setprecision(0) << Intervalo;
}
void ANCHO_DE_INTERVALO() {
	Ancho_Intervalo = Rango / Intervalo;
	gotoxy(85, 5); cout << "|ANCHO DEL INTERVALO: " << setprecision(2) << Ancho_Intervalo << "\n\n";
}
void IMPRIMIR_INTERVALOS() {
	y = 11;
	inicial = nMenor;
	sumador = nMenor + Ancho_Intervalo;
	for (int i = 0; i < Intervalo; i++)
	{
		gotoxy(5, 9); cout << "|No. Intervalos";
		gotoxy(5, y); cout << "|" << setprecision(3) << inicial;
		gotoxy(17, y); cout << setprecision(3) << sumador;
		gotoxy(30, y); cout << "|";
		vectora[i] = inicial;
		vectorb[i] = sumador;

		inicial = sumador;
		sumador = sumador + Ancho_Intervalo;
		y++;
	}
}
void FRECUENCIA_ABSOLUTA() {
	y = 11;
	float auxi = 0;
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
			gotoxy(30, 9); cout << "|fi";
			gotoxy(30, y); cout << "|" << sumador2 << endl;
			auxi = auxi + sumador2;
			FrecuenciaAbsoluta[i] = sumador2;
			FrecuenciaRel[i] = sumador2;
		}
		y++;
	}
	gotoxy(30, y + 1); cout << "|" << auxi;
	gotoxy(41, y + 1); cout << "|";
}
void MARCA_DE_CLASE() {
	int intervaloizq = 0, intervaloder = 0, y = 11;
	for (int i = 0; i < Intervalo; i++)
	{
		marca_de_clase[i] = (vectora[i] + vectorb[i]) / 2;
		gotoxy(41, 9); cout << "|Xi";
		gotoxy(41, y); cout << "|" << marca_de_clase[i];
		y++;
	}
}
void FRECUENCIA_ABSOLUTA_ACUMULADA() {
	y = 11;
	for (i = 0; i <= Intervalo; i++)
	{
		acumulador = FrecuenciaAbsoluta[i] + acumulador;
		FrecuenciaAbsolutaAcumulada[i] = acumulador;
		gotoxy(54, 9); cout << "|Fi";
		gotoxy(54, y); cout << "|" << FrecuenciaAbsolutaAcumulada[i];
		y++;
	}
	ejey = acumulador;
}
void FRECUENCIA_RELATIVA() {
	y = 11;
	for (i = 0; i < Intervalo; i++)
	{
		FrecuenciaRelDesc[i] = (FrecuenciaRel[i] / CantidadDatos);
		gotoxy(65, 9); cout << "|Fr%";
		gotoxy(65, y); cout << "|" << (FrecuenciaRel[i] / CantidadDatos);
		y++;
	}
}
void FRECUENCIA_ACUMULADA_DESCENDENTE() {
	acumulador = CantidadDatos;
	y = 11;
	for (i = 0; i <= Intervalo; i++)
	{
		gotoxy(76, 9); cout << "|fi desc.";
		gotoxy(76, y); cout << "|" << acumulador;
		acumulador = acumulador - FrecuenciaAbsoluta[i];
		y++;
	}
	for (int x = 5; x <= 166; x++)
	{
		gotoxy(x, y); putchar('-');
	}
}
void FRECUENCIA_RELATIVA_ASCENDENTE() {
	y = 11;
	acumulador = FrecuenciaRelDesc[0];
	for (i = 1; i < Intervalo + 1; i++)
	{
		gotoxy(87, 9); cout << "|Fr% asc.";
		gotoxy(87, y); cout << "|" << acumulador;
		acumulador = FrecuenciaRelDesc[i] + acumulador;
		y++;
	}
}
void FRECUENCIA_RELATIVA_DESCENDENTE() {
	acumulador = 1;
	y = 11;
	for (i = 0; i <= Intervalo; i++)
	{
		gotoxy(98, 9); cout << "|Fr% desc.";
		gotoxy(98, y); cout << "|" << acumulador;
		acumulador = acumulador - FrecuenciaRelDesc[i];
		y++;
	}
}
void XIFI() {
	int y = 11;
	float auxi = 0;
	for (int i = 0; i < Intervalo; i++)
	{
		gotoxy(109, 9); cout << "|fi*xi";
		calculoPromedio = FrecuenciaAbsoluta[i] * marca_de_clase[i];
		gotoxy(109, y); cout << "|" << calculoPromedio << endl;
		auxi = auxi + calculoPromedio;
		y++;
	}
	gotoxy(109, y + 1); cout << "|" << auxi;
}
void PROMEDIO() {
	float mcMprom = 0;
	for (int i = 0; i < Intervalo; i++)
	{
		calculoPromedio = FrecuenciaAbsoluta[i] * marca_de_clase[i];
		mcMprom = mcMprom + calculoPromedio;
	}
	mcMprom2 = mcMprom / CantidadDatos;
	gotoxy(118, 5); cout << "|" << "X = " << mcMprom << " / " << CantidadDatos << " = " << mcMprom2;
}
void XmenosPROMEDIO() {
	float x1, auxi = 0;
	y = 11;
	for (int i = 0; i < Intervalo; i++)
	{
		gotoxy(122, 9); cout << "|(Xi - X)";
		x1 = abs(marca_de_clase[i] - mcMprom2);
		gotoxy(122, y); cout << "|" << x1 << endl;
		auxi = auxi + x1;
		y++;
	}
	gotoxy(122, y + 1); cout << "|" << auxi;
}
void XmPCUADRADO() {
	float x2, auxi = 0;
	y = 11;
	for (int i = 0; i < Intervalo; i++)
	{
		gotoxy(135, 9); cout << "|(Xi - X)^2";
		x2 = (marca_de_clase[i] - mcMprom2) * (marca_de_clase[i] - mcMprom2);
		gotoxy(135, y); cout << "|" << x2 << endl;
		auxi = auxi + x2;
		y++;
	}
	gotoxy(135, y + 1); cout << "|" << auxi;
	gotoxy(150, y + 1); cout << "|";
}
void XmPCF() {
	float x3;
	y = 11;
	for (int i = 0; i < Intervalo; i++)
	{
		gotoxy(150, 9); cout << "|(Xi - X)^2 * fi|";
		x3 = ((marca_de_clase[i] - mcMprom2) * (marca_de_clase[i] - mcMprom2)) * FrecuenciaAbsoluta[i];
		gotoxy(150, y); cout << "|" << x3 << endl;
		gotoxy(166, y); cout << "|",
			y++;
	}
}
void DISTRIBUCION_DE_FRECUENCIAS() {
	for (int x = 5; x <= 166; x++)
	{
		gotoxy(x, 4); putchar('-');
	}
	for (int x = 5; x <= 166; x++)
	{
		gotoxy(x, 6); putchar('-');
	}
	gotoxy(166, 5); cout << "|";
	NumeroMayor();
	NumeroMenor();
	RANGO();
	INTERVALO();
	ANCHO_DE_INTERVALO();
	for (int x = 5; x <= 166; x++)
	{
		gotoxy(x, 8); putchar('-');
	}
	for (int x = 5; x <= 166; x++)
	{
		gotoxy(x, 10); putchar('-');
	}
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

	for (int x = 55; x <= 110; x++)
	{
		gotoxy(x, 8);
		putchar('-');
		gotoxy(x, 16);
		putchar('-');
	}

	gotoxy(72, 10); cout << "**MEDIA**";
	for (int i = 0; i < Intervalo; i++)
	{
		calculoPromedio = FrecuenciaAbsoluta[i] * marca_de_clase[i];
		mcMprom = mcMprom + calculoPromedio;
	}
	Media = mcMprom / CantidadDatos;
	gotoxy(65, 12); cout << "----------------------------";
	gotoxy(65, 13); cout << "X = " << mcMprom << " / " << CantidadDatos << " = " << Media;
	gotoxy(65, 14); cout << "----------------------------";
}
void MEDIANA() {
	float calculo1, calculo2, calculo3, totalMediana, auxi[100], encontrado2 = 0;
	bool encontrado = false;
	aux = 650;

	for (int x = 55; x <= 110; x++)
	{
		gotoxy(x, 32);
		putchar('-');
	}

	posicion = CantidadDatos / 2;

	gotoxy(72, 19); cout << "**MEDIANA**";

	gotoxy(65, 21); cout << "Posicion = " << CantidadDatos << " / 2 = " << posicion;
	for (int i = 0; i < Intervalo; i++)
	{
		if (posicion == FrecuenciaAbsolutaAcumulada[i])
		{
			gotoxy(65, 23); cout << " FRECUENCIA ABSOLUTA: " << FrecuenciaAbsoluta[i];
			gotoxy(65, 24); cout << " FRECUENCIA ABSOLUTA ACUMULADA - 1: " << FrecuenciaAbsolutaAcumulada[i - 1];
			gotoxy(65, 25); cout << " LIMITE INFERIOR: " << vectora[i];
			gotoxy(65, 26); cout << " POSICIÓN: " << posicion;
			gotoxy(65, 27); cout << " ANCHO DE INTERVALO: " << Ancho_Intervalo;
			calculo1 = posicion - FrecuenciaAbsolutaAcumulada[i - 1];
			calculo2 = calculo1 / FrecuenciaAbsoluta[i];
			calculo3 = calculo2 * Ancho_Intervalo;
			totalMediana = vectora[i] + calculo3;
			gotoxy(65, 28); cout << "-----------------";
			gotoxy(65, 29); cout << " MEDIANA: " << totalMediana;
			gotoxy(65, 30); cout << "-----------------";
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
		for (int i = 0; i < Intervalo; i++)
		{
			if (aux == FrecuenciaAbsolutaAcumulada[i])
			{
				gotoxy(65, 23); cout << " FRECUENCIA ABSOLUTA: " << FrecuenciaAbsoluta[i];
				gotoxy(65, 24); cout << " FRECUENCIA ABSOLUTA ACUMULADA - 1: " << FrecuenciaAbsolutaAcumulada[i - 1];
				gotoxy(65, 25); cout << " LIMITE INFERIOR: " << vectora[i];
				gotoxy(65, 26); cout << " POSICIÓN: " << posicion;
				gotoxy(65, 27); cout << " ANCHO DE INTERVALO: " << Ancho_Intervalo;
				calculo1 = posicion - FrecuenciaAbsolutaAcumulada[i - 1];
				calculo2 = calculo1 / FrecuenciaAbsoluta[i];
				calculo3 = calculo2 * Ancho_Intervalo;
				totalMediana = vectora[i] + calculo3;
				gotoxy(65, 28); cout << "-----------------";
				gotoxy(65, 29); cout << " MEDIANA: " << totalMediana;
				gotoxy(65, 30); cout << "-----------------";
			}
		}
	}
}
void MODA() {
	float calculo1, calculo2, calculo3, calculo4, totalModa, auxi[100], encontrado2 = 0;
	bool encontrado = false;
	aux = 650;
	posicion = CantidadDatos / 2;

	for (int x = 55; x <= 110; x++)
	{
		gotoxy(x, 47);
		putchar('-');
	}

	gotoxy(72, 34); cout << "**MODA**";

	gotoxy(65, 36); cout << "Posicion = " << CantidadDatos << " / 2 = " << posicion;

	for (int i = 0; i < Intervalo; i++)
	{
		if (posicion == FrecuenciaAbsolutaAcumulada[i])
		{
			gotoxy(65, 38); cout << " FRECUENCIA ABSOLUTA: " << FrecuenciaAbsoluta[i];
			gotoxy(65, 39); cout << " FRECUENCIA ABSOLUTA - 1: " << FrecuenciaAbsoluta[i - 1];
			gotoxy(65, 40); cout << " FRECUENCIA ABSOLUTA + 1: " << FrecuenciaAbsoluta[i + 1];
			gotoxy(65, 41); cout << " LIMITE INFERIOR: " << vectora[i];
			gotoxy(65, 42); cout << " ANCHO DE INTERVALO: " << Ancho_Intervalo;
			calculo1 = FrecuenciaAbsoluta[i] - FrecuenciaAbsoluta[i - 1];
			calculo2 = (FrecuenciaAbsoluta[i] - FrecuenciaAbsoluta[i - 1]) + (FrecuenciaAbsoluta[i] - FrecuenciaAbsoluta[i + 1]);
			calculo3 = calculo1 / calculo2;
			calculo4 = calculo3 * Ancho_Intervalo;
			totalModa = vectora[i] + calculo4;
			gotoxy(65, 43); cout << "--------------";
			gotoxy(65, 44); cout << " MODA: " << totalModa;
			gotoxy(65, 45); cout << "--------------";
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
		for (int i = 0; i < Intervalo; i++)
		{
			if (aux == FrecuenciaAbsolutaAcumulada[i])
			{
				gotoxy(65, 38); cout << " FRECUENCIA ABSOLUTA: " << FrecuenciaAbsoluta[i];
				gotoxy(65, 39); cout << " FRECUENCIA ABSOLUTA - 1: " << FrecuenciaAbsoluta[i - 1];
				gotoxy(65, 40); cout << " FRECUENCIA ABSOLUTA + 1: " << FrecuenciaAbsoluta[i + 1];
				gotoxy(65, 41); cout << " LIMITE INFERIOR: " << vectora[i];
				gotoxy(65, 42); cout << " ANCHO DE INTERVALO: " << Ancho_Intervalo;
				calculo1 = FrecuenciaAbsoluta[i] - FrecuenciaAbsoluta[i - 1];
				calculo2 = (FrecuenciaAbsoluta[i] - FrecuenciaAbsoluta[i - 1]) + (FrecuenciaAbsoluta[i] - FrecuenciaAbsoluta[i + 1]);
				calculo3 = calculo1 / calculo2;
				calculo4 = calculo3 * Ancho_Intervalo;
				totalModa = vectora[i] + calculo4;
				gotoxy(65, 43); cout << "--------------";
				gotoxy(65, 44); cout << " MODA: " << totalModa;
				gotoxy(65, 45); cout << "--------------";
			}
		}
	}
}
void MEDIDASDISPERCION() {
	int i;
	float varianza = 0, desv_estandar = 0, media = 0, suma_valores = 0, desv_med = 0, desv_med2 = 0, coe_var;

	Rango = nMayor - nMenor;

	for (i = 0; i < CantidadDatos; i++)
	{
		suma_valores += Datos[i];
	}

	media = suma_valores / CantidadDatos;

	for (i = 0; i < CantidadDatos; i++)
	{
		varianza = varianza + pow((Datos[i] - media), 2);
	}

	for (i = 0; i < CantidadDatos; i++)
	{
		desv_med = desv_med + abs(Datos[i] - media);
	}
	desv_med2 = desv_med / CantidadDatos;
	desv_estandar = sqrt(varianza / (CantidadDatos - 1));
	coe_var = desv_estandar / media;

	system("cls");
	for (int x = 0; x <= 171; x++)
	{
		gotoxy(x, 0); putchar('-');
	}
	gotoxy(76, 1); cout << "MEDIDAS DE DISPERCIÓN";
	for (int x = 0; x <= 171; x++)
	{
		gotoxy(x, 2); putchar('-');
	}
	gotoxy(68, 4); cout << "El rango es: " << Rango << endl;
	gotoxy(68, 5); cout << "La varianza es: " << varianza << endl;
	gotoxy(68, 6); cout << "La desviacion estandar es: " << desv_estandar << endl;
	gotoxy(68, 7); cout << "La desviacion media es: " << desv_med2 << endl;
	gotoxy(68, 8); cout << "El coeficiente de variacion es: " << coe_var << endl;
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
			gotoxy(72, 28); cout << "**CUARTIL**";
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
				gotoxy(72, 28); cout << "**CUARTIL**";
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
			gotoxy(72, 28); cout << "**DECIL**";
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
				gotoxy(72, 28); cout << "**DECIL**";
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
			gotoxy(72, 28); cout << "**PERCENTIL**";
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
				gotoxy(72, 28); cout << "**PERCENTIL**";
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
void HISTOGRAMA() {
	x = 10, y = ejey * 1.75; int y2, x1 = 5, y3 = ejey * 1.75;
	for (int x = 0; x <= 171; x++)
	{
		gotoxy(x, 0); putchar('-');
	}
	gotoxy(81, 1); cout << "HISTOGRAMA";
	for (int x = 0; x <= 171; x++)
	{
		gotoxy(x, 2); putchar('-');
	}
	for (int i = 0; i <= ejey; i++)
	{
		gotoxy(x1, y3); cout << i;
		y3--;
	}
	for (int i = 0; i < Intervalo; i++)
	{
		y2 = (ejey * 1.75) - 1;
		gotoxy(x, y); cout << setprecision(2) << vectora[i] << "-" << setprecision(2) << vectorb[i] << "\t";
		for (int j = 0; j < FrecuenciaAbsoluta[i]; j++)
		{
			gotoxy(x + 5, y2); putchar('*');
			y2--;
		}
		gotoxy(x + 3, y2); cout << FrecuenciaAbsoluta[i];
		x = x + 15;
	}
}
void POLIGONO_DE_FRECUENCIAS() {
	x = 10, y = ejey * 1.75; int y2 = 0, y3 = ejey * 1.75, x1 = 5, auxiliar;
	for (int x = 0; x <= 171; x++)
	{
		gotoxy(x, 0); putchar('-');
	}
	gotoxy(75, 1); cout << "POLIGONO DE FRECUENCIA";
	for (int x = 0; x <= 171; x++)
	{
		gotoxy(x, 2); putchar('-');
	}
	for (int i = 0; i <= ejey; i++)
	{
		gotoxy(x1, y3); cout << i;
		y3--;
	}
	for (int i = 0; i < Intervalo; i++)
	{
		gotoxy(x, y); cout << marca_de_clase[i];
		y2 = (ejey * 1.75) - 1;
		for (int j = 1; j <= FrecuenciaAbsoluta[i]; j++)
		{
			auxiliar = FrecuenciaAbsoluta[i];
			if (auxiliar == j)
			{
				gotoxy(x + 3, y2); cout << "*";
			}
			y2--;
		};
		x = x + 10;
	}
}
void menu() {
	int opcion = 0;
	do
	{
		system("cls");
		for (int x = 65; x <= 116; x++)
		{
			gotoxy(x, 13);
			putchar('-');
			gotoxy(x, 38);
			putchar('-');
		}
		for (float y = 14; y <= 37; y++)
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
		gotoxy(70, 30); cout << "HISTOGRAMA.............................. 8";
		gotoxy(70, 32); cout << "POLIGONO DE FRECUENCIA.................. 9";
		gotoxy(70, 34); cout << "SALIR DEL PROGRAMA.......................0";
		gotoxy(100, 36); cout << "OPCIÓN:";
		gotoxy(110, 36); cin >> opcion;
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
			CONTAREPE();
			system("pause>null");
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
		case 6:
			system("cls");
			MEDIDASDISPERCION();
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
		case 8:
			system("cls");
			HISTOGRAMA();
			system("pause>null");
			break;
		case 9:
			system("cls");
			POLIGONO_DE_FRECUENCIAS();
			system("pause>null");
			break;
		};
		system("cls");
	} while (opcion != 0);
};
int main() {
	setlocale(LC_CTYPE, "Spanish");
	menu();
	system("pause>null");
	return 0;
}