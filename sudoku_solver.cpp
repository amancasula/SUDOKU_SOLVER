#include<iostream>

using namespace std;
int find(int arr[9][9], int &row, int &col);
 int safe(int arr[9][9], int row, int col, int num);
     int solve(int arr[9][9])
{
  int row, col;
  if (!find(arr, row, col))
    {
      return true;
    }
  for (int num=1; num <=9; num++)
    {
      if(safe(arr, row, col, num))
	{
	  arr[row][col] = num;
	  if (solve(arr))
	    {
	      return true;
	    }
	  arr[row][col] = 0;
	}
    }
  return false;
}

int find(int arr[9][9], int &row, int &col)
{
  for (row = 0; row < 9; row++)
    {
      for (col = 0; col < 9; col++)
	{
	  if (arr[row][col] == 0)
	    {
	      return true;
	    }
	}
    }
  return false;
}
int samerow(int arr[9][9],int row,int num)
{
    for(int col=0;col<9;col++)
    {
        if(arr[row][col] == num)
        {return true;}
    }
    return false;
}
int samecol(int arr[9][9],int col,int num)
{
    for(int row=0;row<9;row++)
    {
        if(arr[row][col] == num)
        {return true;}
    }
    return false;
}
int samebox(int arr[9][9],int frow,int fcol,int num)
{
    for(int row=0;row<3;row++)
    {
        for(int col=0;col<3;col++)
        {
            if(arr[row+frow][col+fcol]==num)
            {return true;}
        }
    }
    return false;
}
int safe(int arr[9][9],int row,int col,int num)
{
    return !samerow(arr,row,num) && !samecol(arr,col,num) && !samebox(arr,row-(row%3),col-(col%3),num);
    
}
int print(int arr[9][9])
{
    for(int row=0;row<9;row++)
    {
        
    for(int col=0;col<9;col++)
    {
        cout<<arr[row][col]<<" ";
        
    }
    cout<<endl;
    }
}
int main()
{
    cout<<"::AMAN'S SUDOKU::";
    cout<<"\nENTER";
int arr[9][9];
int i,j;
for(i=0;i<9;i++)
{
    for(j=0;j<9;j++)
    {
        cin>>arr[i][j];
    }
}  
if(solve(arr) ==true)
{
    print(arr);
    }
else
{
    cout<<"NO SOLUTION";
}
return 0;
}    

 
