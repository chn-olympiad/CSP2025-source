#include<bits/stdc++.h>
const int N=10020;
const int M=1100010;
using namespace std;
typedef long long ll;
ll n,m,k;
ll ans=1e18;
struct edge{
	ll u,v,w;
}e[M];
ll tot=0;
ll c[N];
ll fa[N];
ll Find(ll x){
	if(fa[x]==x)return x;
	return fa[x]=Find(fa[x]);
} 
bool cmp(edge x,edge y){
	return x.w<y.w;
}
inline ll read(){
	ll res=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){res=res*10+ch-'0';ch=getchar();}
	return res;
}
pair<ll,ll> popcount(ll i){
	ll res=0;
	ll sc=0;
	ll j=1;
	while(i){
		res+=i&1;
		sc+=(i&1)*c[j];
		i>>=1;j++;
	}
	return make_pair(res,sc);
}
ll kruskal(ll id){
	ll cnt=0;
	pair<ll,ll>pii=popcount(id);
	ll ck=pii.first;
	ll sum=pii.second;
	for(ll i=1;i<=n+k;i++)fa[i]=i;
	for(ll i=1;i<=tot;i++){
		if(e[i].u>n&&!(id&(1<<(e[i].u-n-1))))continue;
		ll fu=Find(e[i].u);
		ll fv=Find(e[i].v);
		if(fu==fv)continue;
		fa[fu]=fv;
		cnt++;
		sum+=e[i].w;
		if(sum>ans)return 1e18;
		if(cnt>=n+ck-1)break;
	}
	return sum; 
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(ll i=1;i<=m;i++){
		e[i].u=read();e[i].v=read();e[i].w=read();
	}
	tot=m;
	for(ll i=1;i<=k;i++){
		c[i]=read();
		for(ll j=1;j<=n;j++){
			ll w=read();
			e[++tot].u=i+n;
			e[tot].v=j;
			e[tot].w=w;
		}
	}
	sort(e+1,e+tot+1,cmp);
	for(ll i=0;i<(1<<k);i++){
		ll tmp=kruskal(i);
		//cout<<tmp<<endl;
		ans=min(ans,tmp);
	}
	printf("%lld",ans);
	return 0;
}

