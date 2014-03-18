#include<iostream>
#include <time.h>
using namespace std;

int main()
{
  int num;
  bool prime;
clock_t start,end;
double msecs;
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

//t=clock();
  start = clock();
for (int p=2; p<=num; p++)
{int c=2;
                int mul = p*c;
                while(mul<num)
                	{   cout<<"Composite is:"<<mul<<"\n";
                		
	 	 	            c++;
                        mul = p*c;
                     }
			

}
end = clock();



//cout<<"It took me "<<t<<"clicks which is equal to :"<<((float)t)/CLOCKS_PER_SEC<<" seconds";
msecs = ((double) (end - start))/* * 1000*// CLOCKS_PER_SEC;
cout<<"\n"<<msecs<<" seconds";

  return 0;
}