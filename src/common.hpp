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

#define ALPHA 2
#define BETA 15
#define GAMMA 1
#define NUMBER_OF_ANTS 10
#define Q_PARAM 1.0
#define R_PARAM 1.0
#define RO 0.6

#define D 5
typedef INI <string, string, string> ini_t;


using namespace std;

#endif
