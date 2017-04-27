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

#ifndef NETWORK_H
#define NETWORK_H

#include "salad/types.h"

/*!
 * @brief Connects to a destination host on the specified port
 * @param host the destination hostname
 * @param port the destination port number
 * @return Success or failure
 */
SLD_SSINT sld_network_connect(char *host, SLD_USINT port);

/*!
 * @brief Terminates a connection
 * @return Success or failure
 */
SLD_SSINT sld_network_disconnect();

/*!
 * @brief Receives data from a network connection
 * @return Size of data received in bytes
 */
SLD_ULINT sld_network_receive();

/*!
 * @brief Sends data to a destination host
 * @param packet bytes to send
 * @return Size of data sent in bytes
 */
SLD_ULINT sld_network_send(char *packet);

#endif /* NETWORK_H */
