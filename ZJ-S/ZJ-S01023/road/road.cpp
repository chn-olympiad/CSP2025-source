#include<bits/stdc++.h>
#define ll long long
using namespace std;
void read(ll &x){
	ll f=1;x=0;char s=getchar();
	while (s<'0'||s>'9'){if (s=='-'){f=-f;}s=getchar();}
	while (s>='0'&&s<='9'){x=(x<<1)+(x<<3)+s-'0';s=getchar();}
	x*=f;
}
const ll MAXN=1e4+25;
const ll MAXM=2e6+5;
ll n,m,k,ans=0x3f3f3f3f3f3f3f3f;
bool flag=true;
struct node{
	ll w,u,v;
}a[MAXM],b[MAXM],c[MAXN*12],d[12][MAXN],e[MAXN*12];
ll p[15],fa[MAXN];
bool cmp(node x,node y){
	return x.w<y.w;
}
ll fath(ll x){
	if (fa[x]==x) return x;
	return fa[x]=fath(fa[x]);
}
ll work(ll op){
	ll cnt=0,now=0,pot=n;
	for (ll i=0;i<k;i++){
		if (op&(1<<i)){
			now+=p[i];
			pot++;
			ll he1=1,he2=1,x=1;
			ll a=cnt,b=n;
			while (he1<=a || he2<=n){
				if (he1==a+1) e[x]=d[i][he2++];
				else if (he2==n+1) e[x]=c[he1++];
				else if (c[he1].w<d[i][he2].w) e[x]=c[he1++];
				else e[x]=d[i][he2++];
				x++;
			}
			cnt+=n;
			for (ll i=1;i<=cnt;i++)c[i]=e[i];
		}
	}
	ll he1=1,he2=1,x=1;
	while (he1<=m || he2<=cnt){
		if (he1==m+1) b[x]=c[he2++];
		else if (he2==cnt+1) b[x]=a[he1++];
		else if (a[he1].w<c[he2].w) b[x]=a[he1++];
		else b[x]=c[he2++];
		x++;
	}
	cnt=0;
	for (ll i=1;i<=n+k;i++) fa[i]=i;
	ll i=1;
	while (cnt<pot-1){
		ll u=b[i].u,v=b[i].v,w=b[i].w;
		ll x=fath(u),y=fath(v);
		if (x!=y){
			now+=w;
			fa[y]=x;
			cnt++;
		}
		i++;
		if (now>ans) return 0x3f3f3f3f3f3f3f3f;
	}
	return now;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);read(m);read(k);
	for (ll i=1;i<=m;i++){
		read(a[i].u);read(a[i].v);read(a[i].w);
	}
	sort(a+1,a+m+1,cmp);
	for (ll i=0;i<k;i++){
		read(p[i]);
		if (p[i]) flag=false;
		for (ll j=1;j<=n;j++){
			ll x;
			read(x);
			d[i][j].u=i+n+1;
			d[i][j].v=j;
			d[i][j].w=x;
		}
		sort(d[i]+1,d[i]+n+1,cmp);
	}
	if (flag){
		printf("%lld",work((1<<k)-1));
		return 0;
	}
	for (ll i=0;i<(1<<k);i++){
		ans=min(ans,work(i));
	}
	printf("%lld",ans);
	return 0;
}

