#include <iostream>
#include <vector>

using namespace std;

void print_nums(vector<int> nums) {
    for (auto num : nums) cout << num << " ";
    cout << endl;
}

int main() {

    vector<int> nums {11, 24, 57, 61, 77, 92, 108, 144, 175, 200};

    // print out original values
    cout << "Original: ";
    print_nums(nums);

    // double each number
    for (auto &num : nums) num *= 2;

    // print out doubled values
    cout << "Doubled: ";
    print_nums(nums);
    
    return 0;
}