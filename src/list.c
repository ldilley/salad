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
#include <stdio.h>  /* printf() */
#include <stdlib.h> /* EXIT_FAILURE, exit(), free(), malloc() */
#include <string.h> /* strerror() */

/* Local includes */
#include "salad/config.h"
#include "salad/list.h"
#include "salad/types.h"

SLD_SSINT sld_list_init(struct sld_list *list)
{
  list->size = 0;
  list->head = (struct sld_list_node *)malloc(sizeof(struct sld_list_node));

  if(list->head == NULL)
  {
    printf("Unable to allocate memory for list: %s\n", strerror(errno));
#ifdef EXIT_ON_FAILURE
    exit(EXIT_FAILURE);
#endif
    return RETURN_FAILURE;
  }
  else
  {
    list->head->object = NULL;
    list->head->next = NULL;
    list->head->previous = NULL;
  }

  return RETURN_SUCCESS;
}

SLD_UINT sld_list_size(struct sld_list *list)
{
  return list->size;
}

SLD_SSINT sld_list_add(struct sld_list *list, void *object)
{
  struct sld_list_node *current = NULL;
  struct sld_list_node *new = NULL;

  current = list->head;

  /* List is fresh, so set root node */
  if(sld_list_size(list) == 0 && list->head->object == NULL)
  {
    current->object = object;
    list->size++;
  }
  else
  {
    while(current != NULL)
    {
      if(current->next == NULL)
      {
        new = (struct sld_list_node *)malloc(sizeof(struct sld_list_node));
        if(new == NULL)
        {
          printf("Unable to allocate memory for list: %s\n", strerror(errno));
#ifdef EXIT_ON_FAILURE
          exit(EXIT_FAILURE);
#endif
          return RETURN_FAILURE;
        }
        else
        {
          current->next = new;
          new->object = object;
          new->next = NULL;
          new->previous = current;
          list->size++;
          break;
        }
      }
      current = current->next;
    }
  }

  return RETURN_SUCCESS;
}

void sld_list_delete(struct sld_list *list, SLD_UINT index)
{
  struct sld_list_node *current = NULL;
  int i = 0;

  if(index > sld_list_size(list))
    return;

  current = list->head;

  while(current != NULL)
  {
    if(i == index)
    {
      /* If head is being deleted, repoint it to next node */
      if(i == 0 && sld_list_size(list) > 1)
      {
        list->head = current->next;
        list->head->previous = NULL;
      }
      else
      {
        if(current->next != NULL)
        {
          /* Repoint next node to previous and previous node to next */
          current->next->previous = current->previous;
          current->previous->next = current->next;
        }
        else if(sld_list_size(list) == 1 && current->next == NULL) /* Only the head remains */
          current->previous = NULL;       /* Filler assignment */
        else
          current->previous->next = NULL; /* End of the line... Set previous node to NULL */
      }
      free(current);
      list->size--;
      break;
    }
    i++;
    current = current->next;
  }
  return;
}

void *sld_list_get(struct sld_list *list, SLD_UINT index)
{
  struct sld_list_node *current = NULL;
  void *object = NULL;
  int i = 0;

  if(index < 0 || index > sld_list_size(list))
    return NULL;

  current = list->head;

  while(current != NULL)
  {
    if(i == index)
    {
      object = current->object;
      break;
    }
    i++;
    current = current->next;
  }

  return object;
}

void *sld_list_pop(struct sld_list *list)
{
  void *object = NULL;

  object = sld_list_get(list, sld_list_size(list) - 1);
  sld_list_delete(list, sld_list_size(list) - 1);

  return object;
}

void sld_list_free(struct sld_list *list)
{
  struct sld_list_node *current = NULL;
  struct sld_list_node *next = NULL;

  current = list->head;

  while(current->next)
  {
    next = current->next;
    free(current);
    current = next;
  }

  free(current);
  list->size = 0;

  return;
}
