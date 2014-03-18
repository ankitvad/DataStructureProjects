#include<iostream>
#include <time.h>
using namespace std;

int main()
{
  int num;
  int prime;
clock_t t;
  cout << "Please enter a positive integer" << endl;
  cin >> num;
  int max=num-2;
  int array[max];
  int i=0;
  for(int j=2;j<num;j++)
  {
    array[i]=j;
    i++;
  }

t=clock();
  for(int i = 3; i <= num; i++)
  {
    prime =1;
    for(int n = 2; n <= i - 1; n++){
      if(i % n == 0)
      {
        prime = 0;
      }
    }
    if(!prime)
    {      
    cout<<"\n composite is:"<<i;
    }
  }


t=clock()-t;
cout<<"\n";
cout<<"It took me "<<t<<"clicks which is equal to :"<<((float)t)/CLOCKS_PER_SEC<<" seconds";

  return 0;
}