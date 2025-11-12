#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=1e18;
const int N=1e5+10+3,M=1e6+3;
int n,len,m,k,f[N],c[15],vis[15];
ll ans=inf;
struct node{
	int x,y,w;
	bool operator <(const node &a)const{
		return w<a.w;
	}
}a[M+N*10],b[M];
int Find(int x){
	return x==f[x]?x:f[x]=Find(f[x]);
}
ll solve(int X){
//	cout<<X<<"\n";
	ll sum=0;
	for(int i=1;i<=n+k;i++) f[i]=i;
	for(int i=1;i<=k;i++){
		if(((X>>i)&1)) sum+=c[i],vis[i]=1;
		else vis[i]=0;
	}
	for(int i=1;i<=m;i++)
		if((a[i].x<=n||vis[a[i].x-n])&&Find(a[i].x)!=Find(a[i].y)){
			sum+=a[i].w;
			f[Find(a[i].x)]=Find(a[i].y);
//			cout<<a[i].x<<' '<<a[i].y<<" "<<a[i].w<<"\n";
		}
//	cout<<sum<<"\n";
	return sum;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>len>>k;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=len;i++){
		cin>>b[i].x>>b[i].y>>b[i].w;
	}sort(b+1,b+1+len);
	for(int i=1;i<=len;i++)
		if(Find(b[i].x)!=Find(b[i].y)){
			a[++m]=b[i];
			f[Find(b[i].x)]=Find(b[i].y);
		}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1,w;j<=n;j++){
			cin>>w;
			a[++m]=node{i+n,j,w};
		}
	}sort(a+1,a+1+m);
//	for(int i=1;i<=m;i++) cout<<a[i].x<<" "<<a[i].y<<' '<<a[i].w<<"\n";
	for(int i=0;i<(1<<k);i++) ans=min(ans,solve(i<<1));
	cout<<ans;
	return 0;
}
