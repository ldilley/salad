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

#include <stdio.h>

/* Local includes */
#include "salad/search.h"

void *sld_search_linear(void *data_structure, void *search_criterion, SLD_DATA_STRUCTURE data_structure_type, SLD_DATA_TYPE search_criterion_type)
{
  void *return_value = NULL;

  /* See what data type we're working with and hand off the data to the appropriate function... */
  switch(search_criterion_type)
  {
    /* For simplicity, let smaller data types fall through since we can cast them to larger ones... */
    case sld_data_type_char:
    case sld_data_type_signed_char:
    case sld_data_type_unsigned_char:
    case sld_data_type_short:
    case sld_data_type_signed_short:
    case sld_data_type_unsigned_short:
    case sld_data_type_int:
    case sld_data_type_signed_int:
    case sld_data_type_unsigned_int:
    case sld_data_type_long:
      return_value = sld_search_linear_long(data_structure, (long)search_criterion, data_structure_type);
      break;
    case sld_data_type_signed_long:
      return_value = sld_search_linear_signed_long(data_structure, (signed long)search_criterion, data_structure_type);
      break;
    case sld_data_type_unsigned_long:
      return_value = sld_search_linear_unsigned_long(data_structure, (unsigned long)search_criterion, data_structure_type);
      break;
#ifdef C99
    case sld_data_type_long_long:
      return_value = sld_search_linear_long_long(data_structure, (long long)search_criterion, data_structure_type);
      break;
#endif
    case sld_data_type_float:
      return_value = sld_search_linear_float(data_structure, *(float *)search_criterion, data_structure_type);
      break;
    case sld_data_type_double:
      return_value = sld_search_linear_double(data_structure, *(double *)search_criterion, data_structure_type);
      break;
    case sld_data_type_char_pointer:
      return_value = sld_search_linear_char_pointer(data_structure, (char *)search_criterion, data_structure_type);;
      break;
    default:
      /* Should never be reached! */
      puts("Default somehow reached in sld_search_linear() while checking data type!");
  }

  return return_value;
}

void *sld_search_linear_long(void *data_structure, long search_criterion, SLD_DATA_STRUCTURE data_structure_type)
{
  void *return_value = NULL;

  switch(data_structure_type)
  {
    case sld_data_structure_list:
      return_value = (void *)sld_search_linear_long_list((sld_list *)data_structure, search_criterion);
      break;
    case sld_data_structure_map:
      return_value = (void *)sld_search_linear_long_map((sld_map *)data_structure, search_criterion);
      break;
    case sld_data_structure_queue:
      return_value = (void *)sld_search_linear_long_queue((sld_queue *)data_structure, search_criterion);
      break;
    case sld_data_structure_stack:
      return_value = (void *)sld_search_linear_long_stack((sld_stack *)data_structure, search_criterion);
      break;
    case sld_data_structure_tree:
      return_value = (void *)sld_search_linear_long_tree((sld_tree *)data_structure, search_criterion);
      break;
    case sld_data_structure_vector:
      return_value = (void *)sld_search_linear_long_vector((sld_vector *)data_structure, search_criterion);
      break;
    default:
      puts("Default somehow reached in sld_search_linear_long() while checking data structure type!");
  }

  return return_value;
}

void *sld_search_linear_signed_long(void *data_structure, signed long search_criterion, SLD_DATA_STRUCTURE data_structure_type)
{
  void *return_value = NULL;

  switch(data_structure_type)
  {
    case sld_data_structure_list:
      return_value = (void *)sld_search_linear_signed_long_list((sld_list *)data_structure, search_criterion);
      break;
    case sld_data_structure_map:
      return_value = (void *)sld_search_linear_signed_long_map((sld_map *)data_structure, search_criterion);
      break;
    case sld_data_structure_queue:
      return_value = (void *)sld_search_linear_signed_long_queue((sld_queue *)data_structure, search_criterion);
      break;
    case sld_data_structure_stack:
      return_value = (void *)sld_search_linear_signed_long_stack((sld_stack *)data_structure, search_criterion);
      break;
    case sld_data_structure_tree:
      return_value = (void *)sld_search_linear_signed_long_tree((sld_tree *)data_structure, search_criterion);
      break;
    case sld_data_structure_vector:
      return_value = (void *)sld_search_linear_signed_long_vector((sld_vector *)data_structure, search_criterion);
      break;
    default:
      puts("Default somehow reached in sld_search_linear_signed_long() while checking data structure type!");
  }

  return return_value;
}

void *sld_search_linear_unsigned_long(void *data_structure, unsigned long search_criterion, SLD_DATA_STRUCTURE data_structure_type)
{
  void *return_value = NULL;

  switch(data_structure_type)
  {
    case sld_data_structure_list:
      return_value = (void *)sld_search_linear_unsigned_long_list((sld_list *)data_structure, search_criterion);
      break;
    case sld_data_structure_map:
      return_value = (void *)sld_search_linear_unsigned_long_map((sld_map *)data_structure, search_criterion);
      break;
    case sld_data_structure_queue:
      return_value = (void *)sld_search_linear_unsigned_long_queue((sld_queue *)data_structure, search_criterion);
      break;
    case sld_data_structure_stack:
      return_value = (void *)sld_search_linear_unsigned_long_stack((sld_stack *)data_structure, search_criterion);
      break;
    case sld_data_structure_tree:
      return_value = (void *)sld_search_linear_unsigned_long_tree((sld_tree *)data_structure, search_criterion);
      break;
    case sld_data_structure_vector:
      return_value = (void *)sld_search_linear_unsigned_long_vector((sld_vector *)data_structure, search_criterion);
      break;
    default:
      puts("Default somehow reached in sld_search_linear_unsigned_long() while checking data structure type!");
  }

  return return_value;
}

#ifdef C99
void *sld_search_linear_long_long(void *data_structure, long long search_criterion, SLD_DATA_STRUCTURE data_structure_type)
{
  void *return_value = NULL;

  switch(data_structure_type)
  {
    case sld_data_structure_list:
      return_value = (void *)sld_search_linear_long_long_list((sld_list *)data_structure, search_criterion);
      break;
    case sld_data_structure_map:
      return_value = (void *)sld_search_linear_long_long_map((sld_map *)data_structure, search_criterion);
      break;
    case sld_data_structure_queue:
      return_value = (void *)sld_search_linear_long_long_queue((sld_queue *)data_structure, search_criterion);
      break;
    case sld_data_structure_stack:
      return_value = (void *)sld_search_linear_long_long_stack((sld_stack *)data_structure, search_criterion);
      break;
    case sld_data_structure_tree:
      return_value = (void *)sld_search_linear_long_long_tree((sld_tree *)data_structure, search_criterion);
      break;
    case sld_data_structure_vector:
      return_value = (void *)sld_search_linear_long_long_vector((sld_vector *)data_structure, search_criterion);
      break;
    default:
      puts("Default somehow reached in sld_search_linear_long_long() while checking data structure type!");
  }

  return return_value;
}
#endif

void *sld_search_linear_float(void *data_structure, float search_criterion, SLD_DATA_STRUCTURE data_structure_type)
{
  void *return_value = NULL;

  switch(data_structure_type)
  {
    case sld_data_structure_list:
      return_value = (void *)sld_search_linear_float_list((sld_list *)data_structure, search_criterion);
      break;
    case sld_data_structure_map:
      return_value = (void *)sld_search_linear_float_map((sld_map *)data_structure, search_criterion);
      break;
    case sld_data_structure_queue:
      return_value = (void *)sld_search_linear_float_queue((sld_queue *)data_structure, search_criterion);
      break;
    case sld_data_structure_stack:
      return_value = (void *)sld_search_linear_float_stack((sld_stack *)data_structure, search_criterion);
      break;
    case sld_data_structure_tree:
      return_value = (void *)sld_search_linear_float_tree((sld_tree *)data_structure, search_criterion);
      break;
    case sld_data_structure_vector:
      return_value = (void *)sld_search_linear_float_vector((sld_vector *)data_structure, search_criterion);
      break;
    default:
      puts("Default somehow reached in sld_search_linear_float() while checking data structure type!");
  }

  return return_value;
}

void *sld_search_linear_double(void *data_structure, double search_criterion, SLD_DATA_STRUCTURE data_structure_type)
{
  void *return_value = NULL;

  switch(data_structure_type)
  {
    case sld_data_structure_list:
      return_value = (void *)sld_search_linear_double_list((sld_list *)data_structure, search_criterion);
      break;
    case sld_data_structure_map:
      return_value = (void *)sld_search_linear_double_map((sld_map *)data_structure, search_criterion);
      break;
    case sld_data_structure_queue:
      return_value = (void *)sld_search_linear_double_queue((sld_queue *)data_structure, search_criterion);
      break;
    case sld_data_structure_stack:
      return_value = (void *)sld_search_linear_double_stack((sld_stack *)data_structure, search_criterion);
      break;
    case sld_data_structure_tree:
      return_value = (void *)sld_search_linear_double_tree((sld_tree *)data_structure, search_criterion);
      break;
    case sld_data_structure_vector:
      return_value = (void *)sld_search_linear_double_vector((sld_vector *)data_structure, search_criterion);
      break;
    default:
      puts("Default somehow reached in sld_search_linear_double() while checking data structure type!");
  }

  return return_value;
}

void *sld_search_linear_char_pointer(void *data_structure, char *search_criterion, SLD_DATA_STRUCTURE data_structure_type)
{
  void *return_value = NULL;

  switch(data_structure_type)
  {
    case sld_data_structure_list:
      return_value = (void *)sld_search_linear_char_pointer_list((sld_list *)data_structure, search_criterion);
      break;
    case sld_data_structure_map:
      return_value = (void *)sld_search_linear_char_pointer_map((sld_map *)data_structure, search_criterion);
      break;
    case sld_data_structure_queue:
      return_value = (void *)sld_search_linear_char_pointer_queue((sld_queue *)data_structure, search_criterion);
      break;
    case sld_data_structure_stack:
      return_value = (void *)sld_search_linear_char_pointer_stack((sld_stack *)data_structure, search_criterion);
      break;
    case sld_data_structure_tree:
      return_value = (void *)sld_search_linear_char_pointer_tree((sld_tree *)data_structure, search_criterion);
      break;
    case sld_data_structure_vector:
      return_value = (void *)sld_search_linear_char_pointer_vector((sld_vector *)data_structure, search_criterion);
      break;
    default:
      puts("Default somehow reached in sld_search_linear_char_pointer() while checking data structure type!");
  }

  return return_value;
}

SLD_SLINT sld_search_linear_long_list(struct sld_list *list, long search_criterion)
{
  signed long i;
  SLD_BOOL found = SLD_FALSE;

  for(i = 0; i < sld_list_size(list); i++)
  {
    if(search_criterion == (long)sld_list_get(list, i))
    {
      found = SLD_TRUE;
      break;
    }
  }

  if(!found)
    i = -1;

  return i;
}

SLD_SLINT sld_search_linear_long_map(struct sld_map *map, long search_criterion)
{
  return -1;
}

SLD_SLINT sld_search_linear_long_queue(struct sld_queue *queue, long search_criterion)
{
  return -1;
}

SLD_SLINT sld_search_linear_long_stack(struct sld_stack *stack, long search_criterion)
{
  return -1;
}

SLD_SLINT sld_search_linear_long_tree(struct sld_tree *tree, long search_criterion)
{
  return -1;
}

SLD_SLINT sld_search_linear_long_vector(struct sld_vector *vector, long search_criterion)
{
  return -1;
}

SLD_SLINT sld_search_linear_signed_long_list(struct sld_list *list, signed long search_criterion)
{
  return -1;
}

SLD_SLINT sld_search_linear_signed_long_map(struct sld_map *map, signed long search_criterion)
{
  return -1;
}

SLD_SLINT sld_search_linear_signed_long_queue(struct sld_queue *queue, signed long search_criterion)
{
  return -1;
}

SLD_SLINT sld_search_linear_signed_long_stack(struct sld_stack *stack, signed long search_criterion)
{
  return -1;
}

SLD_SLINT sld_search_linear_signed_long_tree(struct sld_tree *tree, signed long search_criterion)
{
  return -1;
}

SLD_SLINT sld_search_linear_signed_long_vector(struct sld_vector *vector, signed long search_criterion)
{
  return -1;
}

SLD_SLINT sld_search_linear_unsigned_long_list(struct sld_list *list, unsigned long search_criterion)
{
  return -1;
}

SLD_SLINT sld_search_linear_unsigned_long_map(struct sld_map *map, unsigned long search_criterion)
{
  return -1;
}

SLD_SLINT sld_search_linear_unsigned_long_queue(struct sld_queue *queue, unsigned long search_criterion)
{
  return -1;
}

SLD_SLINT sld_search_linear_unsigned_long_stack(struct sld_stack *stack, unsigned long search_criterion)
{
  return -1;
}

SLD_SLINT sld_search_linear_unsigned_long_tree(struct sld_tree *tree, unsigned long search_criterion)
{
  return -1;
}

SLD_SLINT sld_search_linear_unsigned_long_vector(struct sld_vector *vector, unsigned long search_criterion)
{
  return -1;
}

#ifdef C99
SLD_SLINT sld_search_linear_long_long_list(struct sld_list *list, long long search_criterion)
{
  return -1;
}

SLD_SLINT sld_search_linear_long_long_map(struct sld_map *map, long long search_criterion)
{
  return -1;
}

SLD_SLINT sld_search_linear_long_long_queue(struct sld_queue *queue, long long search_criterion)
{
  return -1;
}

SLD_SLINT sld_search_linear_long_long_stack(struct sld_stack *stack, long long search_criterion)
{
  return -1;
}

SLD_SLINT sld_search_linear_long_long_tree(struct sld_tree *tree, long long search_criterion)
{
  return -1;
}

SLD_SLINT sld_search_linear_long_long_vector(struct sld_vector *vector, long long search_criterion)
{
  return -1;
}
#endif /* C99 */

SLD_SLINT sld_search_linear_float_list(struct sld_list *list, float search_criterion)
{
  return -1;
}

SLD_SLINT sld_search_linear_float_map(struct sld_map *map, float search_criterion)
{
  return -1;
}

SLD_SLINT sld_search_linear_float_queue(struct sld_queue *queue, float search_criterion)
{
  return -1;
}

SLD_SLINT sld_search_linear_float_stack(struct sld_stack *stack, float search_criterion)
{
  return -1;
}

SLD_SLINT sld_search_linear_float_tree(struct sld_tree *tree, float search_criterion)
{
  return -1;
}

SLD_SLINT sld_search_linear_float_vector(struct sld_vector *vector, float search_criterion)
{
  return -1;
}

SLD_SLINT sld_search_linear_double_list(struct sld_list *list, double search_criterion)
{
  return -1;
}

SLD_SLINT sld_search_linear_double_map(struct sld_map *map, double search_criterion)
{
  return -1;
}

SLD_SLINT sld_search_linear_double_queue(struct sld_queue *queue, double search_criterion)
{
  return -1;
}

SLD_SLINT sld_search_linear_double_stack(struct sld_stack *stack, double search_criterion)
{
  return -1;
}

SLD_SLINT sld_search_linear_double_tree(struct sld_tree *tree, double search_criterion)
{
  return -1;
}

SLD_SLINT sld_search_linear_double_vector(struct sld_vector *vector, double search_criterion)
{
  return -1;
}

SLD_SLINT sld_search_linear_char_pointer_list(struct sld_list *list, char *search_criterion)
{
  return -1;
}

SLD_SLINT sld_search_linear_char_pointer_map(struct sld_map *map, char *search_criterion)
{
  return -1;
}

SLD_SLINT sld_search_linear_char_pointer_queue(struct sld_queue *queue, char *search_criterion)
{
  return -1;
}

SLD_SLINT sld_search_linear_char_pointer_stack(struct sld_stack *stack, char *search_criterion)
{
  return -1;
}

SLD_SLINT sld_search_linear_char_pointer_tree(struct sld_tree *tree, char *search_criterion)
{
  return -1;
}

SLD_SLINT sld_search_linear_char_pointer_vector(struct sld_vector *vector, char *search_criterion)
{
  return -1;
}
