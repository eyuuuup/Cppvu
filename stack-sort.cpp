#include <iostream>
#include <stack>
#include <fstream>
using namespace std;

void insertStack(stack<int>& stack, int original) {

    if (!stack.empty()) {
        int compare = stack.top();

        if(original < compare) {
            stack.push(original);
        } else {
            stack.pop();
            insertStack(stack, original);
            stack.push(compare);
        }
    } else {
        stack.push(original);
    }
}

void sortStack(stack<int>& stack) {
    
    if(!stack.empty()) {
        int original = stack.top();
        stack.pop();
        sortStack(stack);
        insertStack(stack, original);
    }
    
}

int main(int argc, char* argv[]) {

    string fileName;
    stack<int> stack;
    ifstream inputStream;
    int original;

    if(argc < 2) {
        cout << "an error occured: no input file name given" << endl;
        return 1;
    }

    fileName = argv[1];

    inputStream.open(fileName);

    if(!inputStream.is_open()) {
        cout << "an error occured: could not open input file " << fileName << endl;
        return 1;
    }

    while(!inputStream.eof()) {
        inputStream >> original;
        if (!inputStream.fail()) {
            stack.push(original);
        } else {
            break;
        }
    }

    inputStream.close();

    if(stack.size() > 2) {
        sortStack(stack);
    }

    while(!stack.empty()) {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;

    return 0;
    
}