/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0.  If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * Copyright 1997 - July 2008 CWI, August 2008 - 2016 MonetDB B.V.
 */

/*
 * @* Implementation Code
 */
#ifndef __BLOB_H__
#define __BLOB_H__
#include "mal.h"
#include "mal_exception.h"

typedef struct blob {
	size_t nitems;
	/*unsigned */ char data[FLEXIBLE_ARRAY_MEMBER];
} blob;

#define sqlblob blob

#ifdef WIN32
#if !defined(LIBMAL) && !defined(LIBATOMS) && !defined(LIBKERNEL) && !defined(LIBMAL) && !defined(LIBOPTIMIZER) && !defined(LIBSCHEDULER) && !defined(LIBMONETDB5)
#define blob_export extern __declspec(dllimport)
#else
#define blob_export extern __declspec(dllexport)
#endif
#else
#define blob_export extern
#endif

blob_export int TYPE_blob;
blob_export int TYPE_sqlblob;

blob_export var_t blobsize(size_t nitems);
blob_export int sqlblob_tostr(str *tostr, int *l, const blob *p);
blob_export int sqlblob_fromstr(char *instr, int *l, blob **val);

#endif /* __BLOB_H__ */
