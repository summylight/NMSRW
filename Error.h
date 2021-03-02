/* -------------------------------------------------

Error Utilities

Last Update: 11/02/2012
---------------------------------------------------- */

#ifndef _ERROR_
#define _ERROR_

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "Common.h"
#define EXIT_FAILURE 1

class Error {
 public:
  static void msg(const char *format, ...);
};

#endif
