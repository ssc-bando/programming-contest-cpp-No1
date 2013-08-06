#include "fizzbuzz.h"

/* INT_MIN = -2147483648 INT_MAX = 2147483647を想定 */
static const int STR_LEN_MAX    = 12;

static const std::string STR_FIZZBUZZ   = "fizzbuzz";
static const std::string STR_FIZZ       = "fizz";
static const std::string STR_BUZZ       = "buzz";

/*
 * 10進数のみ対応したitoa関数
 */
const std::string& itoa_decimal(int number)
{
        char str[STR_LEN_MAX];
        char* pStr = str;
        unsigned int absVal;    // INT_MINに対応するため

        // 負の場合'-'をつける
        if (number < 0)
        {
                absVal = -number;
                *pStr++ = '-';
        }
        else
        {
                absVal = number;
        }

        // 終端文字分、ポインタ位置をずらす
        pStr++;

        // 桁数だけポインタ位置をずらす
        // ループと除算の方が素直だが、実行速度を優先する
        // INT_MAXが変わったら処理を変更する必要がある
        if(absVal > 10)
                pStr++;
        if(absVal > 100)
                pStr++;
        if(absVal > 1000)
                pStr++;
        if(absVal > 10000)
                pStr++;
        if(absVal > 100000)
                pStr++;
        if(absVal > 1000000)
                pStr++;
        if(absVal > 10000000)
                pStr++;
        if(absVal > 100000000)
                pStr++;
        if(absVal > 1000000000)
                pStr++;

        //終端にNULL文字
        *pStr-- = '\0';

        //下位の桁から値を入れていく
        do {
                //文字'0'に10の剰余を加算するよりも、実行速度が早い
                *pStr-- = "0123456789"[absVal % 10];
                absVal /= 10;
        } while (absVal != 0);

        //clearとappendの方が代入より実行速度が早い
        static std::string ret;
        ret.clear();
        ret.append(str);

        return ret;
}

/*
 * 実行速度部門向け
 *
 * 数値->文字列変換部分を自作して高速化
 */
const std::string& fizzbuzz(int n){
        return (n % 3 == 0) ? (n % 5 == 0) ? STR_FIZZBUZZ
                                           : STR_FIZZ
                            : (n % 5 == 0) ? STR_BUZZ
                                           : itoa_decimal(n);
}

