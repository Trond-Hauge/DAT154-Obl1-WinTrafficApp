#include "framework.h"

class Car {
public:
	int nr, x, y;

	Car(int _nr, int _x, int _y) : nr(_nr), x(_x), y(_y) {}

	void Draw(HDC hdc) {
		Rectangle(hdc, x, y - 10, x + 10, y);
	}
};

class CarList {
public:
	Car* tab[1000];
	int m_i;
	bool move;

	CarList() {
		m_i = 0;
	}

	void push(Car* car) {
		tab[m_i++] = car;
	}

	void Draw(HDC hdc) {
		for (int i = 0; i < m_i; i++) {
			tab[i]->Draw(hdc);
		}
	}

	void Move(int dx, int dy) {
		if (move) {
		for (int i = 0; i < m_i; i++) {
			tab[i]->x += dx;
			tab[i]->y += dy;
		}
		}
	}

	void Clean() {
		for (int i = 0; i < m_i; i++) {
			delete tab[i];
		}
	}
};