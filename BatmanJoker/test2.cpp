#define PB push_back
#define SZ size()

#include <vector>
#include <iostream>
#include <utility>
#include <stdlib.h>
#include <string>
using namespace std;

template <typename T>
void graph_from_maze(int cols, int rows, std::vector<T> &maze, T obstacle, std::vector<int> adjacency_list[]) 
{
    for (int y = 0; y < rows; ++y)
      {  for (int x = 0; x < cols; ++x) 
        {
            int pos = x + y*cols, up = pos - cols, down = pos + cols, left = pos -1, right = pos + 1;
            if(x != 0 && (maze[left] != obstacle) && (maze[pos] != obstacle))
                adjacency_list[pos].push_back(left);
            if( y != 0 && (maze[up] != obstacle) && (maze[pos] != obstacle))
                adjacency_list[pos].push_back(up);
            if( x < (cols-1) && (maze[right] != obstacle) && (maze[pos] != obstacle))
                adjacency_list[pos].push_back(right);
            if(y < (rows-1) && (maze[down] != obstacle) && (maze[pos] != obstacle))
                adjacency_list[pos].push_back(down);
        }

      }  
      
      
}
using namespace std;

int N;                  // number of nodes
vector<int> A[10001];   // adjacency lists

int BFS(int s, int t) //BFS to find route..
{ // distance between s and t
  if (s == t) 
  {
    cout<<"\n Same Position Occupied by Start and End cell.";
    return 0;
  }

  int l[10001], k = 0;  //initialize queue max condition 1001, 100x100.
  vector<int> v(N, -1); // initialize distances(vector-array)->each value for N is=-1, initially.
  l[k++] = s;           // Add to the queue; added then k incremented.
  
  v[s] = 0;             // distance to s is 0
  for (int i = 0; i < k; i++)
    // for all adjacent nodes l [i]
    for (int j = 0; j < (int)A[l[i]].SZ; j++)
      // if the neighbor has not been visited
      if (v[A[l[i]][j]] < 0) 
      {
        // update its distance
        v[A[l[i]][j]] = v[l[i]] + 1;
        // find t and, return result
    if (A[l[i]][j] == t) return v[t];
        // added to queue
    l[k++] = A[l[i]][j];
      }

      
  return -1;
}

int main() 
{cout<<"\n \t\t\tWelcome to Batman-and-Joker..\n";
cout<<" \t\t\t\t  LOADING..\n\n";
//LOADING BAR, JUST FOR THE PRETTY-NESS ;)
float progress = 0.0;
while (progress < 1.0) 
{
    int barWidth = 50;

    cout << "\t\t[";
    int pos = barWidth * progress;
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos) std::cout << "|";
        else if (i == pos) std::cout << ">";
        else std::cout << " ";
    }
    cout << "] " << int(progress * 100.0) << " %%\r";
    cout.flush();
    

    progress += 0.00003; // for demonstration only
}
system("clear");
cout<<"\n \t\t\tWelcome to Batman-and-Joker..\n\n\n";
cout<<"    :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
cout<<"    :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
cout<<"    :::::::::::::::::::::::::::::::::::::::::::::-'    `-::::::::::::::::::\n";
cout<<"    ::::::::::::::::::::::::::::::::::::::::::-'          `::::::::::::::::\n";
cout<<"    :::::::::::::::::::::::::::::::::::::::-  '   /(_M_)\\  `:::::::::::::::\n";
cout<<"    :::::::::::::::::::::::::::::::::::-'        |       |  :::::::::::::::\n";
cout<<"    ::::::::::::::::::::::::::::::::-         .   \\/~V~\\/  ,:::::::::::::::\n";
cout<<"    ::::::::::::::::::::::::::::-'             .          ,::::::::::::::::\n";
cout<<"    :::::::::::::::::::::::::-'                 `-.    .-::::::::::::::::::\n";
cout<<"    :::::::::::::::::::::-'                  _,,-::::::::::::::::::::::::::\n";
cout<<"    ::::::::::::::::::-'                _,--:::::::::::::::::::::::::::::::\n";
cout<<"    ::::::::::::::-'               _.--::::::::::::::::::::::#####:::::::::\n";
cout<<"    :::::::::::-'             _.--:::::::::::::::::::::::::::#####:::::####\n";
cout<<"    ::::::::'    ##     ###.-::::::###:::::::::::::::::::::::#####:::::####\n";
cout<<"    ::::-'       ###_.::######:::::###::::::::::::::#####:##########:::####\n";
cout<<"    :'         .:###::########:::::###::::::::::::::#####:##########:::####\n";
cout<<"         ...--:::###::########:::::###:::::######:::#####:##########:::####\n";
cout<<"     _.--:::##:::###:#########:::::###:::::######:::#####:#################\n";
cout<<"     _.--:::##:::###:#########:::::###:::::######:::#####:#################\n";
cout<<"     _.--:::##:::###:#########:::::###:::::######:::#####:#################\n";
cout<<"    '#########:::###:#########::#########::######:::#####:#################\n";
cout<<"    :#########:::#############::#########::######:::#######################\n";
cout<<"    ##########:::########################::################################\n";
cout<<"    ##########:::##########################################################\n";
cout<<"    ##########:::##########################################################\n";
cout<<"    ################### BATMAN ## AND ## THE ## JOKER #####################\n";
cout<<"    #######################################################################\n";
cout<<"    ### BY: ###### 12BCE0282 ## 12BCE0277 ## 12BCE0622#####################\n";
cout<<"    #######################################################################\n";

cout<<"\n\n\t\t Preparing Format:";
int choice;
cout<<"\nPlease enter the number correspoding to your choice:\n1.To Enter Game\t2.To Exit";
cin>>choice;
switch(choice)
{
  case 1: cout<<" \t\t\tWelcome to Batman-and-Joker..\n\n\n";
          system("clear");
          break;
  case 2: exit(0);
          break;
  default: cout<<"\n Please enter a correct number :/";

}

cout<<"\n How many times do you want to run the program ??";
  int runs;
  cin >> runs;
  for(int run = 0; run < runs; run++) 
  {
    int col, row;
    vector<int> map;
    cout<<"\nPlease enter the number of Rows in the Matrix\n";
    cin>>row;
    cout<<"\nPlease enter the number of Columns in the Matrix\n";
    cin >> col;
    N = col*row;//adjaceny list..
    int display_array[row][col];
    int display_array2[row][col];
    int number=0;
    for(int i=0;i<row;i++)
    {
      for(int j=0; j<col; j++)
        display_array[j][i]=number++;
    }

    cout<<"\nHence the matrix is numbered as:\n";
    for(int a=0;a<row;a++)
    {
      for(int b=0; b<col; b++)
        {cout<<display_array[a][b]<<"\t";}
      cout<<"\n\n";
    }
    cout<<"\nPlease enter 1||0, respetively for an Obstacle or an Empty cell:";
    cout<<"\n0=Empty Space..1=Obstacle in path";
    cout<<"\nSpecified Format: \nFor a 2x2 matrix enter y y y y; where y=0||1\n";
    for (int y = 0; y < row; ++y)
    {
      for (int x = 0; x < col; ++x)
      {
        int cell;
        cin >> cell;
        map.PB(cell);
        display_array2[y][x]=cell;
      }
    }
    cout<<"\nEnter Batman's position from 0 to "<<N-1<<" ";
    int start, end;
    //int coordX, coordY;
    //cin >> coordX >> coordY;
    cin>>start; //= coordX + coordY*col ;
    cout<<"\nEnter The Jokers position from 0 to "<<N-1<<" ";
    //cin >> coordX >> coordY;
    cin>>end; //= coordX + coordY * col;
    
    //Character array so 0 and position of 1 can be shown..
    //Making Map
    //To Add B & J..
    char made_array[row][col];
    for(int q=0;q<row;q++)
    {
      for(int w=0; w<col;w++)
      {
        if(display_array[q][w]==start)
        made_array[q][w]='B';
      else
        if(display_array[q][w]==end)
          made_array[q][w]='J';
      else
        if(display_array2[q][w]==0)
        made_array[q][w]='-';
      else
        if(display_array2[q][w]==1)
          made_array[q][w]='x';
      }
      
    }

    //Printing maze:
    cout<<"\n Hence the Maze Created Is:\n";
    for(int a=0;a<row;a++)
    {
      for(int b=0;b<col;b++)
      {
        cout<<made_array[a][b]<<" ";

      }
      cout<<"\n";
    }
    
    graph_from_maze<int>(col, row, map, 1, A);
    cout<<"\n Hence by BFS the amount of cells Batman has to traverse is:\n";
    cout << BFS(start, end) + 1 << endl;
    for (int i = 0; i < 10001; ++i)
    {
      A[i].clear();
    }

  }
}







