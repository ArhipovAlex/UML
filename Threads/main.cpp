#include<iostream>
#include<thread>
using std::cin;
using std::cout;
using std::endl;
using namespace std::chrono_literals;

bool finish = false;

void Plus()
{
	while (!finish)
	{
		cout << "+ ";
		std::this_thread::sleep_for(1s);
	}
}
void Minus()
{
	while (!finish)
	{
		cout << "- ";
		std::this_thread::sleep_for(1s);
	}
}

void main()
{
	//Plus();
	//Minus();
	std::thread plus_thread(Plus);
	std::thread minus_thread(Minus);
	cin.get();//ожидает Enter
	finish = true;
	plus_thread.join();
	minus_thread.join();
}