#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& elements) {
    
    for(int i = 1; i < elements.size(); i++) {
        int key = elements.at(i);
        int j = i - 1;

        while (j >= 0 && elements.at(j) > key) {
            elements.at(j + 1) = elements.at(j);
            j--;
        }
        elements.at(j + 1) = key;
    }
}

int main() {
    
    try {
        int size;
        cout << "Please enter the number of elements: ";
        cin >> size;

        if (cin.fail()) {
            throw runtime_error("error: invalid input");
        }

        vector<int> elements;
        cout << "Enter the list to be sorted: ";

        int hit = 0;
        while(hit < size) {

            int number;
            cin >> number;

            if (cin.fail()) {
                throw runtime_error("error: invalid input");
            } 
            elements.push_back(number);
            hit++;
        }

        insertionSort(elements);

        cout << "The sorted list is: ";
        for(int i = 0; i < elements.size(); i++) {
             cout << elements.at(i) << " ";
        }
        
    } catch (runtime_error expct) {
        cout << expct.what() << endl;
    }
    
}