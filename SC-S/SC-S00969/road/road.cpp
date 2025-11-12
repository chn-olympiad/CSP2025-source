#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
ll n,m,k,t[11][4514],b[11],cost[1145140],ans;
vector<vector<pair<ll,ll> > > r(1145);
bool vis[1145140];
void bsf(ll now,ll cst,ll pt)
{
//	cout<<now<<" "<<cst<<" "<<pt<<endl;
	if(pt>=n)
	{
		ans=cst;
		return;
	}
	vis[now]=1;
	cost[now]=0;
	int lens=r[now].size();
	for(int i=0;i<lens;i++)
	{
		pair<ll,ll> p;
		p=r[now][i];
		cost[p.first]=min(cost[p.first],p.second);
	}
//	for(int i=1;i<=n;i++) cout<<cost[i]<<" ";
//	cout<<endl;
	int minn=0;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			if(cost[minn]>cost[i]) minn=i;
		}
	}
	cst+=cost[minn];
	pt++;
	bsf(minn,cst,pt);
	return;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,c;
		cin>>u>>v>>c;
		pair<ll,ll> p,q;
		p.first=v;
		q.first=u;
		p.second=c;
		q.second=c;
		r[v].push_back(q);
		r[u].push_back(p);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>b[i];
		for(int j=1;j<=n;j++) 
		{
			cin>>t[i][j];
		}
		if(b[i]==0)
		{
			for(int j=1;j<=n;j++)
			{
				if(t[i][j]==0)
				{
					for(int l=1;l<=n;l++)
					{
						pair<ll,ll> p,q;
						q.first=j;
						p.first=l;
						q.second=t[i][l];
						p.second=t[i][l];
						if(l!=j) 
						{
							r[j].push_back(p);
							r[l].push_back(q);
						}
					}
				}
			}
		}
	}
	for(int i=0;i<=n;i++)
	{
		cost[i]=1145141919810;
	}
	bsf(1,0,1);
	cout<<ans;
	return 0;
}
//哇！！t2居然能拿40pts!!
//stostostostosto西西弗
//100+40?+0+0=140? 