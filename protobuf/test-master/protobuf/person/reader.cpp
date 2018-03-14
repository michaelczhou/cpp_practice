/*
 * =====================================================================================
 *
 *       Filename:  reader.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2011-12-08 21:08:36
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
#include    "lm.person.pb.h"

using namespace std;
using namespace lm;

void
ListPerson (const Person & person)
{
    cout << "name: " << person.name() << endl;
    cout  << "id: " << person.id() << endl;
    if (person.has_email())
        cout << "email: " << person.email() << endl;
    else
        cout << "no email: " << person.email() << endl;
    for (int i=0; i<person.phone_size(); i++) {
        cout << "phone number: " << person.phone(i).number() << endl;
        if (person.phone(i).has_type()) 
            cout << "phone type: " << person.phone(i).type() << endl;
        else
            cout << "no phone type: " << person.phone(i).type() << endl;
    }


	return ;
}		/* -----  end of function ListPerson  ----- */

int
main ( int argc, char *argv[] )
{
    Person person;
    fstream input ("log", ios::binary | ios::in );
    int ret;
    ret = person.ParseFromIstream(&input);
    if (!ret)  {
        cerr << "Failed to Parse." << endl;
        return EXIT_FAILURE;
    }
	ListPerson (person);
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

