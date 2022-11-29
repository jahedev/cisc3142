
#ifndef WEATHER_H
#define WEATHER_H
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::pair<std::string, int>> read_weather_csv(std::ifstream &);

#endif