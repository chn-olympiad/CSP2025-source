#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define re register
const int maxn=1e6+10;
const int N=1e4+10;
int n,m,k;
pair<ll,pair<int,int> >e[maxn],g[maxn],st[maxn],a[15][N];
int tot,top;
ll c[N];
int fa[N];
int fi(int x){
	return x==fa[x]?x:fa[x]=fi(fa[x]);
}
ll ans,sum;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	int x,y;ll z;
	for(int i=1;i<=m;++i){
		cin>>x>>y>>z;
		e[i].first=z;
		e[i].second.first=x;
		e[i].second.second=y;
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j){
			cin>>a[i][j].first;
			a[i][j].second.first=i+n;
			a[i][j].second.second=j;
		}
		sort(a[i]+1,a[i]+n+1);
	}
	for(int i=1;i<=n;++i) fa[i]=i;
	sort(e+1,e+m+1);
	ans=0;
	for(int i=1;i<=m;++i){
		z=e[i].first;
		x=e[i].second.first;
		y=e[i].second.second;
		x=fi(x);y=fi(y);
		if(x==y) continue;
		ans+=z;
		fa[y]=x;
		++tot;
		g[tot].first=z;
		g[tot].second.first=x;
		g[tot].second.second=y;
	}
	for(int i=1;i<(1<<k);++i){
		sum=0;
		top=0;
		for(int j=1;j<=n+k;++j) fa[j]=j;
		for(int j=1;j<=tot;++j) st[++top]=g[j];
		for(int j=1;j<=k;++j){
			if(i&(1<<(j-1))){
				sum+=c[j];
				for(int l=1;l<=n;++l){
					if(a[j][l].first>st[n-1].first) break;
					st[++top]=a[j][l];
				}
			} 
		}
		sort(st+1,st+top+1);
		for(int j=1;j<=top;++j){
			z=st[j].first;
			x=st[j].second.first;
			y=st[j].second.second;
			x=fi(x);y=fi(y);
			if(x==y) continue;
			sum+=z;
			fa[y]=x;
		}
		ans=min(ans,sum);
	}
	cout<<ans<<"\n";
	return 0;
}
/*

*/