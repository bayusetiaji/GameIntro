#include <sl.h>

int main()
{
	slWindow(800, 600, "Hello, World!", 0);

	int imgAstro = slLoadTexture("D:\\exps\\res\\imgs\\astro.png");
	int sndJump  = slLoadWAV("D:\\exps\\res\\audio\\jump3.wav");

	double posX = 400;
	double posY = 600;
	double velY = 0;
	double gForce = -0.096;

	while(!slShouldClose())
	{
		slSetForeColor(1, 1, 1, 1);
		slSprite(imgAstro, posX, posY, 128, 171);

		slRender();

		velY += gForce;
		posY += velY;

		if (posY <= 0) 
		{
			velY *= -1;
			slSoundPlay(sndJump);
		}
	}

	slClose();

	return 0;
}