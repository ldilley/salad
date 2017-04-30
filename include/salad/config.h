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

/*!
 * @mainpage API
 * @section about_section About
 * Salad is a C library with an assortment of useful stuff.<br><br>
 * Visit the project on <a href="http://www.github.com/ldilley/salad">GitHub</a>.<br><br>
 * Salad is copyright &copy; 2016 by <a href="http://www.dilley.me/">Lloyd Dilley</a> under
 * the terms of the <a href="https://www.gnu.org/licenses/lgpl-3.0.txt">GNU LGPL 3</a>.
 */

#ifndef CONFIG_H
#define CONFIG_H

/*!
 * @defgroup sld_config
 * This module contains various macros related to configuration.
 * @{
 */

/*! Salad version */
#define VERSION 1.0.16

/*!
 * Defining EXIT_ON_FAILURE will cause Salad functions to become
 * more sensitive to failures which will more likely result in
 * termination of the program in the event such failures are
 * encountered. 
 */
#define EXIT_ON_FAILURE

#if __STDC_VERSION__ >= 199901L
/*! Defining C99 enables newer features. */
#define C99
#endif

/*! @} */

#endif /* CONFIG_H */
