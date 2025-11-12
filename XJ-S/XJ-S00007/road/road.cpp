#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
int q[1000010];
int c,a[100010];
struct dao{
	int u,v,w;
}lu[1000010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>lu[i].u>>lu[i].v>>lu[i].w;
	}
	cin>>c;
	for(int i=1;i<=k;i++){
		cin>>a[i];
	}
	if(m==n-1){
		for(int i=1;i<=m;i++){
			ans+=lu[i].w;
		}
		cout<<ans;
	}
	return 0;
}
