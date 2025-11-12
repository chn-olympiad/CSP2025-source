#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[10010][10010],z[20];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int q,w,e;
		cin>>q>>w>>e;
		a[q][w]=e;
		a[w][q]=e;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>z[i];
		int q=i+n,e;
		for(int j=1;j<=n;j++)
		{
			cin>>e;
			a[q][j]=e;
			a[j][q]=e;
		}
	}
	return 0;
}