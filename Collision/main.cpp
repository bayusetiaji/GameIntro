#include <sl.h>
#include <cmath>

bool collision(float x1, float y1, float r1, float x2, float y2, float r2)
{
	float dx = x2 - x1;
	float dy = y2 - y1;
	float distance = std::hypot(dx, dy);

	return distance <= (r1 + r2);
}

int main()
{
	float x1 = 400.f;
	float y1 = 300.f;
	float r1 = 40.f;

	float x2 = 0.f;
	float y2 = 0.f;
	float r2 = 20.f;

	slWindow(800, 600, "Collision", 0);

	while(!slShouldClose())
	{
		slSetBackColor(0, 0, 0);

		// cek apakah ada collision antara lingkaran merah dan hijau
		// jika ada, ubah warna lingkaran menjadi hijau
		if (collision(x1, y1, r1, x2, y2, r2))
			slSetForeColor(0, 1, 0, 1);
		else
			slSetForeColor(1, 0, 0, 1);

		slCircleFill(x1, y1, r1, 32);

		slSetForeColor(0, 1, 0, 1);
		x2 = slGetMouseX();
		y2 = slGetMouseY();
		slCircleOutline(x2, y2, r2, 32);

		// ilustrasi garis yang menghubungkan pusat kedua lingkaran
		slSetForeColor(1, 1, 1, 1);
		slLine(x1, y1, x2, y2);

		slRender();
	}
	
	return 0;
}