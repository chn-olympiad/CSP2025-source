#include<bits/stdc++.h>
using namespace std;
const long long maxn=2e6+5;
long long n,m,k,i,j,u,v,hop,cnt,ans,c,w;
struct edge
{
	long long ui,vi,wi;
	friend bool operator >(edge a,edge b)
	{
		return a.wi<b.wi;
	}
}a[maxn],tmp;
struct cmw
{
	long long vi,wi;
	friend bool operator >(cmw a,cmw b)
	{
		return a.wi<b.wi;
	}
};
vector<edge>ve[maxn],zui[maxn];
long long vis[maxn],t[maxn],f[maxn];
long long save(long long x)
{
	if(f[x]==x) return x;
	else return f[x]=save(f[x]);
}
bool cmp(edge x,edge y)
{
	return x.wi<y.wi;
}
priority_queue<edge>q;
void prim()
{
	for(i=1;i<=m;i++)
	{
		//cout<<a[i].ui<<" "<<a[i].vi<<"\n";
		long long p1=save(a[i].ui),q1=save(a[i].vi);
		if(p1==q1) continue;
		//cout<<i<<"\n";
		ans+=a[i].wi;
		f[a[i].ui]=f[a[i].vi];
	}
	return;
}
int main()
{	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(i=1;i<=n;i++) f[i]=i;
	for(i=1;i<=m;i++)
	{
		scanf("%lld %lld %lld",&a[i].ui,&a[i].vi,&a[i].wi);
		ve[a[i].ui].push_back({a[i].vi,a[i].wi});
		ve[a[i].vi].push_back({a[i].ui,a[i].wi});
    }
    cnt=m;                                
	for(i=1;i<=k;i++)
	{
		scanf("%lld",&hop);
		for(j=1;j<=n;j++) scanf("%lld",&t[j]);
		for(j=1;j<=n;j++)
		{
			for(c=j+1;c<=n;c++)
			{
				cnt++;
				a[cnt].ui=j,a[cnt].vi=c,a[cnt].wi=t[j]+t[c]+hop;
				cout<<a[cnt].ui<<" "<<a[cnt].vi<<" "<<a[cnt].wi<<"\n";
				ve[i].push_back({c,t[j]+t[c]+hop});
				ve[c].push_back({i,t[j]+t[c]+hop});
			}
		}
	}
	sort(a+1,a+1+cnt,cmp);
	prim();
	printf("%lld\n",ans);
	return 0;
}
//I want go to the qiguaixingweidashang!
//luogu uid：562443
//Go for it!
//Ren5Jie4Di4Ling5%
//AFO