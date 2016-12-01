/*
 * Salad - An assortment of useful C stuff
 * Copyright (C) 2016 Lloyd Dilley
 * http://www.dilley.me/
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

/* This is a test program that makes use of libsalad for demonstrational purposes. */

#include <stdio.h>  /* printf() */

/* Local includes */
#include "salad/memory.h"
#include "salad/vector.h"

int main()
{
  int i;
  sld_vector v;

  sld_vector_init(&v);
  sld_vector_add(&v, "Foo");
  sld_vector_add(&v, "Bar");

  for (i = 0; i < sld_vector_objects(&v); i++)
    printf("%s ", (char *)sld_vector_get(&v, i));
  printf("\n");

  sld_vector_delete(&v, 0);
  sld_vector_delete(&v, 1);

  sld_vector_set(&v, 0, "Hello");
  sld_vector_add(&v, "world!");
  sld_vector_add(&v, "Pop me!");

  printf("Popped: %s\n", (char *)sld_vector_pop(&v));

  for (i = 0; i < sld_vector_objects(&v); i++)
    printf("%s ", (char *)sld_vector_get(&v, i));
  printf("\n");

  sld_vector_free(&v);
  sld_memory_pool_nuke();

  return 0;
}
