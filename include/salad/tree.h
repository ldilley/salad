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

#ifndef TREE_H
#define TREE_H

#include "salad/types.h"

/*!
 * @defgroup sld_tree
 * This module contains enums, functions, and structures related to sld_tree objects.
 * @note The sld_tree functions are not yet implemented!
 * @todo Implement sld_tree functionality!
 * @{
 */

/*! A sld_node contained within a tree */
typedef struct sld_tree_node
{
  void *object;                /*!< ambiguous object contained within the node */
  struct sld_tree_node *left;  /*!< pointer to left node in memory */
  struct sld_tree_node *right; /*!< pointer to right node in memory */
} sld_node;

/*! A sld_tree contains sld_tree_node structures */
typedef struct sld_tree
{
  SLD_UINT size;         /*!< contains the size of the sld_tree */
  struct sld_node *root; /*!< the starting sld_tree_node of the sld_tree */
} sld_tree;

/*! @} */

#endif /* TREE_H */
