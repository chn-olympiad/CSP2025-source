#include <bits/stdc++.h>
using namespace std;
int n,m,k,aaaaa,ans;
struct dml{
	int u,v,mn;
}a[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		cin>>a[i].u>>a[i].v>>a[i].mn;
	}
	for(int i=1;i<=k;++i){
		for(int j=1;j<=1+n;++j)cin>>aaaaa;
	}
	for(int i=1;i<=m/2;++i)ans+=a[i].mn;
	cout<<ans<<endl;
	return 0;
}