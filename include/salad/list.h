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

#ifndef LIST_H
#define LIST_H

#include "salad/types.h"

typedef struct sld_node
{
  void *object;
  struct sld_node *next;
  struct sld_node *previous;
} sld_node;

typedef struct sld_list
{
  SLD_UINT size;
  struct sld_node *head;
} sld_list;

void sld_list_init(struct sld_list *list);
SLD_UINT sld_list_size(struct sld_list *list);
void sld_list_add(struct sld_list *list, void *object);
void sld_list_delete(struct sld_list *list, SLD_UINT index);
void *sld_list_get(struct sld_list *list, SLD_UINT index);
void *sld_list_pop(struct sld_list *list);
void sld_list_free(struct sld_list *list);

#endif /* LIST_H */
