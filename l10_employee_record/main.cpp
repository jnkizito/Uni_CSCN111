// Joseph. K
// 02-12-2025
// Employee record

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

const int TWO_WEEKS = 14;
const int TWO_WEEK_HOUR_GOAL = 80;
const double TAX_RATE = 0.15;

class Employee {
private:
  string name;
  int id;
  double hour_rate;
  double overtime_rate;
  int hoursOfTwoWeeks[TWO_WEEKS] = {};

public:
  Employee() : name(""), id(0), hour_rate(0), overtime_rate(0) {
    for (int i = 0; i < TWO_WEEKS; i++)
      hoursOfTwoWeeks[i] = 0;
  }

  Employee(string s, int num, double r1, double r2, int hrs[]) {
    name = s;
    id = num;
    hour_rate = r1;
    overtime_rate = r2;
    for (int i = 0; i < TWO_WEEKS; i++) {
      hoursOfTwoWeeks[i] = hrs[i];
    }
  }

  // Setters (FIXED)
  void setName(string tempName) { name = tempName; }
  void setId(int tempId) { id = tempId; }
  void setHourRate(double tempHourRate) { hour_rate = tempHourRate; }
  void setOvertimeRate(double tempOverTimeRate) {
    overtime_rate = tempOverTimeRate;
  }
  void setHoursOfTwoWeeks(int temp[]) {
    for (int i = 0; i < TWO_WEEKS; i++) {
      hoursOfTwoWeeks[i] = temp[i];
    }
  }

  // Getters
  string getName() const { return name; }
  int getId() const { return id; }

  // Pay Calculations
  double calculateBasePay() const {
    double totalHours = 0;
    for (int i = 0; i < TWO_WEEKS; i++)
      totalHours += hoursOfTwoWeeks[i];

    double baseHours =
        (totalHours > TWO_WEEK_HOUR_GOAL) ? TWO_WEEK_HOUR_GOAL : totalHours;
    return baseHours * hour_rate;
  }

  double calculateOvertimePay() const {
    double totalHours = 0;
    for (int i = 0; i < TWO_WEEKS; i++)
      totalHours += hoursOfTwoWeeks[i];

    double overtimeHours = (totalHours > TWO_WEEK_HOUR_GOAL)
                               ? (totalHours - TWO_WEEK_HOUR_GOAL)
                               : 0;
    return overtimeHours * overtime_rate;
  }

  void printRecord() const {
    double basePay = calculateBasePay();
    double overtimePay = calculateOvertimePay();
    double grossPay = basePay + overtimePay;
    double tax = grossPay * TAX_RATE;
    double netPay = grossPay - tax;

    cout << fixed << setprecision(2);
    cout << "\nEmployee Record\n";
    cout << "Name: " << name << "\nID: " << id << endl;
    cout << "Base Pay: $" << basePay << endl;
    cout << "Overtime Pay: $" << overtimePay << endl;
    cout << "Gross Pay: $" << grossPay << endl;
    cout << "Tax: $" << tax << endl;
    cout << "Net Pay: $" << netPay << endl;
  }
};

// FILE LOADER
Employee loadFromFile(const string &filename) {
  ifstream infile(filename);

  string name;
  int id;
  double hr, orate;
  int hrs[14];

  if (!infile) {
    cerr << "File load failed.\n";
    return Employee();
  }

  infile >> name >> id >> hr >> orate;
  for (int i = 0; i < 14; i++)
    infile >> hrs[i];
  infile.close();

  return Employee(name, id, hr, orate, hrs);
}

int main() {
  Employee emp1;

  string name;
  int id;
  double hr, orate;
  int hrs[14];

  cout << "Enter employee name: ";
  getline(cin, name);

  cout << "Enter ID: ";
  cin >> id;

  cout << "Enter hourly rate: ";
  cin >> hr;

  cout << "Enter overtime rate: ";
  cin >> orate;

  cout << "Enter 14 days of hours:\n";
  for (int i = 0; i < 14; i++)
    cin >> hrs[i];

  emp1.setName(name);
  emp1.setId(id);
  emp1.setHourRate(hr);
  emp1.setOvertimeRate(orate);
  emp1.setHoursOfTwoWeeks(hrs);

  Employee emp2 = loadFromFile("employees.txt");

  emp1.printRecord();
  emp2.printRecord();

  return 0;
}
