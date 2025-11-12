#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[10001][10001],d[10001],u,v,w,mn,mnid,s;
bool b[10001];
int main()
{	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i)
	  for(int j=1;j<=n;++j)
	    a[i][j]=-1;
	for(int i=1;i<=m;++i)
	{
		cin>>u>>v>>w;
		a[u][v]=w;
	}
	b[1]=true;
	for(int i=1;i<=n;++i)
	  d[i]=a[1][i];
	mnid=-1;
	for(int i=2;i<=n;++i)
		if(d[i]!=-1)
		{
	  		if(mnid==-1||mn>d[i])
	  		{
	  			mn=d[i];
	  			mnid=i;
			}
		}
		
	for(int i=1;i<n;++i)
	{
		s+=mn;
		b[mnid]=true;
		for(int j=1;j<=n;++j)
		{
			if(d[j]==-1)
			  d[j]=a[mnid][j];else
			  if(a[mnid][j]!=-1)
			    d[j]=min(d[j],a[mnid][j]);
		}
		mnid=-1;
		mn=0;
		for(int j=1;j<=n;++j)
		{
			if((mnid==-1||mn>d[j])&&d[j]!=-1&&!b[j])
			{
				mnid=j;
				mn=d[j];
			}
		}
	}
	cout<<s;
	return 0;
}