#include <iostream>
#include "Student.h"
#include <cstring>

using namespace std;

Student::Student(char* newname) {
  name = new char[20];
  strcpy(name, newname);
}

char* Student::getName() {
  return name;
}

Student::~Student() {
  delete name;
}