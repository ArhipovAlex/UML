#include<iostream>
using namespace std;

#define MIN_TANK_VOLUME 20
#define MAX_TANK_VOLUME 120

class Tank
{
	const int VOLUME;
	double fuel;
public:
	const int get_VOLUME()const
	{
		return VOLUME;
	}
	double get_fuel()const
	{
		return fuel;
	}
	void fill(double fuel)
	{
		if (fuel < 0)return;
		if (this->fuel + fuel < VOLUME)this->fuel += fuel;
		else this->fuel = VOLUME;
	}
	//если нужно задать константу в классе, то инициализировать в заголовке
	Tank(int volume):VOLUME
		(
			volume< MIN_TANK_VOLUME ? MIN_TANK_VOLUME :
			volume>MAX_TANK_VOLUME ? MAX_TANK_VOLUME :
			volume
		)
	{
		this->fuel = 0;
		cout << "Tank is ready:\t" << this << endl;
	}
	~Tank()
	{
		cout << "Tank is over:\t" << this << endl;
	}
	void info()const
	{
		cout << "Volume: " << VOLUME << " liters.\n";
		cout << "Fuel level: "<<fuel<< " liters.\n";
	}
};

//#define TANK_CHECK
#define ENGINE_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef TANK_CHECK
	Tank tank(12);
	double fuel;
	do
	{
		cout << "Введите уровень топлива: "; cin >> fuel;
		tank.fill(fuel);
		tank.info();
	} while (fuel != 0);
#endif //TANK_CHECK
}