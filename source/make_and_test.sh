mkdir ../bin &>/dev/null
mkdir ../bin/obj &>/dev/null

make cleanTest
make
../bin/TestaPilha
