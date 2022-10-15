#include <filesystem>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

struct Point {
  double x;
  double y;
};

vector<Point> read_data(string file_name)
{
  vector<Point> points;
  string line, word;

  string file_path = filesystem::current_path().generic_string() + "/" + file_name;

  cout << file_path << endl;

  // Open File
  fstream file(file_path, ios::in);
  if (!file.is_open())
  {
    cout << "Error: could not open file:\n"
         << file_path << endl;
  }

  // Skip First Line (i.e. headers "X, Y")
  getline(file, line);

  // Read File
  while (getline(file, line))
  {
    Point curr_point;

    stringstream str(line);

    getline(str, word, ',');
    curr_point.x = stod(word);
    getline(str, word, ',');
    curr_point.y = stod(word);

    points.push_back(curr_point);
  }

  // Print Out Data Read from File
  cout << "DATA X, Y:\n================" << endl;
  for (auto point : points) {
    cout << "X: " << point.x << ", Y: " << point.y << endl;
  }
  cout << "\nX,Y Pairs: " << points.size() << "\n\n";

  return points;
}

// Calculates Means for X and Y
// Sigma(X)/Nx and Sigma(Y)/Ny
Point averages(vector<Point> xy_points)
{
  Point mean;

  double x_sum = 0;
  double y_sum = 0;
  int count = xy_points.size();

  for (auto point : xy_points) {
    x_sum += point.x;
    y_sum += point.y;
  }

  mean.x = x_sum / count;
  mean.y = y_sum / count;

  return mean;
}

// Calculates Sum of Squared Deviations
// Sigma(X-meanX)^2
Point sumof_squared_dev(vector<Point> points, Point mean) {
  Point sum_sqrdev {0, 0};

  for (auto point : points) {
    sum_sqrdev.x += pow(point.x - mean.x, 2);
    sum_sqrdev.y += pow(point.y - mean.y, 2);
  }

  return sum_sqrdev;
}

// Calculates Sum of Absolute Deviations
// Sigma(abs(X-meanX))
Point sumof_absolute_dev(vector<Point> points, Point mean) {
  Point sum_absdev {0, 0};

  for (auto point : points) {
    sum_absdev.x += abs(point.x - mean.x);
    sum_absdev.y += abs(point.y - mean.y);
  }

  return sum_absdev;
}

// Calculates Slope:
// Sigma((X - meanX)*(Y - meanY)) / Sigma(X-meanX)^2
double calc_slope(vector<Point> points, Point mean, double sumof_sqrdev_X) {
  // Sum of: (X - meanX)*(Y - meanY)
  double sum = 0;
  for (auto point : points) {
    sum += (point.x - mean.x) * (point.y - mean.y);
  }
  return sum / sumof_sqrdev_X;
}

// Rounds a double to a specified decimal point
// and returns the result as a string
string round_str(double num, int precision) {
  stringstream stream;
  stream << std::fixed << std::setprecision(precision) << num;
  return stream.str();
}

int main()
{
  vector<Point> points = read_data("data.csv");

  Point mean = averages(points);
  Point SSD = sumof_squared_dev(points, mean);

  double slope = calc_slope(points, mean, SSD.x);
  double intercept = mean.y - slope * mean.x;

  string op = slope > 0 ? " + " : " - ";
  string linear_Y = "Y = " + round_str(intercept, 2) + op + round_str(slope, 2) + "x";

  cout << "Simple linear regression model: " << linear_Y << endl;

  return 0;
}