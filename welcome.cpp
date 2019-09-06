#include <iostream>
#include <string>
using namespace std;

int main() {

    string firstName;
    string lastName;
    int age;
    float height;
    
    cout << "Enter your first name: " << endl;
    cin >> firstName;
    cout << "Enter your last name: " << endl;
    cin >> lastName;
    cout << firstName << ", enter your age: " << endl;
    cin >> age;
    cout << firstName << ", enter your height in meters: " << endl;
    cin >> height;
    cout << endl;

    cout << "Hello " << firstName << "," << endl;
    cout << "Welcome to Computer Programming. You entered the following information: " << endl;
    cout << "Full name: " << firstName << " " << lastName << endl;
    cout << "Age: " << age << endl;
    cout << "Height: " << height << endl << endl;
    cout << "We hope you will enjoy the course!";

    return 0;
}
