/*
 * =====================================================================================
 *
 *       Filename:  print_every_5s.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2011-12-12 10:23:03
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

int
main ( int argc, char *argv[] )
{
    FILE * fp = fopen ( "log", "r");
    if (! fp) {
        fprintf (stderr, "Failed to read file.\n");
        return EXIT_FAILURE;
    }
    setbuf(fp, NULL);
    char buf[100];
    while (1) {
        rewind(fp);
        fgets (buf, sizeof(buf), fp);
        fprintf (stdout, "%s\n", buf);
        sleep (2);
    }

    fclose(fp);
        
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
