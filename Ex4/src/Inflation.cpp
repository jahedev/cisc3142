#include <iostream>
#include <cmath>

using namespace std;

void prompt_user(double &item_cost, double &inflation_rate, int &num_years) {
    cout << "Inflation Calculator" << endl;
    cout << "====================" << endl << endl;
    cout << "Enter cost of item: ";
    cin >> item_cost;
    cout << "Enter inflation rate: ";
    cin >> inflation_rate;
    inflation_rate /= 100;
    cout << "Enter number of years from now: ";
    cin >> num_years;
}

float calculate_inflation(double item_cost, double inflation_rate, int num_years) {
    double price = item_cost * pow((1 + inflation_rate), num_years);
    return (float) round(price * 100.0) / 100.0; // round to 2 decimal places
}

int main() {
    double item_cost;
    double inflation_rate;
    int num_years;

    prompt_user(item_cost, inflation_rate, num_years);
float inflated_price = calculate_inflation(item_cost, inflation_rate, num_years);

    cout << endl << "Inflated Price: " << inflated_price << endl;
}