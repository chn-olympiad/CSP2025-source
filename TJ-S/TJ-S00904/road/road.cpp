#include <bits/stdc++.h>
#define ll signed long long
using namespace std;
int const N=1e4+50;
ll f[N][N]={1e18},ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		f[a][b]=f[b][a]=min(f[a][b],c);
	}
	for(int i=1;i<=k;i++){
		int a,b,c,d,e;
		cin>>a>>b>>c>>d>>e;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans+=f[i][j];
		}
	}
	cout<<ans<<endl;
	return 0;
}
