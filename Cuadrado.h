#pragma once
#include "Base.h"
#include "Bala.h"
class Cuadrado : public Base
{
public:
	Cuadrado()
	{
		x = 100;
		y = 450;
		vx = vy = 20;
		ancho = largo = 64;
		cant = 0;
		arr = new Bala*[cant];
	}
	~Cuadrado(){}

	void Mostrar(Graphics^ g)
	{
		g->FillRectangle(Brushes::Coral, x, y, ancho, largo);
	}
	void Mover(Graphics^ g, Direccion dir)
	{
		switch (dir)
		{
		case Arriba:
			if (y - vy > 0)
			{
				y-=vy;
			}
			break;
		case Abajo:
			if (y + vy +largo < g->VisibleClipBounds.Height)
			{
				y += vy;
			}
			break;
		case Izquierda:
			if (x - vx > 0)
			{
				x -= vx;
			}
			break;
		case Derecha:
			if (x + vx + ancho < g->VisibleClipBounds.Width)
			{
				x += vx;
			}
			break;
		}
	}
	void CrearBala(int xMouse, int yMouse)
	{
		Bala** aux = new Bala * [cant + 1];
		for (int i = 0; i < cant; i++)
		{
			aux[i] = arr[i];
		}
		int dx, dy;
		dx = (xMouse - x) * 0.1;
		dy = (yMouse - y) * 0.1;
		aux[cant] = new Bala(x + (ancho / 2), y + (largo / 2) - 20 , dx, dy);
		cant++;
		arr = aux;
	}
	void MostrarBala(Graphics^ g)
	{
		for (int i = 0; i < cant; i++)
		{
			arr[i]->Mostrar(g);
		}
	}
	void MoverBala()
	{
		for (int i = 0; i < cant; i++)
		{
			arr[i]->Mover();
		}
	}
private:
	Bala** arr;
	int cant;
};
