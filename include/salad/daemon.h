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

/*! @example daemon.c */

#ifndef DAEMON_H
#define DAEMON_H

#include <sys/types.h>

/*!
 * @brief Executes code contained in sld_daemon_start() as a background process using the specified options
 * @param pid_file_name path to PID (process ID) file
 * @param runas_user user account to run process as
 * @param runas_group group to run process as
 */
void sld_daemon_daemonize(char *pid_file_name, char *runas_user, char *runas_group);

/*!
 * @brief Wrap code within this function to execute it as a background process
 */
void sld_daemon_start();

/*!
 * @brief Writes the PID (process ID) to the specified file
 * @param pid_file_name path to PID (process ID) file
 * @return PID (process ID) of running process
 */
pid_t sld_daemon_write_pid_file(char *pid_file_name);

#endif /* DAEMON_H */
