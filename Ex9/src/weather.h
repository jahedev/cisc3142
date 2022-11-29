
#ifndef WEATHER_H
#define WEATHER_H
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void read_weather_csv(std::vector<std::pair<std::string, int>> &,
                      std::ifstream &);

#endif