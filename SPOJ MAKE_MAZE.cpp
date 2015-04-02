#include<bits/stdc++.h>
using namespace std;
char graph[20][20];
int solution[20][20];
int points[20][2];
void print_sol(int m,int n)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			cout<<solution[i][j]<<"\t";
		cout<<endl;
	}
}
void dfs(int i,int j,int m,int n,int x,int y)
{
	// backtracking code for dfs to explore the maze 
	if(i<0 || j<0 || i>m-1 || j> n-1)
		return;
	if(i==x && j==y)
	{
		solution[x][y]=1;
		//print_sol(m,n);
		return ;
		//
	}
	else
	{
		if(solution[i][j]!=1 && graph[i][j]!='#')
		{
			solution[i][j]=1;
			dfs(i-1,j,m,n,x,y);
			dfs(i,j-1,m,n,x,y);
			dfs(i+1,j,m,n,x,y);
			dfs(i,j+1,m,n,x,y);
			solution[i][j]=0;
		}
				
	}
	//print_sol(m,n);
}

bool validate(int m,int n)
{
// Check all four edges for entry and exit points
int count=0;
// Check for left and right columns
for(int i=0;i<m;i++)
{
	
	if(graph[i][0]=='.') 
		{
		
			points[count][0]=i;
			points[count][1]=0;
			count++;
		}
	if(graph[i][n-1]=='.' && n-1!=0) 
		{
			
			points[count][0]=i;
			points[count][1]=n-1;
			count++;
		}
}
// Check for topmost and last rows for entry and exit points
for(int i=1;i<n-1;i++)
{
	if(graph[0][i]=='.' )
		{
			//Points contains coordinates for entry and exit coordinates
			points[count][0]=0;
			points[count][1]=i;
			count++;
		}
	if(graph[m-1][i]=='.' && m-1 !=0)
		{
			
			points[count][0]=m-1;
			points[count][1]=i;
			count++;
		}
}
	// If more than 2 exit points then exit.
	if(count!=2)
		return false;
	else
		{
			dfs(points[0][0],points[0][1],m,n,points[1][0],points[1][1]);
			if(solution[points[1][0]][points[1][1]]==1)
				return true;
			else
				return false;
		}
}
int main()
{

int t,m,n;
cin>>t;
while(t--)
{
	memset(solution,0,sizeof(solution));
	memset(points,0,sizeof(points));
	cin>>m>>n;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			cin>>graph[i][j];
	}
	
	if(validate(m,n)==true)
		cout<<"valid"<<endl;
	else	
		cout<<"invalid"<<endl;
}
	return 0;
}
