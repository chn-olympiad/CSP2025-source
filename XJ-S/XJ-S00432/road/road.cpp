#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long int u,v,pr,r;
}s[1000005];
int main()
{
	long long int i,j,n,m,k,ans=0,t=0,a[15][10005],c[10005],f[10005]={0};
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(i=1;i<=m;i++)
	cin>>s[i].u>>s[i].v>>s[i].pr;
	for(i=1;i<=k;i++)
	{
	cin>>c[i];	
	for(j=1;j<=n;j++)	
	cin>>a[i][j];	
	}
	for(i=1;i<=n;i++)
	{
	s[i].r=0;	
	f[i]=i;	
	}
	for(i=1;i<=m;i++)
	{
	ans+=s[i].pr;	
	f[s[i].v]=f[s[i].u];
	for(j=1;j<n;j++)	
	if(f[j]==f[j+1])
	t++;
	if(t==n-1)
	break;
	}	
	cout<<ans;
	return 0;
}
