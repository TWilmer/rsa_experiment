#include <tommath.h>
#include <assert.h>
#ifdef BN_MP_INIT_SIZE_C
/* LibTomMath, multiple-precision integer library -- Tom St Denis
 *
 * LibTomMath is a library that provides multiple-precision
 * integer arithmetic as well as number theoretic functionality.
 *
 * The library was designed directly after the MPI library by
 * Michael Fromberger but has been written from scratch with
 * additional optimizations in place.
 *
 * The library is free for all purposes without any express
 * guarantee it works.
 *
 * Tom St Denis, tomstdenis@gmail.com, http://libtom.org
 */

/* init an mp_init for a given size */
int mp_init_size (mp_int * a, int size)
{
  int x;


  /* pad size so there are always extra digits */
  size += (MP_PREC * 2) - (size % MP_PREC);
  static int max=0;
  if(max<size)
  	{
  		max=size;
  		printf("Max size %d\n", size);
  	}

  if(size>MP_BUFER)
  {
	  printf("Size needed %d\n", size);
  }
  assert(size<=MP_BUFER);
  /* set the members */
  a->used  = 0;
  a->alloc = MP_BUFER;
  a->sign  = MP_ZPOS;

  /* zero the digits */
  for (x = 0; x < size; x++) {
      a->digi[x] = 0;
  }

  return MP_OKAY;
}
#endif

/* $Source: /cvs/libtom/libtommath/bn_mp_init_size.c,v $ */
/* $Revision: 1.4 $ */
/* $Date: 2006/12/28 01:25:13 $ */
