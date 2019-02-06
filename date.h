#pragma once
#include <string>

using namespace std;


class Date {
public:
  Date(const int& year, const int& month, const int& day);

  int GetYear() const;

  int GetMonth() const;

  int GetDay() const;

private:
  const int year_, month_, day_;
};

Date ParseDate(const string& date);