#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::string;

struct Movie {
  unsigned int year; // year in 2 bytes (upto 65,000)
  unsigned int length;
  string title;
  string actor;
  string actress;
  string director;
  unsigned int popularity;
  bool awards;
  string image;
}

// void readMovies(vector<Movie> &movies, string csv_filename) {
// }

int main() {
  return 0;
}