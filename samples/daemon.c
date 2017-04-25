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

#include <stdio.h>  /* puts() */
#include <unistd.h> /* sleep() */

/* Local includes */
#include "salad/daemon.h"
#include "salad/memory.h"
#include "salad/string.h"

int main()
{
  /* If the user and group are set to NULL, the process will run as the user who started it. */ 
  sld_daemon_daemonize("test.pid", NULL, NULL);
  return 0;
}

void sld_daemon_start()
{
  int i;
  char *heap_string = NULL;

  for(;;)
  {
    /* Prints a space-separated string multiplied by itself 3 times. */
    heap_string = sld_string_multiply(sld_string_capitalize("hello!"), 3, ' ');
    puts(heap_string);

    for(i = 0; i < 32; i++)
      sld_string_multiply("This string will be dynamically allocated.", 5, '\n');

    /* sld_string_multiply() allocates memory dynamically. However, there is no need to
     * manually track the pointer or explicitly call free() since sld_free_pool() takes
     * care of any data allocated by salad. You may call sld_multiply_string() multiple
     * times, but it is a good idea to call sld_free_pool() periodically to release all
     * memory back to the operating system. */
    sld_memory_pool_free();

    sleep(5);
  }

  /* When complete with salad, call sld_nuke_pool() to totally free all allocations. */
  sld_memory_pool_nuke();

  return;
}
