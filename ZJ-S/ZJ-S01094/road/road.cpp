#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k,ans=0x3f3f3f3f3f,c[15];
int a[15][10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			sum+=a[i][j];
		}
		sum+=w[i];
		ans=min(ans,sum);
		sum=0;
	}
	cout<<ans;
	return 0;
}
//ÊÇÈË
//2000+
