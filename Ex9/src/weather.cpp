/*
 * Note to Professor: the prompt asked to use a nested vector (2D vector).
 * I have actually spent quite a while thinking through this and I cannot make
 * sense of it. The main issue is that there are multiple types in the CSV
 * files, strings, doubles, etc. We would have to use the equivalent of a Java
 * Generic or a java.lang.Object type for the vector. But we haven't learned
 * these things in the language yet. So I decided to create my own struct, being
 * the type of the vector.
 */

#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace weather {
struct weight {
  double m1 = 1.0 / 5; // weight: 1
  double m2 = 2.0 / 5; // weight: 2
  double m3 = 3.0 / 5; // weight: 3
} weight;

} // namespace weather

int main(int argc, char **argv) {
  // expect argument for csv filepath, otherwise default to weather.csv
  std::string filename = argc > 1 ? argv[1] : "weather.csv";
  // open csv file
  std::ifstream csv_in(filename);
  // if file isn't open, then exit
  if (!csv_in.is_open()) {
    std::cerr << "Unable to open file '" << filename << "'." << std::endl;
    return -1;
  }

  return 0;
}

std::vector<std::pair<std::string, int>> read_weather_csv(std::ifstream) {
  std::vector<std::pair<std::string, int>> data;
}
