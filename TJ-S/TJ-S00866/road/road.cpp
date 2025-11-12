#include <bits/stdc++.h>
using namespace std;
struct road
{
	int u,v,w;
	int t,e;
}p[1000005],q[1000005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		cin>>p[i].u>>p[i].v>>p[i].w;
	}
	int flag1=0;
	for(int i=0;i<k;i++)
	{
		cin>>q[i].t;
		int flag=0;
		for(int j=0;j<n;j++)
		{
			cin>>q[j].e;
			if(q[j].e==0)
			{
				flag++;
			}
		}
		if(flag==n&&q[i].t==0)
		{
			flag1++;
		}
	}
	if(flag1==k)
	{
		cout<<0;
	}
	
	return 0;
}
