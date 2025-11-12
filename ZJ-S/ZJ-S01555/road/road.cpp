#include<bits/stdc++.h>
using namespace std;
//20pts
const int N=1e4+5,M=1e6+5,K=15;
struct node{
	long long u,v,w;
};
node a[2*M];
long long c[K],g[K][N];
map<pair<int,int>,int>mp;
bool cmp(node x,node y){
	return x.w<y.w;	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		mp[{a[i].u,a[i].v}]=i;
		mp[{a[i].v,a[i].u}]=i;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			long long val;
			cin>>val;
			g[i][j]=val;
		}
	}
	int totm=m+1;
	sort(a+1,a+totm,cmp);
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans+=a[i].w;
	}
	cout<<ans;
	return 0;
}
