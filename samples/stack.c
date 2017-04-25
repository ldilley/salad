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

/* This is a test program that makes use of libsalad for demonstrational purposes. */

#include <stdio.h>  /* printf(), puts() */

/* Local includes */
#include "salad/list.h"
#include "salad/memory.h"
#include "salad/stack.h"
#include "salad/vector.h"

int main()
{
  sld_stack stack1;
  sld_stack stack2;
  int i;

  sld_stack_init(&stack1, sld_stack_list);
  sld_stack_init(&stack2, sld_stack_vector);

  printf("Initial stack (list backend) size: %d\n", sld_stack_size(&stack1));
  printf("Initial stack (vector backend) size: %d\n", sld_stack_size(&stack2));

  sld_stack_push(&stack1, "world!");
  sld_stack_push(&stack1, "Hello");
  sld_stack_push(&stack1, "Pop me!");

  sld_stack_push(&stack2, "Bar");
  sld_stack_push(&stack2, "Foo");
  sld_stack_push(&stack2, "Pop me again!");

  printf("Stack (list backend) size after pushing objects: %d\n", sld_stack_size(&stack1));
  printf("Stack (vector backend) size after pushing objects: %d\n", sld_stack_size(&stack2));

  printf("Popped from stack (list backend): %s\n", (char *)sld_stack_pop(&stack1));
  printf("Stack (list backend) size after pop: %d\n", sld_stack_size(&stack1));
  printf("Popped from stack (vector backend): %s\n", (char *)sld_stack_pop(&stack2));
  printf("Stack (vector backend) size after pop: %d\n", sld_stack_size(&stack2));
  printf("Peeking at contents of stack (list backend) top: %s\n", (char *)sld_stack_peek(&stack1));

  puts("Popping remaining contents of stack (list backend)...");
  for(i = 0; i <= sld_stack_size(&stack1); i++)
    printf("%s ", (char *)sld_stack_pop(&stack1));
  puts("");

  puts("Popping remaining contents of stack (vector backend)...");
  for(i = 0; i <= sld_stack_size(&stack2); i++)
    printf("%s ", (char *)sld_stack_pop(&stack2));
  puts("");

  sld_stack_free(&stack1);
  sld_stack_free(&stack2);
  sld_memory_pool_nuke();

  return 0;
}
