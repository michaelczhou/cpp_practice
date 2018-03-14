/*
 * =====================================================================================
 *
 *       Filename:  writer.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2011-12-08 20:20:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  jiye (search engine group), jiye@taobao.com
 *        Company:  www.taobao.com
 *
 * =====================================================================================
 */


#include    <stdlib.h>
#include    <fstream>
#include    <iostream>
#include    "lm.person.pb.h"

using namespace std;
using namespace lm;

int
main ( int argc, char *argv[] )
{
    Person jiye;
    jiye.set_name("jiye");
    jiye.set_id (29886);
    jiye.set_email ("jiye@taobao.com");
    PhoneNumber * pphone = jiye.add_phone();
    pphone->set_number("1588887712");
    pphone->set_type(PhoneNumber::WORK);

    pphone = jiye.add_phone();
    pphone->set_number("1588887713");
    pphone->set_type(PhoneNumber::HOME);

    fstream output ("log", ios::out | ios::binary | ios::trunc);
    if (! jiye.SerializeToOstream(&output)) {
        cerr << "Failed." << endl;
        return EXIT_FAILURE;
    }
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
