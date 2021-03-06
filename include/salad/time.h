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

#ifndef TIME_H
#define TIME_H

#include <time.h>

/*!
 * @defgroup sld_time
 * This module contains functions related to dates and times.
 * @{
 */

/*! A time structure */
struct tm *timedata;

/*!
 * @brief Returns the time in seconds since the epoch (01/01/1970 @ 00:00:00 UTC)
 * @return Time in seconds since the epoch (01/01/1970 @ 00:00:00 UTC)
 *
@code
printf("There have been %ld seconds since the epoch.\n", sld_time_epoch_seconds());
@endcode
 */
time_t sld_time_epoch_seconds();

/*!
 * @brief Returns a pretty timestamp in the format: Wed Apr 19 21:27:08 2017
 * @return A pretty timestamp in the format: Wed Apr 19 21:27:08 2017
 *
@code
puts(sld_time_pretty_timestamp());
@endcode
 */
char *sld_time_pretty_timestamp();

/*! @} */

#endif /* TIME_H */
