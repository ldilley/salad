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

#ifndef MEMORY_H
#define MEMORY_H

#include "salad/types.h"

/* Amount to grow object pool dynamically during add if no free slots remaining */
#define POOL_GROW_AMOUNT 16

void sld_memory_pool_init(SLD_USINT initial_size);
SLD_BOOL sld_memory_pool_initialized();
SLD_ULINT sld_memory_pool_size();
SLD_SSINT sld_memory_pool_resize(SLD_ULINT new_size);
SLD_ULINT sld_memory_pool_add(void *ptr);
SLD_ULINT sld_memory_pool_objects();
SLD_ULINT sld_memory_pool_free();
void sld_memory_pool_nuke();

#endif /* MEMORY_H */
