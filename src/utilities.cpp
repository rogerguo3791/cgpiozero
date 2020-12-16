#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <string>
#include <vector>
#include <stdarg.h>
#include <functional>


using namespace std;

/**
 * 格式化字符串
 * 
 * \param pszFmt 格式描述
 * \param ... 不定参数
 * \return 格式化的结果字符串
 */
string format(const char *pszFmt, ...)
{
    std::string str;
    va_list args;
    va_start(args, pszFmt);
    {
        int nLength = vsnprintf(NULL,0,pszFmt, args);
        nLength += 1;  //上面返回的长度是包含\0，这里加上
        std::vector<char> chars(nLength);
        vsnprintf(chars.data(), nLength, pszFmt, args);
        str.assign(chars.data());
    }
    va_end(args);
    return str;
};


