#include<bits/stdc++.h>
using namespace std;
#define int long long
int u[1000010];
int v[1000010];
int w[1000010];
int a[11][10010];
int c[11];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	int n,m,k,flag=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	if(k==0)
	{
		
	}
	int j;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i]!=0)flag=1;
		for(int l=1;l<=n;l++)
		{
			cin>>a[c[i]][l];
			if(a[c[i]][l]!=0)flag=1;
		}
	}
	if(flag==0)
	{
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++);
		}
	}
	return 0;
} 
