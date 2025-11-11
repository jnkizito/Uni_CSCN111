// Joseph N.K
// 09-05-2025
// Product Discount Calculator

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // constants
    const double TAX_RATE = 0.05;
    const double AI_BONUS_DISCOUNT = 0.12;

    // product data
    string productName;
    double productPrice;
    int stockQty;
    double discountRate;

    // open input file
    ifstream inFile("products.txt");
    if (!inFile) {
        cout << "Error: could not open products.txt" << endl;
        return 1;
    }

    // file format example: LinuxBook 19.99 50 0.10
    inFile >> productName >> productPrice >> stockQty >> discountRate;
    inFile.close();

    int quantity;
    cout << "Welcome to Joseph's Wacky Linux Centre" << endl;
    cout << "Product: " << productName << endl;
    cout << "Price per item: $" << productPrice << endl;
    cout << "In stock: " << stockQty << endl;
    cout << "Base discount: " << discountRate * 100 << "%" << endl;
    cout << "(AI-generated code adds another 12% off!)" << endl;

    cout << "\nEnter quantity to purchase: ";
    cin >> quantity;

    if (quantity <= 0) {
        cout << "Invalid quantity." << endl;
        return 1;
    }

    if (quantity > stockQty) {
        cout << "Error: not enough stock available." << endl;
        return 1;
    }

    // math
    double subtotal = productPrice * quantity;
    double totalDiscountRate = discountRate + AI_BONUS_DISCOUNT;
    double discountAmount = subtotal * totalDiscountRate;
    double discountedSubtotal = subtotal - discountAmount;
    double tax = discountedSubtotal * TAX_RATE;
    double finalTotal = discountedSubtotal + tax;

    // receipt
    cout << "\nItemized Receipt" << endl;
    cout << "----------------" << endl;
    cout << "Item: " << productName << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Price per item: $" << productPrice << endl;
    cout << "Subtotal: $" << subtotal << endl;
    cout << "Discount applied: " << totalDiscountRate * 100 << "%" << endl;
    cout << "Discount amount: $" << discountAmount << endl;
    cout << "Subtotal after discount: $" << discountedSubtotal << endl;
    cout << "Tax (5%): $" << tax << endl;
    cout << "Final total: $" << finalTotal << endl;

    cout << "\nThank you for your order!" << endl;
    return 0;
}

