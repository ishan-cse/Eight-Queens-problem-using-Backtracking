#include <iostream>
using namespace std;

int queenAgent(int column);
int check(int row,int column);

int m=0,b=0,n=8;

int a[8][8];

int main()
{
   int i,j,td;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            a[i][j]=0;
        }
    }

// backtrack

   if (queenAgent(0) == 0)
     {
      cout<<"\n Solution does not exist \n";
     }

// result

   cout<<"\n\n    result \n\n\n";

   for (i = 0; i < n; i++)
     {
        for (j = 0; j < n; j++)
            {
               cout<<" "<<a[i][j]<<" ";
            }
          cout<<"\n\n";
     }

   td=m+b;

   cout<<"\n\n time delay : "<<td<<"\n\n";
   cout<<"\n # total move cost : "<<m;
   cout<<"\n\n # total backtrack : "<<b<<"\n\n";

   return 0;
}

// check position

int check(int row,int column)
{
   int r, c=0;

   // row on the left

   while (c<column)
   {
     if (a[row][c]==1)
         {
         return 0;
         }
       c++;
   }

// top diagonal on the left

   r = row;
   c = column;

   while (r>=0 && c>=0)
     {
         if (a[r][c]==1)
           {
               return 0;
           }
          r--;
          c--;
     }

// down diagonal on the left

   r = row;
   c = column;

   while (c >= 0 && r < n)
   {
       if (a[r][c]==1)
       {
         return 0;
       }
        r++;
        c--;
   }

//move

   m=m+1;
   cout<<"\n move no : "<<m<<"\n";

   return 1;
}

// queenAgent

int queenAgent(int column)
{

// return 1 if the result ready

   if (column >= n)
   {
      return 1;
   }

// with this column ,and iterative  row ,it will work for setting queen

  int i = 0;

  do {
     // possibility for setting the queen a[i][column]
   if (check(i, column)==1)
   {
          // set queen in a[i][column]

          a[i][column] = 1;

          // set remains queen

          int next_column=column + 1;

          if (queenAgent(next_column)==1)
          {
            return 1;
          }

         // if setting queen in a[i][column] don't give solution then remove it from that place

          a[i][column] = 0;      // BACKTRACK

         //backtrack

          b=b+1;
          cout<<"\n backtrack no : "<<b  << "\n";
      }
         i++;
 }
 while(i < n);

// with this column ,and iterative  row , if queen don't get any row for it's position, return 0
    return 0;
}
