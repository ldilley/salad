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

#include <errno.h>     /* errno */
#include <grp.h>       /* getgrnam() */
#include <pwd.h>       /* getpwnam() */
#include <stdio.h>     /* FILE, fclose(), fopen(), fprintf(), printf() */
#include <stdlib.h>    /* EXIT_FAILURE, exit() */
#include <string.h>    /* strerror() */
#include <sys/types.h> /* pid_t */
#include <unistd.h>    /* fork(), getpid(), setgid(), setuid() */

/* Local includes */
#include "salad/daemon.h"

void sld_daemon_daemonize(char *pid_file_name, char *runas_user, char *runas_group)
{
  struct passwd *pwent;
  struct group *grpent;

  pid_t pid = fork();
  if(pid >= 0)
  {
    if(pid == 0)
    {
      sld_daemon_write_pid_file(pid_file_name);
      if(runas_user != NULL)
      {
        if((pwent = getpwnam(runas_user)) == NULL)
        {
          printf("Unable to get user entry %s for setuid(): %s\n", runas_user, strerror(errno));
          exit(EXIT_FAILURE);
        }
        else
        {
          setuid(pwent->pw_uid);
        }
      }
      if(runas_group != NULL)
      {
        if((grpent = getgrnam(runas_group)) == NULL)
        {
          printf("Unable to get group entry %s for setgid(): %s\n", runas_group, strerror(errno));
          exit(EXIT_FAILURE);
        }
        else
        {
          setgid(grpent->gr_gid);
        }
      }
      sld_daemon_start();
    }
  }
  else
  {
    perror("fork() failed:");
  }

  return;
}

/* Writes a pid file to disk and returns the PID written to it */
pid_t sld_daemon_write_pid_file(char *pid_file_name)
{
  FILE *pid_file;

  pid_file = fopen(pid_file_name, "w");

  if(pid_file == NULL)
  {
    printf("Unable to open %s for writing: %s\n", pid_file_name, strerror(errno));
    exit(EXIT_FAILURE);
  }

  fprintf(pid_file, "%d\n", getpid());
  fclose(pid_file);

  return getpid();
}
