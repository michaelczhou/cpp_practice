/*
 * =====================================================================================
 *
 *       Filename:  print_by_open.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2011-12-12 11:17:53
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
#include    <unistd.h>
#include    <sys/mman.h>
#include    <sys/types.h>
#include    <sys/stat.h>
#include    <fcntl.h>

int
main ( int argc, char *argv[] )
{
    int fd;
    fd = open("log", O_RDWR);
    if (fd == -1) {
        fprintf (stderr, "Fail to open file\n");
        return EXIT_FAILURE;
    }
    char buf[100];
    int read_byte;


    while (1) {
        lseek (fd, 0, SEEK_SET);
        read_byte = read (fd, buf, 100);
        if (read_byte == -1)
        {
            fprintf (stderr, "Fail to read file\n");
            close (fd);
            return EXIT_FAILURE;
        }
        buf[read_byte] = '\0';
        fprintf (stdout, "%s\n", buf);
        sleep (2);
    }

    close (fd);
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
