#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Read number of foods and number of nutrients
    int numFoods, numNutrients;
    cin >> numFoods >> numNutrients;
    
    // Read the required units of each nutrient
    vector<int> requiredUnits(numNutrients);
    for (int i = 0; i < numNutrients; ++i) {
        cin >> requiredUnits[i];
    }
    
    // Initialize an array to store total intake of each nutrient
    vector<int> totalIntake(numNutrients, 0);
    
    // Read the nutrient units from each food and accumulate the totals
    for (int i = 0; i < numFoods; ++i) {
        for (int j = 0; j < numNutrients; ++j) {
            int intake;
            cin >> intake;
            totalIntake[j] += intake;
        }
    }
    
    // Check if the goals for all nutrients are met
    bool goalsMet = true;
    for (int i = 0; i < numNutrients; ++i) {
        if (totalIntake[i] < requiredUnits[i]) {
            goalsMet = false;
            break;
        }
    }
    
    // Print the result
    if (goalsMet) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}
