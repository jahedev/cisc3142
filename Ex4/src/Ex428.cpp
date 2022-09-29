#include <iostream>
#include <vector>

using namespace std;

void print_size(string type_name, size_t size) {
    string plural = size > 1 ? "s" : ""; // 1 byte vs multiple bytes
    cout << type_name << ": " << size << " byte" << plural << "." << endl;
}

int main() {
    cout << "Size of Different Data Types: " << endl;
    print_size("Integer", sizeof(int));
    print_size("Char", sizeof(char));
    print_size("Float", sizeof(float));
    print_size("Double", sizeof(double));
    print_size("Void", sizeof(void));
    print_size("Wide Char", sizeof(wchar_t));
    print_size("Size Type", sizeof(size_t));
    cout << endl;
    print_size("Unsigned Int", sizeof(unsigned int));
    print_size("Short Int", sizeof(short int));
    print_size("Long Int", sizeof(long int));
    print_size("Long Long Int", sizeof(long long int));
    print_size("Long Double", sizeof(long double));

    return 0;
}