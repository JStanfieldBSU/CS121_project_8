#include <iostream>
#include <string>
#include <sstream>
#include "Date.h"

Date::Date(){
  dateString = "12/34/5678";
  day = 87;
  month = 65;
  year = 4321;
} // end Date constructor

void Date::init(std::string dateString){
  std::stringstream ss;
  std::string sDay;
  std::string sMonth;
  std::string sYear;
  Date::dateString = dateString;
  // std::string dateString = "12/24/1999"; 

  ss.str(dateString);
  getline(ss, sMonth, '/');
  getline(ss, sDay, '/');
  getline(ss, sYear, '\n');
  ss.clear();
  ss.str("");
  ss << sMonth << " " << sDay << " " << sYear;
  ss >> month >> day >> year;
  /*
  std::cout << day << '\n' << month << '\n' << year << std::endl;
  std::cout << day << '/' << month << '/' << year << std::endl;
  std::cout << day + month + year << std::endl; 
  */
} // end init

void Date::printDate(){
  std::string WORDMONTH[] = {"ERROR", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
  std::string mString = WORDMONTH[month];
  std::cout << mString << ' ' << day << ", " << year << std::endl;
} // end printDate

void Date::printDateAlternate(){
  std::cout << month << '/' << day << '/' << year << std::endl;
} // end printDateAlternate

std::string Date::getDateString(){
  return dateString;
} // end getDateString

void Date::setDateString(std::string dateString){
  Date::dateString = dateString;
} // end setDateString

int Date::getDay(){
  return day;
} // end getDay

void Date::setDay(int day){
  Date::day = day;
} // end setDay

int Date::getMonth(){
  return month;
} // end getMonth

void Date::setMonth(int month){
  Date::month = month;
} // end setMonth

int Date::getYear(){
  return year;
} // end getYear

void Date::setYear(int year){
  Date::year = year;
} // end setYear
