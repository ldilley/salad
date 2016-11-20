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

#include <string.h>    /* strlen() */
#include <time.h>      /* time_t, tm, asctime(), localtime(), strftime(), time() */

/* Local includes */
#include "salad/time.h"

time_t sld_seconds_since_epoch()
{
  return time(NULL);
}

char *sld_pretty_timestamp()
{
  char *timestamp;
  time_t rawtime;
  struct tm *timedata;

  time(&rawtime);
  timedata = localtime(&rawtime);
  timestamp = asctime(timedata);

  /* Remove appended newline */
  if(timestamp[strlen(timestamp) - 1] == '\n')
    timestamp[strlen(timestamp) - 1] = '\0';

  return timestamp;
}
