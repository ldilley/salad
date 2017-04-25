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
#include <stdio.h>  /* printf() */
#include <stdlib.h> /* EXIT_FAILURE, exit(), malloc() */
#include <string.h> /* strerror() */

/* Local includes */
#include "salad/config.h"
#include "salad/memory.h"
#include "salad/types.h"
#include "salad/vector.h"

SLD_SSINT sld_vector_init(sld_vector *vector)
{
  vector->capacity = INITIAL_CAPACITY;
  vector->object_count = 0;
  vector->objects = malloc(sizeof(void *) * vector->capacity);

  if(vector->objects == NULL)
  {
    printf("Unable to allocate memory for vector: %s\n", strerror(errno));
#ifdef EXIT_ON_FAILURE
    exit(EXIT_FAILURE);
#endif
    return RETURN_FAILURE;
  }

  return RETURN_SUCCESS;
}

SLD_SSINT sld_vector_init_size(sld_vector *vector, int size)
{
  vector->capacity = size;
  vector->object_count = 0;
  vector->objects = malloc(sizeof(void *) * vector->capacity);

  if(vector->objects == NULL)
  {
    printf("Unable to allocate memory for vector: %s\n", strerror(errno));
#ifdef EXIT_ON_FAILURE
    exit(EXIT_FAILURE);
#endif
    return RETURN_FAILURE;
  }

  return RETURN_SUCCESS;
}

SLD_UINT sld_vector_objects(sld_vector *vector)
{
  return vector->object_count;
}

SLD_UINT sld_vector_size(sld_vector *vector)
{
  return vector->capacity;
}

SLD_SSINT sld_vector_resize(sld_vector *vector, int new_size)
{
  void **objects = realloc(vector->objects, sizeof(void *) * new_size);
  if(objects)
  {
    vector->objects = objects;
    vector->capacity = new_size;
  }
  else
  {
    printf("Unable to allocate memory for vector: %s\n", strerror(errno));
#ifdef EXIT_ON_FAILURE
    exit(EXIT_FAILURE);
#endif
    return RETURN_FAILURE;
  }

  return RETURN_SUCCESS;
}

SLD_SSINT sld_vector_add(sld_vector *vector, void *object)
{
  SLD_SSINT return_value = RETURN_SUCCESS;
  SLD_UINT old_object_count = 0;

  if(vector->object_count == vector->capacity)
    return_value = sld_vector_resize(vector, vector->capacity * RESIZE_FACTOR);

  old_object_count = sld_vector_objects(vector);
  if(return_value == RETURN_SUCCESS)
    vector->objects[vector->object_count++] = object;

  /* Object was not successfully added */
  if(sld_vector_objects(vector) == old_object_count)
    return_value = RETURN_FAILURE;

  return return_value;
}

void *sld_vector_get(sld_vector *vector, int index)
{
  if(index >= 0 && index < vector->object_count)
    return vector->objects[index];
  return NULL;
}

void sld_vector_set(sld_vector *vector, int index, void *object)
{
  if(index >= 0 && index < vector->object_count)
    vector->objects[index] = object;
  return;
}

void *sld_vector_pop(sld_vector *vector)
{
  void *object = NULL;

  object = sld_vector_get(vector, vector->object_count - 1);
  sld_vector_delete(vector, vector->object_count - 1);

  return object;
}

void sld_vector_delete(sld_vector *vector, SLD_UINT index)
{
  int i;

  if(index < 0 || index >= vector->object_count)
    return;

  vector->objects[index] = NULL;

  for(i = index; i < vector->object_count - 1; i++)
  {
    vector->objects[i] = vector->objects[i + 1];
    vector->objects[i + 1] = NULL;
  }

  vector->object_count--;

  if(vector->object_count > 0 && vector->object_count == vector->capacity / (RESIZE_FACTOR * 2))
    sld_vector_resize(vector, vector->capacity / RESIZE_FACTOR);

  return;
}

void sld_vector_free(sld_vector *vector)
{
  free(vector->objects);
  return;
}
