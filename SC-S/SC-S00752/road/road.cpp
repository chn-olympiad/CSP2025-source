#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
long long n,m,k,a[N][N],c[N],w[N],b[N][N],ans=0;
vector<int> e[N];
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			b[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		int u,v,p;
		cin>>u>>v>>p;
		e[u].push_back(v);
		e[v].push_back(u);
		b[u][v]=p;
		b[v][u]=p;
		w[u]+=p;
		w[v]+=p;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			b[i][j]=0;
			b[j][i]=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans+=b[i][j];
		}
	}
	cout<<ans/2;
	return 0;
}