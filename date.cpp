#include <sstream>
#include <stdexcept>
#include "date.h"

using namespace std;


Date::Date(const int& year, const int& month, const int& day) 
    : year_(year), month_(month), day_(day) {
  if (month > 12 || month < 1) {
    throw logic_error("Month value is invalid: " + to_string(month));
  }
  if (day > 31 || day < 1) {
    throw logic_error("Day value is invalid: " + to_string(day));
  }
}

int Date::GetYear() const {
  return year_;
}

int Date::GetMonth() const {
  return month_;
}

int Date::GetDay() const {
  return day_;
}

Date ParseDate(const string& date) {
  istringstream date_s(date);
  bool res = true;
  int year, month, day;
  res = res && (date_s >> year);
  res = res && (date_s.peek() == '-');
  date_s.ignore(1);
  res = res && (date_s >> month);
  res = res && (date_s.peek() == '-');
  date_s.ignore(1);
  res = res && (date_s >> day);
  res = res && date_s.eof();
  if (!res) {
    throw logic_error("Wrong date format: " + date);
  }
  return Date(year, month, day);
}