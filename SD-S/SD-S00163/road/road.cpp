#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int power(int a,int b){
	int ans=1;
	for(;b;b>>=1){
		if(b&1) ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
int c[10100][10100],fa[10100];
vector<int> g[10100];
void link(int x,int y,int z){
	g[x].push_back(y);
	g[y].push_back(x);
	if(c[x][y]){
		c[x][y]=min(c[x][y],z);
		c[y][x]=min(c[y][x],z); 
	}
	else{
		c[x][y]=z;
		c[y][x]=z;	
	}
	
}
int get(int x){
	if(fa[x]==x) return x;
	return fa[x]=get(fa[x]);
}
void merge(int x,int y){
	fa[get(x)]=get(y);
}
int n,m,k,a[11][10010],v[10010],ans;
map<int,int> mp;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		link(u,v,w);
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			a[i][j]+=a[i][0];
			link(i+n,j,a[i][j]);
		}
	} 
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(v[i]){
			continue;
		}
		v[i]=1;
		int minn=0x3f3f3f3f,mi;
		for(int j=0;j<g[i].size();j++){
			int u=g[i][j];
			if(v[u]){
				continue;
			}
			if(c[i][u]<minn){
				minn=c[i][u];
				mi=u;
			}
		}
//		v[mi]=1;
		if(i!=mi){
			cnt++;
		}
		mp[i]++;
		mp[mi]++;
//		cout<<i<<" "<<mi<<" "<<c[i][mi]<<endl;
		ans+=c[i][mi];
	}
	for(int i=1;i<=k;i++){
		if(mp[i]>1){
			ans-=(mp[i]-1)*a[i][0];
		}
	}
	cout<<ans;
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
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
