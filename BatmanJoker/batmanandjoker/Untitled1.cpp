//function approach
#include<iostream>
#include<stdlib.h>
using namespace std;

main()
{
int x;
x=rand()%20;      
srand(x);
for(int i=0;i<50;i++)
{
cout<<rand()%30<<"\n";
}

system("pause");
}
