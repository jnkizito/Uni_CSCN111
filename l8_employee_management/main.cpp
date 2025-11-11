// Joseph Kizito
// 05-11-2025

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int ROW = 2;
const int MAX_EMPLOYEES = 10; // Column value of 2d table
                              
void printEmployeeList(string emp[ROW][MAX_EMPLOYEES]){
         for (int i = 0; i < MAX_EMPLOYEES; i++){
                int count = 0;
                cout << emp[count][i] << endl;

                count += 1;
                cout << emp[count][i] << endl;
                
        }
}

int main(){
        
        string emp[ROW][MAX_EMPLOYEES];

        ifstream employeeInputFile("employees.txt");
        string tmpLine;
        int count = 0;

        //assign employees to the 2d array
        while (getline(employeeInputFile, tmpLine) && count < MAX_EMPLOYEES){
                emp[0][count] = tmpLine; // Name stored.

                getline(employeeInputFile, tmpLine);
                emp[1][count] = tmpLine; // Role stored aswell.
                
                count += 1;
        }

        printEmployeeList(emp);

        

//
// //        Printing every ROW, then the COLUMNS within.
//         for (int i = 0; i < ROW; i++){
//                 for (int j = 0; j < MAX_EMPLOYEES; j++){
//                         cout << emp[i][j] << endl;
//                 }
//         }
}



