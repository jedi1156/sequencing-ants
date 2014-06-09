#ifndef _INCLUDE_COMMON_HPP
#define _INCLUDE_COMMON_HPP

#include <signal.h>
#include <unistd.h>

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
#include <map>

#include <thread>
#include <mutex>
#include <condition_variable>
#include "INI.hpp"

typedef INI <string, string, string> ini_t;

using namespace std;

#endif
