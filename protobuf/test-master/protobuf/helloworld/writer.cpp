/*
 * =====================================================================================
 *
 *       Filename:  writer.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2011-12-08 12:03:21
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


int
main ( int argc, char *argv[] )
{
    lm::helloworld msg;
    msg.set_id(1);
    msg.set_str("helloworld");

    fstream output ("log", ios::out | ios::trunc | ios::binary);

    if (!msg.SerializeToOstream(&output)) {
        cerr << "Failed to write message. " << endl;
        return EXIT_FAILURE;
    }

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
