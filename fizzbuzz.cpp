#include <sstream>

#include "fizzbuzz.h"

static const std::string STR_FIZZ("fizz");
static const std::string STR_BUZZ("buzz");

/*
 * ・わかりやすさを優先
 * ・fizzbuzzの処理はfizzおよびbuzzと共通化
 * ・retrunは一ヶ所
 */
const std::string& fizzbuzz(int n){

	static std::string str;

	str.erase();

	if(n % 3 == 0)
	{
		str.append(STR_FIZZ);
	}

	if(n % 5 == 0)
	{
		str.append(STR_BUZZ);
	}

	if(str.empty())
	{
		std::stringstream ss;

		ss << n;
		str = ss.str();
	}

	return str;
}

