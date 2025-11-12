#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ms(x,y) memset(x,y,sizeof(x))
const int M=11451;
const ll INF=0x3f3f3f3f3f3f3f3f;
struct EE
{
	int u,v;
	ll d;
}ee[M*100],te[12][M],tmp[M];
int tl[12]={0};
bool cmp(EE a,EE b) {return a.d<b.d;}
int f[M];
int Find(int x) {return (f[x]==x)?(f[x]):(f[x]=Find(f[x]));}
void Union(int x,int y) {f[Find(x)]=Find(y);}
int n,m,k;
ll c[12],d[12][M];
int pos[12];
struct T
{
	ll cost;
	int k;
	bool operator < (T x) const {return cost>x.cost;}
};
priority_queue<T> q;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%d%d%lld",&ee[i].u,&ee[i].v,&ee[i].d);
	sort(ee+1,ee+1+m,cmp);
	for(int i=1;i<=n;i++) f[i]=i;
	ll res=0;
	for(int i=1;i<=m;i++)
	{
		int u=ee[i].u,v=ee[i].v;
		if(Find(u)==Find(v)) continue;
		Union(u,v),te[k][++tl[k]]=ee[i],res+=ee[i].d;
	}
	for(int i=0;i<k;i++)
	{
		scanf("%lld",&c[i]),tl[i]=n;
		for(int j=1;j<=n;j++)
			scanf("%lld",&tmp[j].d),tmp[j].u=n+i+1,tmp[j].v=j;
		sort(tmp+1,tmp+1+n,cmp);
		for(int j=1;j<=n;j++) te[i][j]=tmp[j];
	}
	ll ans=INF;
	for(int st=0;st<(1<<k);st++)
	{
		while(!q.empty()) q.pop();
		ll sum=0,len=n-1;
		for(int i=1;i<=n+k;i++) f[i]=i;
		for(int i=0;i<=k;i++)
		{
			if(i!=k&&!((st>>i)&1)) continue;
			pos[i]=1,q.push({te[i][1].d,i});
			sum+=c[i],len++;
		}
		int cnt=0;
		while(!q.empty()&&len>1)
		{
			T t=q.top();q.pop();
			if(sum+t.cost>=res) {sum=ans;break;}
			EE e=te[t.k][pos[t.k]];
			int u=e.u,v=e.v;
			if(Find(u)==Find(v))
			{
				pos[t.k]+=1;
				if(pos[t.k]<=tl[t.k]) q.push({te[t.k][pos[t.k]].d,t.k});
				continue;
			}
			Union(u,v),sum+=e.d,pos[t.k]+=1;
			if(pos[t.k]<=tl[t.k]) q.push({te[t.k][pos[t.k]].d,t.k});
			len--;
		}
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}

