#include <chrono>
#include <iostream>
#include <ctime>
#include <ratio>
int main()
{
  using namespace std::chrono;

high_resolution_clock::time_point t1 = high_resolution_clock::now();
  int array[100000];
  int array2[100000];
  int array3[100000];

  for(int i = 0; i<100000; i++)
  {

    array[i] = array2[i] + array3[i];

  }

  high_resolution_clock::time_point t2 = high_resolution_clock::now();

duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

std::cout << "It took me " << time_span.count() << " seconds.";
std::cout << std::endl;
return 0;
}
