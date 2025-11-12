#include<bits/stdc++.h>
#include<queue>
#define ll long long
#define endl "\n"
#define pb push_back
#define pe(i) (1ll<<(i))
#define ft first
#define sd second
using namespace std;
bool stsr;
const ll N=1e6+5,INF=0x3f3f3f3f3f3f3f3f,mod=998244353;
ll n,m,T,k;
inline ll read(){
	ll x=0,w=1;char ch=0;
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch-'0');ch=getchar();}
	return x*w;
}
struct dat{
	ll u,v,w;
	bool operator<(const dat &s)const{
		return w<s.w;
	}
}e[N],a[N],hb[N],da[N];
vector<dat> d[30];
ll c[N],cnt;
ll z,y;
ll f[N],sz[N];
ll find(ll x){
	return f[x]=f[x]==x?x:find(f[x]);
}
void merge(){
	ll i=1,j=1,dd=0;
	for(int t=1;t<=z+y;t++){
		if(i>z)da[++dd]=hb[j],j++;
		else if(j>y)da[++dd]=e[i],i++;
		else if(e[i]<hb[j])da[++dd]=e[i],i++;
		else da[++dd]=hb[j],j++;
	}
	for(int i=1;i<=dd;i++)e[i]=da[i];
}
bool ed;
int main(){
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	cerr<<(&stsr-&ed)/1024/1024.0<<endl;
	n=read(),m=read(),k=read();
//	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)e[i].u=read(),e[i].v=read(),e[i].w=read();
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1,w;j<=n;j++){
			w=read();
			d[i].pb({i+n,j,w});
		}
		sort(d[i].begin(),d[i].end());
	}
	sort(e+1,e+1+m);
	for(int i=1;i<=n+k;i++)f[i]=i,sz[i]=1;
	for(int i=1;i<=m;i++){
		ll fx=find(e[i].u),fy=find(e[i].v);
		if(fx==fy)continue;
		f[fx]=fy;
		a[++cnt]=e[i];
		if(cnt==n-1){break;
		}
	}
	ll cc=0;
	ll ans=INF;
	for(int t=0;t<pe(k);t++){
		cc=0;
		ll sum=0,su=0;
		for(int j=1;j<=k;j++){
			if(!(t&pe(j-1)))continue;
			z=cc,y=0;
			for(dat b:d[j])hb[++y]=b; 
			merge();cc+=y;
			sum+=c[j];su++;
		}
		z=cc,y=0;
		for(int i=1;i<=cnt;i++)hb[++y]=a[i];
		merge();cc+=y;
//		cout<<cc<<endl;
//		for(int i=1;i<=cc;i++){
//			cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<endl;
//		}
		for(int i=1;i<=n+k;i++)f[i]=i,sz[i]=1;
		ll tot=0;
		for(int i=1;i<=cc;i++){
			ll fx=find(e[i].u),fy=find(e[i].v);
			if(fx==fy)continue;
			if(sz[fx]>sz[fy])swap(fx,fy);
//			cout<<e[i].u<<' '<<e[i].v<<" "<<e[i].w<<endl;
			f[fx]=fy;sz[fy]+=sz[fx];
			tot++;sum+=e[i].w;
			if(tot==n+su-1){break;
			}
		}
//		cout<<su<<endl;
//		for(int i=1;i<=n;i++)cout<<(t&pe(i-1))<<" ";cout<<endl;
//		cout<<sum<<endl;
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
