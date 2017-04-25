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

#include <ctype.h>  /* tolower(), toupper() */
#include <errno.h>  /* errno */
#include <stdio.h>  /* printf() */
#include <stdlib.h> /* EXIT_FAILURE, exit(), calloc(), malloc() */
#include <string.h> /* strcat(), strcmp(), strcpy(), strerror(), strlen() */

/* Local includes */
#include "salad/config.h"
#include "salad/memory.h"
#include "salad/string.h"
#include "salad/types.h"

char *sld_string_allocate(char *string)
{
  char *new_string = NULL;

  new_string = (char *)calloc(strlen(string) + 1, sizeof(char));

  if(new_string == NULL)
  {
    printf("Unable to allocate memory for string: %s\n", strerror(errno));
#ifdef EXIT_ON_FAILURE
    exit(EXIT_FAILURE);
#endif
  }
  else
    sld_memory_pool_add(new_string);

  return new_string;
}

char *sld_string_chomp(char *string)
{
  char *chomped_string = NULL;
  int length = strlen(string);
  int i;

  chomped_string = sld_string_allocate(string);
  strcpy(chomped_string, string);

  if(chomped_string != NULL && length > 0)
  {
    for(i = length - 1; i >= 0; i--)
    {
      if(chomped_string[i] != '\n' && chomped_string[i] != '\r' && chomped_string[i] != '\0')
        break;
      if(i > 0 && chomped_string[i] == '\n' && chomped_string[i - 1] == '\r')
        chomped_string[i - 1] = '\0';
      else if(chomped_string[i] == '\n')
        chomped_string[i] = '\0';
    }
  }

  return chomped_string;
}

char *sld_string_chop(char *string)
{
  char *chopped_string = NULL;
  int length = strlen(string);

  chopped_string = sld_string_allocate(string);
  strcpy(chopped_string, string);

  if(length == 0 || length == 1)
    chopped_string = "";
  else
  {
    if(chopped_string[length - 1] == '\n' && chopped_string[length - 2] == '\r')
      chopped_string[length - 2] = '\0';
    else
      chopped_string[length - 1] = '\0';
  }

  return chopped_string;
}

char *sld_string_trim_leading(char *string)
{
  char *trimmed_string = NULL;

  trimmed_string = sld_string_allocate(string);
  strcpy(trimmed_string, string);

  while(isspace((unsigned char)*trimmed_string))
    trimmed_string++;

  return trimmed_string;
}

char *sld_string_trim_trailing(char *string)
{
  char *trimmed_string = NULL;
  char *string_end = NULL;

  trimmed_string = sld_string_allocate(string);
  strcpy(trimmed_string, string);
  string_end = trimmed_string + strlen(trimmed_string) - 1;

  while(isspace((unsigned char)*string_end) && string_end > trimmed_string)
    string_end--;
  *(string_end + 1) = '\0';

  return trimmed_string;
}

char *sld_string_trim(char *string)
{
  char *trimmed_string = NULL;

  trimmed_string = sld_string_allocate(string);
  strcpy(trimmed_string, string);

  trimmed_string = sld_string_trim_leading(trimmed_string);
  trimmed_string = sld_string_trim_trailing(trimmed_string);

  return trimmed_string;
}

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

char *sld_string_capitalize(char *string)
{
  int i = 0;
  char *capitalized_string = NULL;

  capitalized_string = sld_string_allocate(string);

  while(string[i])
  {
    capitalized_string[i] = toupper(string[i]);
    i++;
  }

  return capitalized_string;
}

char *sld_string_uncapitalize(char *string)
{
  int i = 0;
  char *uncapitalized_string = NULL;

  uncapitalized_string = sld_string_allocate(string);

  while(string[i])
  {
    uncapitalized_string[i] = tolower(string[i]);
    i++;
  }

  return uncapitalized_string;
}

int sld_string_casecmp(char *string1, char *string2)
{
  char *cmp_string1 = sld_string_capitalize(string1);
  char *cmp_string2 = sld_string_capitalize(string2);
  return strcmp(cmp_string1, cmp_string2);
}

char *sld_string_multiply(char *string, int factor, char separator)
{
  int i;
  char separator_string[2];
  char *concat_string = NULL;

  /* "+ factor + 1" for the separator and terminator */
  concat_string = (char *)malloc(strlen(string) * factor + factor + 1);
  if(concat_string == NULL)
  {
    printf("Unable to allocate memory for string: %s\n", strerror(errno));
#ifdef EXIT_ON_FAILURE
    exit(EXIT_FAILURE);
#endif
  }
  else
  {
    *concat_string = '\0';
    separator_string[0] = separator;
    separator_string[1] = '\0';

    for(i = 0; i < factor; i++)
    {
      strcat(concat_string, string);
      if(i == factor - 1) /* don't add separator to final instance */
        break;
      strcat(concat_string, separator_string);
    }

    sld_memory_pool_add(concat_string);
  }

  return concat_string;
}

char *sld_string_reverse(char *string)
{
  char *reversed_string = NULL;
  int i, j, end_index;

  if(string != NULL && strlen(string) > 0)
  {
    reversed_string = sld_string_allocate(string);
    strcpy(reversed_string, string);

    for(i = 0; string[i] != '\0'; i++)
      end_index = i;

    for(j = 0; j <= i - 1; j++)
    {
      reversed_string[j] = string[end_index];
      end_index--;
    }
  }

  return reversed_string;
}
