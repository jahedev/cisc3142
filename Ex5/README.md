# CISC 3142 - Excercise 5 (M. Hossain)

Created: October 14, 2022 8:22 PM
Last Edited: October 14, 2022 8:31 PM
Note Type: Lecture Note, Textbook Note, Video Note

# CISC 3142 Fall 2022 Class Exercise 5

## Exercises from the textbook:

**4.5**: Determine the result of the following expressions.

(a) -30 * 3 + 21 / 5

> (-30 * 3) + (21 / 5)
-86
> 

(b) -30 + 3 * 21 / 5

> -30 + 3 * (21/5)
-18
> 

(c) 30 / 3 * 21 % 5

> ((30 / 3) * 21) % 5
0
> 

(d) ((-30 / 3) * 21) % 4

> -2
> 

**4.17**: Explain the difference between prefix and postfix increment.

> Prefix first increments the variable (++x) and then returns the value, whereas postfix (x++) returns the variable first and then increments it.
> 

**4.34**: Given the variable definitions in this section, explain what conversions take place in the following expressions:

(a) if (fval)

> Since fval is a float, it will be compared against 0.0, fval != 0.0, will evaluate true if it is not exactly 0.
> 

(b) dval = fval + ival;

> ival is converted to float and added with fval, then the result is converted to double and assigned to dval
> 

(c) dval + ival * cval;

> cval is converted to int and multiplied by ival and then the result is converted to double and added with dval.
> 

## Practice Problems

### 1. Sum of Digits

Calculate the sum of digits of a number. The program prompts the user to enter the number. For example: Enter number: 7865 The output should be  7+ 8 + 6 + 5 = 26

Sample output of the program is shown below:

Enter a positive number: 7865

Sum of digits of the number 7865 is: 26

```cpp
#include <iostream>
#include <cmath>

using namespace std;

int sum_of_digits(int num) {
    // we can count the digits of the number
    // using log10
    int digit_count = log10(num) + 1;

    int sum = 0;

    while (digit_count > 0) {
        // add last digit to sum
        sum += num % 10;
        // remove the last digit
        num /= 10;

        // decrement until final digit
        --digit_count;
    }

    return sum;
}

int main() {
    cout << "Sum of digits 7865: " << sum_of_digits(7865);
    return 0;
}
```

### 2. Prime Numbers

Write a program that finds and prints all the prime numbers between 3 and 100. A prime number is a number such that 1 and itself are the only numbers that evenly divide it (for example, 3, 5, 7, 11, 13, 17, …).

```cpp
#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int num) {
    // 2 and 3 are primes
    if (num == 2 || num == 3)
        return true;
    
    // negatives, evens, divisible by 3 are not primes
    if (num <= 1 || num % 2 == 0 || num % 3 == 0)
        return false;
    
    // check if it perfectly divides by 5 and sqrt(num)
    for (int i = 5; i * i <= num; i += 6)
        if (num % i == 0 || num % (i + 2) == 0)
            return true;
    
    return true;
}

void print_primes(int start, int end) {
    cout << "Prime Numbers:" << endl;
    for (; start <= end; start++) {
        if (is_prime(start)) {
            cout << start << ", ";
        }
    }
    cout << endl;
}

int main() {
    print_primes(3, 100);
    return 0;
}
```

### 3. Linear Regression

Write a program that reads a file containing a pair of numbers in each line (representing x y coordinates); at the end of reading this file compute the linear regression for this set of numbers.  Please use to the linear regression formulas mentioned in class (if you missed class, find a classmate to get notes).

```cpp
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
```