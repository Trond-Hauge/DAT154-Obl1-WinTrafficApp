#include "framework.h"

class Car {
public:
	int nr;
	int x, y;

	Car(int _nr, int _x, int _y) : nr(_nr), x(_x), y(_y) {}

	void Draw(HDC hdc) {
		Rectangle(hdc, x, y - 10, x + 10, y);
	}
};

class CarList {
public:
	Car* tab[1000];
	int m_i;

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

	void Move(int d) {
		for (int i = 0; i < m_i; i++) {
			tab[i]->;
		}
	}

	void Clean() {
		for (int i = 0; i < m_i; i++) {
			delete tab[i];
		}
	}
};