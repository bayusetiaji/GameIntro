#pragma once

#include <cstdlib>
#include <sl.h>

class Particle {
public:
	Particle(float x, float y) : posX(x), posY(y)
	{
		reset();
	}

	// fungsi untuk mereset partikel ke posisi awal dengan kecepatan dan umur acak
	void reset()
	{
		posX = 400;
		posY = 300;
		velX = static_cast<float>(randbetween(-10, 10)) / 10.0f; // random velocity X
		velY = static_cast<float>(randbetween(-10, 10)) / 10.0f; // random velocity Y
		life = static_cast<float>(rand() % 100) / 100.0f; // random life between 0 and 1
	}

	// fungsi untuk memperbarui posisi partikel dan mengurangi umur partikel
	void update()
	{
		posX += velX;
		posY += velY;
		life -= 0.01f; // decrease life over time
		if(life <= 0.f)
		{
			reset();
		}
	}

	// fungsi untuk menggambar partikel menggunakan SL
	void draw()
	{
		slSetForeColor(0.9, 0.1, 0.2, life);
		slCircleFill(posX, posY, 5, 15);
	}

private:
	float posX;
	float posY;
	float velX;
	float velY;
	float life;

	// fungsi untuk menghasilkan angka acak antara min dan max
	int randbetween(int min, int max)
	{
		return rand() % (max - min + 1) + min;
	}
};