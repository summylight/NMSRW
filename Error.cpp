/* -------------------------------------------------
Error Utilities

Last Update: 11/02/2012
copied from GTRIES 
---------------------------------------------------- */

#include "Error.h"


void Error::msg(const char *format, ...) {
  va_list p;
  if (format == NULL)
    msg("%s", (char *)strerror (errno));
  else {
      fprintf (stderr, ERROR_HEADER);
      va_start (p, format);
      vfprintf (stderr, format, p);
      va_end (p);
      fprintf (stderr, "\n");
    }

  exit(EXIT_FAILURE);
}

