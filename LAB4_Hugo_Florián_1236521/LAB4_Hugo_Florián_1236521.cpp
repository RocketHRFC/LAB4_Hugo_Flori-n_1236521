#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include <string.h>

using namespace System;
using namespace std;

int num_Aleatorio()
{
	int num;
	srand(time(NULL));
	num = (rand() % 10)+1;

	return num;
}

void imprimir(string *puntero)
{
	for (int i = 0; i < 70; i++)
	{
		cout << *(puntero + i ) << "|";
	}
}

void InitVectores(string *punteros, char *punterot, char *punterol)
{
	for (int i = 0; i < 70; i++)
	{
		*(punteros + i) = " ";
	}

	for (int i = 0; i < 70; i++)
	{
		*(punterot + i) = ' ';
		*(punterol + i) = ' ';
	}
}

void InitPorcentajes(double *punterodt, double *punterodl)
{
	for (int i = 0; i < 3; i++)
	{
		*(punterodt + i) = 0;
	}

	for (int i = 0; i < 5; i++)
	{
		*(punterodl + i) = 0;
	}
}

int det_movimientosT(int i, int posicion)
{
	if (i >= 1 && i <= 5)
	{
		return 3 + posicion;
	}
	if (i >= 6 && i <= 7)
	{
		return -6 + posicion;
	}
	if (i >= 8 && i <= 10)
	{
		return 1 + posicion;
	}
}

int det_movimientosL(int i, int posicion)
{
	if (i >= 1 && i <= 2)
	{
		return 0 + posicion;
	}
	if (i >= 3 && i <= 4)
	{
		return 9 + posicion ;
	}
	if (i == 5)
	{
		return -12 + posicion;
	}
	if (i >= 6 && i <= 8)
	{
		return 1 + posicion;
	}
	if (i >= 9 && i <= 10)
	{
		return -2 + posicion;
	}
}

int posicion(char *puntero)
{
	for (int i = 0; i < 70; i++)
	{
		if (*(puntero + i) != ' ')
		{
			return i;
		}
	}
}


int Validar(int movimiento)
{
	if (movimiento < 0)
	{
		return 0;
	}
	else if (movimiento > 69)
	{
		return 69;
	}
	else
	{
		return movimiento;
	}

}

void Posiciones(string *vector, int n, int n2)
{

	if (n == n2)
	{
		*(vector + n) = "¡OUCH!";
	}
	else
	{
		*(vector + n) = "T";
		*(vector + n2) = "L";

	}
}

void statsL(double *L, int i) 
{
	if (i >= 1 && i <= 2)
	{
		(*(L + 0))++;
	}
	if (i >= 3 && i <= 4)
	{
		(*(L + 1))++;
	}
	if (i == 5)
	{
		(*(L + 2))++;
	}
	if (i >= 6 && i <= 8)
	{
		(*(L + 3))++;
	}
	if (i >= 9 && i <= 10)
	{
		(*(L + 4))++;
	}
}

void statsT(double *T, int i)
{
	if (i >= 1 && i <= 5)
	{
		(*(T + 0))++;
	}
	if (i >= 6 && i <= 7)
	{
		(*(T + 1))++;
	}
	if (i >= 8 && i <= 10)
	{
		(*(T + 2))++;
	}
}

void ESTADISTICAS(double *T, double *L, int contador)
{

	//Tortuga
	double pv, r, pl;
	pv = (*(T + 0) / contador) * 100;
	r = (*(T + 1) / contador) * 100;
	pl = (*(T + 2) / contador) * 100;
	//Liebre
	float d, gs, gr, sp, rp;
	d = (*(L + 0) / contador) * 100;
	gs = (*(L + 1) / contador) * 100;
	gr = (*(L + 2) / contador) * 100;
	sp = (*(L + 3) / contador) * 100;
	rp = (*(L + 4) / contador) * 100;

	cout << "\nESTADISTICAS | PORCENTAJES DE TIEMPO:\n";
	cout << "---------------Liebre-----------------\n";
	cout << "Durmio: "<<d<<"%"<<endl;
	cout << "Gran Salto: " << gs << "%" << endl;
	cout << "Gran Resbalon: " << gr << "%" << endl;
	cout << "Salto pequeno: " << sp << "%" << endl;
	cout << "Resbalon pequeno: " << rp << "%" << endl;
	cout << "---------------Tortuga-----------------\n";
	cout << "Paso veloz: " << pv << "%" << endl;
	cout << "Resbalon: " << r << "%" << endl;
	cout << "Paso Lento: " << pl << "%" << endl;
}

int main()
{	//Numero aleatorios
	int n, n2;

	//Liebre y Tortuga:
	char T = 'T';
	char L = 'L';

	//vectores
	char vec_liebre[70];
	char vec_tortuga[70];
	string vec_carrera[70];
	double PorcetajesT[3], PorcentajesL[5];

	//punteros
	string *p = vec_carrera;
	char *vectliebre = vec_liebre, *vecttortuga = vec_tortuga;
	double *P_Tortuga = PorcetajesT, *P_Liebre = PorcentajesL;

	char *Pt = &T;
	char *Pl = &L;

	//inicializador de vectores
	InitVectores(p, vecttortuga, vectliebre);
	InitPorcentajes(P_Tortuga, P_Liebre);

	//Inicio de la carrera
	cout << "¡BANG!" << endl << "¡Y ARRANCAN!\n";

	*(vectliebre + 0) = *Pl;
	*(vecttortuga + 0) = *Pt;

	Posiciones(p, 0, 0);
	imprimir(p);

	int movL, movT;
	int cont;

	while (true)
	{
		cont++;

		cout << "\n";
		n = num_Aleatorio();
		_sleep(1000);
		n2 = num_Aleatorio();

		statsL(P_Liebre, n);
		statsT(P_Tortuga, n2);

		movL = det_movimientosL(n, posicion(vectliebre));
		movT = det_movimientosT(n2, posicion(vecttortuga));

		movL = Validar(movL);
		movT = Validar(movT);

		InitVectores(p, vecttortuga, vectliebre);

		*(vectliebre + movL) = *Pl;
		*(vecttortuga + movT) = *Pt;

		Posiciones(p, movT, movL);

		imprimir(p);

		if (movL == 69 && movT == 69)
		{
			cout << "\nWow, esto ha sido un empate";
			break;
		}
		else if (movL == 69)
		{
			cout << "\nLa Liebre ha ganado. Ni hablar";
			break;
		}
		else if (movT == 69)
		{
			cout << "\nLA TORTUGA HA GANADOOOOOOOO!";
			break;
		}
	}

	ESTADISTICAS(P_Tortuga, P_Liebre, cont);

    return 0;
}
