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

#include <stdio.h>

/* Local includes */
#include "salad/daemon.h"
#include "salad/string.h"
#include "salad/time.h"

int main()
{
  /* If the user and group are set to NULL, the process will run as the user who started it. */ 
  sld_daemonize("test.pid", NULL, NULL);
  return 0;
}

void sld_start()
{
  for(;;)
  {
    /* Prints the time multiplied by 3 and is space separated. */
    puts(sld_multiply_string(sld_pretty_timestamp(), 3, ' '));
    sleep(5);
  }
  return;
}
