#include <iostream>
using namespace std;

int main() {
    
    int initValue;
    int count = 0;

    cout << "Enter the first number of the sequence: ";
    cin >> initValue;
    cout << endl;
    
    while (count != 3) {
        cout << initValue << " ";

        if (initValue == 1) {
            count++;
        }

        int mod = initValue % 2;
        if (mod == 0) {
            initValue = initValue / 2;
        } else {
            initValue = 3 * initValue + 1;
        }
    
    }
    cout << "...";

    return 0;
}
