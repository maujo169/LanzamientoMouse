#pragma once
#include "Base.h"
class Bala : public Base
{
public:
	Bala(int x, int y, int vx, int vy)
	{
		this->x = x;
		this->y = y;
		this->vx = vx;
		this->vy = vy;
		largo = ancho = 20;
	}
	~Bala(){}

	void Mostrar(Graphics^ g)
	{
		g->FillEllipse(Brushes::Blue, x, y, ancho, largo);
	}

	void Mover()
	{
		x += vx;
		y += vy;
	}
private:
	
};
