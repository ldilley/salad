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

#ifndef MEMORY_H
#define MEMORY_H

#include "salad/types.h"

/*! Amount to grow object pool dynamically during add if no free slots remain */
#define POOL_GROW_AMOUNT 16

/*!
 * @brief Initialize a memory pool with the specified size
 * @param initial_size initial size of the memory pool
 * @return Success or failure
 */
SLD_SSINT sld_memory_pool_init(SLD_USINT initial_size);

/*!
 * @brief Checks whether or not the memory pool is initialized
 * @return True or false
 */
SLD_BOOL sld_memory_pool_initialized();

/*!
 * @brief Returns the size of the memory pool
 * @return The size of the memory pool
 */
SLD_ULINT sld_memory_pool_size();

/*!
 * @brief Resizes the memory pool to the specified size
 * @param new_size the new size of the memory pool
 * @return Success or failure
 */
SLD_SSINT sld_memory_pool_resize(SLD_ULINT new_size);

/*!
 * @brief Adds an object to the memory pool
 * @param ptr a pointer to the object to be added
 * @return The new total number of objects in the memory pool
 */
SLD_ULINT sld_memory_pool_add(void *ptr);

/*!
 * @brief Returns the total number of objects in the memory pool
 * @return The total number of objects in the memory pool
 */
SLD_ULINT sld_memory_pool_objects();

/*!
 * @brief Frees any memory allocated for objects stored in the memory pool
 * @return The number of freed objects
 */
SLD_ULINT sld_memory_pool_free();

/*!
 * @brief Frees any memory allocated for the initialized memory pool
 */
void sld_memory_pool_nuke();

#endif /* MEMORY_H */
