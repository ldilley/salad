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

#include <stdio.h> /* printf() */

/* Local includes */
#include "salad/list.h"
#include "salad/search.h"

int main()
{
  sld_list list;
  sld_list_init(&list);

  sld_list_add(&list, (void *)1);
  sld_list_add(&list, (void *)3);
  sld_list_add(&list, (void *)7);

  /* A non-zero return type means the criterion was not found in the data structure. */
  printf("Index for value '5' in the list: %i\n", sld_search_linear(&list, (void *)5, sld_data_structure_list, sld_data_type_int));
  printf("Index for value '7' in the list: %i\n", sld_search_linear(&list, (void *)7, sld_data_structure_list, sld_data_type_int));

  sld_list_free(&list);
  sld_memory_pool_nuke();

  return 0;
}
