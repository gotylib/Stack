#include <string>

class Liquid {
protected:
	std::string* name;
	float* density;
public:
	Liquid();
	Liquid(std::string& name, float& dinsity);
	Liquid(Liquid& other);
	~Liquid();
	std::string GetName();
	float GetDensity();
	void SetDensity(float& density);
	void SetName(std::string& name);
};

#include "Liquid.h"

Liquid::Liquid()
{
	name = new std::string("None");
	density = new float(0.0);
}

Liquid::Liquid(std::string& name, float& density) {
	this->name = new std::string(name);
	this->density = new float(density);
}

Liquid::Liquid(Liquid& other)
{
	this->name = new std::string(*other.name);
	this->density = new float(*other.density);
}

Liquid::~Liquid()
{
	delete name;
	delete density;
}

std::string Liquid::GetName()
{
	return *name;
}

float Liquid::GetDensity()
{
	return *density;
}

void Liquid::SetDensity(float& density)
{
	*this->density = density;
}

void Liquid::SetName(std::string& name)
{
	*this->name = name;
}

#include "Liquid.h"
class Alcohol: public Liquid {
private:
	float* fortress;
public:
	Alcohol(std::string& name, float& dinsity, float& fortress);
	Alcohol(Alcohol& other);
	Alcohol();
	~Alcohol();
	float GetFortress();
	void SetFortress(float& fortress);
};

#include "Alcohol.h"

Alcohol::Alcohol(std::string& name, float& dinsity, float& fortress):Liquid(name,dinsity)
{
	this->fortress = new float(fortress);
}

Alcohol::Alcohol(Alcohol& other) :Liquid(other)
{
	this->fortress = new float(*other.fortress);
}

Alcohol::Alcohol():Liquid()
{
	fortress = new float(0.0);
}

Alcohol::~Alcohol() {
	delete fortress;
}

float Alcohol::GetFortress()
{
	return *(fortress);
}

void Alcohol::SetFortress(float& fortress)
{
	*(this->fortress) = fortress;
}


#include <iostream>
#include "Alcohol.h"
#include <vector>

using std::cout;
using std::endl;

int main() {
    std::string w = "Water";
    float density = 1.0;
    float fortress = 12.3;
    Alcohol l(w, density, fortress);

    // Использование методов класса
    cout << "Name: " << l.GetName() << endl;
    cout << "Density: " << l.GetDensity() << endl;
    cout << "Fortress: " << l.GetFortress() << std::endl;

    float newDensity = 1.5;
    l.SetDensity(newDensity);
    float newFortress = 20.5;
    l.SetFortress(newFortress);
    cout << "New density: " << l.GetDensity() << endl;
    cout << "New fortress: " << l.GetFortress() << endl;

}
