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

#include <errno.h>  /* errno */
#include <stdio.h>  /* printf() */
#include <stdlib.h> /* EXIT_FAILURE, exit(), free(), malloc() */
#include <string.h> /* strerror() */

/* Local includes */
#include "salad/list.h"
#include "salad/queue.h"
#include "salad/types.h"
#include "salad/vector.h"

SLD_SSINT sld_queue_init(struct sld_queue *queue, sld_queue_type queue_type)
{
  SLD_SSINT return_value = RETURN_FAILURE;
  queue->size = 0;

  if(queue_type != sld_queue_list && queue_type != sld_queue_vector)
    return RETURN_FAILURE;

  if(queue_type == sld_queue_list)
  {
    queue->queue_type = sld_queue_list;

    queue->list = (struct sld_list *)malloc(sizeof(struct sld_list));
    if(queue->list == NULL)
    {
      printf("Unable to allocate memory for queue: %s\n", strerror(errno));
#ifdef EXIT_ON_FAILURE
      exit(EXIT_FAILURE);
#endif
      return RETURN_FAILURE;
    }

    return_value = sld_list_init(queue->list);
    queue->vector = NULL;
  }

  if(queue_type == sld_queue_vector)
  {
    queue->queue_type = sld_queue_vector;

    queue->vector = (struct sld_vector *)malloc(sizeof(struct sld_vector));
    if(queue->vector == NULL)
    {
      printf("Unable to allocate memory for queue: %s\n", strerror(errno));
#ifdef EXIT_ON_FAILURE
      exit(EXIT_FAILURE);
#endif
      return RETURN_FAILURE;
    }

    return_value = sld_vector_init(queue->vector);
    queue->list = NULL;
  }

  return return_value;
}

SLD_UINT sld_queue_size(struct sld_queue *queue)
{
  return queue->size;
}

SLD_SSINT sld_queue_add(struct sld_queue *queue, void *object)
{
  SLD_SSINT return_value = RETURN_FAILURE;

  if(queue->queue_type == sld_queue_list)
    return_value = sld_list_add(queue->list, object);

  if(queue->queue_type == sld_queue_vector)
    return_value = sld_vector_add(queue->vector, object);

  if(return_value == RETURN_SUCCESS)
    queue->size++;

  return return_value;
}

void *sld_queue_remove(struct sld_queue *queue)
{
  void *object = NULL;

  if(queue->queue_type == sld_queue_list)
  {
    object = sld_list_get(queue->list, 0);
    sld_list_delete(queue->list, 0);
  }

  if(queue->queue_type == sld_queue_vector)
  {
    object = sld_vector_get(queue->vector, 0);
    sld_vector_delete(queue->vector, 0);
  }

  if(object != NULL)
    queue->size--;

  return object;
}

void *sld_queue_peek(struct sld_queue *queue)
{
  void *object = NULL;

  if(queue->queue_type == sld_queue_list)
    object = sld_list_get(queue->list, 0);

  if(queue->queue_type == sld_queue_vector)
    object = sld_vector_get(queue->vector, 0);

  return object;
}

void sld_queue_free(struct sld_queue *queue)
{
  if(queue->queue_type == sld_queue_list)
  {
    if(sld_queue_size(queue) != 0)
      sld_list_free(queue->list);
    free(queue->list);
  }

  if(queue->queue_type == sld_queue_vector)
  {
    if(sld_queue_size(queue) != 0)
      sld_vector_free(queue->vector);
    free(queue->vector);
  }

  return;
}
