#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "Date.h"
#include "Address.h"
#include "Student.h"

void loadStudents(std::vector<Student*>&);
void printStudents(std::vector<Student*>&);
void showStudentNames(std::vector<Student*>&);
void findStudent(std::vector<Student*>&);
void delStudents(std::vector<Student*>&);
void menu();

std::vector<Student*> studentVector;
int studentNumber = 0;

int main(){
  loadStudents(studentVector);
  menu();
  delStudents(studentVector);
} // end main

void loadStudents(std::vector<Student*>& students){
  std::ifstream studentFile("students.csv");
  std::string currentLine;
  std::stringstream ss;
  int i = 0;

  while(std::getline(studentFile, currentLine)){
    i++;
    std::cout << "initializing student " << i << " .\n";
    Student* student = new Student();
    student->init(currentLine);
    students.push_back(student);
  } // end while
} // end loadStudents


void printStudents(std::vector<Student*>& students){
  for(int i = 0; i < students.size(); i++){
    std::cout << students[i]->getLastFirst();
  }
} // end printStudents

void showStudentNames(std::vector<Student*>& students){
  for(int i = 0; i < students.size(); i++){
    students[i]->printStudent();
  }
} // end showStudentNames

void findStudent(std::vector<Student*>& students){
  std::cout << "find Student Called" << std::endl;
} // end findStudent

void delStudents(std::vector<Student*>& students){
  for(int i = (students.size() - 1); i >= 0; i--){
    delete students[i];
  } // end for
} // end delStudents

void menu(){
  const std::string menuText = "0) Quit \n1) Print all Student Names\n2) Print all Student Data\n3) Find a Student\n";
  std::string input;
  bool keepGoing = true;

  while(keepGoing){
    input = "";
    std::cout << menuText; // prints the menu
    std::cin >> input;
    if(input == "0"){
      keepGoing = false;
    } // end if
    else if(input == "1"){
      printStudents(studentVector);
    } // end elseif
    else if(input == "2"){
      showStudentNames(studentVector);
    } // end elseif
    else if(input == "3"){
      findStudent(studentVector);
    } // end elseif
    else{
      std::cout << "Invalid Response.\n Please try again. \n";
    } // end else
  } // end while
} // end menu
