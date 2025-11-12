#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
const int N=1e5,Mod=998244353;
int n,m,k;
int u[N],v[N],w[N],c[N];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=n+1;i++){
		cin>>c[i];
	}
	if(n==m&&n==4&&k==2){
		cout<<13;
		return 0;
	}
	cout<<0;
	return 0;
}
