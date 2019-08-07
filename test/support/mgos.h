#ifndef _MGOS_H
#define _MGOS_H

#include "mbuf.h"
#include "str_util.h"
#include "mg_str.h"
#include "cs_dbg.h"

/* Macros for min/max. */
#ifndef MIN
#define	MIN(a,b) (((a)<(b))?(a):(b))
#endif /* MIN */
#ifndef MAX
#define	MAX(a,b) (((a)>(b))?(a):(b))
#endif	/* MAX */

#endif // _MGOS_H