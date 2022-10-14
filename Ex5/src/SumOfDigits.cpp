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
    cout << sum_of_digits(7865);
    return 0;
}