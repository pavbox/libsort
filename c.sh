

#
# Welcome!
# Please, compile and start program instruction (for mac or linux).
# exec by terminal command:
# sh c.sh
#

# if you experienced user, you can use another compilation.
# for example:
# c++ test.cpp -o test -std=c++11 -stdlib=libc++


# compile sources to object files
g++ -c libsort.cpp -o libsort.o
g++ -c test.cpp -o test.o

# create shared library (.so)
g++ -shared -fPIC -o libsort.so libsort.o

# compile test cpp file.
g++ test.o libsort.o -o test

# ./test
