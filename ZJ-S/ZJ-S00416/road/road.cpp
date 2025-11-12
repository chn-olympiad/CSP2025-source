#include<bits/stdc++.h>
using namespace std;
int a[10015][10015],b[100][10090],u[10015],v[10015],l;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>l;
		a[u[i]][v[i]]=l;
		a[v[i]][u[i]]=l;
	}
	int mx=1e9;
	for(int i=1;i<=k;i++){
		int x,ans=0;
		cin>>x;
		ans=x;
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
			ans+=b[i][j];
		}
		mx=min(mx,ans);
	}
	cout<<mx;
	return 0;
}
