#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
#include<random>
#include<ctime>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<map>
#include<bitset>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<cstdlib>
#include<string>
#define ll long long
#define uint unsigned int
#define FOR(i,m,n) for(ll i=m;i<=n;i++)
#define FRO(i,m,n) for(ll i=m;i>=n;i--)
#define mp(a,b) make_pair(a,b)
using namespace std;
inline ll read(){
	ll res=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch&15),ch=getchar();
	return res*f;
}
const ll M=2e6+5,N=1e4+55;
struct edge{
	ll u,v,w;
}e[M];
ll c[20];
struct DSU{
	ll fa[N],siz[N];
	void init(ll n){
		FOR(i,0,n)fa[i]=i,siz[i]=1;
	}
	ll find(ll x){
		return fa[x]=(fa[x]==x?x:find(fa[x]));
	}
	void merge(ll x,ll y){
		x=find(x);y=find(y);
		if(x==y)return ;
		if(siz[x]>siz[y])swap(x,y);
		fa[x]=y;
		siz[y]+=x;siz[x]=0;
	}
	bool check(ll x,ll y){
		return (find(x)==find(y));
	}
}s;
bool cmp(edge x,edge y){
	return x.w<y.w;
}
ll p[1024][N],cnt[1024];
ll calc(ll idx,ll d){
	if(!s.check(e[idx].u,e[idx].v)){
		cnt[d]++;
		p[d][cnt[d]]=idx;
		s.merge(e[idx].u,e[idx].v);
//		cout<<e[idx].w<<" ";
		return e[idx].w;
	}
	else return 0;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n=read(),m=read(),k=read();
	FOR(i,1,m){
		ll u=read(),v=read(),w=read();
		e[i].u=u;e[i].v=v;e[i].w=w;
	}
	sort(e+1,e+1+m,cmp);
	s.init(n);
	ll ans=0;
	FOR(i,1,m){
		ans+=calc(i,0);
	}
	ll tot=m;
	FOR(i,1,k){
		c[i]=read();
		FOR(j,1,n){
			e[++tot].u=i+n;
			e[tot].v=j;e[tot].w=read();
		}
		sort(e+m+(i-1)*n+1,e+m+i*n+1,cmp);
	}
	FOR(i,1,k){
		ll r=1;
		ll sum=c[i];
		s.init(n+k);
		FOR(j,m+(i-1)*n+1,m+i*n){
			while(r<=cnt[0]&&e[p[0][r]].w<=e[j].w)sum+=calc(p[0][r],(1ll<<(i-1))),r++;
			sum+=calc(j,(1ll<<(i-1)));
		}
		while(r<=cnt[0])sum+=calc(p[0][r],(1ll<<(i-1))),r++;
//		cout<<sum<<endl;
		ans=min(ans,sum);
	}
//		cout<<ans<<endl; 
	FOR(i,1,(1ll<<k)-1){
		ll ct=0,u=-1,sum=0;
		FOR(j,1,k){
			if((1ll<<(j-1))&i){
				u=j;ct++;
				sum+=c[j];
			}
		}
		if(ct==0||ct==1)continue;
		ll x=(1ll<<(u-1)),y=(i-(1ll<<(u-1)));
//		cout<<x<<" "<<y<<endl;
		ll r=1;
		s.init(n+k);
		FOR(j,1,cnt[x]){
			while(r<=cnt[y]&&e[p[y][r]].w<=e[p[x][j]].w)sum+=calc(p[y][r],i),r++;
			sum+=calc(p[x][j],i);
		}
//		cout<<i<<" "<<sum<<endl; 
		while(r<=cnt[y])sum+=calc(p[y][r],i),r++;
		ans=min(ans,sum);
	}
	printf("%lld\n",ans);
	return 0;
}

/*
2h T2

*/





