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

#include <errno.h>  /* errno */
#include <stdio.h>  /* printf(), puts() */
#include <stdlib.h> /* EXIT_FAILURE, exit(), free(), malloc() */
#include <string.h> /* strcmp(), strerror() */

/* Local includes */
#include "salad/config.h"
#include "salad/map.h"
#include "salad/types.h"
#include "salad/vector.h"

SLD_SSINT sld_map_init(struct sld_map *map)
{
  SLD_SSINT return_value = RETURN_FAILURE;

  map->keys = (struct sld_vector *)malloc(sizeof(struct sld_vector));
  if(map->keys == NULL)
  {
    printf("Unable to allocate memory for map: %s\n", strerror(errno));
#ifdef EXIT_ON_FAILURE
    exit(EXIT_FAILURE);
#endif
    return RETURN_FAILURE;
  }

  return_value = sld_vector_init(map->keys);
  if(return_value == RETURN_FAILURE)
  {
    puts("Unable to initialize map.");
#ifdef EXIT_ON_FAILURE
    exit(EXIT_FAILURE);
#endif
    return RETURN_FAILURE;
  }

  map->values = (struct sld_vector *)malloc(sizeof(struct sld_vector));
  if(map->values == NULL)
  {
    printf("Unable to allocate memory for map: %s\n", strerror(errno));
#ifdef EXIT_ON_FAILURE
    exit(EXIT_FAILURE);
#endif
    return RETURN_FAILURE;
  }

  return_value = sld_vector_init(map->values);
  if(return_value == RETURN_FAILURE)
  {
    puts("Unable to allocate memory for map.");
#ifdef EXIT_ON_FAILURE
    exit(EXIT_FAILURE);
#endif
    return RETURN_FAILURE;
  }

  return return_value;
}

SLD_UINT sld_map_size(struct sld_map *map)
{
   return sld_vector_objects(map->keys);
}

SLD_SSINT sld_map_add(struct sld_map *map, char *key, void *value)
{
  SLD_SSINT return_value = RETURN_FAILURE;

  /* Replace pair if it exists */
  if(sld_map_has_key(map, key))
    sld_map_delete(map, key);

  return_value = sld_vector_add(map->keys, key);
  if(return_value == RETURN_FAILURE)
    return RETURN_FAILURE;

  return_value = sld_vector_add(map->values, value);
  /* If previous key operation succeeded, but the value add failed,
     undo the key add to maintain integrity. */
  if(return_value == RETURN_FAILURE)
    sld_vector_pop(map->keys);

  return return_value;
}

SLD_BOOL sld_map_delete(struct sld_map *map, char *key)
{
  int i;

  for(i = 0; i < sld_vector_objects(map->keys); i++)
  {
    if(strcmp(key, (char *)sld_vector_get(map->keys, i)) == 0)
    {
      sld_vector_delete(map->keys, i);
      sld_vector_delete(map->values, i);
      return SLD_TRUE;
    }
  }

  return SLD_FALSE;
}

SLD_BOOL sld_map_has_key(struct sld_map *map, char *key)
{
  int i;

  for(i = 0; i < sld_map_size(map); i++)
  {
    if(strcmp(key, (char *)sld_vector_get(map->keys, i)) == 0)
      return SLD_TRUE;
  }

  return SLD_FALSE;
}

void *sld_map_get_value(struct sld_map *map, char *key)
{
  int i;

  for(i = 0; i < sld_map_size(map); i++)
  {
    if(strcmp(key, (char *)sld_vector_get(map->keys, i)) == 0)
      return sld_vector_get(map->values, i);
  }

  return "";
}

void *sld_map_key_at(struct sld_map *map, SLD_UINT index)
{
  if(index > sld_vector_objects(map->keys))
    return "";

  return sld_vector_get(map->keys, index);
}

void *sld_map_value_at(struct sld_map *map, SLD_UINT index)
{
  if(index > sld_vector_objects(map->values))
    return "";

  return sld_vector_get(map->values, index);
}

void sld_map_free(struct sld_map *map)
{
  if(sld_map_size(map) != 0)
  {
    sld_vector_free(map->keys);
    sld_vector_free(map->values);
    free(map->keys);
    free(map->values);
  }

  return;
}
