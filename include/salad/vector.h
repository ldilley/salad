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

void sld_vector_init(sld_vector *v);
void sld_vector_init_size(sld_vector *v, int size);
SLD_UINT sld_vector_objects(sld_vector *v);
SLD_UINT sld_vector_size(sld_vector *v);
void sld_vector_resize(sld_vector *v, int new_size);
void sld_vector_add(sld_vector *v, void *object);
void *sld_vector_get(sld_vector *v, int index);
void sld_vector_set(sld_vector *v, int index, void *object);
void *sld_vector_pop(sld_vector *v);
void sld_vector_push(sld_vector *v, void *object);
void sld_vector_delete(sld_vector *v, int index);
void sld_vector_clear(sld_vector *v);
void sld_vector_free(sld_vector *v);

#endif /* VECTOR_H */
