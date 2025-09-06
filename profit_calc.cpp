// Joseph. N.k
//09-05-2025 

//Prerequisites 
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

//function for calculating total. func(price, amount)
double calcTotalAmount(double itemPrice, int itemAmount){
        double total = 0.0;
        //Casting to make sure output is a double. Might be overkill honestly.
        total = itemPrice * static_cast<double>(itemAmount);

        return total;
}

//function for calculation tax func(total, taxPercentage)
double calcTaxedTotal(double total, double taxPercentage){
        double taxedTotal = static_cast<double>(total);
        //Casting to make sure output is a double. Might be overkill honestly.
        taxedTotal -= taxedTotal * taxPercentage;

        return taxedTotal;
}

int main(){
        // Profit Calculator
        // Ask for Item > Cost > how many. 
        // Calculate the total cost of the order.
        // Print dollar amound with 5% tax rate
        
        // variable setting
        double TAX_PERCENTAGE = 0.05;
        string itemName = "";
        double itemPrice = 0.0;
        int itemAmount = 0; 

        // Linux for beginners: 5
        // SSH for beginners: 10

        //Enter name of item
        cout << "Welcome to Joseph's Wacky Linux Centre." << endl;
        cout << "Enter the name of your item: ";
        cin >> itemName; // capturing the input and storing it. 
        cout << "\n" << endl;

        cout << "Enter the price of your item: ";
        cin >> itemPrice; // capturing the input and storing it. 
        cout << "\n" << endl;

        cout << "Enter the amount: ";
        cin >> itemAmount; // capturing the input and storing it. 
        cout << "\n" << endl;

        //calculate total 
        double total = calcTotalAmount(itemPrice, itemAmount);
        
        //calculate with tax
        double taxedTotal = calcTaxedTotal(total, TAX_PERCENTAGE);

            cout << "==============================\n";
    cout << "          FINAL BILL          \n";
    cout << "==============================\n";
    
    cout << "Item Name: " <<  itemName << "\n";
    cout << "Item Price:$ " <<  itemPrice << "\n";
    cout << "Item Amount: " <<  itemAmount<< "\n";
    cout << "------------------------------\n";
    cout << "TOTAL          : $" << taxedTotal<< "\n";
    cout << "==============================\n";
    cout << "   Thank you for your order!  \n";
    cout << "==============================\n";


        return 0;
}

        
