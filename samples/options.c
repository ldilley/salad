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

#include <stdio.h> /* printf() */

/* Local includes */
#include "salad/map.h"
#include "salad/memory.h"
#include "salad/options.h"

int main()
{
  int i;
  /* A struct would've been nice, but we use a map here since C has no reflection. */
  sld_map map;
  sld_map_init(&map);

  sld_options_read("sample.cfg", &map);

  for(i = 0; i < sld_map_size(&map); i++)
  {
    printf("%s: %s\n", (char *)sld_map_key_at(&map, i), (char *)sld_map_value_at(&map, i));
  }

  sld_map_free(&map);
  sld_memory_pool_nuke();

  return 0;
}
