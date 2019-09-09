#include <iostream>
using namespace std;

int main() {

    int a;
    int b;
    int c;
    int discriminant;

    cout << "Please enter the values of a, b, and c: ";
    cin >> a;
    cin >> b;
    cin >> c;

    discriminant = discriminantCalc(a, b ,c);

    if (discriminant > 0) {
        cout << "There are 2 solutions." << endl;
        cout << "The solutions are: <first_solution> and <second_solution>";
    } else if (discriminant == 0) {
        cout << "There is 1 solution." << endl;
        cout << "The solution is: <solution>";
    } else {
        cout << "There is no solution.";
    }


    
}

int discriminantCalc(int a, int b, int c){
    return (b * b) - (4*a*c);
}