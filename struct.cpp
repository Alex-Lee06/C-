#include <iostream>
#include <cmath>
#include <string>
using namespace std;

struct Point{
  float x;
  float y;
};

float calculateDistance(float *x, float *y)
{
  float result;


  result = sqrt(pow(*x,2)+pow(*y,2));
  return result;
}
//Main function to ask the user for 2 points and calls the calculating distance.
int main()
{
  Point p1, p2;
  float result1,x, y;

    cout<< "Please enter the X and X2 Coordanite for the first point.";
    cin >> p1.x >> p2.x;
    cout<< "Please enter the Y and Y2 Coordanite for the second point."<<endl;
    cin>>p1.y>>p2.y;
    x = p2.x - p1.x;
    y = p2.y - p1.y;


  result1 = calculateDistance(&x, &y );
  cout << "The result is: " << result1;
  return 0;
}
