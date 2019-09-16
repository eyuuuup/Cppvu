#include <iostream>
#include <vector>
using namespace std;

int sortVector(vector<int> elements) {
    
    if(elements.size() < 2) {
        throw runtime_error("error: no second smallest");
    }

    for (int i = 0; i < elements.size() - 1; i++) {
        int min = i;
        for (int j = i + 1; j < elements.size(); j++) {
            if (elements.at(j) < elements.at(min)) {
                min = j;
            }
        }

        int temp = elements.at(i);
        elements.at(i) = elements.at(min);
        elements.at(min) = temp;
    }

    int smallest = elements.at(0);
    int secondSmallest;
    int hit;

    for (int i = 0; i < elements.size(); i++) {
        if (elements.at(i) != smallest) {
            secondSmallest = elements.at(i);
            hit++;
            break;
        }
    }

    if (hit == 0) {
        throw runtime_error("error: no second smallest");
    }

    return secondSmallest;
}

int main() {

    try { 
    cout << "Enter the numbers in random order: (close by entering q)" << endl;

    vector<int> elements;

    bool con = true;
    while(con) {

        int number;
        cin >> number;

        if (cin.fail()) {
            break;
            con = false;

        } else {
            elements.push_back(number);
        }
    }

    int result = sortVector(elements);

    cout << "The second smallest number is: " << result;

    } catch (runtime_error excpt) {
        cout << excpt.what() << endl;
    }

}