#include <bits/stdc++.h>
using namespace std;
int n,m,k,ans,w;
struct node{
	int u,v,w;
}a[1000010];
int c[15],s[1000010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>s[j];
	}
	for(int i=1;i<=m;i++){
		ans+=a[i].w;
	}
	cout<<ans;
	return 0;
}
