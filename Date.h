#ifndef DATE_H
#define DATE_H

class Date{
  protected:
    std::string dateString;
    int day;
    int month;
    int year;

  public:
    Date();
    void init(std::string dateString);
    void printDate();
    void printDateAlternate(); // Throws a crazy error
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
