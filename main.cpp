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
void sortMenu();

std::vector<Student*> studentVector;
int studentNumber = 0;

int main(){
  loadStudents(studentVector);
  menu();
  delStudents(studentVector);
  studentVector.clear();
} // end main

void loadStudents(std::vector<Student*>& students){
  std::ifstream studentFile("students.csv");
  std::string currentLine;
  std::stringstream ss;
  // int i = 0;

  while(std::getline(studentFile, currentLine)){
    // i++;
    // std::cout << "initializing student " << i << " .\n";
    Student* student = new Student();
    student->init(currentLine);
    students.push_back(student);
  } // end while
} // end loadStudents

void printStudents(std::vector<Student*>& students){
  for(int i = 0; i < students.size(); i++){
    students[i]->printStudent();
  }
} // end printStudents

void showStudentNames(std::vector<Student*>& students){
  for(int i = 0; i < students.size(); i++){
    std::cout << students[i]->getLastFirst();
  }
} // end showStudentNames

void findStudent(std::vector<Student*>& students){
  std::vector<Student*> searchTrue;
  std::string searchTerm;
  std::string studentName;
  
  std::cout << "Last name of Student: ";
  std::cin >> searchTerm;

  for(int i = 0; i < students.size(); i++){
    studentName = "";
    studentName = students[i]->getLastName();
    int check = studentName.find(searchTerm);
    if(check != std::string::npos){
      searchTrue.push_back(students[i]);
    }
  }
  if(searchTrue.size() > 0){
    printStudents(searchTrue);
    searchTrue.clear();
  }
  else{
    std::cout << "Student not Found." << std::endl;
  }
}

void delStudents(std::vector<Student*>& students){
  for(int i = (students.size() - 1); i >= 0; i--){
    delete students[i];
  } // end for
} // end delStudents

void menu(){
  const std::string menuText = "0) Quit \n1) Print all Student Names\n2) Print all Student Data\n3) Find a Student\n4) Sort the File\n";
  const std::string sortMenuText = "0) Quit \n1) Sort by Last Name\n2) Sort by First Name\n3) Sort by Credit Hour\n";
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
      showStudentNames(studentVector);
    } // end elseif
    else if(input == "2"){
      printStudents(studentVector);
    } // end elseif
    else if(input == "3"){
      findStudent(studentVector);
    } // end elseif
    else if(input == "4"){ // This submenu is incredibly clunky, but functional. Perhaps could be split into its own function
      sortMenu();
    } // end elseif
    else{
      std::cout << "Invalid Response.\n Please try again. \n";
    } // end else
  } // end while
} // end menu

void sortMenu(){
  const std::string menuText = "0) Quit \n1) Sort by Last Name\n2) Sort by First Name\n3) Sort by Credit Hour\n";
  std::string input;
  bool keepGoing = true;

  while(keepGoing){
    input = "";
    std::cout << sortMenuText;
    std::cin >> input;
    if(input == "0"){
    keepGoing = false;
    } // end if
    else if(input == "1"){
      showStudentNames(studentVector);
    } // end elseif
    else if(input == "2"){
      printStudents(studentVector);
    } // end elseif
    else if(input == "3"){
      findStudent(studentVector);
    } // end elseif
    else{
      std::cout << "Invalid Response.\n Please try again. \n";
    } // end else
  } // end while
} // end sortMenu
