#include <iostream>
#include "Address.h"

Address::Address(){
  street = "placeholderStreet";
  city = "placeholderCity";
  state = "placeholderState";
  zip = "placeholderZip";
} // end Address constructor

void Address::init(std::string street, std::string city, std::string state, std::string zip){
  Address::street = street;
  Address::city = city;
  Address::state = state;
  Address::zip = zip;
} // end init

void Address::printAddress(){
  std::cout << street << ", " << city << " " << state << " " << zip << std::endl;
} // end printAddress

std::string Address::getStreet(){
  return street;
} // end getStreet

void Address::setStreet(std::string street){
  Address::street = street;
} // end setStreet

std::string Address::getCity(){
  return city;
} // end getCity

void Address::setCity(std::string city){
  Address::city = city;
} // end setCity

std::string Address::getState(){
  return state;
} // end getState

void Address::setState(std::string state){
  Address::state = state;
} // end setState

std::string Address::getZip(){
  return zip;
} // end getZip

void Address::setZip(std::string zip){
  Address::zip = zip;
} // end setZip