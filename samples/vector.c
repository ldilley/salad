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

#include <stdio.h>  /* printf(), puts() */

/* Local includes */
#include "salad/memory.h"
#include "salad/vector.h"

int main()
{
  sld_vector vector;
  int i;

  sld_vector_init(&vector);

  printf("Initial vector object count: %d\n", sld_vector_objects(&vector));

  sld_vector_add(&vector, "Hello");
  sld_vector_add(&vector, "world!");
  sld_vector_add(&vector, "Pop me!");

  printf("Vector object count after adding objects: %d\n", sld_vector_objects(&vector));  
  printf("Popped: %s\n", (char *)sld_vector_pop(&vector));
  printf("Vector object count after pop: %d\n", sld_vector_objects(&vector));

  puts("Printing vector contents...");
  for (i = 0; i < sld_vector_objects(&vector); i++)
    printf("%s ", (char *)sld_vector_get(&vector, i));
  puts("");

  sld_vector_free(&vector);
  sld_memory_pool_nuke();

  return 0;
}
