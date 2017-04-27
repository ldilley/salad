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

/*! @example vector.c */

#ifndef VECTOR_H
#define VECTOR_H

#include "salad/types.h"

/*! Default initial capacity for a sld_vector */
#define INITIAL_CAPACITY 16

/*! Double or halve a sld_vector during a resize operation */
#define RESIZE_FACTOR 2

/*! A sld_vector is a resizeable array */
typedef struct sld_vector
{
  void **objects;   /*!< contains the data housed in the sld_vector */
  int capacity;     /*!< contains the size of the sld_vector */
  int object_count; /*!< contains the number of objects in the sld_vector */
} sld_vector;

/*!
 * @brief Initializes a sld_vector
 * @param vector an uninitialized sld_vector
 * @return Success or failure
 */
SLD_SSINT sld_vector_init(sld_vector *vector);

/*!
 * @brief Initializes a sld_vector with the specified size
 * @param vector an uninitialized sld_vector
 * @param size an initial size
 * @return Success or failure
 */
SLD_SSINT sld_vector_init_size(sld_vector *vector, int size);

/*!
 * @brief Returns the number of objects contained within a sld_vector
 * @param vector an initialized sld_vector
 * @return The number of objects contained within the passed sld_vector
 */
SLD_UINT sld_vector_objects(sld_vector *vector);

/*!
 * @brief Returns the capacity of a sld_vector
 * @param vector an initialized sld_vector
 * @return The capacity of the passed sld_vector
 */
SLD_UINT sld_vector_size(sld_vector *vector);

/*!
 * @brief Resizes a sld_vector to the specified size
 * @param vector an initialized sld_vector
 * @param new_size the new size of the sld_vector
 * @return Success or failure
 */
SLD_SSINT sld_vector_resize(sld_vector *vector, int new_size);

/*!
 * @brief Adds an object to a sld_vector
 * @param vector an initialized sld_vector
 * @param object an arbitrary object
 * @return Success or failure 
 */
SLD_SSINT sld_vector_add(sld_vector *vector, void *object);

/*!
 * @brief Returns an object from an sld_vector at index
 * @param vector an initialized sld_vector
 * @param index an index where an object resides within the sld_vector
 * @return The object residing at the specified index
 */
void *sld_vector_get(sld_vector *vector, int index);

/*!
 * @brief Sets the data residing at the specified index in a sld_vector
 * @param vector an initialized sld_vector
 * @param index an index where an object may reside within the sld_vector
 * @param object an arbitrary object
 */
void sld_vector_set(sld_vector *vector, int index, void *object);

/*!
 * @brief Returns and removes the last object in a sld_vector
 * @param vector an initialized sld_vector
 * @return The last object in the passed sld_vector
 */
void *sld_vector_pop(sld_vector *vector);

/*!
 * @brief Removes an object from a sld_vector at the specified index
 * @param vector an initialized sld_vector
 * @param index an index where an object resides within the sld_vector
 */
void sld_vector_delete(sld_vector *vector, SLD_UINT index);

/*!
 * @brief Frees any memory allocated for an initialized sld_vector
 * @param vector an initialized sld_vector
 */
void sld_vector_free(sld_vector *vector);

#endif /* VECTOR_H */
