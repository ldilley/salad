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

#include <stdio.h>  /* printf() */

/* Local includes */
#include "salad/map.h"
#include "salad/memory.h"

int main()
{
  sld_map map;

  sld_map_init(&map);

  printf("Initial map size: %u\n", sld_map_size(&map));

  sld_map_add(&map, "foo", "bar");

  printf("Map size after adding a single key/value pair: %d\n", sld_map_size(&map));

  printf("Value for key \"foo\": %s\n", (char *)sld_map_get_value(&map, "foo"));

  sld_map_add(&map, "foo", "baz");
  sld_map_add(&map, "hello", "world");

  printf("Map size after replacing value for key \"foo\" and adding another key/value pair: %d\n", sld_map_size(&map));

  printf("New value for key \"foo\": %s\n", (char *)sld_map_get_value(&map, "foo"));

  sld_map_free(&map);
  sld_memory_pool_nuke();  

  return 0;
}
