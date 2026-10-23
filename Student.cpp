#include <iostream>
#include <string>
#include <sstream>
#include "Student.h"
#include "Address.h"
#include "Date.h"

Student::Student(){
  studentString = "Arthur,Pendragon,000 Avalon Lane,Camelot,ENGLAND,77777,01/01/1100,04/03/1975,255";
  firstName = "Caradoc";
  lastName = "Vreichvras";
  studentAddress = new Address();
  birthDate = new Date();
  gradDate = new Date();
} // end Student constructor

Student::~Student(){
  delete studentAddress;
  delete birthDate;
  delete gradDate;
} // end Student Destructor

void Student::init(std::string studentString){
  std::stringstream ss;
  std::string street;
  std::string city;
  std::string state;
  std::string zip;
  std::string sBirth;
  std::string sGrad;
  std::string sCredits;
  Student::studentString = studentString;
  
  ss.clear();
  ss.str("");
  ss.str(studentString);
  getline(ss, firstName, ',');
  getline(ss, lastName, ',');
  getline(ss, street, ',');
  getline(ss, city, ',');
  getline(ss, state, ',');
  getline(ss, zip, ',');
  studentAddress->init(street, city, state, zip);
  getline(ss, sBirth, ',');
  birthDate->init(sBirth);
  getline(ss, sGrad, ',');
  gradDate->init(sGrad);
  getline(ss, sCredits, '\n');
  ss.clear();
  ss.str("");
  ss << sCredits;
  ss >> creditHours;
} // end init

void Student::printStudent(){
  std::cout << firstName << " " << lastName << '\n';
  studentAddress->printAddress();
  std::cout << "DOB: ";
  birthDate->printDate();
  std::cout << "Grad: ";
  gradDate->printDate();
  std::cout << "Credits: " << creditHours << std::endl;
  std::cout << "____________________________________\n";
} // end printStudent

std::string Student::getLastFirst(){
  return lastName + ", " + firstName + '\n';
} // end getLastFirst

std::string Student::getFirstName(){
  return firstName;
} // end getFirstName

void Student::setFirstName(std::string firstName){
  Student::firstName = firstName;
} // end setFirstName
    
std::string Student::getLastName(){
  return lastName;
} // end getLastName
    
void Student::setLastName(std::string lastName){
  Student::lastName = lastName;
} // end setLastName
    
int Student::getCreditHours(){
  return creditHours;
} // end getCreditHours
    
void Student::setCreditHours(int creditHours){
  Student::creditHours = creditHours;
} // end setCreditHours
