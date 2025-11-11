// Joseph N.K
// 11-10-2025
// Payroll Calculator

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    const double HOURLY_RATE = 17.17;
    const double DAILY_RATE = 33.33;

    bool loop = true;
    int choice;

    while (loop) {
        cout << "\n--- Joseph's Payroll Calculator ---\n";
        cout << "1. Import hours from file\n";
        cout << "2. Enter hours manually\n";
        cout << "3. Use flat daily rate\n";
        cout << "4. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            ifstream inFile("hours.txt");
            if (!inFile) {
                cout << "Error: could not open hours.txt\n";
            } else {
                double hours, total = 0;
                while (inFile >> hours) {
                    if (hours >= 0 && hours <= 24) {
                        total += hours;
                    } else {
                        cout << "Invalid hour value skipped: " << hours << endl;
                    }
                }
                inFile.close();

                double grossPay = total * HOURLY_RATE;
                cout << "\nTotal hours: " << total << endl;
                cout << "Hourly rate: $" << HOURLY_RATE << endl;
                cout << "Gross pay: $" << grossPay << endl;
            }
        } 
        else if (choice == 2) {
            double total = 0, hours;
            for (int i = 1; i <= 7; i++) {
                cout << "Enter hours for day " << i << ": ";
                cin >> hours;
                while (hours < 0 || hours > 24) {
                    cout << "Invalid input. Re-enter: ";
                    cin >> hours;
                }
                total += hours;
            }
            double grossPay = total * HOURLY_RATE;
            cout << "\nTotal hours: " << total << endl;
            cout << "Hourly rate: $" << HOURLY_RATE << endl;
            cout << "Gross pay: $" << grossPay << endl;
        } 
        else if (choice == 3) {
            int days = 0;
            char again = 'y';
            while (again == 'y' || again == 'Y') {
                days++;
                cout << "Add another day? (y/n): ";
                cin >> again;
            }
            double grossPay = days * DAILY_RATE;
            cout << "\nDays worked: " << days << endl;
            cout << "Daily rate: $" << DAILY_RATE << endl;
            cout << "Gross pay: $" << grossPay << endl;
        } 
        else if (choice == 4) {
            // Quit
            loop = false;
            cout << "Goodbye!\n";
        } 
        else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}

