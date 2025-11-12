#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct edge
{
	ll fr;
	ll to;
	ll qz;
	friend bool operator < (edge x,edge y)
	{
		return x.qz>y.qz;
	}
};
ll n,m,k,Y,u[1000005],v[1000005],w[1000005],wer;
ll ans = 10000000000,f[10005],c[15],a[15][10005];
priority_queue<edge> p;
int find(int p)
{
	if(f[p]==p)
		return p;
	return f[p] = find(f[p]);
}
void hb(int x,int y)
{
	int xx = find(x),yy = find(y);
	f[xx] = yy;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i = 1;i <= m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i = 1;i <= k;i++)
	{
		cin>>c[i];
		for(int j = 1;j <= n;j++)
		{
			cin>>a[i][j];
		}
		c[i]+=a[i][i];
	}
	for(int i = 0;i < pow(2,k);i++)
	{
		wer = 0;
		for(int j = 1;j <= n;j++)
		{
			f[j] = j;
		}
		for(int j = 1;j <= k;j++)
		{
			if((i>>(j-1))%2)
			{
				wer+=c[j];
				for(int l = 1;l <= n;l++)
				{
					if(j!=l)
					{
						p.push({j,l,a[j][l]});
					}
					
				}
			}
		}
		for(int j = 1;j <= m;j++)
		{
			p.push({u[j],v[j],w[j]});
		}
		Y = 0;
		while(p.size() && Y < n-1)
		{
			edge tp = p.top();
			p.pop();
			if(find(tp.fr)!=find(tp.to))
			{
				Y++;
				wer+=tp.qz;
				hb(tp.fr,tp.to);
			}
		}
		ans = min(ans,wer);
	}
	cout<<ans;
	return 0;
}