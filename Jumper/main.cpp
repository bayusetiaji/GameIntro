#include <cstdlib>
#include <ctime>
#include <string>
#include <sl.h>

int main()
{
	slWindow(800, 600, "Jumper", 0);

	int imgSorc = slLoadTexture("D:\\exps\\res\\imgs\\sorcerer.png");
	int imgCloud = slLoadTexture("D:\\exps\\res\\imgs\\cloud.png");
	int sndJump = slLoadWAV("D:\\exps\\res\\audio\\jump.wav");
	int fnt = slLoadFont("D:\\exps\\res\\fonts\\whitrabt.ttf");

	float posSorcX = 400.f;
	float posSorcY = 600.f;
	float velSorcY = 0.f;

	float posCloudX = 950.f;
	float posCloudY = 400.f;

	float gForce = -0.6f;

	int life = 5;
	bool gameOver = false;

	srand(static_cast<unsigned int>(time(0)));

	while(!slShouldClose())
	{
		if (!gameOver)
		{
			posCloudX -= 2.f; // gerakkan awan ke kiri
			if (posCloudX < -128.f) // jika awan keluar dari layar, reset posisinya
			{
				posCloudX = 950.f;

				// acak posisi vertikal awan antara 300 dan 500
				int rnd = rand() % 4 + 1; // hasil antara 1, 2, atau 3
				posCloudY = 100 * rnd;
			}

			velSorcY += gForce;
			posSorcY += velSorcY;

			// jika mendarat di tanah, atur posisi ke tanah 
			// dan reset kecepatan
			if (posSorcY <= 0.f)
			{
				posSorcY = 300.f;
				velSorcY = 0.f;

				if (life > 0)
					life--; // kurangi nyawa saat mendarat

				if (life == 0)	
					gameOver = true; // set game over jika nyawa habis
			}

			// deteksi penekanan tombol spasi untuk melompat
			if (slGetKey(32)) // 32 adalah kode ASCII untuk spasi
			{
				velSorcY = 5.f;			// atur kecepatan lompat
				slSoundPlay(sndJump);	// mainkan suara lompat saat mendarat
			}
		}
		
		slSprite(imgCloud, posCloudX, posCloudY, 256, 166);
		slSprite(imgSorc, posSorcX, posSorcY, 128, 128);

		slSetForeColor(1, 1, 1, 1);
		slSetFont(fnt, 24);
		slText(50, 550, "Life: ");
		slText(150, 550, std::to_string(life).c_str());

		if(gameOver)
		{
			slSetForeColor(1, 0, 0, 1);
			slSetFont(fnt, 48);
			slText(300, 300, "Game Over!");
		}

		slRender();
	}

	slClose();

	return 0;
}