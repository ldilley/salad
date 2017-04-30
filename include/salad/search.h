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

#ifndef SEARCH_H
#define SEARCH_H

#include "salad/list.h"
#include "salad/map.h"
#include "salad/queue.h"
#include "salad/stack.h"
#include "salad/tree.h"
#include "salad/vector.h"
#include "salad/types.h"

/*!
 * @defgroup sld_search
 * This module contains functions related to searching for data.
 * @note The sld_search functions are not yet implemented!
 * @todo Implement sld_search functionality!
 * @{
 */

/*!
 * @brief Searches through data with a "divide and conquer" approach
 * @param data_structure a sld_list, sld_map, sld_queue, sld_stack, sld_tree, or sld_vector
 * @param search_criterion the value to search for in the passed data structure
 * @param data_structure_type any type defined by SLD_DATA_STRUCTURE such as sld_data_structure_vector for example
 * @param search_criterion_type any type defined by SLD_DATA_TYPE such as sld_data_type_int for example
 * @return Index, key, or true/false depending on the data structure passed
 * @note This is a generic function that passes off the arguments to other functions depending on data type.
 *
@code
int index = (int *)sld_search_binary(&vector, "foo", sld_data_structure_vector, sld_data_type_char_pointer);
@endcode
 */
void *sld_search_binary(void *data_structure, void *search_criterion, SLD_DATA_STRUCTURE data_structure_type, SLD_DATA_TYPE search_criterion_type);

/*!
 * @brief Searches through data sequentially
 * @param data_structure a sld_list, sld_map, sld_queue, sld_stack, sld_tree, or sld_vector
 * @param search_criterion the value to search for in the passed data structure
 * @param data_structure_type any type defined by SLD_DATA_STRUCTURE such as sld_data_structure_vector for example
 * @param search_criterion_type any type defined by SLD_DATA_TYPE such as sld_data_type_int for example
 * @return Index, key, or true/false depending on the data structure passed
 * @note This is a generic function that passes off the arguments to other functions depending on data type.
 *
@code
int index = (int *)sld_search_linear(&vector, "foo", sld_data_structure_vector, sld_data_type_char_pointer);
@endcode
 */
void *sld_search_linear(void *data_structure, void *search_criterion, SLD_DATA_STRUCTURE data_structure_type, SLD_DATA_TYPE search_criterion_type);

/*!
 * @brief Searches through long data sequentially
 * @param data_structure a sld_list, sld_map, sld_queue, sld_stack, sld_tree, or sld_vector
 * @param search_criterion the value to search for in the passed data structure
 * @param data_structure_type any type defined by SLD_DATA_STRUCTURE such as sld_data_structure_vector for example
 * @return Index, key, or true/false depending on the data structure passed
 * @note This function is called by sld_search_linear().
 *
@code
void *return_value = sld_search_linear_long(&list, (long)search_criterion, sld_data_structure_list);
@endcode 
 */
void *sld_search_linear_long(void *data_structure, long search_criterion, SLD_DATA_STRUCTURE data_structure_type);

/*!
 * @brief Searches through signed long data sequentially
 * @param data_structure a sld_list, sld_map, sld_queue, sld_stack, sld_tree, or sld_vector
 * @param search_criterion the value to search for in the passed data structure
 * @param data_structure_type any type defined by SLD_DATA_STRUCTURE such as sld_data_structure_vector for example
 * @return Index, key, or true/false depending on the data structure passed
 * @note This function is called by sld_search_linear().
 *
@code
void *return_value = sld_search_linear_signed_long(&list, (signed long)search_criterion, sld_data_structure_list);
@endcode
 */
void *sld_search_linear_signed_long(void *data_structure, signed long search_criterion, SLD_DATA_STRUCTURE data_structure_type);

/*!
 * @brief Searches through unsigned long data sequentially
 * @param data_structure a sld_list, sld_map, sld_queue, sld_stack, sld_tree, or sld_vector
 * @param search_criterion the value to search for in the passed data structure
 * @param data_structure_type any type defined by SLD_DATA_STRUCTURE such as sld_data_structure_vector for example
 * @return Index, key, or true/false depending on the data structure passed
 * @note This function is called by sld_search_linear().
 *
@code
void *return_value = sld_search_linear_unsigned_long(&list, (unsigned long)search_criterion, sld_data_structure_list);
@endcode
 */
void *sld_search_linear_unsigned_long(void *data_structure, unsigned long search_criterion, SLD_DATA_STRUCTURE data_structure_type);

#ifdef C99
/*!
 * @brief Searches through long long data sequentially
 * @param data_structure a sld_list, sld_map, sld_queue, sld_stack, sld_tree, or sld_vector
 * @param search_criterion the value to search for in the passed data structure
 * @param data_structure_type any type defined by SLD_DATA_STRUCTURE such as sld_data_structure_vector for example
 * @return Index, key, or true/false depending on the data structure passed
 * @note This function is called by sld_search_linear().
 *
@code
void *return_value = sld_search_linear_long_long(&list, (long long)search_criterion, sld_data_structure_list);
@endcode
 */
sld_search_linear_long_long(void *data_structure, long long search_criterion, SLD_DATA_STRUCTURE data_structure_type);
#endif

/*!
 * @brief Searches through float data sequentially
 * @param data_structure a sld_list, sld_map, sld_queue, sld_stack, sld_tree, or sld_vector
 * @param search_criterion the value to search for in the passed data structure
 * @param data_structure_type any type defined by SLD_DATA_STRUCTURE such as sld_data_structure_vector for example
 * @return Index, key, or true/false depending on the data structure passed
 * @note This function is called by sld_search_linear().
 *
@code
void *return_value = sld_search_linear_float(&list, (float)search_criterion, sld_data_structure_list);
@endcode
 */
void *sld_search_linear_float(void *data_structure, float search_criterion, SLD_DATA_STRUCTURE data_structure_type);

/*!
 * @brief Searches through double data sequentially
 * @param data_structure a sld_list, sld_map, sld_queue, sld_stack, sld_tree, or sld_vector
 * @param search_criterion the value to search for in the passed data structure
 * @param data_structure_type any type defined by SLD_DATA_STRUCTURE such as sld_data_structure_vector for example
 * @return Index, key, or true/false depending on the data structure passed
 * @note This function is called by sld_search_linear().
 *
@code
void *return_value = sld_search_linear_double(&list, (double)search_criterion, sld_data_structure_list);
@endcode
 */
void *sld_search_linear_double(void *data_structure, double search_criterion, SLD_DATA_STRUCTURE data_structure_type);

/*!
 * @brief Searches through char * data sequentially
 * @param data_structure a sld_list, sld_map, sld_queue, sld_stack, sld_tree, or sld_vector
 * @param search_criterion the value to search for in the passed data structure
 * @param data_structure_type any type defined by SLD_DATA_STRUCTURE such as sld_data_structure_vector for example
 * @return Index, key, or true/false depending on the data structure passed
 * @note This function is called by sld_search_linear().
 *
@code
void *return_value = sld_search_linear_char_pointer(&list, (char *)search_criterion, sld_data_structure_list);
@endcode
 */
void *sld_search_linear_char_pointer(void *data_structure, char *search_criterion, SLD_DATA_STRUCTURE data_structure_type);

/*!
 * @brief Searches through long data in a sld_list sequentially
 * @param list a sld_list
 * @param search_criterion the long value to search for in the passed sld_list
 * @return The index if the value is detected or -1 otherwise
 * @note This function is called by sld_search_linear_long().
 *
@code
long return_value = sld_search_linear_long_list(&list, 107);
@endcode
 */
SLD_SLINT sld_search_linear_long_list(struct sld_list *list, long search_criterion);

/*!
 * @brief Searches through long data in a sld_map sequentially
 * @param list a sld_map
 * @param search_criterion the long value to search for in the passed sld_map
 * @return The key if the value is detected or -1 otherwise
 * @note This function is called by sld_search_linear_long().
 *
@code
long return_value = sld_search_linear_long_map(&map, 107);
@endcode
 */
SLD_SLINT sld_search_linear_long_map(struct sld_map *map, long search_criterion);

/*!
 * @brief Searches through long data in a sld_queue sequentially
 * @param list a sld_queue
 * @param search_criterion the long value to search for in the passed sld_queue
 * @return The position if the value is detected or -1 otherwise
 * @note This function is called by sld_search_linear_long().
 *
@code
long return_value = sld_search_linear_long_queue(&queue, 107);
@endcode
 */
SLD_SLINT sld_search_linear_long_queue(struct sld_queue *queue, long search_criterion);

/*!
 * @brief Searches through long data in a sld_stack sequentially
 * @param list a sld_stack
 * @param search_criterion the long value to search for in the passed sld_stack
 * @return The position if the value is detected or -1 otherwise
 * @note This function is called by sld_search_linear_long().
 *
@code
long return_value = sld_search_linear_long_stack(&stack, 107);
@endcode
 */
SLD_SLINT sld_search_linear_long_stack(struct sld_stack *stack, long search_criterion);

/*!
 * @brief Searches through long data in a sld_tree sequentially
 * @param list a sld_tree
 * @param search_criterion the long value to search for in the passed sld_tree
 * @return True or false
 * @note This function is called by sld_search_linear_long().
 *
@code
long return_value = sld_search_linear_long_tree(&tree, 107);
@endcode
 */
SLD_SLINT sld_search_linear_long_tree(struct sld_tree *tree, long search_criterion);

/*!
 * @brief Searches through long data in a sld_vector sequentially
 * @param list a sld_vector
 * @param search_criterion the long value to search for in the passed sld_vector
 * @return The index if the value is detected or -1 otherwise
 * @note This function is called by sld_search_linear_long().
 *
@code
long return_value = sld_search_linear_long_vector(&vector, 107);
@endcode
 */
SLD_SLINT sld_search_linear_long_vector(struct sld_vector *vector, long search_criterion);

SLD_SLINT sld_search_linear_signed_long_list(struct sld_list *list, signed long search_criterion);
SLD_SLINT sld_search_linear_signed_long_map(struct sld_map *map, signed long search_criterion);
SLD_SLINT sld_search_linear_signed_long_queue(struct sld_queue *queue, signed long search_criterion);
SLD_SLINT sld_search_linear_signed_long_stack(struct sld_stack *stack, signed long search_criterion);
SLD_SLINT sld_search_linear_signed_long_tree(struct sld_tree *tree, signed long search_criterion);
SLD_SLINT sld_search_linear_signed_long_vector(struct sld_vector *vector, signed long search_criterion);

SLD_SLINT sld_search_linear_unsigned_long_list(struct sld_list *list, unsigned long search_criterion);
SLD_SLINT sld_search_linear_unsigned_long_map(struct sld_map *map, unsigned long search_criterion);
SLD_SLINT sld_search_linear_unsigned_long_queue(struct sld_queue *queue, unsigned long search_criterion);
SLD_SLINT sld_search_linear_unsigned_long_stack(struct sld_stack *stack, unsigned long search_criterion);
SLD_SLINT sld_search_linear_unsigned_long_tree(struct sld_tree *tree, unsigned long search_criterion);
SLD_SLINT sld_search_linear_unsigned_long_vector(struct sld_vector *vector, unsigned long search_criterion);

#ifdef C99
SLD_SLINT sld_search_linear_long_long_list(struct sld_list *list, long long search_criterion);
SLD_SLINT sld_search_linear_long_long_map(struct sld_map *map, long long search_criterion);
SLD_SLINT sld_search_linear_long_long_queue(struct sld_queue *queue, long long search_criterion);
SLD_SLINT sld_search_linear_long_long_stack(struct sld_stack *stack, long long search_criterion);
SLD_SLINT sld_search_linear_long_long_tree(struct sld_tree *tree, long long search_criterion);
SLD_SLINT sld_search_linear_long_long_vector(struct sld_vector *vector, long long search_criterion);
#endif /* C99 */

SLD_SLINT sld_search_linear_float_list(struct sld_list *list, float search_criterion);
SLD_SLINT sld_search_linear_float_map(struct sld_map *map, float search_criterion);
SLD_SLINT sld_search_linear_float_queue(struct sld_queue *queue, float search_criterion);
SLD_SLINT sld_search_linear_float_stack(struct sld_stack *stack, float search_criterion);
SLD_SLINT sld_search_linear_float_tree(struct sld_tree *tree, float search_criterion);
SLD_SLINT sld_search_linear_float_vector(struct sld_vector *vector, float search_criterion);

SLD_SLINT sld_search_linear_double_list(struct sld_list *list, double search_criterion);
SLD_SLINT sld_search_linear_double_map(struct sld_map *map, double search_criterion);
SLD_SLINT sld_search_linear_double_queue(struct sld_queue *queue, double search_criterion);
SLD_SLINT sld_search_linear_double_stack(struct sld_stack *stack, double search_criterion);
SLD_SLINT sld_search_linear_double_tree(struct sld_tree *tree, double search_criterion);
SLD_SLINT sld_search_linear_double_vector(struct sld_vector *vector, double search_criterion);

SLD_SLINT sld_search_linear_char_pointer_list(struct sld_list *list, char *search_criterion);
SLD_SLINT sld_search_linear_char_pointer_map(struct sld_map *map, char *search_criterion);
SLD_SLINT sld_search_linear_char_pointer_queue(struct sld_queue *queue, char *search_criterion);
SLD_SLINT sld_search_linear_char_pointer_stack(struct sld_stack *stack, char *search_criterion);
SLD_SLINT sld_search_linear_char_pointer_tree(struct sld_tree *tree, char *search_criterion);
SLD_SLINT sld_search_linear_char_pointer_vector(struct sld_vector *vector, char *search_criterion);

/*! @} */

#endif /* SEARCH_H */
