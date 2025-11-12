#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,mod=1e9+7;
int T,n,a[N][5],maxx,f[N][5];
void dfs(int k,int d1,int d2,int d3,int ans){
	if(k>n){
		maxx=max(maxx,ans);
		return;
	}
	if(d1<n/2) dfs(k+1,d1+1,d2,d3,ans+a[k][1]);
	if(d2<n/2&&a[k][1]!=a[k][2]) dfs(k+1,d1,d2+1,d3,ans+a[k][2]);
	if(d3<n/2&&a[k][1]!=a[k][3]&&a[k][2]!=a[k][3]) dfs(k+1,d1,d2,d3+1,ans+a[k][3]);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
		maxx=0;
		if(n<=10){
			dfs(1,0,0,0,0);
			cout<<maxx<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++)
			maxx+=max(a[i][1],max(a[i][2],a[i][3]));
		cout<<maxx<<'\n';
	}
	return 0;
}
