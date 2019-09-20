#include <iostream>
#include <vector>
using namespace std;

int findNumber(vector<int> elements) {
    
    if (elements.size() < 2) {
        throw runtime_error("error: no second smallest");
    }

    int pointerSmaller = INT32_MAX;
    int pointerSmallest = elements.at(0);
    int hit = 0;

    for(int i = 0; i < elements.size(); i++){
        if (elements.at(i) < pointerSmallest) {
            pointerSmallest = elements.at(i);
        }
    }

    for(int i = 0; i < elements.size(); i++){
        if (elements.at(i) <= pointerSmaller && pointerSmallest != elements.at(i)) {
            pointerSmaller = elements.at(i);
            hit++;
        }
    }

    if (hit == 0) {
        throw runtime_error("error: no second smallest");
    }

    return pointerSmaller;
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

    int result = findNumber(elements);

    cout << "The second smallest number is: " << result;

    } catch (runtime_error excpt) {
        cout << excpt.what() << endl;
    }
}