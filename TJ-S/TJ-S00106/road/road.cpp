#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,k,sum=0;
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		sum+=w;
	}
	cout<<sum;
	return 0;
}
