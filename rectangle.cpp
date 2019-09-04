#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main(){
    int length;
    int width;
    int perimeter;
    int area;
    float diagonal;

    cout << "Please enter the length and width of the rectangle: " << endl;
    cin >> length;
    cin >> width;

    perimeter = length * 2 + width * 2;
    area = length * width;
    diagonal = sqrt(length * length + width * width);

    cout << "The perimeter: " << perimeter << " area: " << area  << "," << " and diagonal " << diagonal;

}
