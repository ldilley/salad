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

void sld_init_pool(SLD_USINT object_slots);
SLD_BOOL sld_pool_initialized();
SLD_USINT sld_pool_add(void *ptr);
SLD_USINT sld_free_pool();

#endif /* MEMORY_H */
