#include "Person.h"
#include "SimplePerson.h"
#include <vector>
#include <iostream>
#include <chrono>

int main()
{
	std::chrono::steady_clock clock;
	auto timepoint1 = clock.now();
	std::vector<Person> employees;
	std::vector<SimplePerson> simpleEmployees;
	for (size_t i = 0ull; i < 10'000ull; i++)
	{
		employees.push_back(Person());
	}
	auto timepoint2 = clock.now();
	for (size_t i = 0ull; i < 10'000ull; i++)
	{
		simpleEmployees.push_back(SimplePerson());
	}
	auto timepoint3 = clock.now();

	auto durationOfTheTest1 = timepoint2 - timepoint1;
	auto durationOfTheTestUs1 = std::chrono::duration_cast<std::chrono::microseconds>(durationOfTheTest1);
	auto durationOfTheTestMs1 = std::chrono::duration_cast<std::chrono::milliseconds>(durationOfTheTest1);

	auto durationOfTheTest2 = timepoint3 - timepoint2;
	auto durationOfTheTestUs2 = std::chrono::duration_cast<std::chrono::microseconds>(durationOfTheTest2);
	auto durationOfTheTestMs2 = std::chrono::duration_cast<std::chrono::milliseconds>(durationOfTheTest2);

	std::cout << "constructor was called " << Person::m_constructorCounter << " times" <<std::endl;
	std::cout << "desctructor was called " << Person::m_descructorCounter << " times" <<std::endl;
	std::cout << "copy constructor was called " << Person::m_copyConstructorCounter << " times" <<std::endl;
	std::cout << "copy assign operator was called " << Person::m_copyAssignOperatorCounter << " times" <<std::endl;
	std::cout << "move constructor was called " << Person::m_moveConstructorCounter << " times" <<std::endl;
	std::cout << "move assign operator was called " << Person::m_moveAssignOperatorCounter << " times" <<std::endl;
	std::cout << "duration: test 1 [us]: " << durationOfTheTestUs1.count() << std::endl;
	std::cout << "duration: test 1 [ms]: " << durationOfTheTestMs1.count() << std::endl;
	std::cout << "duration: test 2 [us]: " << durationOfTheTestUs2.count() << std::endl;
	std::cout << "duration: test 2 [ms]: " << durationOfTheTestMs2.count() << std::endl;
}


