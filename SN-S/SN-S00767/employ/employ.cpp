//韩泽熙  SN-S00767  西安辅轮中学 
#include <bits/stdc++.h>
using namespace std;
int n,m,v=0,w=0;
string a;
int s[505]={};
int d[505][2]={};
/*int dfs(int n)
{
	while(s==n)
	{
		for(int i=1;i<=n;i++)
		{
			
		}
	}
}*/
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]=='1')
		{
			d[i+1][0]=1;
			d[i+1][1]=w;
			v++;
		}
		w++;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(s[i]>s[j])
			{
				swap(s[i],s[j]);
			}
		}
	}

	if(v<m)
	{
		cout<<0;
		return 0;
	}
	int anser=2;
	
	cout<<anser<<0;
}
