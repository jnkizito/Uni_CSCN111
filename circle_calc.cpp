// Joseph Kizito
// 09/01/2025

#include <cmath>
#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>

using namespace std;

int main(){
        double radius = 0.0; area = 0.0; circumference = 0.0; diameter = 0.0;
        // const double M_PI = 3.14
        
        //prompt for radius
        cout<< "Enter your radius: " << endl;
        cin >> radius;

        //Circle calculations
        diameter = 2 * radius;
        circumference = 2 * M_PI * radius;
        area = M_PI * pow(radius, 2.0);

        //now print em ouot

        
}


