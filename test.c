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

#include <stdio.h>  /* puts() */
#include <stdlib.h> /* free() */

/* Local includes */
#include "salad/daemon.h"
#include "salad/string.h"

int main()
{
  /* If the user and group are set to NULL, the process will run as the user who started it. */ 
  sld_daemonize("test.pid", NULL, NULL);
  return 0;
}

void sld_start()
{
  int i;
  char *heap_string = NULL;

  for(;;)
  {
    /* Prints a space-separated string multiplied by itself 3 times. */
    heap_string = sld_multiply_string("hello!", 3, ' ');
    puts(heap_string);

    for(i = 0; i < 32; i++)
      sld_multiply_string("This string will be dynamically allocated.", 5, '\n');

    /* sld_multiply_string() allocates memory dynamically. However, there is no need to
     * manually track the pointer or explicitly call free() since sld_free_pool() takes
     * care of any data allocated by salad. You may call sld_multiply_string() multiple
     * times, but it is a good idea to call sld_free_pool() periodically to release all
     * memory back to the operating system. */
    sld_free_pool();

    sleep(5);
  }

  /* When complete with salad, call sld_nuke_pool() to totally free all allocations. */
  sld_nuke_pool();

  return;
}
