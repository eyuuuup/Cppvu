#include <iostream>
#include <vector>
using namespace std;

vector<double> multiplication(vector< vector<double> > table, vector<double> coef) {
    vector<double> result(3);
    result.at(0) = table.at(0).at(0) * coef.at(0) + table.at(0).at(1) * coef.at(1) + table.at(0).at(2) * coef.at(2);
    result.at(1) = table.at(1).at(0) * coef.at(0) + table.at(1).at(1) * coef.at(1) + table.at(1).at(2) * coef.at(2);
    result.at(2) = table.at(2).at(0) * coef.at(0) + table.at(2).at(1) * coef.at(1) + table.at(2).at(2) * coef.at(2);
    return result;
}


int main() {

    vector< vector<double> > table = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };
    vector<double> coef(3);
    vector<double> result(3);

    cout << "Please enter the three vector coefficients" << endl;
    cin >> coef.at(0);
    cin >> coef.at(1);
    cin >> coef.at(2);

    result = multiplication(table, coef);
    

    cout << "The result vector is [" << result.at(0) << ", " << result.at(1) << ", " << result.at(2) << "]";
    
}