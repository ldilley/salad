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

#ifndef QUEUE_H
#define QUEUE_H

/* Allows the user to define how queue data should reside in memory
   (contiguous or not.) This can also affect performance (resizing
   arrays can be expensive in the case of a vector for example.) */
typedef enum { sld_queue_list = 0, sld_queue_vector = 1 } sld_queue_type;

typedef struct sld_queue
{
  sld_queue_type queue_type; /* can exist in a resizeable array or a linked list */
  SLD_UINT size;
  struct sld_list *list;
  struct sld_vector *vector;
} sld_queue;

SLD_SSINT sld_queue_init(struct sld_queue *queue, sld_queue_type queue_type);
SLD_UINT sld_queue_size(struct sld_queue *queue);
SLD_SSINT sld_queue_add(struct sld_queue *queue, void *object);
void *sld_queue_remove(struct sld_queue *queue);
void *sld_queue_peek(struct sld_queue *queue);
void sld_queue_free(struct sld_queue *queue);

#endif /* QUEUE_H */
