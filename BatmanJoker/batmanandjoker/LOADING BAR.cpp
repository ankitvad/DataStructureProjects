#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
using namespace std;

   
class maze
{
      char array[10][10];
      int adjacency_array[100][100];
      int i,j,k,l;
      int *batman_position;
      int *joker_position;
      char batman;
      char joker;
      char exit;
      
      public:
             void initialize_members();
             void create_maze();//#'s and " "'s
             void display_maze();
             void randomize_layout();//random open's and closes";
             void place_char();
             void move();
};

void maze::initialize_members()
{
      char batman='B';
      char joker='J';
       char exit='E';
};      
     
void maze::create_maze()
{
     for(int r=0;r<10;r++)
     {for(int c=0;c<10;c++)
     
     array[r][c]='#';
     //array[r][c]=':';
     }
};

void maze::display_maze()
{ for(int r=0;r<10;r++)
     {    for(int c=0;c<10;c++)
          {cout<<array[r][c]<<" ";}
     
     cout<<"\n";
     
     }
     
};
     
     
main()
{
      maze x;
      x.initialize_members();
      x.create_maze();
      x.display_maze();
      
      cout<<"\n";
      system("pause");
      /*
      srand(20);
      for(int m=0; m<20;m++)
      {
      int x=rand()%10;
      cout<<x;
      cout<<"\n";
      }
      unsigned long int i;
unsigned long int j;
      for (j=0;j<4000000000;j++)
      {}*/
      /*char hello[10][5][50];
      for (i=0;i<5;i++)
      {
         cin>>hello[10][i];
      } 
      for (i=0;i<5;i++)
      {
         cout<<hello[10][i]<<endl;
         
      }
      int x;
          int y;
          x=20;
          y=30;
          x=x+y;
          y=x-y;
          x=x-y;
      */
      /*for (i=0;i<4000000000;i++)
      {          
          
          cout<<"\\";
          for(unsigned long int j=0;j<100000000;j++)
          {}
          system("cls");
          cout<<"|";
          for(unsigned long int x=0;x<100000000;x++)
          {}
          system("cls");
          cout<<"/";
         for(unsigned long int z=0;z<100000000;z++)
          {}
          system("cls");
          cout<<"-";
          for(unsigned long int y=0;y<100000000;y++)
          {}
          system("cls");
          }*/
          
          
}

