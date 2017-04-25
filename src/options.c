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

#include <errno.h>  /* errno */
#include <stdio.h>  /* FILE, fclose(), fgets(), fopen(), printf() */
#include <stdlib.h> /* EXIT_FAILURE, exit() */
#include <string.h> /* strcpy(), strerror(), strlen(), strtok() */

/* Local includes */
#include "salad/options.h"
#include "salad/string.h"

/* A struct would've been nice, but we use a map here since C has no reflection. */
SLD_SSINT sld_options_read(const char *file_name, struct sld_map *options)
{
  int i;
  char line[256];
  char *result, *value;
  char *heap_result = NULL;
  char *heap_value = NULL;
  SLD_BOOL comment = SLD_FALSE;
  FILE *options_file = fopen(file_name, "r");

  if(options_file == NULL)
  {
    printf("Unable to open options file (%s): %s\n", file_name, strerror(errno));
#ifdef EXIT_ON_FAILURE
    exit(EXIT_FAILURE);
#endif
    return RETURN_FAILURE;
  }

  while(fgets(line, sizeof(line), options_file) != NULL)
  {
    /* Ignore blank lines and comments */
    if(line[0] == '\n' || line[0] == '\r' || line[0] == '#')
      continue;

    /* Trim leading whitespace from line to see if it is another comment */
    for(i = 0; i < strlen(line); i++)
    {
      if(line[i] == ' ' || line[i] == '\t')
        continue;
      if(line[i] != '#')
        break;
      if(line[i] == '#')
      {
        comment = SLD_TRUE;
        break;
      }
    }
    if(comment)
      continue;

    /* Populate configuration variables from options file */
    result = sld_string_chomp(strtok(line, " \t"));
    value = sld_string_chomp(strtok(NULL, " \t"));
    heap_result = sld_string_allocate(result);
    heap_value = sld_string_allocate(value);
    strcpy(heap_result, result);
    strcpy(heap_value, value);
    sld_map_add(options, heap_result, heap_value);
  }

  fclose(options_file);

  return 0;
}
