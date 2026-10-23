# Heap of Students
### CS121 Stanfield

## Student Class
```
  # studentString : string
  # firstName : string
  # lastName : string
  # studentAddress : Address*
  # birthDate : Date*
  # gradDate : Date*
  # creditHours : int

  + Student()
  + ~Student()
  + void init(studentString)
  + void printStudent()
  + string getLastFirst()
  + string getFirstName()
  + void setFirstName(firstName : string)
  + string getLastName()
  + void setLastName(lastName : string)
  + int getCreditHours()
  + void setCreditHours(creditHours : int)
```

## Address Class
```
  # street : string
  # city : string
  # state : string
  # zip : string

  + Address()
  + void init(street : string, city : string, state : string, zip : string)
  + void printAddress()
  + string getStreet()
  + void setStreet(street : string)
  + string getCity()
  + void setCity(city : string)
  + string getState()
  + void setState(state : string)
  + string getZip()
  + void setZip(zip : string)
```

## Date Class
```
  # dateString : string
  # day : int
  # month : int
  # year : int
  # const WORDMONTH[12] : const string[12]

  + Date()
  + void init(dateString : string)
  + void printDate()
  + void printDateAlternate()
  + string getDateString()
  + void setDateString(dateString : string)
  + int getDay()
  + void setDay(day : int)
  + int getMonth()
  + void setMonth(month : int)
  + int getYear()
  + void setYear(year : int)
```

## Main.cpp
```
import libraries (iostream fstream string sstream)

create a vector of student pointers

void loadStudents(std::vector<Student*>&){
  open students.csv in with ifstream students
  temp string currentLine
  stringstream ss
  
  while(getline(students, currentLine)){
  new student on the heap, 
  initialize new student with current line
  push the student to the end of the stack
}  


void printStudents(std::vector<Student*>&){
  for each student in the vector
    call the print statement from the student class
  
}

void showStudentNames(std::vector<Student*>&){
  for each student in the vector
    call getLastFirst and getCreditHours
}

void findStudent(std::vector<Student*>&){
  create a new vector searchTrue
  create a new string searchTerm
  create a new string studentName
  
  cout << "Last name of Student: ";
  cin >> searchTerm;

  for each student in the main vector{
    studentName = "";
    studentName = students[i]->getLastName();
    int check = studentName.find(searchTerm);
    if(check is not no position){
      push the current student into searchTrue
    } 
  if(searchTrue.size() > 0){
  call printStudents(searchTrue);
  }
  else{
    cout << "student not found" << endl;
  }
}

void delStudents(std::vector<Student*>&){
  for each student in the vector
    call deconstructor ~student()
}

void menu(){
  const std::string menuText = "0) Quit \n1) Print all Student Names\n2) Print all Student Data\n3) Find a Student\n";
  std::string input;
  bool keepGoing = true;

  while(keepGoing){
    clear input;
    std::cout << menuText; // prints the menu
    accept user input of 0-3
    if(input 0)
      keepGoing false
    elseif(input 1)
      printStudents(vector)
    elseif(input 2)
      showStudentNames(vector)
    elseif(input 3)
      findStudent(vector)
    else
      // should just ask again
  }
}

```

## Student.cpp
```
cool student code goes here

the student constructor should only seed the properties that are not related to other objects 
or maybe since the properties are pointers, they should be created in the constructor and then modified in the init?

Student Constructor
  studentString = "Place,Holder,1234 Lorem Ipsum,Dolor,SIT,00000,99/99/9999,11/11/1111,255";
  firstName = "Error";
  lastName = "Bug";
  studentAddress = new Address();
  birthDate = new Date();
  gradDate = new Date();
  creditHours = 777;

student init
  init accepts the string read from a line of the csv
  sstream
  create strings for each property and init
  then use getline with a comma delimiter to get each necessary string and place it in the proper space. should look something like
  push first datapoint into firstName
  second datapoint into lastName
  split the next four datapoints into temporary strings for street, city, state, zip
  studentAddress->init with the strings holding the proper data 
  push the next line into the string used to initialize birthDate
  birthDate->init with said string
  push the next line into the string used to initialize gradDate
  gradDate->init with said string
  getline(ss, sCredit, '\n')
  clear and set ss string to ""
  put sCredit into ss
  push ss out to creditHours to convert to int
  
print Student
  print first name last name new line
  call printAddress from studentAddress
  print "DOB: " and then call printDate from birthDate
  print "Grad: " and then call printDate from gradDate
  print "Credits: " and then print creditHours

getLastFirst
  return lastName , firstName , \n

getters (studentString, firstName, lastName, creditHours)
  seems self explanatory, simply return the value of sought property
setters (studentString, firstName, lastName, creditHours)
  also seems self explanatory, but take the variable passed and assign it to the relevant property
```

## Address.cpp
```
include the header and iostream

define the constructor for Address
  street = "placeholderStreet";
  city = "placeholderCity";
  state = "placeholderState";
  zip = "placeholderZip";

define the init
  accepting data from the bigger box of Student, place it into the following variables
  street, city, state, and zip in that order.

define print address
  print the properties of the class in the following order and syntax
  'street', 'city' 'state' 'zip'

getters (street, city, state, zip)
  seems self explanatory, simply return the value of sought property

setters (street, city, state, zip)
  also seems self explanatory, but take the variable passed and assign it to the relevant property
```

## Date.cpp
```
include the header, iostream, string, and sstream

define the constructor for Date
  datestring = "12345678";
  day = 00;
  month = 00;
  year = 0000;

define the init
  accepting datestring from the input, split it apart and place it into its proper spaces.
  define a sstream to parse the data
  define three temporary strings for day month and year
  assign the input datestring to the property datestring
  write the data within datestring to sstream
  getline sstream with the end character / twice and assign to day and month
  getline sstream with the end character \n to grab the year
  clear and set sstream string to ""
  place each temporary string into the sstream in order separated by spaces
  push sstream into the properties in the correct order

define printDate
  print day '/' month '/' year;

define printDateAlternate
  print WORDMONTH[month] ' ' day ', ' year;

getters (datestring, day, month, year)
  seems self explanatory, simply return the value of sought property

setters (datestring, day, month, year)
  also seems self explanatory, but take the variable passed and assign it to the relevant property
```

## Student.h
```
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
    void init(studentString);
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
```

## Address.h
```
#ifndef ADDRESS_H
#define ADDRESS_H

class Address{
  protected:
    std::string street;
    std::string city;
    std::string state;
    std::string zip;

  public:
    Address();
    void init(std::string street, std::string city, std::string state, std::string zip);
    void printAddress();
    std::string getStreet();
    void setStreet(std::string street);
    std::string getCity();
    void setCity(std::string city);
    std::string getState();
    void setState(std::string state);
    std::string getZip();
    void setZip(std::string zip);
};

#endif
```

## Date.h
```
#ifndef DATE_H
#define DATE_H

class Date{
  protected:
    std::string dateString;
    int day;
    int month;
    int year;
    const std::string WORDMONTH[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

  public:
    Date();
    void init(std::string dateString);
    void printDate();
    void printDateAlternate();
    std::string getDateString();
    void setDateString(std::string dateString);
    int getDay();
    void setDay(int day);
    int getMonth();
    void setMonth(int month);
    int getYear();
    void setYear(int year);
};

#endif
```

do i need setters? honestly probably not. probably better to keep them though. Even if they're unneccesary, they could be used for a blackbelt at the end.

maybe i could make it so you could add a second file of students and be able to see them as one list and sort them together.

## Blackbelt (Sorting)
void sortLast(std::vector<Student*>&);
bool compLast(Student* a, Student* b);
```
call sort from the algo header with the first item in the students vector and the last, as well as a comparison func.
the comparison func takes the current two compared students and grabs their lastname through the class's getter function and compares them
this one sorts in alphabetical order based on the comparison
```

void sortFirst(std::vector<Student*>&);
bool compFirst(Student* a, Student* b);
```
call sort from the algo header with the first item in the students vector and the last, as well as a comparison func.
the comparison func takes the current two compared students and grabs their firstname through the class's getter function and compares them
this one sorts in alphabetical order based on the comparison
```

void sortCredits(std::vector<Student*>&);
bool compCredits(Student* a, Student* b);
```
call sort from the algo header with the first item in the students vector and the last, as well as a comparison func.
the comparison func takes the current two compared students and grabs their creditHours through the class's getter function and compares them
this one sorts in descending order based on the comparison
```

void sortMenu(); // Functions near identical to the menu() function, except it jumps back to the upper menu after everything but invalid input.
```
  const std::string menuText = "0) Quit \n1) Sort by Last Name\n2) Sort by First Name\n3) Sort by Credit Hour\n";
  std::string input;
  bool keepGoing = true;

  while(keepGoing){
    clear input;
    std::cout << menuText; // prints the menu
    accept user input of 0-3
    if(input 0)
      keepGoing false
    elseif(input 1)
      sortLast(vector)
      keepGoing false
    elseif(input 2)
      sortFirst(vector)
    elseif(input 3)
      sortCredits(vector)
    else
      // should just ask again
  }
```