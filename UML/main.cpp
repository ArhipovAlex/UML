﻿#include<iostream>
using namespace std;

#define MIN_TANK_VOLUME 20
#define MAX_TANK_VOLUME 120
#define MIN_MAX_SPEED 90
#define MAX_MAX_SPEED 400

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
	Tank(int volume) :VOLUME
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
		cout << "Fuel level: " << fuel << " liters.\n";
	}
};
class Engine
{
	double consumption;
	double consumption_per_sec;
	bool is_started;
public:
	double get_consumption()const
	{
		return consumption;
	}
	double get_consumption_per_sec()const
	{
		return consumption_per_sec;
	}
	bool get_is_started()const
	{
		return is_started;
	}
	void set_is_started(bool is_started)
	{
		this->is_started = is_started;
	}
	Engine(double consumption, double consumption_per_sec)
	{
		this->consumption = consumption;
		this->consumption_per_sec = consumption_per_sec;
		this->is_started = 0;
		cout << "Engine is ready:\t" << this << endl;
	}
	~Engine()
	{
		cout << "Engine is over:\t" << this << endl;
	}
	void info()const
	{
		cout << "Consumption: " << consumption << endl;
		cout << "Consumption per second: " << consumption_per_sec << endl;
		cout << "Status: "; is_started ? cout << "ON" : cout << "OFF"; cout << endl;
	}
};
class Car
{
	const int MAX_SPEED;
	int speed;
public:
	const int get_max_speed()const
	{
		return MAX_SPEED;
	}
	int get_speed()const
	{
		return speed;
	}
	void set_speed(int speed)
	{
		this->speed = speed;
	}
	Car(int max_speed):MAX_SPEED
	(
		max_speed< MIN_MAX_SPEED ? MIN_MAX_SPEED :
		max_speed>MAX_MAX_SPEED ? MAX_MAX_SPEED :
		max_speed
	)
	{
		this->speed = 0;
		cout << "Car is ready:\t" << this << endl;
	}
	~Car()
	{
		cout << "Car is over:\t" << this << endl;
	}
	void info()const
	{
		cout << "Max speed: " << MAX_SPEED << endl;
		cout << "Speed: " << speed << endl;
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