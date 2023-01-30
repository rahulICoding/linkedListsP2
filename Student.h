#pragma once
#include <iostream>

using namespace std;

class Student {
  public:
  Student(char*);
  char * getName();
  ~Student();

  char* name = new char[20];
};