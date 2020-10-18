rm *.gcov
cd ../source/

echo "#define TipoPilha PilhaVetor" > TestaPilhaTipo.cpp
source ../source/make_and_test.sh > ../gcov/gtest.out
gcov PilhaVetor.cpp --object-file ../bin/obj/ | grep -A 3 "File 'PilhaVetor.cpp'" > ../gcov/gcov.out
mv PilhaVetor.cpp.gcov ../gcov/
rm *.gcov

echo "#define TipoPilha PilhaEncadeada" > TestaPilhaTipo.cpp
source ../source/make_and_test.sh >> ../gcov/gtest.out
gcov PilhaEncadeada.cpp --object-file ../bin/obj/ | grep -A 3 "File 'PilhaEncadeada.cpp'"  >> ../gcov/gcov.out
mv PilhaEncadeada.cpp.gcov ../gcov/
rm *.gcov