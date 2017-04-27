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

#ifndef TYPES_H
#define TYPES_H

/*! A zero value is false */
#define SLD_FALSE 0

/*! A non-zero value is true */
#define SLD_TRUE !(SLD_FALSE)

/*! A zero return value is a success */
#define RETURN_SUCCESS 0

/*! A -1 return value is a failure */
#define RETURN_FAILURE -1

/*! An unsigned char is 1 byte */
typedef unsigned char SLD_BYTE;

/*! SLD_SSINT is a signed short */
typedef signed short int SLD_SSINT;

/*! SLD_USINT is an unsigned short */
typedef unsigned short int SLD_USINT;

/*! SLD_SINT is a signed int */
typedef signed int SLD_SINT;

/*! SLD_UINT is an unsigned int */
typedef unsigned int SLD_UINT;

/*! SLD_SLINT is a signed long */
typedef signed long int SLD_SLINT;

/*! SLD_ULINT is an unsigned long */
typedef unsigned long int SLD_ULINT;

/*! SLD_BOOL is an unsigned short */
typedef SLD_USINT SLD_BOOL;

#endif /* TYPES_H */
