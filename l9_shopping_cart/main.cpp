// Joseph.K
// TUE 25TH NOV 2025
// Shoppong Cart

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

const int SHELF_SIZE = 10;

struct ShelfProduct {
  string name;
  string price;
};

struct Product {
  string name;
  double price;
  int quantityOrdered;
  bool discountStatus;
  bool shippingStatus;
};

void loadProductsIntoShelf();

Product initProduct(string name, double price, int quantityOrdered) {
  Product prototype = {name, price, quantityOrdered};
  return prototype;
}

Product applyDiscount(Product ProductNoDiscount, double totalPrice);
// if statement, if discountStatus, apply fixed discount, if not, return as is.

Product applyShipping(Product productNoShipping, double totalPrice);
// if statement, if shippingStatus, apply fixed shipping, maybe implement
// distance based shipping ?

int main() {

  ShelfProduct shelf[SHELF_SIZE];

  // Init vars
  int CART_SIZE = 0;
  string tmp;

  // Dynamic Cart size
  cout << "Please tell us how many items you'll be purchasing today : ";
  getline(cin, tmp);
  CART_SIZE = stoi(tmp);

  // Setting cart, Cart size success
  string shoppingCart[CART_SIZE];
  cout << CART_SIZE;

  return 0;
}
