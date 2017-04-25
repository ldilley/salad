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

char *sld_string_allocate(char *string);
char *sld_string_chomp(char *string);
char *sld_string_chop(char *string);
char *sld_string_trim_leading(char *string);
char *sld_string_trim_trailing(char *string);
char *sld_string_trim(char *trim);
SLD_BOOL sld_string_contains_character(char *string, char character);
char *sld_string_capitalize(char *string);
char *sld_string_uncapitalize(char *string);
int sld_string_casecmp(char *string1, char *string2);
char *sld_string_multiply(char *string, int factor, char separator);
char *sld_string_reverse(char *string);

#endif /* STRING_H */
