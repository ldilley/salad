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

#ifndef SORT_H
#define SORT_H

#include "salad/types.h"

/*!
 * @defgroup sld_sort
 * This module contains functions related to sorting data.
 * @note The sld_sort functions are not yet implemented!
 * @todo Implement sld_sort functionality!
 * @{
 */

/*!
 * @brief A simple sorting algorithm that sorts by swapping pairs of data and works well for small sets of data
 * @param data_structure a sld_list, sld_map, sld_queue, sld_stack, sld_tree, or sld_vector
 * @param data_structure_type any type defined by SLD_DATA_STRUCTURE such as sld_data_structure_vector for example
 * @param data_type any type defined by SLD_DATA_TYPE such as sld_data_type_int for example
 *
@code
sld_sort_bubble(&vector, sld_data_structure_vector, sld_data_type_int);
@endcode
 */
void sld_sort_bubble(void *data_structure, SLD_DATA_STRUCTURE data_structure_type, SLD_DATA_TYPE data_type);

/*!
 * @brief A simple sorting algorithm that sorts by inserting data that is out of order and works well for small sets of data
 * @param data_structure a sld_list, sld_map, sld_queue, sld_stack, sld_tree, or sld_vector
 * @param data_structure_type any type defined by SLD_DATA_STRUCTURE such as sld_data_structure_vector for example
 * @param data_type any type defined by SLD_DATA_TYPE such as sld_data_type_int for example
 *
@code
sld_sort_insertion(&vector, sld_data_structure_vector, sld_data_type_int);
@endcode
 */
void sld_sort_insertion(void *data_structure, SLD_DATA_STRUCTURE data_structure_type, SLD_DATA_TYPE data_type);

/*!
 * @brief A simple sorting algorithm that sorts by swapping data that is out of order and suffices for small sets of data
 * @param data_structure a sld_list, sld_map, sld_queue, sld_stack, sld_tree, or sld_vector
 * @param data_structure_type any type defined by SLD_DATA_STRUCTURE such as sld_data_structure_vector for example
 * @param data_type any type defined by SLD_DATA_TYPE such as sld_data_type_int for example
 *
@code
sld_sort_selection(&vector, sld_data_structure_vector, sld_data_type_int);
@endcode
 */
void sld_sort_selection(void *data_structure, SLD_DATA_STRUCTURE data_structure_type, SLD_DATA_TYPE data_type);

/*! @} */

#endif /* SORT_H */
