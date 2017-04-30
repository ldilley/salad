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

/*! @example stack.c */

#ifndef STACK_H
#define STACK_H

#include "salad/list.h"
#include "salad/types.h"
#include "salad/vector.h"

/*!
 * @defgroup sld_stack
 * This module contains enums, functions, and structures related to sld_stack objects.
 * @{
 */

/*!
 * These constants allow the user to define how stack data should reside
 * in memory (contiguous or not.) This can also affect performance
 * (resizing arrays can be expensive in the case of a vector for example.)
 */
typedef enum { sld_stack_list = 0, sld_stack_vector = 1 } sld_stack_type;

/*! A sld_stack contains data in a LIFO (last in, first out) arrangement */
typedef struct sld_stack
{
  sld_stack_type stack_type; /*!< can exist in a resizeable array or a linked list */
  SLD_UINT size;             /*!< contains the size of the sld_stack */
  struct sld_list *list;     /*!< a sld_list containing non-contiguous data */
  struct sld_vector *vector; /*!< a sld_vector containing contiguous data */
} sld_stack;

/*!
 * @brief Initializes a sld_stack
 * @param stack an uninitialized sld_stack
 * @param stack_type can be either a sld_stack_list or sld_stack_vector
 * @return Success or failure
 * @relates sld_stack
 *
@code
sld_stack stack;
sld_stack_init(&stack, sld_stack_list);
@endcode
 */
SLD_SSINT sld_stack_init(struct sld_stack *stack, sld_stack_type stack_type);

/*!
 * @brief Returns the size of a sld_stack
 * @param stack an initialized sld_stack
 * @return The size of the passed sld_stack
 * @relates sld_stack
 *
@code
printf("There are %u items in the stack.\n", sld_stack_size(&stack));
@endcode
 */
SLD_UINT sld_stack_size(struct sld_stack *stack);

/*!
 * @brief Adds an object to the top of a sld_stack
 * @param stack an initialized sld_stack
 * @param object an arbitrary object
 * @return Success or failure
 * @relates sld_stack
 *
@code
sld_stack_push(&stack, "foo");
@endcode
 */
SLD_SSINT sld_stack_push(struct sld_stack *stack, void *object);

/*!
 * @brief Returns and removes the object at the top of a sld_stack
 * @param stack an initialized sld_stack
 * @return The object at the top of the passed sld_stack
 * @relates sld_stack
 *
@code
puts((char *)sld_stack_pop(&stack));
@endcode
 */
void *sld_stack_pop(struct sld_stack *stack);

/*!
 * @brief Returns the object at the top of a sld_stack
 * @param stack an initialized sld_stack
 * @return The object at the top of the passed sld_stack
 * @relates sld_stack
 *
@code
puts((char *)sld_stack_pop(&stack));
@endcode
 */
void *sld_stack_peek(struct sld_stack *stack);

/*!
 * @brief Frees any memory allocated for an initialized sld_stack
 * @param stack an initialized sld_stack
 * @relates sld_stack
 *
@code
sld_stack_free(&stack);
@endcode
 */
void sld_stack_free(struct sld_stack *stack);

/*! @} */

#endif /* STACK_H */
