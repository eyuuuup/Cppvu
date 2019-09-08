#include <iostream>
#include <vector>
using namespace std;

int main() {

    int elements;
    int partial;

    cout << "Summing up 1 to n, please enter n: ";
    cin >> elements;

    cout << "Which partial sum (1+...+x) would you like to know? Please enter x<=n: ";
    cin >> partial;

    vector<int> sum(elements);
    sum.at(0) = 1;
    for(int i = 1; i < elements; i++) {
        sum.at(i) = sum.at(i - 1) + i + 1;
    }

    for(int i = 1; i < partial; i++) {
        cout << i << "+";
    }
    cout << partial << " = " << sum.at(partial - 1) << endl;

    cout << "The entire sequence of partial sums up to " << elements << " is: ";
    for(int i = 0; i < sum.size(); i++) {
        cout << sum.at(i) << " ";
    }

}