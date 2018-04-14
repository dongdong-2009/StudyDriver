/*
 * stdafx.h
 *
 *  Created on: 2013-9-12
 *      Author: LiuHao
 */

#ifndef _SystemInclude_H_
#define _SystemInclude_H_

/*** C header. ***/
#include <stddef.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <fcntl.h>
#include <assert.h>
#include <syslog.h>
#include <errno.h>
#include <termios.h>
#include <pthread.h>
#include <limits.h>

/*** OS header. ***/
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>   //for wait() function.
#include <sys/resource.h>

/*** C++ header. ***/
#if defined(__cplusplus)
#include <cstddef>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <list>
#include <map>
#include <set>
#include <typeinfo>
#include <functional>
#include <algorithm>

using namespace std;
#endif  //#if defined(__cplusplus)

#endif /* _STDAFX_H_ */
