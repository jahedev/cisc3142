#include <iostream>

using namespace std;

int calculate_diet_soda(int desired_weight) {
    int sweetener_death = 5;
    int mouse_weight = 35;
    double death_grams = sweetener_death / mouse_weight;
    int dieter_weight = 45400;
    double lethal_dose = death_grams * dieter_weight;

    return lethal_dose / sweetener_death * .001 + 13;
}

int main() {
    
    int end_weight;

    cout << "Diet Soda Nutrition Calculator" << endl;
    cout << "==============================" << endl << endl;
    cout << "At what weight will you stop drinking (from 100 lbs)?: ";
    cin >> end_weight;
    cout << endl;

    int drinkable_soda_cans = calculate_diet_soda(end_weight);

    cout << drinkable_soda_cans * end_weight;
}