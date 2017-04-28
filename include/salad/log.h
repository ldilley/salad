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

/*! @example log.c */

#ifndef LOG_H
#define LOG_H

#include "salad/types.h"

/*!
 * @defgroup sld_log
 * This module contains enums and functions related to logging.
 * @{
 */

/*! Contains constants for log severity */
typedef enum { DBUG = 0, INFO = 1, WARN = 2, CRIT = 3 } sld_log_severity;

/*!
 * @brief Writes the specified text to the provided log file with the given severity
 * @param file_name log file name
 * @param severity log severity
 * @param text text entry for log
 * @return Success or failure
@code
sld_log_write("salad.log", INFO, "This is only a test.");
@endcode
 */
SLD_SSINT sld_log_write(const char *file_name, sld_log_severity severity, const char *text);

/*! @} */

#endif /* LOG_H */
