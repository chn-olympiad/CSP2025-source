#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+100;
struct aaa{
	ll u,v,w;
}g[N];
bool cmp(aaa x,aaa y){
	return x.w<y.w;
}
ll a[20][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>g[i].u>>g[i].v>>g[i].w;
	}
	sort(g+1,g+n+1,cmp);
	for(int i=1;i<=m+1;i++){
		for(int j=1;j<=k;j++){
			cin>>a[i][j];
		}
	}
	ll ans=0;
	for(int i=1;i<=m-k;i++){
		ans+=g[i].w;
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
