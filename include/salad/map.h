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

#ifndef MAP_H
#define MAP_H

#include "salad/types.h"
#include "salad/vector.h"

typedef struct sld_map
{
  /* No hashing occurs using two arrays. The key and value pairs are
     simply mapped to the same index in both arrays. Perhaps a table
     or map with hashing will be added later... */
  struct sld_vector *keys;
  struct sld_vector *values;
} sld_map;

SLD_SSINT sld_map_init(struct sld_map *map);
SLD_UINT sld_map_size(struct sld_map *map);
SLD_SSINT sld_map_add(struct sld_map *map, char *key, void *value);
SLD_BOOL sld_map_delete(struct sld_map *map, char *key);
SLD_BOOL sld_map_has_key(struct sld_map *map, char *key);
void *sld_map_get_value(struct sld_map *map, char *key);
void *sld_map_key_at(struct sld_map *map, SLD_UINT index);
void *sld_map_value_at(struct sld_map *map, SLD_UINT index);
void sld_map_free(struct sld_map *map);

#endif /* MAP_H */
