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

/*! @example map.c */

#ifndef MAP_H
#define MAP_H

#include "salad/types.h"
#include "salad/vector.h"

/*! A sld_map contains key/value pairs */
typedef struct sld_map
{
  /* No hashing occurs using two arrays. The key and value pairs are
     simply mapped to the same index in both arrays. Perhaps a table
     or map with hashing will be added later... */
  struct sld_vector *keys;   /*!< a sld_vector containing keys as strings */
  struct sld_vector *values; /*!< a sld_vector containing ambiguous objects */
} sld_map;

/*!
 * @brief Initializes a sld_map
 * @param map an uninitialized sld_map
 * @return Success or failure
 */
SLD_SSINT sld_map_init(struct sld_map *map);

/*!
 * @brief Returns the size of a sld_map
 * @param map an initialized sld_map
 * @return The size of the passed sld_map
 */
SLD_UINT sld_map_size(struct sld_map *map);

/*!
 * @brief Adds an object to a sld_map
 * @param map an initialized sld_map
 * @param key a key as a string
 * @param value an arbitrary object
 * @return Success or failure
 */
SLD_SSINT sld_map_add(struct sld_map *map, char *key, void *value);

/*!
 * @brief Removes an object from a sld_map with the specified key
 * @param map an initialized sld_map
 * @param key a key as a string
 * @return Success or failure
 */
SLD_BOOL sld_map_delete(struct sld_map *map, char *key);

/*!
 * @brief Checks whether or not a sld_map contains the specified key
 * @param map an initialized sld_map
 * @param key a key as a string
 * @return True or false
 */
SLD_BOOL sld_map_has_key(struct sld_map *map, char *key);

/*!
 * @brief Obtains the value from a sld_map using the specified key
 * @param map an initialized sld_map
 * @param key a key as a string
 * @return The object paired with the specified key
 */
void *sld_map_get_value(struct sld_map *map, char *key);

/*!
 * @brief Obtains the key from a sld_map at the specified index 
 * @param map an initialized sld_map
 * @param index an index where a key resides within the sld_map
 * @return The key residing at index
 */
void *sld_map_key_at(struct sld_map *map, SLD_UINT index);

/*!
 * @brief Obtains the value from a sld_map at the specified index
 * @param map an initialized sld_map
 * @param index an index where a value resides within the sld_map
 * @return The object residing at index
 */
void *sld_map_value_at(struct sld_map *map, SLD_UINT index);

/*!
 * @brief Frees any memory allocated for an initialized sld_map
 * @param map an initialized sld_map
 */
void sld_map_free(struct sld_map *map);

#endif /* MAP_H */
