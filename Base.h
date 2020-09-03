#pragma once
enum Direccion
{
	Arriba, Abajo, Izquierda, Derecha
};

using namespace System::Drawing;

class Base
{
public:
	Base() {}
	~Base() {}

	int getX() { return x; }
	int getY() { return y; }
	int getVX() { return vx; }
	int getVY() { return vy; }
	int getLargo() { return largo; }
	int getAncho() { return ancho; }

	void setX(int n) { x = n; }
	void setY(int n) { y = n; }
	void setVX(int n) { vx = n; }
	void setVY(int n) { vy = n; }
	void setLargo(int n) { largo = n; }
	void setAncho(int n) { ancho = n; }

protected:
	int x, y, ancho, largo, vx, vy;
};

