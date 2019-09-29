#include <iostream>
using namespace std;

void checkError(string vunetID) {
    
    if (vunetID.size() != 6) {
        throw runtime_error("error: size incorrect (is " + to_string(vunetID.size()) + ", should be 6)");
    }

    for(int i = 0; i < vunetID.size(); i++) {

        if (!isalpha(vunetID.at(i)) && i < 3) {
            throw runtime_error("error: letter expected at position " + to_string(i + 1));
        }
  
        if (!isdigit(vunetID.at(i)) && i >= 3) {
            throw runtime_error("error: digit expected at position " + to_string(i + 1));
        }
    }
}

int main() {
    
    try {

        string vunetID;
        
        cout << "Please enter a vunet id: ";
        cin >> vunetID;
        checkError(vunetID);
        cout << "The vunet id " + vunetID + " is valid";

    } catch (runtime_error excpt) {
        cout << excpt.what() << endl;
    }
}