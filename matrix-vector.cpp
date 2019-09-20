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

    vector< vector<double> > table(3, vector<double>(2));

    double element = 1.0;
    for(int i = 0; i < table.size(); i++){
        for(int j = 0; j < table.at(i).size(); j++){
            table.at(i).at(j) = element;
            element++;
        }
    }
    vector<double> coef(3);
    vector<double> result(3);

    cout << "Please enter the three vector coefficients" << endl;
    cin >> coef.at(0);
    cin >> coef.at(1);
    cin >> coef.at(2);

    result = multiplication(table, coef);
    

    cout << "The result vector is [" << result.at(0) << ", " << result.at(1) << ", " << result.at(2) << "]";
    
}