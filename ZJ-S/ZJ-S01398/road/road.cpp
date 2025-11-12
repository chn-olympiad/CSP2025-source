#include<bits/stdc++.h>
#define pb push_back
#define ll long long 
using namespace std;
inline int rd(){
	int x=0,y=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')y=-1;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return x*y;
}
const int N=2e6+5;
struct nd{int u,v,w,id;};
vector<nd>e;
int n,f[N],m,k,c[N],a[11][N];
bool flg[N];
ll ans;
int getf(int x){
	return x==f[x]?x:f[x]=getf(f[x]);
}
bool cmp(nd a,nd b){
	return a.w<b.w;
}
void sol(int s){
	fill(flg,flg+k+1,0);
	iota(f+1,f+n+k+1,1);
	flg[0]=1;
	ll sum=0;
	for(int i=0;i<k;i++)
		if(s>>i&1)flg[i+1]=1,sum+=c[i+1];
	for(auto [u,v,w,id]:e)if(flg[id]){
		u=getf(u),v=getf(v);
		if(u==v)continue;
		sum+=w;
		f[u]=v;
	}
	ans=min(ans,sum);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=rd();m=rd();k=rd();
	vector<array<int,3>>E;
	for(int u,v,w;m--;)
		u=rd(),v=rd(),w=rd(),E.pb({w,u,v});
	sort(E.begin(),E.end());
	iota(f+1,f+n+1,1);
	ll sum=0;
	for(auto [w,u,v]:E){
		if(getf(v)!=getf(u)){
			e.pb({u,v,w,0});
			f[getf(u)]=getf(v);
			sum+=w;
		}
	}
	ans=sum;
	for(int i=1;i<=k;i++){
		c[i]=rd();
		for(int j=1;j<=n;j++)
			a[i][j]=rd(),e.pb({j,n+i,a[i][j],i});
	}
	sort(e.begin(),e.end(),cmp);
	for(int s=1;s<1<<k;s++)sol(s);
	cout<<ans<<'\n';
	return 0;
}
/*
记得造极限数据
*/