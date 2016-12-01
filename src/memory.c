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

#include <errno.h>  /* errno */
#include <stdio.h>  /* printf() */
#include <stdlib.h> /* EXIT_FAILURE, calloc(), exit(), realloc() */
#include <string.h> /* strerror() */

/* Local includes */
#include "salad/config.h"
#include "salad/memory.h"
#include "salad/types.h"

static SLD_BOOL sld_memory_pool_is_initialized = SLD_FALSE;
static SLD_ULINT sld_memory_pool_capacity = 0;
static void **sld_memory_pool = NULL;

void sld_memory_pool_init(SLD_USINT initial_size)
{
  if(!sld_memory_pool_is_initialized)
  {
    sld_memory_pool = calloc(initial_size, sizeof(void *));
    if(sld_memory_pool != NULL)
    {
      sld_memory_pool_is_initialized = SLD_TRUE;
      sld_memory_pool_capacity = initial_size;
    }
    else
    {
      printf("Unable to allocate memory: %s\n", strerror(errno));
#ifdef EXIT_ON_FAILURE
      exit(EXIT_FAILURE);
#endif
    }
  }
  return;
}

SLD_BOOL sld_memory_pool_initialized()
{
  SLD_BOOL ret_value = SLD_FALSE;

  if(sld_memory_pool_is_initialized && sld_memory_pool != NULL)
    ret_value = SLD_TRUE;
  return ret_value;
}

SLD_ULINT sld_memory_pool_size()
{
  return sld_memory_pool_capacity;
}

SLD_SSINT sld_memory_pool_resize(SLD_ULINT grow_amount)
{
  void **new_object_pool = NULL;
  SLD_SSINT ret_value = -1;
  int i;

  if(sld_memory_pool_initialized())
  {
    new_object_pool = realloc(sld_memory_pool, (sld_memory_pool_capacity + grow_amount) * sizeof(void *));
    if(new_object_pool != NULL)
    {
      /* Don't use memset() since the initialized data may not be NULL. */
      /*memset(new_object_pool, 0, sizeof(void *) * grow_amount);*/
      for(i = sld_memory_pool_capacity; i < sld_memory_pool_capacity + grow_amount; i++)
        new_object_pool[i] = NULL;
      sld_memory_pool_capacity += grow_amount;
      sld_memory_pool = new_object_pool;
      ret_value = 0;
    }
    else
    {
      printf("Unable to allocate memory: %s\n", strerror(errno));
#ifdef EXIT_ON_FAILURE
      exit(EXIT_FAILURE);
#endif
    }
  }
  return ret_value;
}

SLD_ULINT sld_memory_pool_add(void *ptr)
{
  int i;

  if(!sld_memory_pool_initialized())
    sld_memory_pool_init(POOL_GROW_AMOUNT);

  if(sld_memory_pool_initialized())
  {
    if(sld_memory_pool_objects() == sld_memory_pool_size())
      sld_memory_pool_resize(POOL_GROW_AMOUNT);
    for(i = 0; i < sld_memory_pool_size(); i++)
    {
      if(sld_memory_pool[i] == NULL)
      {
        sld_memory_pool[i] = ptr;
        break;
      }
    }
  }
  return sld_memory_pool_objects();
}

SLD_ULINT sld_memory_pool_objects()
{
  SLD_ULINT object_count = 0;
  int i;

  if(sld_memory_pool_initialized())
  {
    for(i = 0; i < sld_memory_pool_size(); i++)
    {
      if(sld_memory_pool[i] != NULL)
        object_count++;
    }
  }
  return object_count;
}

/* Returns objects freed */
SLD_ULINT sld_memory_pool_free()
{
  SLD_ULINT object_count = 0;

  if(sld_memory_pool_initialized() && sld_memory_pool_objects() > 0)
  {
    int i;
    for(i = 0; i < sld_memory_pool_size(); i++)
    {
      if(sld_memory_pool[i] != NULL)
      {
        object_count++;
        free(sld_memory_pool[i]);
        sld_memory_pool[i] = NULL;
      }
    }
  }
  return object_count;
}

void sld_memory_pool_nuke()
{
  if(sld_memory_pool_initialized())
  {
    sld_memory_pool_free();
    free(sld_memory_pool);
    sld_memory_pool = NULL;
    sld_memory_pool_is_initialized = SLD_FALSE;
    sld_memory_pool_capacity = 0;
  }
  return;
}
