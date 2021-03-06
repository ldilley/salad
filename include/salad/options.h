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

/*! @example options.c */

#ifndef OPTIONS_H
#define OPTIONS_H

#include "salad/map.h"
#include "salad/types.h"

/*!
 * @defgroup sld_options
 * Tbis module contains functions related to parsing configuration files.
 * @{
 */

/*!
 * @brief Parses the specified configuration file and stores the results in a sld_map
 * @param file_name a configuration file name to parse
 * @param options an initialized sld_map to populate with key/value pairs
 * @return Success or failure
 * @warning This function makes use of the sld_memory_pool. Be sure to periodically
 * check memory pool usage by calling sld_memory_pool_objects() and sld_memory_pool_size().
 * If necessary, call sld_memory_pool_free() or sld_memory_pool_nuke() to prevent memory
 * leaks.
 *
@code
sld_options_read("salad.cfg", &options);
@endcode
 */
SLD_SSINT sld_options_read(const char *file_name, struct sld_map *options);

/*! @} */

#endif /* OPTIONS_H */
