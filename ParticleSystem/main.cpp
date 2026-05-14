#include <sl.h>
#include <cstdlib>
#include <ctime>
#include <vector>

#include "particle.h"

int main()
{
	std::vector<Particle> particles;
	// menambah 100 partikel ke dalam sistem / vektor
	for (int i = 0; i < 1000; ++i)
	{
		particles.emplace_back(400.f, 300.f);
	}

	slWindow(800, 600, "Particle System", 0);

	srand(static_cast<unsigned int>(time(0)));
	// set mode blending untuk membuat efek partikel lebih menarik
	slSetAdditiveBlend(true);
	while (!slShouldClose())
	{
		slSetBackColor(0, 0, 0);
		// menggambar dan memperbarui setiap partikel dalam sistem
		for(Particle& p : particles)
		{
			p.update();
			p.draw();
		}

		slRender();
	}
	slClose();

	return 0;
}