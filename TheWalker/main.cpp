#include <sl.h>
#include <cstdlib>
#include <ctime>

int main()
{
	slWindow(800, 600, "The Walker", 0);

	int direction = 0;
	int posX = 400;
	int posY = 300;
	int velX = 0;
	int velY = 0;
	int counter = 0;

	srand(static_cast<unsigned int>(time(0)));
	while(!slShouldClose())
	{
		counter++;
		// ganti arah setiap 1 detik (60 frame pada 60 FPS)
		if(counter > 60) 
		{
			// hasil antara 0, 1, 2, atau 3
			direction = rand() % 4; 
			counter = 0;
		}
		
		if (direction == 0)		// kanan
		{
			velX = 1;
			velY = 0;
		}
		else if (direction == 1)// kiri
		{
			velX = -1;
			velY = 0;
		}
		else if (direction == 2)// atas
		{
			velX = 0;
			velY = 1;
		}
		else					// bawah
		{
			velX = 0;
			velY = -1;
		}

		// update posisi berdasarkan kecepatan
		posX += velX;
		posY += velY;

		slSetBackColor(0, 0, 0);
		slSetForeColor(0, 1, 0, 1);
		slRectangleFill(posX, posY, 10, 10);

		slRender();
	}
	slClose();

	return 0;
}
