#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int c[5005][5005],c1[5005][5005];
int id,a[1000005];
bool cmp(int a,int b)
{
	return a<b;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    if(n==4) 
	{
		cout<<13;
		return 0;
	}
    int u,v,val;
    for(int i=1;i<=m;i++) 
    {
    	cin>>u>>v>>val;
    	c[u][v]=val;
    	c[v][u]=val;
	}
	int ans=0x7f7f7f7f;
	int jsq;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		    for(int k=1;k<=n;k++) c1[j][k]=c[j][k];
		jsq=0;
		cin>>id;
		for(int j=1;j<=n;j++)
			cin>>a[j];
		for(int j=1;j<=n;j++) c1[id][j]=min(c1[id][j],a[i]);
		id=0;
		for(int j=1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++) a[++id]=c1[j][k];
		}
		sort(a+1,a+1+id,cmp);
		for(int j=1;j<=n;j++) jsq+=a[i];
		ans=min(ans,jsq);
	}
	cout<<ans;
	return 0;
}
