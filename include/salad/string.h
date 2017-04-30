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

#ifndef STRING_H
#define STRING_H

#include "salad/types.h"

/*!
 * @defgroup sld_string
 * This module contains functions related to string management.
 * @{
 */

/*!
 * @brief Allocates enough memory to store the specified string. You can then
 * call strcpy() using the returned heap space as a destination.
 * @param string a string
 * @return A pointer to a block of uninitialized memory large enough to contain
 * the passed string
 * @warning This function makes use of the sld_memory_pool. Be sure to periodically
 * check memory pool usage by calling sld_memory_pool_objects() and sld_memory_pool_size().
 * If necessary, call sld_memory_pool_free() or sld_memory_pool_nuke() to prevent memory
 * leaks.
 *
@code
sld_string_allocate("foo");
@endcode
 */
char *sld_string_allocate(char *string);

/*!
 * @brief Removes trailing "\r\n" characters on a passed string
 * @param string a string potentially containing a trailing "\r\n"
 * @return A new string free of trailing "\r\n" characters
 * @warning This function makes use of the sld_memory_pool. Be sure to periodically
 * check memory pool usage by calling sld_memory_pool_objects() and sld_memory_pool_size().
 * If necessary, call sld_memory_pool_free() or sld_memory_pool_nuke() to prevent memory
 * leaks.
 *
@code
char *new_string = sld_string_chomp("Hello!\r\n"); // returns "Hello!"
@endcode
 */
char *sld_string_chomp(char *string);

/*!
 * @brief Removes trailing "\r\n" characters on a passed string
 * or the last character if "\r\n" does not exist
 * @param string a string potentially containing a trailing "\r\n" or
 * containing a trailing character to be removed
 * @return A new string free of trailing "\r\n" characters or the last
 * character removed
 * @warning This function makes use of the sld_memory_pool. Be sure to periodically
 * check memory pool usage by calling sld_memory_pool_objects() and sld_memory_pool_size().
 * If necessary, call sld_memory_pool_free() or sld_memory_pool_nuke() to prevent memory
 * leaks.
 *
@code
char *new_string1 = sld_string_chop("Hello!\r\n"); // returns "Hello!"
char *new_string2 = sld_string_chop("Hello!");     // returns "Hello"
@endcode
 */
char *sld_string_chop(char *string);

/*!
 * @brief Removes leading whitespace from the passed string
 * @param string a string potentially containing leading whitespace
 * @return A new string free of leading whitespace
 * @warning This function makes use of the sld_memory_pool. Be sure to periodically
 * check memory pool usage by calling sld_memory_pool_objects() and sld_memory_pool_size().
 * If necessary, call sld_memory_pool_free() or sld_memory_pool_nuke() to prevent memory
 * leaks.
 *
@code
char *new_string = sld_string_trim_leading("   Hello!   "); // returns "Hello!   "
@endcode
 */
char *sld_string_trim_leading(char *string);

/*!
 * @brief Removes trailing whitespace from the passed string
 * @param string a string potentially containing trailing whitespace
 * @return A new string free of trailing whitespace
 * @warning This function makes use of the sld_memory_pool. Be sure to periodically
 * check memory pool usage by calling sld_memory_pool_objects() and sld_memory_pool_size().
 * If necessary, call sld_memory_pool_free() or sld_memory_pool_nuke() to prevent memory
 * leaks.
 *
@code
char *new_string = sld_string_trim_trailing("   Hello!   "); // returns "   Hello!"
@endcode
 */
char *sld_string_trim_trailing(char *string);

/*!
 * @brief Removes leading and trailing whitespace from the passed string
 * @param string a string potentially containing leading and trailing whitespace
 * @return A new string free of leading and trailing whitespace
 * @warning This function makes use of the sld_memory_pool. Be sure to periodically
 * check memory pool usage by calling sld_memory_pool_objects() and sld_memory_pool_size().
 * If necessary, call sld_memory_pool_free() or sld_memory_pool_nuke() to prevent memory
 * leaks.
 *
@code
char *new_string = sld_string_trim("   Hello!   ");  // returns "Hello!"
@endcode
 */
char *sld_string_trim(char *string);

/*!
 * @brief Checks whether or not a string contains a specified character
 * @param string a string potentially containing a specified character
 * @param character a character which possibly exists in the passed string
 * @return True or false
 *
@code
if(sld_string_contains_character("foo", 'f')) // returns true
  ...
@endcode
 */
SLD_BOOL sld_string_contains_character(char *string, char character);

/*!
 * @brief Capitalizes the specified string
 * @param string a string to be capitalized
 * @return A new capitalized string
 * @warning This function makes use of the sld_memory_pool. Be sure to periodically
 * check memory pool usage by calling sld_memory_pool_objects() and sld_memory_pool_size().
 * If necessary, call sld_memory_pool_free() or sld_memory_pool_nuke() to prevent memory
 * leaks.
 *
@code
char *new_string = sld_string_capitalize("foo"); // returns "FOO"
@endcode
 */
char *sld_string_capitalize(char *string);

/*!
 * @brief Uncapitalizes the specified string
 * @param string a string to be uncapitalized
 * @return A new uncapitalized string
 * @warning This function makes use of the sld_memory_pool. Be sure to periodically
 * check memory pool usage by calling sld_memory_pool_objects() and sld_memory_pool_size().
 * If necessary, call sld_memory_pool_free() or sld_memory_pool_nuke() to prevent memory
 * leaks.
 *
@code
char *new_string = sld_string_uncapitalize("FOO"); // returns "foo"
@endcode
 */
char *sld_string_uncapitalize(char *string);

/*!
 * @brief Compares two strings for equality regardless of capitalization
 * @param string1 a string
 * @param string2 a string
 * @return True or false
 * @warning This function makes use of the sld_memory_pool. Be sure to periodically
 * check memory pool usage by calling sld_memory_pool_objects() and sld_memory_pool_size().
 * If necessary, call sld_memory_pool_free() or sld_memory_pool_nuke() to prevent memory
 * leaks.
 *
@code
if(sld_string_casecmp("foo", "FOO")) // returns true
  ...
@endcode
 */
SLD_BOOL sld_string_casecmp(char *string1, char *string2);

/*!
 * @brief Multiplies a passed string by the specified factor and separated by
 * the specified character
 * @param string a string to repeat
 * @param factor an amount to repeat
 * @param separator character used to separate each string instance
 * @return A new string containing the original string repeated by the passed
 * factor and separated by separator
 * @warning This function makes use of the sld_memory_pool. Be sure to periodically
 * check memory pool usage by calling sld_memory_pool_objects() and sld_memory_pool_size().
 * If necessary, call sld_memory_pool_free() or sld_memory_pool_nuke() to prevent memory
 * leaks.
 *
@code
char *new_string = sld_string_multiply("foo", 2, ' '); // returns "foo foo"
@endcode
 */
char *sld_string_multiply(char *string, int factor, char separator);

/*!
 * @brief Reverses the passed string
 * @param string a string to reverse
 * @return A new string which is the reverse of the original string
 * @warning This function makes use of the sld_memory_pool. Be sure to periodically
 * check memory pool usage by calling sld_memory_pool_objects() and sld_memory_pool_size().
 * If necessary, call sld_memory_pool_free() or sld_memory_pool_nuke() to prevent memory
 * leaks.
 *
@code
char *new_string = sld_string_reverse("foo"); // returns "oof"
@endcode
 */
char *sld_string_reverse(char *string);

/*! @} */

#endif /* STRING_H */
