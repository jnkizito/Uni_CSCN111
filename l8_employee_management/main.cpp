// Joseph Kizito
// 05-11-2025

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

const int ROW = 2;
const int MAX_EMPLOYEES = 10; // Column value of 2D table

void printEmployeeList(string emp[ROW][MAX_EMPLOYEES]) {
  for (int i = 0; i < MAX_EMPLOYEES; i++) {
    if (emp[0][i] != " " && emp[0][i] != "")
      cout << emp[0][i] << " - " << emp[1][i] << endl;
  }
}

void printToFile(string emp[ROW][MAX_EMPLOYEES]) {
  ofstream outfile("out.txt");
  for (int i = 0; i < MAX_EMPLOYEES; i++) {
    if (emp[0][i] != " " && emp[0][i] != "")
      outfile << emp[0][i] << " is a " << emp[1][i] << " employee." << endl;
  }
  outfile.close();
}

void hireEmployee(string emp[ROW][MAX_EMPLOYEES]) {
  int insertPosition = -1;
  for (int i = 0; i < MAX_EMPLOYEES; i++) {
    if (emp[0][i] == " " || emp[0][i] == "") {
      insertPosition = i;
      break;
    }
  }

  string newName, newRole;
  if (insertPosition != -1) {
    cout << "Enter new employee's name: ";
    getline(cin, newName);
    emp[0][insertPosition] = newName;

    cout << "Enter new employee's role: ";
    getline(cin, newRole);
    emp[1][insertPosition] = newRole;

    cout << "New employee added at position " << insertPosition << endl;
  } else {
    cout << "No empty space was found for a new employee. Sorry!" << endl;
  }
}

int sequentialSearch(string emp[ROW][MAX_EMPLOYEES], int length,
                     string searchName) {
  for (int i = 0; i < length; i++) {
    if (emp[0][i] == searchName) {
      cout << "Search successful." << endl;
      return i;
    }
  }
  cout << "Search failed." << endl;
  return -1;
}

void fireEmployee(string emp[ROW][MAX_EMPLOYEES], string unfortunateEmployee) {
  int delPos = sequentialSearch(emp, MAX_EMPLOYEES, unfortunateEmployee);
  if (delPos != -1) {
    emp[0][delPos] = " ";
    emp[1][delPos] = " ";
    cout << unfortunateEmployee << " has been fired." << endl;
  } else {
    cout << unfortunateEmployee << " not found." << endl;
  }
}

void calculateWages(string emp[ROW][MAX_EMPLOYEES]) {
  ofstream wageFile("wages.txt");
  double hourlyRate, hoursWorked;

  cout << "\nCalculating Wages for Employees:\n";
  for (int i = 0; i < MAX_EMPLOYEES; i++) {
    if (emp[0][i] != " " && emp[0][i] != "") {
      cout << "\nEnter hourly rate for " << emp[0][i] << ": ";
      cin >> hourlyRate;
      cout << "Enter hours worked for " << emp[0][i] << ": ";
      cin >> hoursWorked;
      cin.ignore(); // to clear newline from input buffer

      double wage = hourlyRate * hoursWorked;
      cout << emp[0][i] << " earned $" << wage << endl;
      wageFile << emp[0][i] << " (" << emp[1][i] << ") earned $" << wage
               << endl;
    }
  }
  wageFile.close();
}

int main() {
  string emp[ROW][MAX_EMPLOYEES];

  // Initialize all slots to blanks
  for (int i = 0; i < MAX_EMPLOYEES; i++) {
    emp[0][i] = " ";
    emp[1][i] = " ";
  }

  ifstream employeeInputFile("employees.txt");
  string tmpLine;
  int count = 0;

  // Assign employees to the 2D array
  while (getline(employeeInputFile, tmpLine) && count < MAX_EMPLOYEES) {
    emp[0][count] = tmpLine; // Name
    if (getline(employeeInputFile, tmpLine))
      emp[1][count] = tmpLine; // Role
    count += 1;
  }

  employeeInputFile.close();

  cout << "Employee Management System\n";
  printEmployeeList(emp);

  string choice;
  while (true) {
    cout << "\nOptions: [H]ire  [F]ire  [W]ages  [L]ist  [Q]uit\n";
    cout << "Enter choice: ";
    getline(cin, choice);

    if (choice == "H" || choice == "h")
      hireEmployee(emp);
    else if (choice == "F" || choice == "f") {
      string name;
      cout << "Enter name to fire: ";
      getline(cin, name);
      fireEmployee(emp, name);
    } else if (choice == "W" || choice == "w")
      calculateWages(emp);
    else if (choice == "L" || choice == "l")
      printEmployeeList(emp);
    else if (choice == "Q" || choice == "q")
      break;
    else
      cout << "Invalid option.\n";
  }

  printToFile(emp);
  cout << "Program ended. Data written to 'out.txt' and 'wages.txt'.\n";
  return 0;
}
