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

#include <stdlib.h> /* calloc(), realloc() */
#include <string.h> /* memset() */

/* Local includes */
/*#include "salad/memory.h"*/
#include "salad/types.h"

static SLD_BOOL sld_is_initialized = SLD_FALSE;
static void **sld_object_pool = NULL;

void sld_init_pool(SLD_USINT initial_size)
{
  if(!sld_is_initialized)
  {
    sld_is_initialized = SLD_TRUE;
    sld_object_pool = calloc(initial_size, sizeof(void *));
  }

  return;
}

SLD_BOOL sld_pool_initialized()
{
  SLD_BOOL ret_value = SLD_FALSE;

  if(sld_is_initialized && sld_object_pool != NULL)
    ret_value = SLD_TRUE;

  return ret_value;
}

SLD_ULINT sld_pool_size()
{
  SLD_ULINT size = 0;

  if(sld_pool_initialized())
    size = sizeof(sld_object_pool) * sizeof(void *);

  return size;
}

SLD_SSINT sld_resize_pool(SLD_ULINT new_size)
{
  void **new_object_pool = NULL;
  SLD_SSINT ret_value = -1;

  if(sld_pool_initialized() && sld_pool_size() < new_size)
  {
    new_object_pool = realloc(sld_object_pool, new_size * sizeof(void *));
    if(new_object_pool != NULL)
    {
      memset(new_object_pool, 0, sizeof(void *) * new_size);
      sld_object_pool = new_object_pool;
      ret_value = 0;
    }
  }

  return ret_value;
}

SLD_ULINT sld_pool_add(void *ptr)
{
  SLD_ULINT object_counter = 0;

  if(sld_pool_initialized())
  {
    /* Insert object into pool if there is a free slot detected, else resize it by POOL_GROW_AMOUNT */
  }

  return object_counter;
}

SLD_ULINT sld_objects_in_pool()
{
  SLD_ULINT object_count = 0;
  int i;

  if(sld_pool_initialized())
  {
    for(i = 0; i < sld_pool_size(); i++)
    {
      if(sld_object_pool[i] != NULL)
        object_count++;
    }
  }

  return object_count;
}

/* Returns objects freed */
SLD_ULINT sld_free_pool()
{
  SLD_ULINT object_count = 0;

  if(sld_pool_initialized() && sld_objects_in_pool() > 0)
  {
    int i;
    for(i = 0; i < sld_pool_size(); i++)
    {
      if(sld_object_pool[i] != NULL)
      {
        object_count++;
        free(sld_object_pool[i]);
        sld_object_pool[i] = NULL;
      }
    }
  }

  return object_count;
}

void sld_nuke_pool()
{
  if(sld_pool_initialized())
  {
    sld_free_pool();
    free(sld_object_pool);
    sld_object_pool = NULL;
    sld_is_initialized = SLD_FALSE;
  }

  return;
}
