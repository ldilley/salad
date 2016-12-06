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

#ifndef STACK_H
#define STACK_H

#include "salad/list.h"
#include "salad/types.h"
#include "salad/vector.h"

/* Allows the user to define how stack data should reside in memory
   (contiguous or not.) This can also affect performance (resizing
   arrays can be expensive in the case of a vector for example.) */
typedef enum { sld_stack_list = 0, sld_stack_vector = 1 } sld_stack_type;

typedef struct sld_stack
{
  sld_stack_type stack_type; /* can exist in a resizeable array or a linked list */
  SLD_UINT size;
  struct sld_list *list;
  struct sld_vector *vector;
} sld_stack;

SLD_SSINT sld_stack_init(struct sld_stack *stack, sld_stack_type stack_type);
SLD_UINT sld_stack_size(struct sld_stack *stack);
SLD_SSINT sld_stack_push(struct sld_stack *stack, void *object);
void *sld_stack_pop(struct sld_stack *stack);
void *sld_stack_peek(struct sld_stack *stack);
void sld_stack_free(struct sld_stack *stack);

#endif /* STACK_H */
