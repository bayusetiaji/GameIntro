#include <sl.h>
#include <string>

int main()
{
	slWindow(800, 600, "Dragon", 0);

	const char imgPath[] = "./dragon/";
	const int numFrames = 9;
	int frames[numFrames];

	// menyimpan semua frame ke array
	for(int i = 0; i < numFrames; i++)
	{
		frames[i] = slLoadTexture((std::string(imgPath) + std::to_string(i) + ".png").c_str());
	}

	int idx = 0;
	double elapsedTime = 0.0;

	while (!slShouldClose())
	{
		slSetBackColor(0.0, 0.0, 0.0);
		slSprite(frames[idx], 400, 300, 192, 176);
		slRender();

		// update frame index setiap 0.1 detik
		if(elapsedTime >= 0.05)
		{
			// geser ke frame berikutnya
			idx++;
			elapsedTime = 0.0;

			// reset index jika sudah mencapai jumlah frame
			if (idx >= numFrames)
			{
				idx = 0;
			}
		}

		// update waktu elapsed
		elapsedTime += slGetDeltaTime();
	}

	slClose();
	return 0;
}