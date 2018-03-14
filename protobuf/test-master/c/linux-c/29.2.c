/*
 * =====================================================================================
 *
 *       Filename:  29.2.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2011-12-31 15:05:07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  jiye (search engine group), jiye@taobao.com
 *        Company:  www.taobao.com
 *
 * =====================================================================================
 */


#include    <stdlib.h>
#include    <stdio.h>
#include    <fcntl.h>
#include    <unistd.h>
#include    <string.h>
#include    <sys/stat.h>

int
main ( int argc, char *argv[] )
{
	int fd;
    int save_fd;

    char msg [] = "this is test\n";
    fd = open ("somefile", O_RDWR|O_CREAT, S_IRUSR|S_IWUSR);
    if (fd < 0) {
        perror ("open");
        exit (1);
    }

    save_fd = dup(1);
    dup2 (fd, 1); //close(1) first
    close (fd);
    write (1, msg, strlen(msg));

    dup2(save_fd, 1); //close (1) first
    close(save_fd);
    write (1, msg, strlen(msg));
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
