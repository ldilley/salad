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

#include <errno.h>  /* errno */
#include <stdio.h>  /* FILE, fclose(), fopen(), fprintf(), printf() */
#include <stdlib.h> /* EXIT_FAILURE, exit() */
#include <string.h> /* strcpy(), strerror() */

/* Local includes */
#include "salad/log.h"
#include "salad/time.h"
#include "salad/types.h"

SLD_SSINT sld_log_write(const char *file_name, sld_log_severity severity, const char *text)
{
  char level[5];
  FILE *log_file = fopen(file_name, "a");
  if(log_file == NULL)
  {
    printf("Unable to open log file (%s): %s\n", file_name, strerror(errno));
#ifdef EXIT_ON_FAILURE
    exit(EXIT_FAILURE);
#endif
    return RETURN_FAILURE;
  }

  switch(severity)
  {
    /* DBUG */
    case 0:
      strcpy(level, "DBUG");
      break;
    /* INFO */
    case 1:
      strcpy(level, "INFO");
      break;
    /* WARN */
    case 2:
      strcpy(level, "WARN");
      break;
    /* CRIT */
    case 3:
      strcpy(level, "CRIT");
      break;
    /* DBUG */
    default:
      strcpy(level, "DBUG");
  }

  fprintf(log_file, "%s %s: %s\n", sld_time_pretty_timestamp(), level, text);
  fclose(log_file);

  return RETURN_SUCCESS;
}
