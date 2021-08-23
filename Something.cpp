#include <iostream>
#include <string>

using namespace std;

// Product
class Computer
{
	string Type;
	string CPU;
	string GPU;
	string RAM;
	string Disk;
	bool on;
public:
	Computer()
	{
		on = false;
	}
	void setType(const string& Type)
	{
		this->Type = Type;
	}
	void setCPU(const string& CPU)
	{
		this->CPU = CPU;
	}
	void setGPU(const string& GPU)
	{
		this->GPU = GPU;
	}
	void setRAM(const string& RAM)
	{
		this->RAM = RAM;
	}
	void setDisk(const string& Disk)
	{
		this->Disk = Disk;
	}
	void power_button()
	{
		on = on ? false : true;
	}
	void info()const
	{
		cout << "\n------------------------------------------------------\n";
		cout << Type << endl;
		if (on)
		{
			cout << "System properties:\n";
			cout << "CPU: " << CPU << endl;
			cout << "RAM: " << RAM << endl;
			cout << "Disk: " << Disk << endl;
			cout << "GPU: " << GPU << endl;
		}
		else
		{
			cout << "Computer is off" << endl;
		}
		cout << "\n------------------------------------------------------\n";
	}
};

// Abstract builder

class ComputerBuilder
{
protected:
	Computer* computer;
public:
	ComputerBuilder()
	{
		this->computer = new Computer;
	}
	virtual ~ComputerBuilder()
	{
		delete this->computer;
	}
	Computer* getComputer()const
	{
		return this->computer;
	}
	virtual void setType() = 0;
	virtual void setCPU() = 0;
	virtual void setGPU() = 0;
	virtual void setRAM() = 0;
	virtual void setDisk() = 0;
};

class CheepComputerBuilder : public ComputerBuilder
{
public:
	~CheepComputerBuilder() {}
	void setType()
	{
		computer->setType("CheepComputer");
	}
	void setCPU()
	{
		computer->setCPU("Celeron");
	}
	void setGPU()
	{
		computer->setGPU("IntelHD Graphics");
	}
	void setRAM()
	{
		computer->setRAM("4GB");
	}
	void setDisk()
	{
		computer->setDisk("Samsung 360GB");
	}
};

class OfficeComputerBuilder : public ComputerBuilder
{
public:
	void setType()
	{
		computer->setType("OfficeComputer");
	}
	void setCPU()
	{
		computer->setCPU("Core i3-2125");
	}
	void setGPU()
	{
		computer->setGPU("Intel HD Graphics 3000");
	}
	void setRAM()
	{
		computer->setRAM("8GB");
	}
	void setDisk()
	{
		computer->setDisk("Kingston SSD 128 GB");
	}
};

class GameComputerBuilder : public ComputerBuilder
{
public:
	void setType()
	{
		computer->setType("GameComputer");
	}
	void setCPU()
	{
		computer->setCPU("Core i9-9900K");
	}
	void setGPU()
	{
		computer->setGPU("Geforce 3090-TI");
	}
	void setRAM()
	{
		computer->setRAM("64GB");
	}
	void setDisk()
	{
		computer->setDisk("Samsung 980-pro");
	}
};

class ServerBuilder : public ComputerBuilder
{
public:
	void setType()
	{
		computer->setType("Server");
	}
	void setCPU()
	{
		computer->setCPU("Inter Xeon E3");
	}
	void setGPU()
	{
		computer->setGPU("Maxtor");
	}
	void setRAM()
	{
		computer->setRAM("128GB");
	}
	void setDisk()
	{
		computer->setDisk("Disk");
	}
};

class Sysadmin
{
	ComputerBuilder* comp_builder;
public:
	void assemblyComputer(ComputerBuilder* comp_builder)
	{
		this->comp_builder = comp_builder;
		comp_builder->setType();
		comp_builder->setCPU();
		comp_builder->setGPU();
		comp_builder->setRAM();
		comp_builder->setDisk();
	}
	void turnOnTheComputer()
	{
		comp_builder->getComputer()->power_button();
		comp_builder->getComputer()->info();
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	system("color 0A");

	Sysadmin nice_guy;
	CheepComputerBuilder computer_for_bookkeeper;
	nice_guy.assemblyComputer(&computer_for_bookkeeper);
	nice_guy.turnOnTheComputer();
	//computer_for_bookkeeper.getComputer()->info();

	OfficeComputerBuilder computer_for_director;
	nice_guy.assemblyComputer(&computer_for_director);
	computer_for_director.getComputer()->power_button();
	computer_for_director.getComputer()->info();

	GameComputerBuilder computer_for_sysadmin;
	nice_guy.assemblyComputer(&computer_for_sysadmin);

}