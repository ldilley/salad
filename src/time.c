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

#include <string.h>    /* strlen() */
#include <time.h>      /* time_t, tm, asctime(), localtime(), strftime(), time() */

/* Local includes */
#include "salad/time.h"

time_t sld_time_epoch_seconds()
{
  return time(NULL);
}

char *sld_time_pretty_timestamp()
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
