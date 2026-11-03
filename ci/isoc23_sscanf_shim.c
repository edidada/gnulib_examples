/* Compatibility shim for old glibc (<= 2.37).

   The Gnulib sources committed in this repository were generated against a
   glibc that provides __isoc23_sscanf (glibc >= 2.38). On older glibc the
   symbol is missing and the get_ppid_of module fails to link. This tiny
   function supplies it by delegating to vsscanf. It is only linked on the
   older Ubuntu images; newer glibc already exports the real symbol. */

#include <stdio.h>
#include <stdarg.h>

int
__isoc23_sscanf (const char *s, const char *fmt, ...)
{
  va_list ap;
  int r;
  va_start (ap, fmt);
  r = vsscanf (s, fmt, ap);
  va_end (ap);
  return r;
}
