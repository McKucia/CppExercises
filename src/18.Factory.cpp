
#include <iostream>
#include <memory>

class Bike
{
public:
	virtual void specification() = 0;
	virtual ~Bike() = default;
};

class UrbanBike : public Bike
{
public:
	void specification() override { std::cout << "To jest rower miejski\n"; }
};

class SportBike : public Bike
{
public:
	void specification() override { std::cout << "To jest rower sportowy\n"; }
};

class Car
{
public:
	virtual void specification() = 0;
	virtual ~Car() = default;
};

class UrbanCar : public Car
{
public:
	void specification() override { std::cout << "To jest samochod miejski\n"; }
};

class SportCar : public Car
{
public:
	void specification() override { std::cout << "To jest samochod sportowy\n"; }
};

class Factory
{
public:
	virtual std::unique_ptr<Car> createCar() = 0;
	virtual std::unique_ptr<Bike> createBike() = 0;
};

class UrbanFactory : public Factory
{
public:
	std::unique_ptr<Car> createCar() override {
		return std::make_unique<UrbanCar>();
	}
	std::unique_ptr<Bike> createBike() override {
		return std::make_unique<UrbanBike>();
	}
};

class SportFactory : public Factory
{
public:
	std::unique_ptr<Car> createCar() override {
		return std::make_unique<SportCar>();
	}
	std::unique_ptr<Bike> createBike() override {
		return std::make_unique<SportBike>();
	}
};

int main()
{
	std::unique_ptr<Factory> factory = std::make_unique<UrbanFactory>();

	std::unique_ptr<Car> car = factory->createCar();
	std::unique_ptr<Bike> bike = factory->createBike();

	car->specification();
	bike->specification();
    return 0;
}