/*
 * =====================================================================================
 *
 *       Filename:  29.1.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2011-12-28 21:16:50
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
#include    <sys/types.h>
#include    <sys/stat.h>
#include    <string.h>
#include    <dirent.h>
#include    <unistd.h>

#define MAX_PATH    1024

void fsize (char *name);
void dirwalk (char *, void (*fcn) (char *));

int
main ( int argc, char *argv[] )
{
	if ( argc == 1 ) {
        fsize (".");
    } else {
        while (--argc > 0)
            fsize (*++argv);
    }

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

void
fsize ( char * name )
{
    struct stat stbuf;
    if (stat(name, &stbuf) == -1) {
        fprintf (stderr, "fsize: can't access %s\n", name);
        return;
    }
    if ((stbuf.st_mode & S_IFMT) == S_IFDIR) {
        dirwalk (name, fsize);
    }
    fprintf (stdout, "%8ld %s\n", stbuf.st_size, name);
	return ;
}		/* -----  end of function fsize  ----- */


void
dirwalk ( char *dir, void (*fcn)(char*) )
{
    char name [MAX_PATH];
    struct dirent *dp;
    DIR *dfd;
    if((dfd = opendir(dir)) == NULL) {
        fprintf (stderr, "dirwalk: can't open %s\n", dir);
        return ;
    }
    while ((dp = readdir(dfd)) != NULL) {
        if (strcmp(dp->d_name, ".") ==0 || strcmp (dp->d_name, "..") == 0)
            continue;
        if (strlen(dir) + strlen(dp->d_name) + 2 > sizeof(name)) {
            fprintf (stderr, "dirwalk: name %s %s too long\n", dir, dp->d_name);
        } else {
            snprintf (name, MAX_PATH, "%s/%s", dir, dp->d_name);
            (*fcn) (name);
        }
    }
    closedir(dfd);
	return ;
}		/* -----  end of function dirwalk  ----- */
