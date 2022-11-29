/*
 * Mohammed Hossain
 * Exercise 9
 * CISC 3142
 * November 28, 2022
 */

#include "weather.h"
#include <cstdio>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main(int argc, char **argv) {
  using namespace std;

  // expect argument for csv filepath, otherwise default to weather.csv
  string filename = argc > 1 ? argv[1] : "weather.csv";

  // open csv file
  ifstream csv_in(filename);

  // if file isn't open, then exit
  if (!csv_in.is_open()) {
    cerr << "Unable to open file '" << filename << "'." << endl;
    return -1;
  }

  // read weather data from file
  weather::w_list wdata;
  read_weather_csv(wdata, csv_in);

  // calculate moving averages
  weather::month_temp moving_avg;
  moving_averages(moving_avg, wdata);

  // calculated weighted averages
  weather::month_temp weighted_avg;
  weighted_averages(weighted_avg, wdata);

  // print data

  return 0;
}
void moving_averages(weather::month_temp &month_temp, weather::w_list &wdata) {
  weather::MovingMonths moving_months(wdata[0].second, wdata[1].second,
                                      wdata[2].second);

  // skip the first three, as we can't calculate 3-month
  // moving averages for those
  for (int i = 3; i < wdata.size(); i++) {
    month_temp[wdata[i].first] = moving_months.simple_avg();
    moving_months.add_moving_avg(wdata[i].second);
  }
}
void weighted_averages(weather::month_temp &month_temp,
                       weather::w_list &wdata) {
  weather::MovingMonths moving_months(wdata[0].second, wdata[1].second,
                                      wdata[2].second);

  // set weights for each month in order
  moving_months.set_weights(1, 2, 3);

  for (int i = 3; i < wdata.size(); i++) {
    month_temp[wdata[i].first] = moving_months.weighted_avg();
    moving_months.add_moving_avg(wdata[i].second);
  }
}

void read_weather_csv(weather::w_list &wdata, std::ifstream &csv_file) {

  std::string line;

  // go through each line of csv file
  while (getline(csv_file, line) >> line) {
    // get month and temperature
    std::string month = line.substr(0, line.find(','));
    int temp = stoi(line.substr(line.find(',') + 1));

    /* DEBUG*/
    // std::cout << month << " -- " << temp << std::endl;

    // add to vector
    wdata.push_back(std::make_pair(month, temp));
  }
}
