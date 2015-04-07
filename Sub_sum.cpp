#include<iostream>
#include<algorithm>
using namespace std;
int dp[50001][101];
int ar[50000];
int knapSack(int W, int wt[], int n)
{
   int i, w;
   int K[n+1][W+1];
 
   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = 1 + K[i-1][w-wt[i-1]]+  K[i-1][w];
           else
                 K[i][w] = K[i-1][w];
       }
   }
 
   return K[n][W];
}
int main()
{
int wt[]={10,20,30};
int W=50;
cout<<knapSack(W,wt,3);
}
