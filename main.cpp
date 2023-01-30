//Rahul Iyer
//node but with student list adding, deleting, printing, averaging the gpas in a node list.
//per 7
//thank you armaan for help with delete function

#include <iostream>
#include <cstring>
#include <cstdio>
#include "Student.h"
#include "Node.h"

using namespace std;

//function prototype
void add(Node* head, Node* newNode);
void print(Node* head);
void average(float total, int students, Node* head);
void deleteFunc(int id, Node* head);


int main() {
  Node* head = NULL;
  char input[10];
  bool running = true;

  // runs the code until quit
  while (running == true) {
    cout << "" << endl;
    cout << "Enter 'add' to add a student, enter 'delete' to delete a student, enter 'print' to print all students, enter average to average all the gpas, or enter 'quit' to quit the program" << endl;

    cin.get(input, 10);
    cin.ignore(1, '\n');

    if (strcmp(input, "add") == 0) { // adds student to node
      char firstName[20];
      char lastName[20];
      int studentID = 0;
      float gpa = 0.0;
      Student* newStudent = new Student(firstName, lastName, studentID, gpa);
      
      // read in first name and set
      cout << "First Name: " << endl;
      cin.get(firstName, 20);
      cin.ignore(1, '\n');
      newStudent->set_first_name(firstName);

      // read in last name and set
      cout << "Last Name: " << endl;
      cin.get(lastName, 20);
      cin.ignore(1, '\n');
      newStudent->set_last_name(lastName);

      // read in student id and set
      cout << "Student ID: " << endl;
      cin >> studentID;
      cin.ignore();
      newStudent->set_id(studentID);

      // read in gpa and set
      cout << "GPA: " << endl;
      cin >> gpa;
      cin.ignore();
      newStudent->set_gpa(gpa);

      Node* node1 = new Node(newStudent);

      if (head == NULL) { // if no node in list set to first
        head = node1;
        node1->setNext(NULL);
      }
      else if (node1->getStudent()->getId() < head->getStudent()->getId()) { // if node smaller than head node goes first
        node1->setNext(head);
        head = node1;
      }
      else {
        add(head, node1);
      }
    }
    else if (strcmp(input, "print") == 0) { // all students are printed from first to last
      print(head);
    }
    else if (strcmp(input, "average") == 0) { // averages gpas
      float total = 0.0;
      int students = 0;

      // add gpa to head
      total += head->getStudent()->getGpa(); 
      students++;
      average(total, students, head);
    }
    else if (strcmp(input, "delete") == 0) { // deletes a student
      int id;

      // read in id
      cout << "who do you want to delete" << endl;
      cin >> id;
      cin.ignore(1, '\n');

      deleteFunc(id, head);
    }
    else if (strcmp(input, "quit") == 0) { // quit program
      cout << "quit" << endl;
      running = false;
    }
    else {
      cout << "enter again" << endl;
    }
  }  
  return 0;
}
  
void add(Node* head, Node* newNode) {
  if (head->getNext() != NULL) { // if reached the end of the node list
    if (newNode->getStudent()->getId() >= head->getNext()->getStudent()->getId()) { // id > head id
      head = head->getNext();
      add(head, newNode);
    }
    else { // id < head id
      Node* temp = head->getNext();
      head->setNext(newNode);
      newNode->setNext(temp);
    }
  }
  else { // reached end of list
    head->setNext(newNode);
    newNode->setNext(NULL);
  }
}

// prints all students
void print(Node* head) {
  Node* current = head;
  if (current != NULL) { //stops print when reaches end of node list
    cout << "" << endl;
    cout << "First Name: " << current->getStudent()->getFirstName() << endl;
    cout << "Last Name: " << current->getStudent()->getLastName() << endl;
    cout << "Student ID: " << current->getStudent()->getId() << endl;
    cout << "GPA: " << current->getStudent()->getGpa() << endl;
    current = current->getNext(); // continues to the last node
    print(current);
  }
}

// avg of all gpas
void average(float total, int students, Node* head) {
  if (head->getNext() != NULL) { // adds all gpas together
    head = head->getNext();
    total = total + head->getStudent()->getGpa();
    students++;
    average(total, students, head);
  }
  else { // round to 2 decimal places when printing
    float gpaAvg = total / students;
    cout << "Average: " << printf("%.2f", gpaAvg) << endl;
  }
}

void deleteFunc(int id, Node* head) {
  bool deleted = false;
  if (id == head->getStudent()->getId()) { // delete node setting id to chose id
    Node* temp = head;
    head = head->getNext();
    delete temp;
    deleted = true;
    cout << "deleted!" << endl;
  }
  else if (id == head->getNext()->getStudent()->getId()) { 
    Node* temp = head->getNext();
    head->setNext(head->getNext()->getNext());
    delete temp;
    deleted = true;
    cout << "deleted!" << endl;
  }
  else { // not equal to node in the list
    head = head->getNext();
    deleteFunc(id, head);
  }

  if (deleted == false) { // not found
    cout << "student not found" << endl;
  }
}