/*
 * Salad - An assortment of useful C stuff
 * Copyright (C) 2016 Lloyd Dilley
 * http://www.dilley.me/
 *
 * This file is part of Salad.
 *
 * Salad is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version
 * 3 of the License, or (at your option) any later version.
 *
 * Salad is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with Salad. If not, see <http://www.gnu.org/licenses/>.
 */

/* This is a test program that makes use of libsalad for demonstrational purposes. */

#include <stdio.h>  /* printf(), puts() */

/* Local includes */
#include "salad/list.h"
#include "salad/memory.h"

int main()
{
  sld_list list;
  int i;

  sld_list_init(&list);

  printf("Initial list size: %u\n", sld_list_size(&list));

  sld_list_add(&list, "Hello");
  sld_list_add(&list, "world!");
  sld_list_add(&list, "Pop me!");

  printf("List size after adding objects: %d\n", sld_list_size(&list));
  printf("Popped: %s\n", (char *)sld_list_pop(&list));
  printf("List size after pop: %d\n", sld_list_size(&list));

  puts("Printing list contents...");
  for(i = 0; i < sld_list_size(&list); i++)
    printf("%s ", (char *)sld_list_get(&list, i));
  puts("");

  sld_list_free(&list);
  sld_memory_pool_nuke();

  return 0;
}
