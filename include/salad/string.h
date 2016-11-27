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

#ifndef STRING_H
#define STRING_H

#include "salad/types.h"

char *sld_allocate_string(char *string);
char *sld_chomp(char *string);
char *sld_chop(char *string);
char *sld_trim_leading(char *string);
char *sld_trim_trailing(char *string);
char *sld_trim(char *trim);
SLD_BOOL sld_string_contains_character(char *string, char character);
char *sld_capitalize(char *string);
char *sld_uncapitalize(char *string);
int sld_casecmp(char *string1, char *string2);
char *sld_multiply_string(char *string, int factor, char separator);
char *sld_reverse(char *string);

#endif /* STRING_H */
