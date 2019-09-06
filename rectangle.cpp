#include <iostream>
#include <string>
#include <math.h>

int main(){

    int length;
    int width;
    int perimeter;
    int area;
    float diagonal;

    std::cout << "Please enter the length and width of the rectangle: " << std::endl;
    std::cin >> length;
    std::cin >> width;

    perimeter = length * 2 + width * 2;
    area = length * width;
    diagonal = sqrt(length * length + width * width);

    std::cout << "The perimeter: " << perimeter << " area: " << area  << "," << " and diagonal " << diagonal;

}
