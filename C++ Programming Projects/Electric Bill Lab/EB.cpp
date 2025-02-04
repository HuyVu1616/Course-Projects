#include <iostream>
#include <iomanip>

using namespace std;

const double TIER1_RATE = 0.23;
const double TIER2_RATE = 0.29;
const double TIER3_RATE = 0.45;
const double COMMISSION_TAX = 0.20;

int main() {
    double kWh, tier1_kWh, tier2_kWh, tier3_kWh;
    double electric_bill, tier1_bill, tier2_bill, tier3_bill;

    // Input
    cout << "Enter kWh: ";
    cin >> kWh;

    if (kWh < 1) {
        cerr << "Error: kWh cannot be less than 1" << endl;
        return 1;
    }

    // Process
    if (kWh <= 350.0) {
        tier1_kWh = kWh;
        tier2_kWh = 0.0;
        tier3_kWh = 0.0;
    } else if (kWh <= 1450.0) {
        tier1_kWh = 350.0;
        tier2_kWh = kWh - tier1_kWh;
        tier3_kWh = 0.0;
    } else {
        tier1_kWh = 350.0;
        tier2_kWh = 1100.0;
        tier3_kWh = kWh - 1450.0;
    }

    tier1_bill = tier1_kWh * TIER1_RATE;
    tier2_bill = tier2_kWh * TIER2_RATE;
    tier3_bill = tier3_kWh * TIER3_RATE;

    electric_bill = tier1_bill + tier2_bill + tier3_bill + COMMISSION_TAX;

    // Output
    cout << "Tier 1 charges: $" << tier1_bill << endl;
    cout << "Tier 2 charges: $" << tier2_bill << endl;
    cout << "Tier 3 charges: $" << tier3_bill << endl;
    cout << "Energy Tax: $" << COMMISSION_TAX << endl;
    cout << "Total Bill: $" << electric_bill << endl;

    return 0;
}