#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,e=1,n=0,m=0,ma=0;
string x;
int y[1000];
int z[1000];
void dfs(int dep,int s)
{
	if(dep==a && s>=b)
	{
		ma=ma+1;
		ma=ma%998244353;
	}
	for(int i=1;i<=a;i=i+1)
	{
		if(z[i]==0)
		{
			int up=0;
			z[i]=1;
			if(x[dep]=='1' && dep-s<y[i])
			{
				up=1;
			}
			dfs(dep+1,s+up);
			z[i]=0;
		}	
	}
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>a>>b;
	cin>>x;
	for(long long i=1;i<=a;i=i+1)
	{
		cin>>y[i];
	}
	dfs(0,0);
	cout<<ma;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3 2
101
1 1 2
*/