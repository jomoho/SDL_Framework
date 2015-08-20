/*
 * stringtools.h
 *
 *  Created on: Aug 29, 2013
 *      Author: Moritz Laass
 */

#ifndef STRINGTOOLS_H_
#define STRINGTOOLS_H_

//SOURCE: http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring?lq=1
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>
#include <vector>


// trim from start
static inline std::string &ltrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
        return s;
}

// trim from end
static inline std::string &rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
        return s;
}

// trim from both ends
static inline std::string &trim(std::string &s) {
        return ltrim(rtrim(s));
}



#endif /* STRINGTOOLS_H_ */
