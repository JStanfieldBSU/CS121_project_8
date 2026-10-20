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