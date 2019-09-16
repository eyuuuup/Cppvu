#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

double discriminantCalc(double a, double b, double c) {
    return (b * b) - (4*a*c);
}

vector<double> solutionCalc (double a, double b, double c, bool two) {
    if (two) {
        double positive = (-b + sqrt( (b*b) - (4*a*c) )) / (2 * a);
        double negative = (-b - sqrt( (b*b) - (4*a*c) )) / (2 * a);
        vector<double> sol = {positive, negative};
        return sol;
    } else {
        double positive = (-b + sqrt( (b*b) - (4*a*c) )) / (2 * a);
        vector<double> sol = {positive};
        return sol;
    }
}

vector<double> checkError() {
        double a;
        double b;
        double c;
        
        cin >> a;
        cin >> b;
        cin >> c;

        if (cin.fail()) {
            throw runtime_error("An error occurred: Malformed user input");
        }

         if (a == 0) {
            throw runtime_error("An error occurred: a must not be zero");
        }

        vector<double> elements = {a, b, c};
        return elements;
}

int main() {

    try{
        double a;
        double b;
        double c;
        double discriminant;

        cout << "Please enter the values of a, b, and c: " << endl;
        
        vector<double> elements(3);
        elements = checkError();
        a = elements.at(0);
        b = elements.at(1);
        c = elements.at(2);


        discriminant = discriminantCalc(a, b ,c);

        if (discriminant > 0) {
            cout << "There are 2 solutions." << endl;
            vector<double> solution =  solutionCalc(a, b ,c, true);
            cout << "The solutions are: " << solution.at(0) << " and " << solution.at(1) << endl;
        } else if (discriminant == 0) {
            cout << "There is 1 solution." << endl;
            cout << "The solution is: " << solutionCalc(a, b, c, false).at(0) << endl;
        } else {
            cout << "There is no solution." << endl;
        }
    } catch (runtime_error& excpt) {
        cout << excpt.what() << endl;
    }
}