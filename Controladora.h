#pragma once
#include "Cuadrado.h"
#include <fstream>

using namespace System::Windows::Forms;
using namespace std;

ref class Controladora
{
public:
	Controladora()
	{
		obj = new Cuadrado();
		contBalas = 0;
	}
	~Controladora(){}
	void MostrarCuadrado(Graphics^ g)
	{
		obj->Mostrar(g);
	}
	void MoverCuadrado(Graphics^ g, Keys key)
	{
		if (key == Keys::W)
			obj->Mover(g, Direccion::Arriba);
		if (key == Keys::A)
			obj->Mover(g, Direccion::Izquierda);
		if (key == Keys::S)
			obj->Mover(g, Direccion::Abajo);
		if (key == Keys::D)
			obj->Mover(g, Direccion::Derecha);
	}
	void Disparo(int xMouse, int yMouse)
	{
		obj->CrearBala(xMouse, yMouse);
		contBalas++;
	}
	void MostrarMoverBalas(Graphics^ g)
	{
		obj->MostrarBala(g);
		obj->MoverBala();
	}
	void FinJuegoEscritura()
	{
		ofstream archivo;
		archivo.open("datos.txt", ios::out);
		archivo << "BALAS DISPARADAS: " << contBalas << endl;
	}
	void Timer(Graphics^ g)
	{
		g->Clear(Color::Black);
		MostrarCuadrado(g);
		MostrarMoverBalas(g);
	}
private:
	Cuadrado* obj;
	int contBalas;
};
