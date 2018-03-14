/*
 * =====================================================================================
 *
 *       Filename:  reader.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2011-12-08 13:13:07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  jiye (search engine group), jiye@taobao.com
 *        Company:  www.taobao.com
 *
 * =====================================================================================
 */


#include    <stdlib.h>
#include    <iostream>
#include    <fstream>
#include    "lm.helloworld.pb.h"

using namespace std;

void
ListMsg ( const lm::helloworld & msg )
{
    cout << msg.id() << endl;
    cout << msg.str() << endl;
	return ;
}		/* -----  end of function ListMsg  ----- */

int
main ( int argc, char *argv[] )
{
    lm::helloworld msg;
    fstream input ("log", ios::in | ios::binary);
    if (!msg.ParseFromIstream(&input)) {
        cerr << "Failed to parse input." << endl;
        return EXIT_FAILURE;
    }
    ListMsg(msg);
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
