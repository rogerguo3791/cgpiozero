#pragma once
#ifndef UTILITIES_H
#define UTILITIES_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include "data.hpp"
#include  <stdarg.h>
#include <functional>
using namespace std;


string format_str(const char *pszFmt, ...);

#endif