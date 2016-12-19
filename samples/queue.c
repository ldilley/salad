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

/* This is a test program that makes use of libsalad for demonstrational purposes. */

#include <stdio.h>  /* printf(), puts() */

/* Local includes */
#include "salad/list.h"
#include "salad/memory.h"
#include "salad/queue.h"
#include "salad/vector.h"

int main()
{
  sld_queue queue1;
  sld_queue queue2;
  int i;

  sld_queue_init(&queue1, sld_queue_list);
  sld_queue_init(&queue2, sld_queue_vector);

  printf("Initial queue (list backend) size: %d\n", sld_queue_size(&queue1));
  printf("Initial queue (vector backend) size: %d\n", sld_queue_size(&queue2));

  sld_queue_add(&queue1, "Added first and out first!");
  sld_queue_add(&queue1, "Hello");
  sld_queue_add(&queue1, "world!");

  sld_queue_add(&queue2, "Added first and out first!");
  sld_queue_add(&queue2, "Foo");
  sld_queue_add(&queue2, "Bar");

  printf("Queue (list backend) size after adding objects: %d\n", sld_queue_size(&queue1));
  printf("Queue (vector backend) size after adding objects: %d\n", sld_queue_size(&queue2));

  printf("Removed from queue (list backend): %s\n", (char *)sld_queue_remove(&queue1));
  printf("queue (list backend) size after remove: %d\n", sld_queue_size(&queue1));
  printf("Removed from queue (vector backend): %s\n", (char *)sld_queue_remove(&queue2));
  printf("queue (vector backend) size after remove: %d\n", sld_queue_size(&queue2));
  printf("Peeking at contents of queue (list backend) end: %s\n", (char *)sld_queue_peek(&queue1));

  puts("Removing remaining contents of queue (list backend)...");
  for(i = 0; i <= sld_queue_size(&queue1); i++)
    printf("%s ", (char *)sld_queue_remove(&queue1));
  puts("");

  puts("Removing remaining contents of queue (vector backend)...");
  for(i = 0; i <= sld_queue_size(&queue2); i++)
    printf("%s ", (char *)sld_queue_remove(&queue2));
  puts("");

  sld_queue_free(&queue1);
  sld_queue_free(&queue2);
  sld_memory_pool_nuke();

  return 0;
}
