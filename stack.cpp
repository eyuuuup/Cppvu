#include <iostream>
#include <vector>
using namespace std;

class Stack {
    public:
        bool isEmpty();

        int top();

        int pop();

        void push(int);
    
    private:
        vector<int> elements;
};

bool Stack::isEmpty() {
    if(elements.empty()) {
        return true;
    } else {
        return false;
    }
}

int Stack::top() {
    
    if(!isEmpty()) {
        return elements.front();
    }
    
}

int Stack::pop() {

    if(!isEmpty()) {
        int element = elements.front();

        vector<int> tooLazy;
        for(int i = 1; i < elements.size(); i++) {
            tooLazy.push_back(elements.at(i));
        }
        elements = tooLazy;
        return element;
    }

}

void Stack::push(int element) {
    elements.insert(elements.begin(), element);
}


int main() {

    Stack elements;

    bool continueProgram = true;
    while(continueProgram) {
        cout << "stack> ";

        string command;
        cin >> command;

        if(command == "end" || cin.eof()){
            continueProgram = false;
            break;
        }

        if (command == "push") {
            
            string element;
            cin >> element;

            if(cin.fail()) {
                cout << "error: not a number" << endl;
            } else {
                int number = (int) element.at(0) - '0';
                if(number > 9) {
                    cout << "error: not a number" << endl;
                } else {
                    elements.push(number);
                }
            }

            
        } else if (command == "pop") {
            
            if(elements.isEmpty()){
                cout << "error: stack is empty" << endl;
            } else {
                cout << elements.pop() << endl;
            }
            
        } else if (command == "top") {
            
            if(elements.isEmpty()){
                cout << "error: stack is empty" << endl;
            } else {
                cout << elements.top() << endl;
            }

        } else if (command == "list") {
            Stack tempStorage = elements;
        
            cout << "[";

            bool comma = true;
            while(!elements.isEmpty()) {
                if(comma) {
                    cout << elements.pop();
                    comma = false;
                } else {
                    cout << "," << elements.pop();
                }
                
            }

            elements = tempStorage;
            cout << "]" << endl;

        } else {
            cout << "error: invalid command" << endl;
        }

    }
}