#include <sl.h>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

// representasi bola dengan posisi (x, y) dan radius r
struct Ball {
	float x;
	float y;
	float r;
};

// fungsi untuk mendeteksi collision antara dua bola
bool collision(const Ball& b1, const Ball& b2)
{
	float dx = b2.x - b1.x;
	float dy = b2.y - b1.y;
	// hitung jarak antara pusat kedua bola
	float distance = std::hypot(dx, dy);

	// collision terjadi jika jarak antara pusat kedua bola 
	// kurang dari atau sama dengan jumlah radius kedua bola
	return distance <= (b1.r + b2.r);
}

int main()
{
	Ball myBall{ 0.f, 0.f, 20.f };
	std::vector<Ball> balls;

	srand(static_cast<unsigned int>(time(0)));
	// inisialisasi 10 bola dengan posisi acak
	for(int i = 0; i < 10; i++)
	{
		float x = static_cast<float>(rand() % 800);
		float y = static_cast<float>(rand() % 600);
		float r = 20.f;
		
		// tambahkan bola ke vector
		balls.push_back({ x, y, r });
	}

	slWindow(800, 600, "Interaction", 0);

	while (!slShouldClose())
	{
		slSetBackColor(0, 0, 0);
		
		slSetForeColor(0, 1, 0, 1);
		myBall.x = static_cast<float>(slGetMouseX());
		myBall.y = static_cast<float>(slGetMouseY());
		slCircleOutline(myBall.x, myBall.y, myBall.r, 32);
		
		// cek collision antara myBall dengan setiap bola di vector
		for(auto &ball : balls)
		{
			if (collision(myBall, ball))
				slSetForeColor(0, 1, 0, 1);
			else
				slSetForeColor(1, 0, 0, 1);

			slCircleFill(ball.x, ball.y, ball.r, 32);
		}

		slRender();
	}
	
	return 0;
}