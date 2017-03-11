#include <iostream>
#include <chrono>
#include <stdlib.h>
using namespace std;
int math(float f, int c){
  float result;
for(int i = 0; i<999999; i++)
{
  result = f+c*(f/c);
  return result;
}
}

int main()
{
  int z;
  chrono::steady_clock::time_point start = chrono::steady_clock::now(); // Start Chrono time count

  z = math(5.6,3);
  cout << "The answer is: " << z<<endl;
  chrono::steady_clock::time_point end = chrono::steady_clock::now();// end chrono time count
  chrono::steady_clock::duration d = end - start;
  cout<<"Time is: "<<chrono::duration_cast<chrono::nanoseconds>(d).count()<<" nanoseconds."<<endl;


  return 0;
}
