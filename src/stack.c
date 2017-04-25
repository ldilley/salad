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
#include "salad/stack.h"
#include "salad/types.h"
#include "salad/vector.h"

SLD_SSINT sld_stack_init(struct sld_stack *stack, sld_stack_type stack_type)
{
  SLD_SSINT return_value = RETURN_FAILURE;
  stack->size = 0;

  if(stack_type != sld_stack_list && stack_type != sld_stack_vector)
    return RETURN_FAILURE;

  if(stack_type == sld_stack_list)
  {
    stack->stack_type = sld_stack_list;

    stack->list = (struct sld_list *)malloc(sizeof(struct sld_list));
    if(stack->list == NULL)
    {
      printf("Unable to allocate memory for stack: %s\n", strerror(errno));
#ifdef EXIT_ON_FAILURE
      exit(EXIT_FAILURE);
#endif
      return RETURN_FAILURE;
    }

    return_value = sld_list_init(stack->list);
    stack->vector = NULL;
  }

  if(stack_type == sld_stack_vector)
  {
    stack->stack_type = sld_stack_vector;

    stack->vector = (struct sld_vector *)malloc(sizeof(struct sld_vector));
    if(stack->vector == NULL)
    {
      printf("Unable to allocate memory for stack: %s\n", strerror(errno));
#ifdef EXIT_ON_FAILURE
      exit(EXIT_FAILURE);
#endif
      return RETURN_FAILURE;
    }

    return_value = sld_vector_init(stack->vector);
    stack->list = NULL;
  }

  return return_value;
}

SLD_UINT sld_stack_size(struct sld_stack *stack)
{
  return stack->size;
}

SLD_SSINT sld_stack_push(struct sld_stack *stack, void *object)
{
  SLD_SSINT return_value = RETURN_FAILURE;

  if(stack->stack_type == sld_stack_list)
    return_value = sld_list_add(stack->list, object);

  if(stack->stack_type == sld_stack_vector)
    return_value = sld_vector_add(stack->vector, object);

  if(return_value == RETURN_SUCCESS)
    stack->size++;

  return return_value;
}

void *sld_stack_pop(struct sld_stack *stack)
{
  void *object = NULL;

  if(stack->stack_type == sld_stack_list)
    object = sld_list_pop(stack->list);

  if(stack->stack_type == sld_stack_vector)
    object = sld_vector_pop(stack->vector);

  if(object != NULL)
    stack->size--;

  return object;
}

void *sld_stack_peek(struct sld_stack *stack)
{
  void *object = NULL;

  if(stack->stack_type == sld_stack_list)
    object = sld_list_get(stack->list, sld_list_size(stack->list) - 1);

  if(stack->stack_type == sld_stack_vector)
    object = sld_vector_get(stack->vector, sld_vector_objects(stack->vector) - 1);

  return object;
}

void sld_stack_free(struct sld_stack *stack)
{
  if(stack->stack_type == sld_stack_list)
  {
    if(sld_stack_size(stack) != 0)
      sld_list_free(stack->list);
    free(stack->list);
  }

  if(stack->stack_type == sld_stack_vector)
  {
    if(sld_stack_size(stack) != 0)
      sld_vector_free(stack->vector);
    free(stack->vector);
  }

  return;
}
