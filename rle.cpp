#include <iostream>
#include <vector>
using namespace std;


string compressData(string data) {

    if (data == "") {
        return "";
    }

    vector<char> listChar;
    vector<int> amountChar;
    
    for(int i = 0; i < data.size(); i++) {
        listChar.push_back(data.at(i));
    }

    char currentKey = listChar.at(0);
    int hits = 0;
     for(int i = 0; i < listChar.size(); i++) {
        if(currentKey == listChar.at(i)) {
            hits++;
            
        } else {
            amountChar.push_back(hits);
            currentKey = listChar.at(i);
            hits = 1;
        }

        if(i == listChar.size() - 1){
            amountChar.push_back(hits);
        }
        
    }

    vector<char> invdChar;
    invdChar.push_back(data.at(0));
    int j = 0;
    for(int i = 1; i < data.size(); i++) {
        if(data.at(i) != invdChar.at(j)) {
            invdChar.push_back(data.at(i));
            j++;
        }
    }

    string result;

    for(int i = 0; i < invdChar.size(); i++) {
        result += to_string(amountChar.at(i));
        result += invdChar.at(i);
    }

    return result;
    
}

void errorCheck(string data) {
    
    for(int i = 0; i < data.size(); i++) {
        if(!islower(data.at(i))) {
            throw runtime_error("error: invalid input");
        }
    }
}

int main() {
    
    try { 

        string data;

        cout << "Enter the data to be compressed: " << endl;
        cin >> data;
        errorCheck(data);

        string result = compressData(data);
        cout << "The compressed data is: " << result;

        return 0;
        
    } catch (runtime_error expct) {
        cout << expct.what() << endl;
    }

}