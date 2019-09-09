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

int main() {

    double a;
    double b;
    double c;
    double discriminant;

    cout << "Please enter the values of a, b, and c: ";
    cin >> a;
    cin >> b;
    cin >> c;

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
}