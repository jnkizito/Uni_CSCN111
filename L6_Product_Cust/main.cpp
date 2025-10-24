//Joseph Kizito

#include <iostream> 
#include <fstream>
#include <string>
using namespace std;

// function to generate final invoice
// function to calculate subtotal

double calcSubTotal(double itemPrice, int itemMultiplier){
        double subTotal = itemPrice * itemMultiplier;
        return subTotal;
}


void genFinalInvoice(string itemName, double itemPrice, int multiplier, double shippingCost, double taxRate, double discountRate){
        double subtotal = 0;
        subtotal = calcSubTotal(itemPrice, multiplier);
        double discountAmount = subtotal * (discountRate / 100);
        double discounted = subtotal - discountAmount;
        double discountedTotalWithShipping = discounted + shippingCost;
        double taxAmount = discountedTotalWithShipping * taxRate;
        double taxedSubtotal = discountedTotalWithShipping + taxAmount;


        //Now, that calc is done, should be able to just print it all out.
        cout << "PRODUCT INVOICE\n";
        cout << "Payable To: Joseph's Wacky Linux Centre\n";
        cout << "Test Product #001: \n"<< itemName<< "\n";
        cout << "-------------------------------\n";
        cout << "Quantity:" << multiplier << "\n";
        cout << "x price:       $ "<< itemPrice << "\n";
        cout << "Cost:          $ " << subtotal << "\n";
        cout << "- discount:    $ " << discountAmount << "\n";
        cout << "+ shipping:    $ " << shippingCost << "\n";
        cout << "Subtotal:      $ " << discountedTotalWithShipping << "\n";
        cout << "+ Tax:         $ " << taxAmount << "\n";
        cout << "Total:         $ " << taxedSubtotal << "\n";
}

int main(){

        //Bring in the values from the file
        fstream inputFile("input.txt");

        string itemName;
        double itemPrice;

        string priceString;
        string amountString;

        //reading to the variables, line by line
        while(getline(inputFile, itemName)){
                getline(inputFile, priceString);
                getline(inputFile, amountString);

                itemPrice = stod(priceString);

                cout << itemName << endl;
                cout << itemPrice << endl;
                
        }

        //tracking variables
        bool running = true;
        bool shippingAdded = false;
        bool discountAdded = false;
        bool multiplierAdded = false;

        double subTotal = 0.0;
        double discountRate = 0.0;
        int multiplier = 1;

        double SHIPPING_COST = 10.0;
        double TAX_RATE = 0.04;


        while(running){

                char userChoice;

                cout << "\n--- Product Customization Menu ---\n";
                cout << "[S] Add shipping\n";
                cout << "[D] Apply discount\n";
                cout << "[M] Set multiplier\n";
                cout << "[Q] Quit\n";
                cout << "Choose an option: ";
                cin >> userChoice;

                userChoice = toupper(userChoice);

                //shipping
                if(userChoice == 'S' && !shippingAdded){
                        shippingAdded = true;
                        cout << "Shipping Cost added" << endl;
                }

                //check discount
                if(userChoice == 'D' && !discountAdded){
                        cout << "Enter a whole number: %: ";
                        cin >> discountRate;
                        discountAdded = true;
                        cout << "Discount added" << endl;
                }

                //check mult 
                if(userChoice == 'M' && !multiplierAdded){
                        cout << "Enter a whole number: (ex. 2 for two items) : ";
                        cin >> multiplier;
                        multiplierAdded = true;
                        cout << "Multiplier Added" << endl;
                }

                // Quit
                if(userChoice == 'Q'){
                        running = false;
                }

                if (shippingAdded && discountAdded && multiplierAdded){
                        running = false;
                }
       }

        genFinalInvoice(itemName, itemPrice, multiplier, SHIPPING_COST, TAX_RATE, discountRate);
 
        inputFile.close();
}

