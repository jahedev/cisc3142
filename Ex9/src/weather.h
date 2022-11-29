
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
  float m1_avg, m2_avg, m3_avg;

  // weights for weighted averages are equal by default
  struct weight {
    int m1 = 1;
    int m2 = 1;
    int m3 = 1;
  } weight;

public:
  // Constructor
  MovingMonths(float m1_avg, float m2_avg, float m3_avg)
      : m1_avg(m1_avg), m2_avg(m2_avg), m3_avg(m3_avg) {}

  // shift M2 average to M1, and M3 average to M2
  // previous M1 average is removed, M3 average will take new value
  void add_moving_avg(float new_m3_avg) {
    m1_avg = m2_avg;
    m2_avg = m3_avg;
    m3_avg = new_m3_avg;
  }

  void set_weights(int m1, int m2, int m3) {
    weight.m1 = m1;
    weight.m2 = m2;
    weight.m3 = m3;
  }

  float simple_avg() const { return (m1_avg + m2_avg + m3_avg) / 3; }
  float weighted_avg() const {
    return (m1_avg * weight.m1 + m2_avg * weight.m2 + m3_avg * weight.m3) /
           (weight.m1 + weight.m2 + weight.m3);
  }
  float get_m1_avg() const { return this->m1_avg; }
  float get_m2_avg() const { return this->m2_avg; }
  float get_m3_avg() const { return this->m3_avg; }
};

} // namespace weather

void read_weather_csv(weather::w_list &, std::ifstream &);
void moving_averages(weather::month_temp &, weather::w_list &);
void weighted_averages(weather::month_temp &, weather::w_list &);
void print_weather_data(weather::w_list &, weather::month_temp &,
                        weather::month_temp &);
#endif