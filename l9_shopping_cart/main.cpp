#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

const int SHELF_SIZE = 10;
const double SHIPPING_RATE = 18.45;

struct ShelfProduct {
  string name;
  double price;
};

struct Product {
  string name;
  double price;
  int quantityOrdered;
  bool discountStatus;
  bool shippingStatus;
  double finalCost = 0.0;

  Product()
      : name(""), price(0.0), quantityOrdered(0), discountStatus(false),
        shippingStatus(false), finalCost(0.0) {}

  Product(string n, double p, int q)
      : name(n), price(p), quantityOrdered(q), discountStatus(false),
        shippingStatus(false), finalCost(0.0) {}
};

void loadProductsIntoShelf(ShelfProduct shelf[]) {
  ifstream infile("product_input.txt");
  string tmpPrice;
  int count = 0;

  while (infile && count < SHELF_SIZE) {
    getline(infile, shelf[count].name);
    getline(infile, tmpPrice);
    shelf[count].price = stod(tmpPrice);
    count++;
  }
  infile.close();
}

void printShelfItems(ShelfProduct shelf[]) {
  cout << "\n--- Available Products ---\n";
  for (int i = 0; i < SHELF_SIZE; i++) {
    cout << setw(2) << (i + 1) << ". " << setw(25) << left << shelf[i].name
         << " $" << fixed << setprecision(2) << shelf[i].price << "\n";
  }
}

Product initProduct(string name, double price, int quantityOrdered) {
  return Product(name, price, quantityOrdered);
}

double applyDiscount(int qty, double pricePerUnit, bool &flag) {
  double base = qty * pricePerUnit;

  if (qty >= 30) {
    flag = true;
    return base * 0.80;
  }
  if (qty >= 20) {
    flag = true;
    return base * 0.90;
  }
  if (qty >= 10) {
    flag = true;
    return base * 0.95;
  }

  flag = false;
  return base;
}

int getUserChoice() {
  string tmp;
  int val;
  while (true) {
    cout << "Select item (1-" << SHELF_SIZE << ", 0 to quit): ";
    getline(cin, tmp);
    try {
      val = stoi(tmp);
    } catch (...) {
      continue;
    }
    if (val >= 0 && val <= SHELF_SIZE)
      return val;
  }
}

int getQuantity() {
  string tmp;
  int val;
  while (true) {
    cout << "Enter quantity: ";
    getline(cin, tmp);
    try {
      val = stoi(tmp);
    } catch (...) {
      continue;
    }
    if (val > 0)
      return val;
  }
}

bool getShippingChoice() {
  string tmp;
  while (true) {
    cout << "Ship this item? (Y/N): ";
    getline(cin, tmp);
    if (tmp == "Y" || tmp == "y")
      return true;
    if (tmp == "N" || tmp == "n")
      return false;
  }
}

void printReceipt(Product cart[], int cartCount) {
  cout << "\n\n=========== ITEMIZED RECEIPT ===========\n";
  cout << left << setw(25) << "Item" << setw(10) << "Qty" << setw(12) << "Base"
       << setw(12) << "Final" << "Shipping\n";

  double grandTotal = 0;

  for (int i = 0; i < cartCount; i++) {
    cout << left << setw(25) << cart[i].name << setw(10)
         << cart[i].quantityOrdered << "$" << setw(11) << fixed
         << setprecision(2) << (cart[i].price * cart[i].quantityOrdered) << "$"
         << setw(11) << cart[i].finalCost
         << (cart[i].shippingStatus ? "Yes" : "No") << "\n";

    grandTotal += cart[i].finalCost;
    if (cart[i].shippingStatus)
      grandTotal += SHIPPING_RATE;
  }

  cout << "\nTOTAL: $" << fixed << setprecision(2) << grandTotal << "\n";
}

void saveReceipt(Product cart[], int cartCount) {
  ofstream out("receipt.txt");

  out << "=========== ITEMIZED RECEIPT ===========\n";
  out << left << setw(25) << "Item" << setw(10) << "Qty" << setw(12) << "Base"
      << setw(12) << "Final" << "Shipping\n";

  double grandTotal = 0;

  for (int i = 0; i < cartCount; i++) {
    out << left << setw(25) << cart[i].name << setw(10)
        << cart[i].quantityOrdered << "$" << setw(11) << fixed
        << setprecision(2) << (cart[i].price * cart[i].quantityOrdered) << "$"
        << setw(11) << cart[i].finalCost
        << (cart[i].shippingStatus ? "Yes" : "No") << "\n";

    grandTotal += cart[i].finalCost;
    if (cart[i].shippingStatus)
      grandTotal += SHIPPING_RATE;
  }

  out << "\nTOTAL: $" << fixed << setprecision(2) << grandTotal << "\n";
  out.close();
}

int main() {
  ShelfProduct shelf[SHELF_SIZE];
  int cartCount = 0;
  Product fullCart[SHELF_SIZE];

  cout << "Loading items...." << endl;
  loadProductsIntoShelf(shelf);

  cout << "Welcome Customer!" << endl;
  printShelfItems(shelf);

  cout << "\n Cart Mode: Select items directly from shelf.\n";

  while (true) {
    int choice = getUserChoice();
    if (choice == 0)
      break;

    int idx = choice - 1;
    int qty = getQuantity();

    fullCart[cartCount] = initProduct(shelf[idx].name, shelf[idx].price, qty);
    fullCart[cartCount].shippingStatus = getShippingChoice();
    fullCart[cartCount].finalCost = applyDiscount(
        qty, shelf[idx].price, fullCart[cartCount].discountStatus);
    cartCount++;
  }

  printReceipt(fullCart, cartCount);

  string tmp;
  cout << "Save to file? (Y/N): ";
  getline(cin, tmp);
  if (tmp == "Y" || tmp == "y") {
    saveReceipt(fullCart, cartCount);
    cout << "Saved.\n";
  }

  return 0;
}
