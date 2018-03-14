#include "zc.helloworld.pb.h"
#include <fstream>
#include <iostream>

using namespace std;

void ListMsg(const protobuf::helloworld & msg)
{
	cout << msg.id() << endl;
	cout << msg.str() << endl;
}

int writer()
{
	protobuf::helloworld msg1;
	msg1.set_id(101);
	msg1.set_str("hello");
	fstream output("./log.txt", ios::out | ios::trunc | ios::binary);
	if (!msg1.SerializeToOstream(&output))
	{
		cerr << "Failed to write msg." << endl;
		return -1;
	}
	return 0;
}

int reader()
{
	protobuf::helloworld msg1;
	fstream input("./log.txt", ios::in | ios::binary);
	if (!msg1.ParseFromIstream(&input))
	{
		cerr << "Failed to parse address book." << endl;
		return -1;
	}
	ListMsg(msg1);
	return 0;
}

int main(void)
{
	writer();
	reader();
}
