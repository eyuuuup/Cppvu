#include <iostream>
#include <stack>
#include <fstream>
using namespace std;

void insertStack(stack<int>& s, int number) {
    
    if (!s.empty()) {

        int compare = s.top();

        if(number > compare) {
            s.pop();
            insertStack(s, number);
            s.push(compare);
        } else {
            s.push(number);
        }
    } else {
        s.push(number);
    }
}

void sortStack(stack<int>& s) {
    
    if(!s.empty()) {
        int number = s.top();
        s.pop();
        sortStack(s);
        insertStack(s, number);
    }
    
}

int main(int argc, char* argv[]) {

    string fileName;
    stack<int> s;
    ifstream inFS;
    int number;

    if(argc < 2) {
        cout << "an error occured: no input file name given" << endl;
        return 1;
    }

    fileName = argv[1];

    inFS.open(fileName);

    if(!inFS.is_open()) {
        cout << "an error occured: could not open input file " << fileName << endl;
        return 1;
    }

    while(!inFS.eof()) {
        inFS >> number;
        if (!inFS.fail()) {
            s.push(number);
        } else {
            break;
        }
    }

    inFS.close();

    if(s.size() > 2) {
        sortStack(s);
    }

    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
    
}