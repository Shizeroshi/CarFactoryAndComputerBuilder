#include <iostream>
#include <map>
using namespace std;

// Abstract Prototyoe
class BMW
{
protected:
	const unsigned int max_speed;
	const unsigned int Doors;
public:
	BMW(const unsigned int max_speed, const unsigned int Doors):max_speed(max_speed), Doors(Doors){}
	virtual ~BMW(){}
	void info()const
	{
		cout << this << ":" << typeid(*this).name() << "\t";
		cout << "Max speed: " << max_speed << ", \tDoors: " << Doors << endl;
	}
	virtual BMW* clone()const = 0;
};

// Concrete prototype
class BMW_3 : public BMW
{
public:
	BMW_3() :BMW(220, 3){}
	~BMW_3(){}
	BMW* clone()const
	{
		return new BMW_3(*this);
	}
};

class BMW_5 : public BMW
{
public:
	BMW_5() :BMW(250, 4) {}
	~BMW_5() {}
	BMW* clone()const
	{
		return new BMW_5(*this);
	}
};

class BMW_7 : public BMW
{
public:
	BMW_7() :BMW(280, 5) {}
	~BMW_7() {}
	BMW* clone()const
	{
		return new BMW_7(*this);
	}
};

class BMWFactory
{
	static map<int, BMW*> prototype;
public:
	static BMW* create_model(int model)
	{
		return prototype[model]->clone();
	}
};

map<int, BMW*> BMWFactory::prototype =
{
	pair<int, BMW*>(3, new BMW_3),
	pair<int, BMW*>(5, new BMW_5),
	pair<int, BMW*>(7, new BMW_7),
};

int main()
{
	setlocale(LC_ALL, "Russian");
	system("color 0A");

	BMW* bmw = BMWFactory::create_model(3); bmw->info();
	BMW* bmw3 = BMWFactory::create_model(3); bmw3->info();
	BMW_3 bmw_3;
	bmw_3.info();
}