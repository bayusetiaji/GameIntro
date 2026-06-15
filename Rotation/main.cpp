#include <sl.h>

int main()
{
	slWindow(600, 600, "Rotation", false);

	double angle = 0.0;

	while(!slShouldClose())
	{
		slSetBackColor(0.0, 0.0, 0.0);
		
		slPush();
		slTranslate(300.0, 300.0);
		slRotate(angle);

		slSetForeColor(0.0, 1.0, 0.0, 1.0);
		slRectangleFill(0.0, 0.0, 200.0, 10.0);

		slSetForeColor(1.0, 0.0, 0.0, 1.0);
		slCircleFill(0.0, 0.0, 16.0, 16.0);
		slPop();

		slRender();

		angle += 10.0;
	}

	return 0;
}