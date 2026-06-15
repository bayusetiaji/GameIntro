#include <sl.h>

int main()
{
	slWindow(800, 800, "Solar System", false);

	double angleEarth = 0.0;
	double angleMoon = 0.0;

	while (!slShouldClose())
	{
		// matahari
		slPush();
			slTranslate(400.0, 400.0);
			slSetForeColor(1.0, 0.0, 0.0, 1.0);
			slCircleFill(0.0, 0.0, 60.0, 60.0);
			// bumi
			slRotate(angleEarth);
			slPush();
				slTranslate(250.0, 0.0);
				slSetForeColor(0.0, 0.0, 1.0, 1.0);
				slCircleFill(0.0, 0.0, 30.0, 20.0);

				// bulan
				slRotate(angleMoon);
				slPush();
					slTranslate(80.0, 0.0);
					slSetForeColor(0.5, 0.5, 0.5, 1.0);
					slCircleFill(0.0, 0.0, 8.0, 8.0);
				slPop();
			slPop();
		slPop();
		
		slRender();

		// update angle
		angleEarth += 1.0;
		angleMoon += 5.0;
	}
	slClose();
	
	return 0;
}