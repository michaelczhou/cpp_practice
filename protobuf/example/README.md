example1:
>protoc addressbook.proto --cpp_out=./
g++ add_person.cc addressbook.pb.cc `pkg-config --cflags --libs protobuf`
./a.out pb.txt
g++ list_people.cc addressbook.pb.cc `pkg-config --cflags --libs protobuf`
./a.out pb.txt

example2:
protoc test.proto --cpp_out=./

