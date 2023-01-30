/*
  * Tyler Du
  * 1/15/23
  * Linked List. Like student list but with nodes.
  */

#include <iostream>
#include <cstring>
#include "Student.h"
#include "Node.h"

using namespace std;

int main() {
  char name[20] = "";
  strcpy(name, "Tyler");
  Student* tyler = new Student(name);
  Node* node1 = new Node(tyler);

  strcpy(name, "Rahul");
  Student* rahul = new Student(name);
  Node* node2 = new Node(rahul);

  strcpy(name, "Armaan");
  Student* armaan = new Student(name);
  Node* node3 = new Node(armaan);
  
  node1->setNext(node2);
  node2->setNext(node3);
  node3->setNext(NULL);

  cout << node1->getStudent()->name << endl;
  cout << node1->getNext()->getStudent()->name << endl;
  cout << node2->getNext()->getStudent()->name << endl;
}