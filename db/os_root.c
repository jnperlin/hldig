/*-
 * See the file LICENSE for redistribution information.
 *
 * Copyright (c) 1999
 *	Sleepycat Software.  All rights reserved.
 */

#include "db_config.h"

#ifndef lint
static const char sccsid[] = "@(#)os_root.c	11.2 (Sleepycat) 9/13/99";
#endif /* not lint */

#ifndef NO_SYSTEM_INCLUDES
#include <sys/types.h>

#ifndef _MSC_VER /* _WIN32 */
#include <unistd.h>
#endif
#endif

#include "db_int.h"

/*
 * CDB___os_isroot --
 *	Return if user has special permissions.
 *
 * PUBLIC: int CDB___os_isroot __P((void));
 */
int
CDB___os_isroot()
{
#ifdef HAVE_GETUID
	return (getuid() == 0);
#else
	return (0);
#endif
}
