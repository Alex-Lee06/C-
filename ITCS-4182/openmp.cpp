#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <omp.h>// used for openmp
#include <cmath>
#include <chrono>// used for chrono time counter

using namespace std;

//Write a program that will generate a random array of integers. Then it will square the value of
//each entry of the array in parallel using the OpenMP for loop construct.

int main() {
int array_size;
int thread_count;
int dynm_number;
char policy;
srand(time(NULL));

cout<<"What would you like the size of the array to be?"<<endl;
cin>>array_size;
cout<<"How many threads would you like to use?"<<endl;
cin>>thread_count;
cout<<"Pick scheduling policy (s, d)."<<endl;
cin>>policy;
if (policy == 'd')
  {
    cout<<"Pick number of dynamics."<<endl;
    cin>>dynm_number;
  }
int array[array_size];
int result[array_size];

for(int i = 0; i< array_size; i++)
{
  array[i] = rand() % 100 + 1;
}// end of for loop
cout<<endl;
chrono::steady_clock::time_point start = chrono::steady_clock::now(); // Start Chrono time count
#pragma omp parallel num_threads(thread_count)//set the number of threads and open mp parallel to start
{
#pragma omp master// not sure what this does but it allows me to set my threads.
cout<<"Number of threads "<<omp_get_num_threads()<<endl;// show the number of threads
if(policy == 's')
{
  #pragma omp for schedule(static)
    for(int i = 0; i<array_size; i++)
    {
      result[i] = array[i] * array[i];
    }// end of for loop
}
if(policy == 'd' && dynm_number == 1)
{
#pragma omp for schedule(dynamic,1)
  for(int i = 0; i<array_size; i++)
  {
    result[i] = array[i] * array[i];
  }// end of for loop
}
// dynamic = 1000
if(policy == 'd' && dynm_number == 1000)
{
#pragma omp for schedule(dynamic,1000)
  for(int i = 0; i<array_size; i++)
  {
    result[i] = array[i] * array[i];
  }// end of for loop
}
// dynamic = 100000
if(policy == 'd' && dynm_number == 100000)
{
#pragma omp for schedule(dynamic,100000)
  for(int i = 0; i<array_size; i++)
  {
    result[i] = array[i] * array[i];
  }// end of for loop
}
}// end of parallel openmp
chrono::steady_clock::time_point end = chrono::steady_clock::now();// end chrono time count
chrono::steady_clock::duration d = end - start; // figures out the time of squaring the array.
if(d == chrono::steady_clock::duration::zero())
  cout<<"NO TIME ELAPSED"<<endl;
cout<<"Time is: "<<chrono::duration_cast<chrono::nanoseconds>(d).count()<<" nanoseconds."<<endl;

  return 0;
}
