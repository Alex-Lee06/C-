#include <pthread.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <omp.h>
#include <cmath>

using namespace std;

//Write a program that will generate a random array of integers. Then it will square the value of
//each entry of the array in parallel using the OpenMP for loop construct.


int main() {
  /* code */
int array_size;

srand(time(NULL));

cout<<"What would you like the size of the array to be?"<<endl;
cin>>array_size;
int array[array_size];
int result[array_size];
cout<<"First array is."<<endl;
for(int i = 0; i< array_size; i++)
{
  array[i] = rand() % 100 + 1;
  cout<<array[i]<<" ";
  result[i] = array[i] * array[i];
}
cout<<endl;
cout<<"Squared array."<<endl;
for(int i = 0; i<array_size; i++)
{
  cout<<result[i]<<" ";
}
  return 0;
}
