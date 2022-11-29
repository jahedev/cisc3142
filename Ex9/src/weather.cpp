/*
 * Mohammed Hossain
 * Exercise 9
 * CISC 3142
 * November 28, 2022
 */

#include "weather.h" // custom data types, incl. nested vector
#include <cmath>     // round floats
#include <fstream>   // read csv file
#include <iomanip>   // print with justification
#include <iostream>
#include <string>

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

  // print weather data
  print_weather_data(wdata, moving_avg, weighted_avg);

  return 0;
}

void print_weather_data(weather::w_list &wdata, weather::month_temp &moving_avg,
                        weather::month_temp &weighted_avg) {
  using std::cout, std::endl, std::setw, std::string;

  cout << "\n―――――――――――――――――――――――――――――――――――――――――――――――――" << endl;
  cout << string(12, ' ') << "WEATHER DATA CALCULATIONS" << endl;
  cout << "―――――――――――――――――――――――――――――――――――――――――――――――――\n" << endl;
  cout << setw(6) << "Month" << setw(14) << "Temperature" << setw(14)
       << "Moving Avg." << setw(14) << "Weighted Avg" << endl;
  cout << setw(6) << "~~~~~" << setw(14) << "~~~~~~~~~~~" << setw(14)
       << "~~~~~~~~~~~" << setw(14) << "~~~~~~~~~~~~" << endl;

  for (weather::w_list::size_type i = 0; i < wdata.size(); i++) {
    string month = wdata[i].first;
    string temp = round_str(wdata[i].second);
    string simple_avg =
        moving_avg.count(month) > 0 ? round_str(moving_avg[month]) : "---";
    string weight_avg =
        weighted_avg.count(month) > 0 ? round_str(weighted_avg[month]) : "---";

    cout << setw(6) << month << setw(14) << temp << setw(14) << simple_avg
         << setw(14) << weight_avg << endl;
  }
}

std::string round_str(float val) {
  int decimals = 1;

  std::ostringstream ss;
  ss << std::fixed << std::setprecision(decimals) << val;
  std::string s = ss.str();
  if (decimals > 0 && s[s.find_last_not_of('0')] == '.') {
    s.erase(s.size() - decimals + 1);
  }
  return s;
}

void moving_averages(weather::month_temp &month_temp, weather::w_list &wdata) {
  weather::MovingMonths moving_months(wdata[0].second, wdata[1].second,
                                      wdata[2].second);

  // skip the first three, as we can't calculate 3-month
  // moving averages for those
  for (weather::w_list::size_type i = 3; i < wdata.size(); i++) {
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

  for (weather::w_list::size_type i = 3; i < wdata.size(); i++) {
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
