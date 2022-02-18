#include "framework.h"

class Car {
public:
	int nr, x, y;
	bool down;

	Car(int _nr, int _x, int _y, bool _down) : nr(_nr), x(_x), y(_y), down(_down) {}

	void Draw(HDC hdc) {
		Rectangle(hdc, x, y - 10, x + 10, y);
	}
};

class CarList {
public:
	Car* tab[1000];
	int m_i;
	bool move;
	Car* tmp;

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
		for (int i = 0; i < m_i; i++) {
			tmp = tab[i];
			if (move ||
				((tmp->x < 330 || tmp->x > 330) && tmp->down == false) ||
				((tmp->y < 350 || tmp->y > 350) && tmp->down)){
				tmp->x += dx;
				tmp->y += dy;
			}
		}
	}

	void Clean() {
		for (int i = 0; i < m_i; i++) {
			delete tab[i];
		}
	}
};