#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>

int main()
{

double time;
int size = 1024*1024*1024;
int sum;
  using namespace std::chrono;

  high_resolution_clock::time_point t1 = high_resolution_clock::now();

  for(int i=0; i < size; i++)
  {
    sum += array[i];
  }
    sum += array[i];

  high_resolution_clock::time_point t1 = high_resolution_clock::now();

  duration<double> time_span = duration_cast<duration_cast<duration<double>>(t2-t1);

  std::cout<<"Time it took "<<time_span.count() << " seconds.";
  std::cout<< std::endl;

  return 0;

}
