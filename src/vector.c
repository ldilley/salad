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

#include <errno.h>  /* errno */
#include <stdio.h>  /* printf() */
#include <stdlib.h> /* EXIT_FAILURE, exit(), malloc() */
#include <string.h> /* strerror() */

/* Local includes */
#include "salad/config.h"
#include "salad/memory.h"
#include "salad/types.h"
#include "salad/vector.h"

void sld_vector_init(sld_vector *v)
{
  v->capacity = INITIAL_CAPACITY;
  v->object_count = 0;
  v->objects = malloc(sizeof(void *) * v->capacity);

  if(v->objects == NULL)
  {
    printf("Unable to allocate memory for vector: %s\n", strerror(errno));
#ifdef EXIT_ON_FAILURE
    exit(EXIT_FAILURE);
#endif
  }

  return;
}

void sld_vector_init_size(sld_vector *v, int size)
{
  v->capacity = size;
  v->object_count = 0;
  v->objects = malloc(sizeof(void *) * v->capacity);

  if(v->objects == NULL)
  {
    printf("Unable to allocate memory for vector: %s\n", strerror(errno));
#ifdef EXIT_ON_FAILURE
    exit(EXIT_FAILURE);
#endif
  }

  return;
}

SLD_UINT sld_vector_objects(sld_vector *v)
{
  return v->object_count;
}

SLD_UINT sld_vector_size(sld_vector *v)
{
  return v->capacity;
}

void sld_vector_resize(sld_vector *v, int new_size)
{
  void **objects = realloc(v->objects, sizeof(void *) * new_size);
  if(objects)
  {
    v->objects = objects;
    v->capacity = new_size;
  }
  else
  {
    printf("Unable to allocate memory for vector: %s\n", strerror(errno));
#ifdef EXIT_ON_FAILURE
    exit(EXIT_FAILURE);
#endif
  }

  return;
}

void sld_vector_add(sld_vector *v, void *object)
{
  if(v->object_count == v->capacity)
    sld_vector_resize(v, v->capacity * RESIZE_FACTOR);
  v->objects[v->object_count++] = object;
  return;
}

void *sld_vector_get(sld_vector *v, int index)
{
  if(index >= 0 && index < v->object_count)
    return v->objects[index];
  return NULL;
}

void sld_vector_set(sld_vector *v, int index, void *object)
{
  if(index >= 0 && index < v->object_count)
    v->objects[index] = object;
  return;
}

void *sld_vector_pop(sld_vector *v)
{
  void *object = NULL;

  object = sld_vector_get(v, v->object_count - 1);
  sld_vector_delete(v, v->object_count - 1);

  return object;
}

void sld_vector_delete(sld_vector *v, int index)
{
  int i;

  if(index < 0 || index >= v->object_count)
    return;

  v->objects[index] = NULL;

  for(i = index; i < v->object_count - 1; i++)
  {
    v->objects[i] = v->objects[i + 1];
    v->objects[i + 1] = NULL;
  }

  v->object_count--;

  if(v->object_count > 0 && v->object_count == v->capacity / (RESIZE_FACTOR * 2))
    sld_vector_resize(v, v->capacity / RESIZE_FACTOR);

  return;
}

void sld_vector_free(sld_vector *v)
{
  free(v->objects);
  return;
}
