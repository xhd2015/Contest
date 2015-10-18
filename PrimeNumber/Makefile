
;makefile 
;deFactors.record
;getFactors.cpp
;getFactors.h
;main.cpp
;main.exe
;main_testGetFactors.cpp
;read.record
;readme.md

main_testGetFactors.exe:libgetFactors.a main_testGetFactors.o
	g++ -o main_testGetFactors.exe  main_testGetFactors.o -L . -lgetFactors -std=c++11
libgetFactors.a:getFactors.o
	ar cr libgetFactors.a getFactors.o
main_testGetFactors.o:
	g++ main_testGetFactors.cpp -c -std=c++11
getFactors.o:
	g++ -c getFactors.cpp-std=c++11
