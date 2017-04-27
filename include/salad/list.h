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

/*! @example list.c */

#ifndef LIST_H
#define LIST_H

#include "salad/types.h"

/*! A sld_node contained within a list */
typedef struct sld_node
{
  void *object;              /*!< ambiguous object contained within the node */
  struct sld_node *next;     /*!< pointer to next node in memory */
  struct sld_node *previous; /*!< pointer to previous node in memory */
} sld_node;

/*! A sld_list contains sld_node structures */
typedef struct sld_list
{
  SLD_UINT size;         /*!< contains the size of the sld_list */
  struct sld_node *head; /*!< the starting sld_node of the sld_list */
} sld_list;

/*!
 * @brief Initializes a sld_list
 * @param list an uninitialized sld_list
 * @return Success or failure
 */
SLD_SSINT sld_list_init(struct sld_list *list);

/*!
 * @brief Returns the size of a sld_list
 * @param list an initialized sld_list
 * @return The size of the passed sld_list
 */
SLD_UINT sld_list_size(struct sld_list *list);

/*!
 * @brief Adds an object to a sld_list
 * @param list an initialized sld_list
 * @param object an arbitrary object
 * @return Success or failure 
 */
SLD_SSINT sld_list_add(struct sld_list *list, void *object);

/*!
 * @brief Removes an object from a sld_list at the specified index
 * @param list an initialized sld_list
 * @param index an index where an object resides within the sld_list
 */
void sld_list_delete(struct sld_list *list, SLD_UINT index);

/*!
 * @brief Returns an object from an sld_list at index
 * @param list an initialized sld_list
 * @param index an index where an object resides within the sld_list
 * @return The object residing at the specified index
 */
void *sld_list_get(struct sld_list *list, SLD_UINT index);

/*!
 * @brief Returns and removes the last object in a sld_list 
 * @param list an initialized sld_list
 * @return The last object in the passed sld_list
 */
void *sld_list_pop(struct sld_list *list);

/*!
 * @brief Frees any memory allocated for an initialized sld_list
 * @param list an initialized sld_list
 */
void sld_list_free(struct sld_list *list);

#endif /* LIST_H */
