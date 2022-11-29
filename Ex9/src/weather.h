
#ifndef WEATHER_H
#define WEATHER_H
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

namespace weather {
// i.e. vector<pair<string, int>
typedef std::pair<std::string, int> w_item;
typedef std::vector<w_item> w_list;

// for moving and weighted averages, accessible by month name
typedef std::map<std::string, float> month_temp;

// Take the values of averages of 3 months, and calculate
// simple and weighted averages. Allow adding new averages,
// thereby *shifting* the values of each month's average.
class MovingMonths {
private:
  float m1_temp, m2_temp, m3_temp;

  // weights for weighted averages are equal by default
  struct weight {
    int m1 = 1;
    int m2 = 2;
    int m3 = 9;
  } weight;

public:
  // Constructor
  MovingMonths(float m1_temp, float m2_temp, float m3_temp)
      : m1_temp(m1_temp), m2_temp(m2_temp), m3_temp(m3_temp) {}

  // shift M2 temperature to M1, and M3 temperature to M2
  // previous M1 temperature is removed, M3 temperature will take new value
  void add_moving_avg(float new_m3_temp) {
    m1_temp = m2_temp;
    m2_temp = m3_temp;
    m3_temp = new_m3_temp;
  }

  void set_weights(int m1, int m2, int m3) {
    weight.m1 = m1;
    weight.m2 = m2;
    weight.m3 = m3;
  }

  float simple_avg() const { return (m1_temp + m2_temp + m3_temp) / 3; }
  float weighted_avg() const {

    return (m1_temp * weight.m1 + m2_temp * weight.m2 + m3_temp * weight.m3) /
           (weight.m1 + weight.m2 + weight.m3);
  }
  float get_m1_avg() const { return this->m1_temp; }
  float get_m2_avg() const { return this->m2_temp; }
  float get_m3_avg() const { return this->m3_temp; }
};

} // namespace weather

void read_weather_csv(weather::w_list &, std::ifstream &);
void moving_averages(weather::month_temp &, weather::w_list &);
void weighted_averages(weather::month_temp &, weather::w_list &);
void print_weather_data(weather::w_list &, weather::month_temp &,
                        weather::month_temp &);
std::string round_str(float);
#endif