#include <iostream>
#include <vector>
using namespace std;

int sortVector(vector<int> elements) {
    
    if(elements.size() < 2) {
        throw runtime_error("error: no second smallest");
    }

    int pointerSmaller = elements.at(0);
    int pointerSmallest = elements.at(0);

    for(int i = 0; i < elements.size(); i++){
        
        if(elements.at(i) < pointerSmallest) {
            pointerSmaller = pointerSmallest;
            pointerSmallest = elements.at(i);
        }

        if(elements.at(i) > pointerSmaller && pointerSmaller == pointerSmallest) {
            pointerSmaller = elements.at(i);
        } else if (elements.at(i) < pointerSmaller && pointerSmaller > pointerSmallest) {
            pointerSmaller = elements.at(i);
        }

    }

    if(pointerSmallest == pointerSmaller) {
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

    int result = sortVector(elements);

    cout << "The second smallest number is: " << result;

    } catch (runtime_error excpt) {
        cout << excpt.what() << endl;
    }

}