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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Local includes */
#include "salad/string.h"
#include "salad/types.h"

SLD_BOOL sld_string_contains_character(char *string, char character)
{
  int i;
  SLD_BOOL found = SLD_FALSE;

  for(i = 0; i < strlen(string); i++)
  {
    if(string[i] == character)
    {
      found = SLD_TRUE;
      break;
    }
  }
  return found;
}

char *sld_multiply_string(char *string, int factor, char separator)
{
  int i;
  char separator_string[2];
  char *concat_string = (char *)malloc(strlen(string) * factor + factor); /* "+ factor" for the separator */

  separator_string[0] = separator;
  separator_string[1] = '\0';

  for(i = 0; i < factor; i++)
  {
    strcat(concat_string, string);
    if(i == factor - 1) /* don't add separator to final instance */
      break;
    strcat(concat_string, separator_string);
  }

  return concat_string;
}
