#ifndef STUDENT_H
#define STUDENT_H

#include "Address.h"
#include "Date.h"

class Student{
  protected:
    std::string studentString;
    std::string firstName;
    std::string lastName;
    Address* studentAddress;
    Date* birthDate;
    Date* gradDate;
    int creditHours;

  public:
    Student();
    ~Student();
    void init(std::string studentString);
    void printStudent();
    std::string getLastFirst();
    std::string getFirstName();
    void setFirstName(std::string firstName);
    std::string getLastName();
    void setLastName(std::string lastName);
    int getCreditHours();
    void setCreditHours(int creditHours);
};

#endif