#include <iostream>
#include <limits>

using namespace std;

double get_positive_number(string prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
        }
        else if (value <= 0) {
            cout << "Value must be positive."<<endl<<endl;
        }
        else {
            return value;
        }
    }
}

int main() {
    cout << "=== Loan-to-Income Ratio Calculator ===\n";

    double loan_amount = get_positive_number("Enter total loan amount: ");
    double annual_income = get_positive_number("Enter annual income: ");

    double ratio = loan_amount / annual_income;

    cout << "Loan-to-Income Ratio: " << ratio << endl<<endl;

    cout << "24CE103_Manthan Rangpariya" << endl;
    return 0;
}
