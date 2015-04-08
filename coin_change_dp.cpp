#include<iostream>
#include<algorithm>
using namespace std;
int coin[]={1,2,5,10,20,50,100,200};
int dp[9][201];
int ways(int type,int val,int n)
{
if(val==0)
return 1;
if(val<0)
return 0;
if(type >n)
return 0;
return ways(type+1,val,n)+ways(type,val-coin[type],n);
//return ret;
}
int ways_dp(int val)
{
for(int i=0;i<9;i++)
dp[i][0]=1;
for(int i=1;i<=8;i++)
{
for(int j=1;j<201;j++)
{
	if(coin[i-1]>j)
	dp[i][j]=dp[i][j-1];
	else
	dp[i][j]=dp[i-1][j]+dp[i][j-coin[i-1]];
}
}
	return dp[8][200];
}
int main()
{
cout<<ways_dp(200);
for(int i=0;i<9;i++)
{
for(int j=0;j<201;j++)
cout<<dp[i][j]<<" ";
cout<<endl;
}

}
