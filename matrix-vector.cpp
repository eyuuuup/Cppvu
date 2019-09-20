#include <iostream>
#include <vector>
using namespace std;

vector<double> multiplication(vector< vector<double> > table, vector<double> coef) {
    vector<double> result(3, 0);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result.size(); j++){
            result.at(i) += table.at(i).at(j) * coef.at(j);
        }
    }


    return result;
}


int main() {

    vector< vector<double> > table(3, vector<double>(3));

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