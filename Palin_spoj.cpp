#include<iostream>
#include<string>
#include<algorithm>
int dp[5001][10001];
using namespace std;
string s;
int min_insert(int n)
{
int j;
for(int i=0;i<n;i++)
	dp[i][i]=0;
int gap=0;
for(int gap=1;gap<n;gap++)
{	
	//gap++;
	for(int r=0,c=gap;c<n;++r,++c)
	{
				
		if(s[r]==s[c])
			dp[r][c]=dp[(r+1)][(c-1)];
		else
			dp[r][c]=1+min(dp[(r+1)][c],dp[r][(c-1)]);
	}
}
return dp[0][(c-1)];
}
int main() {
// your code goes here
int t;
cin>>t;
//cout<<"erer";
cin>>s;
//cout<<s<<endl;
cout<<min_insert(t)<<endl;
for(int i=0;i<t;i++)
{
	for(int j=0;j<t;j++)
		cout<<dp[i][j]<<"\t";
	cout<<endl;
}
return 0;
}
