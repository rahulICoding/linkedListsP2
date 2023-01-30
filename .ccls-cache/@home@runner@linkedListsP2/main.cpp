
#include <iostream>
#include <cstring>
#include <cstdio>
#include "Student.h"
#include "Node.h"

using namespace std;

void add(Node* head, Node* newNode);
void print(Node* head);

int main() {
  Node* head = NULL;
  char input[10];
  bool running = true;

  // main code, running will stay true until user says "QUIT"
  while (running == true) {
    cout << "" << endl;
    cout << "Enter 'add' to add a student, enter 'delete' to delete a student, enter 'print' to print all students, enter average to average all the gpas, or enter 'quit' to quit the program" << endl;

    cin.get(input, 10);
    cin.ignore(1, '\n');

    if (strcmp(input, "add") == 0) { // adds student
      char firstName[20];
      char lastName[20];
      int studentID = 0;
      float gpa = 0.0;
      Student* newStudent = new Student(firstName, lastName, studentID, gpa);
      
      // read in first name
      cout << "First Name: " << endl;
      cin.get(firstName, 20);
      cin.ignore(1, '\n');
      newStudent->set_first_name(firstName);

      // read in last name
      cout << "Last Name: " << endl;
      cin.get(lastName, 20);
      cin.ignore(1, '\n');
      newStudent->set_last_name(lastName);

      // read in student id
      cout << "Student ID: " << endl;
      cin >> studentID;
      cin.ignore();
      newStudent->set_id(studentID);

      // read in gpa
      cout << "GPA: " << endl;
      cin >> gpa;
      cin.ignore();
      newStudent->set_gpa(gpa);

      Node* node1 = new Node(newStudent);

      if (head == NULL) { // no nodes already in list
        head = node1;
        node1->setNext(NULL);
      }
      else if (node1->getStudent()->getId() < head->getStudent()->getId()) { // new node is smaller than head
        node1->setNext(head);
        head = node1;
      }
      else {
        add(head, node1);
      }
    }
    else if (strcmp(input, "print") == 0) { // prints all students inputted
      print(head);
    }
    else if (input[0] == 'Q' || input[0] == 'q') { // ends program
      cout << "Thank You For Using the Student List Maker!" << endl;
      running = false;
    }
    else {
      cout << "Not Sure What You're Trying To Do" << endl;
    }
  }  
  return 0;
}
  
// adds new student
void add(Node* head, Node* newNode) {
  if (head->getNext() != NULL) { // if not at end of list
    if (newNode->getStudent()->getId() >= head->getNext()->getStudent()->getId()) { // if id of new node is greater than or equal to id of the current node
      head = head->getNext();
      add(head, newNode);
    }
    else { // if id of new node is less than id of the current node
      Node* temp = head->getNext();
      head->setNext(newNode);
      newNode->setNext(temp);
    }
  }
  else { // at end of list
    head->setNext(newNode);
    newNode->setNext(NULL);
  }
}

// prints all students on seperate lines until there is no more printing to be done
void print(Node* head) {
  Node* current = head;
  if (current != NULL) { //stops print when current == null
    cout << "" << endl;
    cout << "First Name: " << current->getStudent()->getFirstName() << endl;
    cout << "Last Name: " << current->getStudent()->getLastName() << endl;
    cout << "Student ID: " << current->getStudent()->getId() << endl;
    cout << "GPA: " << current->getStudent()->getGpa() << endl;
    current = current->getNext(); ///goes to next node
    print(current);
  }
}

