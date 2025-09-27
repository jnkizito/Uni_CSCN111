//
//Joseph Kizito
//26-09-2025

/* 
 * TODO: 
 * - [x] Read values from input file (name, annual wage, federal income tax, state income tax)
 * - [x] Store values read in appropriate variables
 * - [x] create Variables for Social Security and Medicare tax rates
 * - [x] Employee gets payed twice a month, calc amnt based off yearly income
 * - [x] Calculate the deductions for federal, state taxes, social security and medicare
 * - [x] Print Paystup for employee to file that shows pay and deduct
 * - [x] Print net pay to console
 */

/*
 * Input file 
 * name, annualWage, fedTax, stateTax,
*/

#include <iostream> 
#include <fstream>
#include <sstream>
#include <string>

//func to give netpay. monthpay is netPay * 2 
double employeeNetPayCalc(int annualWage, double federalRate, double stateRate, double ssRate, double mediRate){
        double netPerCheck;
        double grossCheck = annualWage / 24;

        //Do the tax deductions
        double fedDeduct = grossCheck * federalRate;
        double stateDeduct = grossCheck * stateRate;
        double ssDeduct = grossCheck * ssRate;
        double mediDeduct = grossCheck * mediRate;

        netPerCheck = grossCheck - fedDeduct - stateDeduct - ssDeduct - mediDeduct;
        
        return netPerCheck;
}

void writePaystub(std::string filename, std::string name, double employeePay){
        
        std::ofstream outstream(filename, std::ios::app); //Append the file

        if (!outstream){
                std::cout << "Something's wrong, can't write to file.";
        }

        outstream << "--------------------\n"
        << name << " net pay per check: $" << employeePay << "\n"
        << "Monthly Salary: $" << employeePay * 2 << "\n"
        << "Annual Net Salary: $" << employeePay * 24 << "\n";
}

int main(){

        //task 1: read Values from input file
        std::ifstream inputFile("input.txt");

        std::string strLine;
        std::string strTemp; //Can't cast from string to double, need to parse.

        //Vars
        std::string name;
        int annualWage;
        double fedTax;
        double stateTax;

        double SOCIAL_SECURITY_TAXRATE = 0.062;
        double MEDICARE_TAXRATE = 0.0145;

        while (std::getline(inputFile, strLine)) {
        //goes line by line, worker to worker and reads the data,

                // std::cout << "inputdata: " <<  strLine << std::endl;
                std::istringstream ss(strLine); //turns the string into a 'stream' called ss for getline(stream) to read.
                
                std::getline(ss, name, ',');

                std::getline(ss, strTemp, ',');
                annualWage = std::stoi(strTemp);

                std::getline(ss, strTemp, ',');
                fedTax = std::stod(strTemp);

                std::getline(ss, strTemp, ',');
                stateTax = std::stod(strTemp);

                //Print check
                std::cout << name << std::endl;
                // std::cout << annualWage << std::endl;
                // std::cout << fedTax << std::endl;
                // std::cout << stateTax << std::endl;

                //Grab and calculate employee pay
                double employeePay;
                employeePay = employeeNetPayCalc(annualWage, fedTax, stateTax, SOCIAL_SECURITY_TAXRATE, MEDICARE_TAXRATE);

                std::string outfile = "out.txt";
                writePaystub(outfile, name, employeePay);

                std::cout << "--------------------" << std::endl;
                std::cout << name << "'s netpay is : $" << employeePay << std::endl;
                std::cout << "Monthly Salary : $" << employeePay * 2 << std::endl;
                std::cout << "Annual Net Salary : $" << employeePay * 24 << std::endl;
                std::cout << "Paystub created." << std::endl;
                std::cout << "--------------------" << std::endl;
                std::cout << "\n" << std::endl;



                }
        inputFile.close();
}

