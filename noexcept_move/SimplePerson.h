#pragma once


#include "defnoexcept.h"
#include <string>

class SimplePerson
{
public:

	std::wstring m_name{ L"Maaagdalena" };
	unsigned long m_age{ 16ul };
	std::wstring m_address{ L"Hauptstrasse 25c, 01865 Bregenz" };
	float m_weight{ 53.2f };
	std::string m_hobby{ "eating chocolatte" };


	SimplePerson() = default;
	~SimplePerson() = default;
	SimplePerson(const SimplePerson& rhs) = default;
	SimplePerson& operator=(const SimplePerson& rhs) = default;


#ifdef USE_NOEXCEPT_WITH_MOVE_MEMBER_FUNC
	SimplePerson(SimplePerson&& rhs) noexcept = default;
#else
	SimplePerson(SimplePerson&& rhs) = default;
#endif


#ifdef USE_NOEXCEPT_WITH_MOVE_MEMBER_FUNC
	SimplePerson& operator=(SimplePerson&& rhs) noexcept = default;
#else
	SimplePerson& operator=(SimplePerson&& rhs) = default;
#endif


};
