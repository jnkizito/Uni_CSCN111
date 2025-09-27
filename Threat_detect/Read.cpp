#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(){

        std::ifstream inFile("threats.txt");
        std::string line;
 
        if (!inFile.is_open()) {
                std::cerr << "Error opening file. \n";
                return 1;
        }

        std::cout << "Threat Level Descriptions: \n";

        while(std::getline(inFile, line)) { 

                std::stringstream ss(line);//Define string stream as 'ss'
                std::string level, category, action;

                // - [ ] read comma-seperate values
                std::getline(ss, level, ','); // read until you encounter a comma
                std::getline(ss, category, ',');
                std::getline(ss, action, ',');

                //Format the output.
                std::cout << "level : " << level << " - category : " << category << " - action : " << action << std::endl << std::endl;

        }
        
       inFile.close(); 


        return 0
}


