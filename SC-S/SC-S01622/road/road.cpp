#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u[114514],v[114514],w[114514],a[1145][11451],c[114514];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=0;i<=k;i++){
		cin>>c[i];
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	if(k==n)
	cout<<'0';
	else{
		int ans=0;
		sort(w,w+m);
		for(int i=0;i<n-k;i++){
			ans+=w[i];
		}
		cout<<ans;
	}
	return 0;
}