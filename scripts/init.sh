#!/bin/bash
# CREATE PROJECT TEMPLATE

# create root project folder
mkdir $1 
cd $1 

# make all neccesary dirs
mkdir build 
mkdir cmake-build 
mkdir includes
mkdir src 
mkdir test 

SRC_C=$1.c
INC_H=$1.h
TST_C=test_$1.cpp

# make all neccesary src n test files
touch "src/$SRC_C"
touch "includes/$INC_H"
touch "test/$TST_C"

# copy and modify CMAKE file for project
cp ../scripts/CMakeLists.txt . 
sed -i -e "s/_PR/$1/" CMakeLists.txt # project name
sed -i -e "s/_SF1/$SRC_C/" CMakeLists.txt # src c file
sed -i -e "s/_SF2/$INC_H/" CMakeLists.txt # header file
sed -i -e "s/_TF/$TST_C/" CMakeLists.txt # gtest file

#modify header
UPPER=${INC_H^^}
UPPER=${UPPER/./"_"}
echo "#ifndef $UPPER" >> includes/$INC_H 
sed -i "1a #define $UPPER\n\n#include <stdio.h>\n\n#endif" includes/$INC_H

#modify c file 
echo "#include \"../includes/$INC_H\"" >> src/$SRC_C
echo "" >> src/$SRC_C 
sed -i '2a int main(int argc, char* argv[]) { \n \n}' src/$SRC_C

#modify gtest file
echo "#include <gtest/gtest.h>" >> test/$TST_C
echo "" >> test/$TST_C
sed -i "2a extern \"C\" {\n  #include \"../includes/$INC_H\"\n}\n\nTEST(func, name) {\n\n}" test/$TST_C