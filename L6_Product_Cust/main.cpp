//Joseph Kizito

#include <iostream> 
#include <fstream>
#include <string>
using namespace std;

int main(){

        //Bring in the values from the file
        fstream inputFile("input.txt");

        string itemName;
        double itemPrice;
        int itemAmount;

        string priceString;
        string amountString;

        //reading to the variables, line by line
        while(getline(inputFile, itemName)){
                getline(inputFile, priceString);
                getline(inputFile, amountString);

                itemPrice = stod(priceString);
                itemAmount = stoi(amountString);

                cout << itemName << endl;
                cout << itemPrice << endl;
                cout << itemAmount << endl;
                
        }

        //tracking variables
        bool running = true;
        bool shippingAdded = false;
        bool discountAdded = false;
        bool multiplierAdded = false;

        double subTotal = 0.0;
        double shippingCost = 0.0;
        double discountRate = 0.0;
        int multiplier = 1;


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
                        shippingCost = 15.0;
                        shippingAdded = true;
                        cout << "Shipping Cost added" << endl;
                }

                //check discount
                if(userChoice == 'D' && !discountAdded){
                        cin >> discountRate;
                        discountAdded = true;
                        cout << "Discount added" << endl;
                }

                //check mult 
                if(userChoice == 'M' && !multiplierAdded){
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

        // final cost calculation
        double subtotal = itemPrice * multiplier;
        double discounted = subtotal - (subtotal * (discountRate / 100));
        double total = discounted + shippingCost;
 
        inputFile.close();
}

