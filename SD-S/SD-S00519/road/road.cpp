#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define ll long long
#define pii pair<int,int>
#define fr first
#define sc second
#define gtc getchar
#define ptc putchar
inline ll read(){
	ll x=0,f=1; char ch=gtc();
	while(ch<'0'||ch>'9'){ if(ch=='-') f=-1; ch=gtc(); }
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=gtc();
	return x*f;
}
inline void write(ll x){
	if(x<0) ptc('-'),x=-x;
	if(x>9) write(x/10);
	ptc(x%10+'0');
}
inline void println(ll x){ write(x),ptc('\n'); }
inline void printsp(ll x){ write(x),ptc(' '); }
const int maxn=1e4+6,maxm=2e6+6;
const ll inf=1e18;
int n,m,nowm,k,data_a=1;
struct edge{
	int u,v;
	ll w;
	void scan(){
		u=read(),v=read(),w=read();
	}
}e[maxm],ne[maxm],tmp[maxn*15];
ll a[15][maxn],c[15];
int fa[maxn];

bool cmp(edge x,edge y){
	return x.w<y.w;
}

int fi(int x){
	if(fa[x]==x) return x;
	return fa[x]=fi(fa[x]);
}

void mer(){
	int l=1,r=1;
	for(int i=1;i<=nowm+m;i++){
		if(r==nowm+1||(l<=m&&e[l].w<tmp[r].w)){
			ne[i]=e[l];
			l++;
		}else{
			ne[i]=tmp[r];
			r++;
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
		e[i].scan();	
	for(int i=1;i<=k;i++){
		c[i]=read();
		if(c[i]) data_a=0;
		int Ec=0;
		for(int j=1;j<=n;j++){
			a[i][j]=read();
			if(!a[i][j]) Ec=1;
		}
		if(!Ec) data_a=0;
	}
	ll ans=0;
	if(data_a){//拉出来直接跑kruskal 
//		cout<<"Data A!!!\n";
		for(int i=1;i<=k;i++)
			for(int j=1;j<=n;j++){
				e[++m].u=n+i,e[m].v=j,e[m].w=a[i][j];
			}
		sort(e+1,e+m+1,cmp);
//		cout<<"Edge ending\n";
		for(int i=1;i<=n+k;i++) fa[i]=i;
		for(int i=1;i<=m;i++){
			if(fi(e[i].u)!=fi(e[i].v)){
				fa[fi(e[i].u)]=fi(e[i].v);
				ans+=e[i].w;
			}
		}
		println(ans);
		return 0;
	}
	sort(e+1,e+m+1,cmp);
	ans=inf;
	for(int S=0;S<(1<<k);S++){
		nowm=0;
		ll tot=0;
		for(int i=1;i<=k;i++){
			if(!((S>>i-1)&1)) continue;
			tot+=c[i];
			for(int j=1;j<=n;j++){
				tmp[++nowm].u=n+i,tmp[nowm].v=j,tmp[nowm].w=a[i][j];
			}
		}
		sort(tmp+1,tmp+nowm+1,cmp);
		mer();
		for(int i=1;i<=n+k;i++) fa[i]=i;
		for(int i=1;i<=nowm+m;i++){
			if(fi(ne[i].u)!=fi(ne[i].v)){
				fa[fi(ne[i].u)]=fi(ne[i].v);
				tot+=ne[i].w;
			}
		}
		ans=min(ans,tot);
	} 
	println(ans);
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
注意开ll！！！ 
*/
