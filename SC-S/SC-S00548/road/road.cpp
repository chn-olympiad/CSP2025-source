#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
struct edge
{
	long long u,v,w;
};
struct node
{
	long long i,w;
}p[110010];
vector<edge> ee,e,o,us[11],es;
bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
bool cmp2(node a,node b)
{
	return a.w<b.w;
}
long long c[111010];
long long fin(long long a)
{
	if(c[a]==a) return a;
	else return c[a]=fin(c[a]);
}
void ad(long long a,long long b)
{
	c[fin(a)]=fin(b);
}
long long as[1100];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++)
	{
		long long x,y,z;
		cin>>x>>y>>z;
		ee.push_back({x,y,z});
	}
	for(long long i=1;i<=n;i++) c[i]=i;
	long long ans=0;
	sort(ee.begin(),ee.end(),cmp);
	long long llen=0;
	for(edge i:ee)
	{
		if(fin(i.u)!=fin(i.v))
		{
			ans+=i.w;
			ad(i.u,i.v);
			e.push_back(i);
			llen++;
			if(llen==n-1) break;
		}
	}
	long long rk=0;
	for(long long i=1;i<=k;i++)
	{
		long long yyy;
		cin>>yyy;
		if(yyy<ans)
	    {
		rk++;
			as[i]=yyy;
			for(long long i=1;i<=n;i++)
			{
				cin>>p[i].w;
				p[i].i=i;
			}
			sort(p+1,p+1+n,cmp2);
			for(long long i=1;i<=n;i++)
			{
				us[rk].push_back({n+rk,p[i].i,p[i].w});
			}
		}
		else{
			cin>>p[i].w;
		}
	}
	k=rk;
	long long j=-1;
	long long mm=(1<<rk);
	for(long long i=1;i<=mm;i++)
	{
		long long hee=0;
		es.clear();
		for(edge i:e)
		{
			es.push_back(i);
		}
		j++;
		long long r=j,rk=0;
		while(r)
		{
			rk++;
			if(r&1)
			{
				hee+=as[rk];
				if(hee>=ans) break;
				long long iq=0,jq=0,len=es.size(),len2=us[rk].size();
				while(iq<len&&jq<len2)
				{
					if(es[iq].w<us[rk][jq].w)
					{
						o.push_back(es[iq]);
						iq++;
					}
					else
					{
						o.push_back(us[rk][jq]);
						jq++;
					}
				}
				if(iq<=len-1)
				{
					for(;iq<=len-1;iq++)
					{
						o.push_back(es[iq]);
					}
				}
				if(jq<=len2-1)
				{
					for(;jq<=len2-1;jq++)
					{
						o.push_back(us[rk][jq]);
					}
				}
				es.clear();
				for(edge i:o)
				{
					es.push_back(i);
				}
				o.clear();
			}
			r>>=1;
		}
		for(long long u=1;u<=n+rk;u++) c[u]=u;
		long long ans2=0,llen=0;
		for(edge u:es)
		{
			if(fin(u.u)!=fin(u.v))
			{
				ans2+=u.w;
				ad(u.u,u.v);
			    llen++;
				if(llen==n+rk-1) break;
			}
		}
		ans=min(ans,ans2+hee);
	}
	cout<<ans;
	return 0;
}