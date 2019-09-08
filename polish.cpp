#include <iostream>
using namespace std;

int main() {

    char operators;
    double firstNumber;
    double secondNumber;
    double result;
    bool quit = true;

    while (quit) {
        cout << "Enter the expression: ";
        cin >> operators;
        if (operators == 'q') {
            quit = false;
            break;
        }
      
        cin >> firstNumber;
        cin >> secondNumber;

        switch (operators) {
            case '+':
                result = firstNumber + secondNumber;
                break;
            
            case '-':
                result = firstNumber - secondNumber;
                break;

            case '*':
                result = firstNumber * secondNumber;
                break;

            case '/':
                result = firstNumber / secondNumber;
                break;
            
            default:
                cout << "Wrong operator inserted" << endl;
        }

        cout << firstNumber << " " << operators << " " << secondNumber << " = " << result << endl;
    }

}