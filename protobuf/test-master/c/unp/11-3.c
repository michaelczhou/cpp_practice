/*
 * =====================================================================================
 *
 *       Filename:  11-3.c
 *
 *    Description:  gethostbyname
 *
 *        Version:  1.0
 *        Created:  2012-01-06 22:27:38
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
#include    <netdb.h>
#include    <arpa/inet.h>

int
main ( int argc, char *argv[] )
{
	char *ptr;
    char **pptr;
    char str[INET_ADDRSTRLEN];
    struct hostent *hptr;

    while (--argc > 0) {
        ptr = *++argv;
        hptr = gethostbyname(ptr);
        if (hptr == NULL) {
            fprintf (stderr, "gethostbyname error: %s, %s\n", ptr, hstrerror(h_errno));
            exit (1);
        }

        fprintf (stdout, "canonical name: %s\n", hptr->h_name);
        for (pptr = hptr->h_aliases; *pptr != NULL; pptr++) {
            fprintf (stdout, "alias: %s\n", *pptr);
        }

        switch (hptr->h_addrtype) {
            case AF_INET:
                for (pptr = hptr->h_addr_list; *pptr != NULL; pptr++) {
                    fprintf (stdout, "address: %s\n", 
                            inet_ntop(AF_INET, *pptr, str, sizeof(str)));
                }
                break;
            default: 
                fprintf (stderr, "hostent addr type error\n");
                exit (1);
        }
    }

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

