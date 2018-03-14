/*
 * =====================================================================================
 *
 *       Filename:  print_by_map.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2011-12-12 11:01:00
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
    void * addr;
    addr = mmap (NULL, 100, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED) {
        fprintf (stderr, "Fail to mmap.\n");
        close (fd);
        return EXIT_FAILURE;
    }
    char * buf = (char *) addr;

    while (1) {
        fprintf (stdout, "%s\n", buf);
        sleep (2);
    }

    close (fd);
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
