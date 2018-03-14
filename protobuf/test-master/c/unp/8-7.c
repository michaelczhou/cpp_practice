/*
 * =====================================================================================
 *
 *       Filename:  8-7.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012-01-05 23:10:04
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
#include    <arpa/inet.h>
#include    <strings.h>
#define SERVER_PORT 6677
#define MAXLINE 1024

typedef struct sockaddr SA;

void
dg_cli (FILE * fp, int sockfd, const SA * pserver_addr, socklen_t len)
{
    int n;
    char sendline[MAXLINE];
    char recvline[MAXLINE];
    while (fgets(sendline, MAXLINE, fp) != NULL) {
        sendto(sockfd, sendline, strlen(sendline), 0, pserver_addr, len);
        n = recvfrom(sockfd, recvline, MAXLINE, 0, NULL, NULL);
        recvline[n] = 0;
        fputs (recvline, stdout);
    }
    return;
}

int
main ( int argc, char *argv[] )
{
	int sockfd;
    struct sockaddr_in server_addr;

    if (argc != 2) {
        fprintf (stderr, "Usage: %s <ip>\n", argv[0]);
        exit (1);
    }

    bzero (&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons (SERVER_PORT);
    inet_pton (AF_INET, argv[1], &server_addr.sin_addr);

    sockfd = socket (AF_INET, SOCK_DGRAM, 0);
    dg_cli (stdin, sockfd, (SA *) &server_addr, sizeof(server_addr));

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
