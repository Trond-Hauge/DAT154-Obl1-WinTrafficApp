#include "framework.h"

class TrafficLight {
	const int height = 130;
	const int width = 50;
public:
	int x, y;

	TrafficLight(int _x, int _y) : x(_x), y(_y){}

	void Draw(const HDC& hdc, int state) {
		HBRUSH hb = CreateSolidBrush(RGB(20, 20, 20));
		HBRUSH hd = CreateSolidBrush(RGB(50, 50, 50));
		HBRUSH hr = CreateSolidBrush(RGB(255, 20, 20));
		HBRUSH hy = CreateSolidBrush(RGB(255, 200, 20));
		HBRUSH hg = CreateSolidBrush(RGB(20, 255, 20));
		HGDIOBJ hgObj = SelectObject(hdc, hb);

		Rectangle(hdc, x, y - height, x + width, y);

		switch (state) {
			case 1: // Red
				hgObj = SelectObject(hdc, hr);
				Ellipse(hdc, x + 10, y - height + 10, x + 40, y - height + 40);

				hgObj = SelectObject(hdc, hd);
				Ellipse(hdc, x + 10, y - height + 50, x + 40, y - height + 80);
				Ellipse(hdc, x + 10, y - height + 90, x + 40, y - height + 120);
				break;

			case 2: // Red - Yellow
				hgObj = SelectObject(hdc, hr);
				Ellipse(hdc, x + 10, y - height + 10, x + 40, y - height + 40);

				hgObj = SelectObject(hdc, hy);
				Ellipse(hdc, x + 10, y - height + 50, x + 40, y - height + 80);

				hgObj = SelectObject(hdc, hd);
				Ellipse(hdc, x + 10, y - height + 90, x + 40, y - height + 120);
				break;

			case 3: // Green
				hgObj = SelectObject(hdc, hd);
				Ellipse(hdc, x + 10, y - height + 10, x + 40, y - height + 40);
				Ellipse(hdc, x + 10, y - height + 50, x + 40, y - height + 80);

				hgObj = SelectObject(hdc, hg);
				Ellipse(hdc, x + 10, y - height + 90, x + 40, y - height + 120);
				break;

			default: // Yellow
				hgObj = SelectObject(hdc, hd);
				Ellipse(hdc, x + 10, y - height + 10, x + 40, y - height + 40);

				hgObj = SelectObject(hdc, hy);
				Ellipse(hdc, x + 10, y - height + 50, x + 40, y - height + 80);

				hgObj = SelectObject(hdc, hd);
				Ellipse(hdc, x + 10, y - height + 90, x + 40, y - height + 120);
				break;
		}

		DeleteObject(hb);
		DeleteObject(hd);
		DeleteObject(hr);
		DeleteObject(hy);
		DeleteObject(hg);
	}
};

class TrafficLightList {
public:
	TrafficLight* tab[2];
	bool vertical;
	int state = 0;

	TrafficLightList(bool _vertical) : vertical(_vertical) {
		if (vertical) {
			tab[0] = new TrafficLight(330,200);
			tab[1] = new TrafficLight(430,200);
		}
		else {
			tab[0] = new TrafficLight(200,380);
			tab[1] = new TrafficLight(200,530);
		}

		if (vertical) state = 2;
	}

	bool Draw(HDC hdc, int time) {
		if (time % 80 == 0) state++;
		if (state == 5) state = 0;

		for (int i = 0; i < 2; i++) {
			tab[i]->Draw(hdc, state);
		}

		return (state == 3 || state == 4);
	}

	void Clean() {
		for (int i = 0; i < 2; i++) {
			delete tab[i];
		}
	}
};