#pragma once


#include "defnoexcept.h"
#include <string>

class Person
{
public:

	std::wstring m_name{ L"Maaagdalena" };
	unsigned long m_age{ 16ul };
	std::wstring m_address{ L"Hauptstrasse 25c, 01865 Bregenz" };
	float m_weight{ 53.2f };
	std::string m_hobby { "eating chocolatte" };

	inline static unsigned long long m_constructorCounter{ 0ull }; //requires C++17
	inline static unsigned long long m_descructorCounter{ 0ull };
	inline static unsigned long long m_moveConstructorCounter{ 0ull };
	inline static unsigned long long m_moveAssignOperatorCounter{ 0ull };
	inline static unsigned long long m_copyConstructorCounter{ 0ull };
	inline static unsigned long long m_copyAssignOperatorCounter{ 0ull };

	Person()
	{
		m_constructorCounter++;
	}

	~Person()
	{
		m_descructorCounter++;
	}

	Person (const Person& rhs): 
		m_name(rhs.m_name), 
		m_age(rhs.m_age), 
		m_address(rhs.m_address), 
		m_weight(rhs.m_weight), 
		m_hobby(rhs.m_hobby)
	{
		m_copyConstructorCounter++;
	}

	Person& operator=(const Person& rhs)
	{
		m_name = rhs.m_name;
		m_age = rhs.m_age;
		m_address = rhs.m_address;
		m_weight = rhs.m_weight;
		m_hobby = rhs.m_hobby;
		m_copyAssignOperatorCounter++;
	}

#ifdef USE_NOEXCEPT_WITH_MOVE_MEMBER_FUNC
	Person(Person&& rhs) noexcept:
#else
	Person(Person&& rhs) :
#endif
		m_name(std::move(rhs.m_name)),
		m_age(std::move(rhs.m_age)),
		m_address(std::move(rhs.m_address)),
		m_weight(std::move(rhs.m_weight)),
		m_hobby(std::move(rhs.m_hobby))
	{
		m_moveConstructorCounter++;
	}

#ifdef USE_NOEXCEPT_WITH_MOVE_MEMBER_FUNC
	Person& operator=(Person&& rhs) noexcept
#else
	Person& operator=(Person&& rhs)
#endif
	{
		m_name = std::move(rhs.m_name);
		m_age = std::move(rhs.m_age);
		m_address = std::move(rhs.m_address);
		m_weight = std::move(rhs.m_weight);
		m_hobby = std::move(rhs.m_hobby);
		m_moveAssignOperatorCounter++;
	}

};