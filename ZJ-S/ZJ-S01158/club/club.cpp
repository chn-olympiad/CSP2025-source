#include<bits/stdc++.h>
using namespace std;
int n,a[100001][4]={},b[100001]={},d[4]={},s=0;
void dfs(int x)
{
	if(x==n+1)
	{
		int s1=0;
		for(int i=1;i<=n;i++)
		{
			s1+=b[i];
		}
		s=max(s,s1);
	}
	else
	{
		for(int i=1;i<=3;i++)
		{
			if(d[i]<n/2)
			{
				b[x]=a[x][i];
				d[i]++;
				dfs(x+1);
				d[i]--;
				b[x]=0;
			}
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
	 	a[100001][4]={};b[100001]={};d[4]={};
		cin>>n;
		for(int i=1;i<=n;i++) 
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}	
		}
		dfs(1);
		cout<<s<<endl;
	}
	return 0;
}
