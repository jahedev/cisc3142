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