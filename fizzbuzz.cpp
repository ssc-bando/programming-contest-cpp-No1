#include <boost/lexical_cast.hpp>

#include "fizzbuzz.h"

/*
 * ・わかりやすさを優先
 * ・fizzbuzzの処理はfizzおよびbuzzの処理と共通化
 * ・returnは一ヶ所
 */
const std::string& fizzbuzz(int n){

	using std::string;
	using boost::lexical_cast;

	static string str;

	//clear()の方が、空文字列の代入より早い
	//clear()の方が、erase()より直感的にわかりやすい
	str.clear();

	if(n % 3 == 0)
	{
 		//空文字列へのappend()の方が、代入より早い(気がする)
		str.append("fizz");
	}

	if(n % 5 == 0)
	{
		str.append("buzz");
	}

 	//empty()の方が、size() == 0より早い(気がする)
	if(str.empty())
	{
		//ここが一番時間がかかる
 		//lexical_castの方が、stringstreamより早い
 		//lexical_castとsnprintfは速度的に大差なく
		//lexical_castの方が、snprintfより直感的にわかりやすい
		str = lexical_cast<string>(n);
	}

	return str;
}

