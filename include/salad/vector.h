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

#ifndef VECTOR_H
#define VECTOR_H

#include "salad/types.h"

#define INITIAL_CAPACITY 16
#define RESIZE_FACTOR 2

typedef struct sld_vector
{
  void **objects;
  int capacity;
  int object_count;
} sld_vector;

SLD_SSINT sld_vector_init(sld_vector *vector);
SLD_SSINT sld_vector_init_size(sld_vector *vector, int size);
SLD_UINT sld_vector_objects(sld_vector *vector);
SLD_UINT sld_vector_size(sld_vector *vector);
SLD_SSINT sld_vector_resize(sld_vector *vector, int new_size);
SLD_SSINT sld_vector_add(sld_vector *vector, void *object);
void *sld_vector_get(sld_vector *vector, int index);
void sld_vector_set(sld_vector *vector, int index, void *object);
void *sld_vector_pop(sld_vector *vector);
void sld_vector_delete(sld_vector *vector, SLD_UINT index);
void sld_vector_free(sld_vector *vector);

#endif /* VECTOR_H */
