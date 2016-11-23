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

/* Local includes */
#include "salad/memory.h"
#include "salad/types.h"

static SLD_BOOL sld_is_initialized = SLD_FALSE;
static SLD_ULINT sld_pool_capacity = 0;
static void **sld_object_pool = NULL;

void sld_init_pool(SLD_USINT initial_size)
{
  if(!sld_is_initialized)
  {
    sld_object_pool = calloc(initial_size, sizeof(void *));
    if(sld_object_pool != NULL)
    {
      sld_is_initialized = SLD_TRUE;
      sld_pool_capacity = initial_size;
    }
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
  return sld_pool_capacity;
}

SLD_SSINT sld_resize_pool(SLD_ULINT grow_amount)
{
  void **new_object_pool = NULL;
  SLD_SSINT ret_value = -1;
  int i;

  if(sld_pool_initialized())
  {
    new_object_pool = realloc(sld_object_pool, (sld_pool_capacity + grow_amount) * sizeof(void *));
    if(new_object_pool != NULL)
    {
      /* Don't use memset() since the initialized data may not be NULL. */
      /*memset(new_object_pool, 0, sizeof(void *) * grow_amount);*/
      for(i = sld_pool_capacity; i < sld_pool_capacity + grow_amount; i++)
        new_object_pool[i] = NULL;
      sld_pool_capacity += grow_amount;
      sld_object_pool = new_object_pool;
      ret_value = 0;
    }
  }
  return ret_value;
}

SLD_ULINT sld_pool_add(void *ptr)
{
  int i;

  if(!sld_pool_initialized())
    sld_init_pool(POOL_GROW_AMOUNT);

  if(sld_pool_initialized())
  {
    if(sld_objects_in_pool() == sld_pool_size())
      sld_resize_pool(POOL_GROW_AMOUNT);
    for(i = 0; i < sld_pool_size(); i++)
    {
      if(sld_object_pool[i] == NULL)
      {
        sld_object_pool[i] = ptr;
        break;
      }
    }
  }
  return sld_objects_in_pool();
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
    sld_pool_capacity = 0;
  }
  return;
}
