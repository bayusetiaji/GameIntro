#include <sl.h>
#include <Windows.h>

int main()
{
	slWindow(400, 400, "Animation", false); 

	int runTexture = slLoadTexture("Run-Sheet.png");
	// rasio frame dalam sprite sheet
	double frameRatioX = 1.0 / 8.0;
	
	// offset per frame
	double offsetX = 0.0;
	// pencacah waktu untuk update frame
	double timeElapsed = 0.0;

	// memainkan background music secara loop (SND_LOOP) dan asynchronous (SND_ASYNC)
	// agar tidak menghambat loop utama (non-blocking)
	PlaySound(L"KoncoMabur.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	while (!slShouldClose())
	{
		slSetBackColor(1.0, 1.0, 1.0);

		// atur tiling dan scroll untuk menampilkan frame yang benar
		slSetSpriteTiling(frameRatioX, 1.0);
		slSetSpriteScroll(offsetX, 0.0);

		slSprite(runTexture, 200, 200, 80, 80);
		slRender();

		// update frame setiap 0.1 detik
		if(timeElapsed >= 0.1)
		{
			// geser ke frame berikutnya
			offsetX += frameRatioX;
			timeElapsed = 0.0;
			// jika sudah melewati frame terakhir, kembali ke frame pertama
			if(offsetX >= 1.0)
			{
				offsetX = 0.0;
			}
		}

		// update waktu elapsed
		timeElapsed += slGetDeltaTime();
	}
	slClose();

	return 0;
}